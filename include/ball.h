#ifndef BALL_H
#define BALL_H
#include <raylib.h>

typedef enum{
    UP = 1,
    DOWN = -1,
}DIRECTIONS;

typedef struct Padle Padle;

typedef struct{
    Color clr;
    Vector2 center;
    Vector2 velocity;
    float radius;
    DIRECTIONS drct;
}Ball;

Ball init_ball(Vector2 c,Vector2 v,float rd,Color cl);
void start_ball(Ball *b);
void check_win(Ball *b);
void move_ball(Ball *b, float deltaTime);
void b_collision(Ball *b, Padle *p1, Padle *p2);

#endif
