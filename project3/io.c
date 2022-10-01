#include "scheduler.h"

void InputEventDescription(char *prompt, char *str, int max)
{
    char buffer[100];

    printf("%s", prompt);
    /* Get a line of up to 100 characters */
    fgets(buffer, sizeof(buffer), stdin);

    /* Remove any stray newlines from the buffer */
    while (buffer[0] == '\n')
        fgets(buffer, sizeof(buffer), stdin);

    /* Remove any \n we may have input */
    if (strlen(buffer) > 0)
        buffer[strlen(buffer) - 1] = '\0';

    /* Copy up to max characters to our string */
    strncpy(str, buffer, max);
    str[max - 1] = '\0';
}

time_t InputDate(char *prompt)
{
    char buffer[100];
    char *result;
    struct tm date;

    do
    {
        printf("%s", prompt);

        /* Get a line of up to 100 characters */
        fgets(buffer, sizeof(buffer), stdin);

        /* Remove any \n we may have input */
        if (strlen(buffer) > 0)
            buffer[strlen(buffer) - 1] = '\0';

        result = strptime(buffer, "%m/%d/%Y", &date);

    } while (result == NULL || date.tm_year + 1970 < 1970);

    /* Convert to time_t format */
    date.tm_min = 0;
    date.tm_hour = 0;
    date.tm_sec = 0;
    date.tm_isdst = -1;

    return mktime(&date);
}

time_t InputTime(char *prompt, time_t date)
{
    char buffer[100];
    char *result;
    struct tm time;

    time = *localtime(&date);

    do
    {
        printf("%s", prompt);

        /* Get a line of up to 100 characters */
        fgets(buffer, sizeof(buffer), stdin);

        /* Remove any \n we may have input */
        if (strlen(buffer) > 0)
            buffer[strlen(buffer) - 1] = '\0';

        result = strptime(buffer, "%I:%M%p", &time);

    } while (result == NULL);

    return mktime(&time);
}

int InputCommand(char *prompt)
{
    char buffer[100];
    int value = 0;

    do
    {
        printf("%s", prompt);

        /* Get a line of up to 100 characters */
        fgets(buffer, sizeof(buffer), stdin);

        /* Remove any \n we may have input */
        if (strlen(buffer) > 0)
            buffer[strlen(buffer) - 1] = '\0';

        sscanf(buffer, "%d", &value);
    } while (value < CommandExit || value > CommandDeleteExpired);

    return value;
}

void OutputDate(time_t date)
{
    struct tm result;
    result = *localtime(&date);
    printf("%d/%d/%d  ", result.tm_mon + 1, result.tm_mday, result.tm_year + 1900);
}

void OutputTime(time_t time)
{
    struct tm result;
    result = *localtime(&time);
    if (result.tm_hour > 12)
    {
        printf("%d:%02dPM  ", result.tm_hour - 12, result.tm_min);
    }
    else
    {
        printf("%d:%02dAM  ", result.tm_hour, result.tm_min);
    }
}

void DisplayEvent(char *prompt, Event e)
{
    printf("%s", prompt);
    OutputDate(e.date);
    OutputTime(e.startTime);
    OutputTime(e.endTime);
    printf("%s\n", e.description);
}

void DisplayEvents(Schedule schedule)
{
    int i;

    printf("\nSchedule:\n");
    for (i = 0; i < schedule.numEvents; i++)
    {
        DisplayEvent("", schedule.events[i]);
    }

    printf("\n");
}

void DisplayNow(Schedule schedule)
{
    time_t now = time(0);
    for (int i = 0; i < schedule.numEvents; i++)
    {
        if (now >= schedule.events[i].startTime && now <= schedule.events[i].endTime)
        {
            DisplayEvent("Currently active events:", schedule.events[i]);
        }
    }
}

Schedule InputEvent(Schedule schedule)
{
    Event e;
    Event tmp_e;
    InputEventDescription("What is the event", e.description, sizeof(e.description));
    e.date = InputDate("Event date: ");
    e.startTime = InputTime("Start time: ", e.date);
    e.endTime = InputTime("End time: ", e.date);

    schedule.numEvents++;
    schedule.events = realloc(schedule.events, sizeof(Event) * (schedule.numEvents));

    for (int i = 0; i < schedule.numEvents; i++)
    {
        if (i == schedule.numEvents - 1)
        {
            // the final one of array, just insert
            schedule.events[i] = e;
        }
        if ((e.startTime >= schedule.events[i].startTime && e.startTime < schedule.events[i].endTime) || (e.endTime > schedule.events[i].startTime && e.endTime <= schedule.events[i].endTime))
        {
            if (strcmp(e.description, schedule.events[i].description))
            {
                // overlap detection
                DisplayEvent("\n\n!Warning, this event overlaps!:\n", schedule.events[i]);
            }
        }
        if (e.startTime < schedule.events[i].startTime)
        {
            // replace the old one, use the tmp_e to insert
            // the next
            tmp_e = schedule.events[i];
            schedule.events[i] = e;
            e = tmp_e;
        }
    }

    return schedule;
}

Schedule DeleteExpired(Schedule schedule)
{
    time_t now = time(0);
    bool deleted_something = false;
    for (int i = schedule.numEvents-1; i >= 0; i--)
    {
        if (schedule.events[i].endTime < now){
            schedule.numEvents--;
            schedule.events = realloc(schedule.events, sizeof(Event) * (schedule.numEvents));
            DisplayEvent("Deleting:\n", schedule.events[i]);
            deleted_something = true;
        }
    }
    if (!deleted_something){
        printf("No expired events\n");
    }
    return schedule;
}
