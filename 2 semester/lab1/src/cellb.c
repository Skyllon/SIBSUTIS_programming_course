#include "../include/cellb.h"

cellB *fill_cell(const unsigned int id, const unsigned int type,
                 const unsigned int size, const unsigned int sec_lvl,
                 const unsigned int sec_video, const unsigned int rent,
                 const unsigned int cost) {
  cellB *c = (cellB *)malloc(sizeof(cellB));
  if (!c) {
    printf("Память не была аллоцирована!\n");
    return 1;
  }

  c->id = id;
  c->type = type;
  c->size = size;
  c->sec_lvl = sec_lvl;
  c->sec_video = sec_video;
  c->rent = rent;
  c->cost = cost;

  return c;
}

void rm_cell(cellB *c) { free(c); }
