#ifndef PADLE_H
#define PADLE_H

#define PADLE_INIT(H, W, X, Y, color, spd) \
    { .body = { .height = (H), .width = (W), .x = (X), .y = (Y) }, \
      .clr = (color), \
      .speed = (spd) }
#include<raylib.h>

typedef struct{
    Rectangle body;
    Color clr;
    float speed;
}Padle;

void move_player(Padle *player,float deltaTime);

#endif

