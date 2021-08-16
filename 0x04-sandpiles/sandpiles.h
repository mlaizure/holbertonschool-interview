#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void check_stable(int sum[3][3]);
void cascade_top(int sum[3][3]);
void cascade_mid(int prev[3][3], int sum[3][3]);
void cascade_bottom(int prev[3][3], int sum[3][3]);

#endif /* SANDPILES_H */
