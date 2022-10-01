#ifndef SCHEDULER_H
#define SCHEDULER_H

#define CommandInsert 1
#define CommandDisplay 2
#define CommandNow 3
#define CommandDeleteExpired 4
#define CommandExit 0

#define __USE_XOPEN
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Event
{
    char description[50];
    time_t date;
    time_t startTime;
    time_t endTime;
    
} Event;

typedef struct Schedule
{
    int numEvents;
    Event *events;
    
} Schedule;

Schedule InputEvent(Schedule schedule);
int InputCommand(char *prompt);
void DisplayEvents(Schedule schedule);
void DisplayNow(Schedule schedule);
Schedule DeleteExpired(Schedule schedule);
#endif