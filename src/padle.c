#include "../include/padle.h"
#include "../include/ball.h"
#include "../include/config.h"

void move_player(Padle *player, float deltaTime){
    if(IsKeyDown(KEY_W))
        player->body.y -= deltaTime * player->speed;
    if(IsKeyDown(KEY_S))
        player->body.y += deltaTime * player->speed;
    if (player->body.y < 0)
        player->body.y = 0;

    if (player->body.y + player->body.height > WINDOW_HEIGHT)
        player->body.y = WINDOW_HEIGHT - player->body.height;
}
void move_cpu(Padle *cpu,Ball *b ,float deltaTime){
    float paddleCenterY = cpu->body.y + cpu->body.height / 2.0f;
    float distance = b->center.y - paddleCenterY;
    float step = cpu->speed * deltaTime;

    if (distance > step)
        cpu->body.y += step;
    else if (distance < -step)
        cpu->body.y -= step;
    else
        cpu->body.y = b->center.y - cpu->body.height / 2.0f;

    if (cpu->body.y < 0)
        cpu->body.y = 0;

    if (cpu->body.y + cpu->body.height > WINDOW_HEIGHT)
        cpu->body.y = WINDOW_HEIGHT - cpu->body.height;
}
