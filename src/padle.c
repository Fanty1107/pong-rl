#include "../include/padle.h"
#include <raylib.h>

void move_player(Padle *player, float deltaTime){
    if(IsKeyDown(KEY_W))
        player->body.y -= deltaTime * player->speed;
    if(IsKeyDown(KEY_S))
        player->body.y += deltaTime * player->speed;
}
