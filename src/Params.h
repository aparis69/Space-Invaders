#pragma once
#include <SDL.h>

// Window settings
#define WINDOW_SIZE_X 640
#define WINDOW_SIZE_Y 480
#define WINDOW_FPS 120
#define WINDOW_TITLE "Space Invaders 2"

// Player settings
#define START_LP 5
#define PLAYER_SPEED 50
#define X_SPAWN 250
#define Y_SPAWN 330
#define MENU_KEY SDLK_m

// Spawning settings
#define ENEMY_SPAWN_DELAY 500

// Missile settings
#define SMALL_MISSILE_SPEED 100
#define MEDIUM_MISSILE_SPEED 50
#define BIG_MISSILE_SPEED 100

#define SMALL_MISSILE_SPAWN_DELAY 500
#define MEDIUM_MISSILE_SPAWN_DELAY 500

// Other settings
#define SCROLL_SPEED 200
#define SPEED_ADJUST 50

enum GameState
{
	MENU,
	OPTION,
	GAME,
	GAME_OVER,
	QUIT,
};