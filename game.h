#include "Types.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h> 
#include <windows.h>

#define WIDTH 640
#define HEIGHT 480
#define PIXEL_PER_BLOCK 20
#define BLOCKS_X (WIDTH/PIXEL_PER_BLOCK-1)
#define BLOCKS_Y (HEIGHT/PIXEL_PER_BLOCK-2)
#define ROCK_APPEARANCE_RATE 10 // rate: 1/this value
#define ROCK_TURN_RATE 10

Snake snake;

Point food;

Point rock;
int rx,ry;

int gameover;

void InitGame(); 
void UpdateGame();
void AfterGameOver(HWND hwnd);
