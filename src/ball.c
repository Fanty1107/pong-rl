#include "../include/ball.h"


Ball init_ball(Vector2 c, float rd, Color cl, float g){
   Ball b = {.clr = cl, .center = c, .radius = rd, .gravity = g}; 
   return b;
}

void start_ball(Ball *b)
{
    b->drct = GetRandomValue(UP, LEFT);
};
void move_ball(Ball *b, float deltaTime){
    if(b->drct == UP){
        b->center.y -= deltaTime * b->gravity;
        b->center.x += deltaTime * b->gravity;
    }
    else if (b->drct == RIGHT){
        b->center.x += deltaTime * b->gravity;
    }
    else if (b->drct == LEFT){
        b->center.x -= deltaTime * b->gravity;
    }
    else{
        b->center.y += deltaTime * b->gravity;
        b->center.x -= deltaTime * b->gravity;
    }
}
void b_collision(Ball *b, Padle *p1, Padle *p2){
    static double hit_time = 0.0;
    static bool waiting = false;
    if(CheckCollisionCircleRec(b->center, b->radius, p1->body)){
        b->drct = RIGHT;
        p1->clr = WHITE;
        hit_time = GetTime();
        waiting = true;
    }
    if(waiting && GetTime() - hit_time >= 0.5){
        p1->clr = RED;
        p2->clr = RED;
        waiting = false;
    }
    if(CheckCollisionCircleRec(b->center, b->radius, p2->body)){
        b->drct = LEFT;
        p2->clr = WHITE;
        hit_time = GetTime();
        waiting = true;
    }
}
