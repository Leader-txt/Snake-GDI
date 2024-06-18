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
		snake.dx = rand()%2 ? 1 : - 1;
	else
		snake.dy = rand()%2 ? 1 : - 1;
	snake.body[0].x = rand()%BLOCKS_X;
	snake.body[0].y = rand()%BLOCKS_Y;
	generateFood();
}

int checkCollision(Point head){
	int i;
	for(i=1;i<snake.length;i++){
		if(head.x == snake.body[i].x && head.y == snake.body[i].y)
			return 1;
	}
	int hx = head.x , hy = head.y;
	return hx < 0 || hx >= BLOCKS_X || hy < 0 || hy >= BLOCKS_Y;
}

void UpdateGame(){
	Point head = { snake.body[0].x + snake.dx , snake.body[0].y + snake.dy};
	if(checkCollision(head)){
		gameOver();
		return;
	}
	if(head.x == food.x && head.y == food.y){
		snake.length++;
		generateFood();
	}
	int i;
	for(i = 1;i<snake.length;i++){
		snake.body[i].x = snake.body[i-1].x;
		snake.body[i].y = snake.body[i-1].y;
	}
	snake.body[0] = head;
}

void gameOver(){
	
}
