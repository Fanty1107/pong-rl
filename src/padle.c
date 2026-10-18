#include "../include/padle.h"
#include "../include/ball.h"

void move_player(Padle *player, float deltaTime){
    if(IsKeyDown(KEY_W))
        player->body.y -= deltaTime * player->speed;
    if(IsKeyDown(KEY_S))
        player->body.y += deltaTime * player->speed;
}
void move_cpu(Padle *cpu,Ball *b ,float deltaTime){
    cpu->body.y = b->center.y;
}
