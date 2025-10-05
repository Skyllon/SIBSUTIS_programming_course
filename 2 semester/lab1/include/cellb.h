#ifndef CELLB_H
#define CELLB_H

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned int id : 32, type : 2, size : 8, sec_lvl : 3, sec_video : 1,
      rent : 15, cost : 30;
} cellB;

cellB *fill_cell(const unsigned int id, const unsigned int type,
                 const unsigned int size, const unsigned int sec_lvl,
                 const unsigned int sec_video, const unsigned int rent,
                 const unsigned int cost);

void rm_cell(cellB *c);

#endif
