#include "../include/padle.h"
#include "../include/ball.h"
#include "../include/config.h"
#include <stdlib.h>

int main(){
    InitWindow(WINDOW_WIDTH,WINDOW_HEIGHT, "PONG-PING");
    atexit(CloseWindow);

    Padle p1 = PADLE_INIT(250,10, 0,150, RED, 800.0f);
    Padle cpu = PADLE_INIT(250, 10, 790, 150, RED, 800.0f);
    Vector2 ball_pos = {.x =(float)WINDOW_WIDTH/2, .y = (float)WINDOW_HEIGHT/2};
    Vector2 velocity = {1600.0f, 1600.0f};
    Ball b = init_ball(ball_pos,velocity,15.0f,RED);

    start_ball(&b);
    while(!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();
        move_player(&p1, deltaTime);
        move_ball(&b,deltaTime);
        b_collision(&b, &p1, &cpu);
        check_win(&b);
        move_cpu(&cpu, &b, deltaTime);
        BeginDrawing();
            DrawRectangleRec(p1.body, p1.clr);
            DrawRectangleRec(cpu.body, cpu.clr);
            DrawCircleV(b.center, b.radius, b.clr);
            ClearBackground(BLACK);
        EndDrawing();
    }
    return 0;
}
