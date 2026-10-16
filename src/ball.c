#include "../include/ball.h"
#include <raylib.h>


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
