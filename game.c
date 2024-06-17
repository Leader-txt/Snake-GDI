#include "game.h"

void generateFood(){
	int filled,i;
	while(1){
		filled = 0;
		food.x = rand()%BLOCKS_X;
		food.y = rand()%BLOCKS_Y;
		for(i = 0;i<snake.length;i++){
			if(snake.body[i].x == food.x && snake.body[i].y == food.y){
				filled = 1;
				break;
			}
		}
		if(!filled)
			break;
	}
}

void InitGame(){
	srand(time(0));
	snake.length = 1;
	snake.dx = snake.dy = 0;
	if(rand()%2)
		snake.dx = rand()%3 - 1;
	else
		snake.dy = rand()%3 - 1;
	snake.body[0].x = rand()%BLOCKS_X;
	snake.body[0].y = rand()%BLOCKS_Y;
	generateFood();
}

int checkCollision(){
	int i;
	for(i=1;i<snake.length;i++){
		if(snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y)
			return 1;
	}
	int hx = snake.body[0].x , hy = snake.body[0].y;
	return hx < 0 || hx >= BLOCKS_X || hy < 0 || hy >= BLOCKS_Y;
}

void UpdateGame(){
	snake.body[0].x += snake.dx;
	snake.body[0].y += snake.dy;
	
}

void gameOver(){
	
}
