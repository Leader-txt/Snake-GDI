#include "Types.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h> 

#define WIDTH 640
#define HEIGHT 480
#define PIXEL_PER_BLOCK 20
#define BLOCKS_X WIDTH/PIXEL_PER_BLOCK
#define BLOCKS_Y HEIGHT/PIXEL_PER_BLOCK

Snake snake;

Point food;

void InitGame(); 
