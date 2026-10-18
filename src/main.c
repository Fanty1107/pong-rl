#include "../include/padle.h"
#include "../include/ball.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

int main(){
    InitWindow(WINDOW_WIDTH,WINDOW_HEIGHT, "PONG-PING");

    Padle p1 = PADLE_INIT(250,10, 0,150, RED, 400.0f);
    Padle cpu = PADLE_INIT(250, 10, 790, 150, RED, 400.0f);
    Vector2 ball_pos = {.x =(float)WINDOW_WIDTH/2, .y = (float)WINDOW_HEIGHT/2};
    Ball b = init_ball(ball_pos,15.0f,RED,300.0f);

    start_ball(&b);
    while(!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();
        move_player(&p1, deltaTime);
        move_ball(&b,deltaTime);
        b_collision(&b, &p1, &cpu);
        BeginDrawing();
            DrawRectangleRec(p1.body, p1.clr);
            DrawRectangleRec(cpu.body, cpu.clr);
            DrawCircleV(b.center, b.radius, b.clr);
            ClearBackground(BLACK);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
