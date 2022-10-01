#ifndef AUTOSOLVE_H
#define AUTOSOLVE_H

#include "hanoi.h"

void AutoMove(int tower[NumPins][NumDisks], int num, int fm, int to);
void Autosolve(int tower[NumPins][NumDisks]);

#endif