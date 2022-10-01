#include "scheduler.h"

int main()
{   
    int command;
    bool keep_loop = true;
    Schedule schedule;
    schedule.numEvents=0;
    schedule.events=malloc(0);

    while (keep_loop) {
        command = InputCommand("1 - Insert a new event\n2 - Display all events\n"
        "3 - Now?\n4 - Delete expired\n0 - Exit\nPlease select an option: ");

        switch (command)
        {
        case CommandInsert:
            schedule = InputEvent(schedule);
            break;
        case CommandDisplay:
            DisplayEvents(schedule);
            break;
        case CommandNow:
            DisplayNow(schedule);
            break;
        case CommandDeleteExpired:
            schedule = DeleteExpired(schedule);
            break;
        case CommandExit:
            keep_loop = false;
            break;
        }
    }

}
