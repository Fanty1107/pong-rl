#ifndef BALL_H
#define BALL_H
#include "../include/padle.h"

typedef enum{
    UP,
    DOWN,
    RIGHT,
    LEFT,
}DIRECTIONS;

typedef struct{
    Color clr;
    Vector2 center;
    float radius;
    float gravity;
    DIRECTIONS drct;
}Ball;
Ball init_ball(Vector2 c, float rd,Color cl,float g);
void start_ball(Ball *b);
void move_ball(Ball *b, float deltaTime);
void b_collision(Ball *b, Padle *p1, Padle *p2);

#endif
