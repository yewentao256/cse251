#ifndef HANOI_H
#define HANOI_H

#define NumPins 3
#define NumDisks 6
#define MaxDiskSize 13

void DisplayDisk(int p);
void DisplayTower(int tower[NumPins][NumDisks]);
int InputPin(char *msg, int fm, int to);
void MoveDisk(int tower[NumPins][NumDisks], int fm, int to);
void Reset(int tower[NumPins][NumDisks]);

#endif