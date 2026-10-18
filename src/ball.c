#include "../include/ball.h"
#include "../include/padle.h"
#include "../include/config.h"
#include <math.h>



Ball init_ball(Vector2 c,Vector2 v, float rd, Color cl){
   Ball b = {.clr = cl, .center = c, .radius = rd, .velocity = v}; 
   return b;
}

void start_ball(Ball *b)
{
    b->center.x = (float)WINDOW_WIDTH / 2.0f;
    b->center.y = (float)WINDOW_HEIGHT / 2.0f;

    float direction = GetRandomValue(0, 1) == 0 ? -1.0f : 1.0f;

    b->velocity.x = 300.0f * direction;
    b->velocity.y = 150.0f; 
};
void move_ball(Ball *b, float deltaTime){
    b->center.x += b->velocity.x * deltaTime;
    b->center.y += b->velocity.y * deltaTime;
}
void b_collision(Ball *b, Padle *p1, Padle *p2){
    static double hit_time = 0.0;
    static bool waiting = false;
    if(CheckCollisionCircleRec(b->center, b->radius, p1->body)){
        float paddle_center = p1->body.y + p1->body.height / 2.0f;
        float offset = (b->center.y - paddle_center) / (p1->body.height / 2.0f);

        if (offset < -1.0f) offset = -1.0f;
        if (offset >  1.0f) offset =  1.0f;

        b->velocity.x = fabsf(b->velocity.x);
        b->velocity.y = offset * 300.0f;

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
        float paddle_center = p2->body.y + p2->body.height / 2.0f;
        float offset = (b->center.y - paddle_center) / (p2->body.height / 2.0f);

        if (offset < -1.0f) offset = -1.0f;
        if (offset >  1.0f) offset =  1.0f;

        b->velocity.x = -fabsf(b->velocity.x);
        b->velocity.y = offset * 300.0f;

        p2->clr = WHITE;
        hit_time = GetTime();
        waiting = true;
    }
}
void check_win(Ball *b){
    if(b->center.x > WINDOW_WIDTH || b->center.x < 0){
        start_ball(b);
    }
}
void check_wall(Ball *b){
   if(b->center.y > WINDOW_HEIGHT || b->center.y < 0){
       b->drct *= -1;
   } 
}
