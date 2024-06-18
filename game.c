#include "game.h"

void generateFood(){
	int filled,i;
	while(1){
		filled = 0;
		food.x = rand()%BLOCKS_X;
		food.y = rand()%BLOCKS_Y;
		if(food.x == rock.x && food.y == rock.y)
			continue;
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

// 0 for up 1 for down 2 for left 3 for right
void generateRock(){
	int isFilled(){
		if(rock.x == food.x && rock.y == food.y)
			return 1;
		int i;
		for(i=0;i<snake.length;i++){
			if(rock.x == snake.body[i].x && rock.y == snake.body[i].y)
				return 1;
		}
		return 0;
	}
	do{
		switch(rand()%4){
			case 0:{
				rock.x = rand()%BLOCKS_X;
				rock.y = 0;
				break;
			}
			case 1:{
				rock.x = rand()%BLOCKS_X;
				rock.y = BLOCKS_Y - 1;
				break;
			}
			case 2:{
				rock.y = rand()%BLOCKS_Y;
				rock.x = 0;
				break;
			}
			case 3:{
				rock.y = rand()%BLOCKS_Y;
				rock.x = BLOCKS_X - 1;
				break;
			}
		}	
	}
	while(isFilled());
}

void hideRock(){
	rock.x = -1;
	rock.y = -1;
}

int isRockActive(){
	return rock.x != -1 && rock.y != -1;
}

int canRockAppear(){
	return !(rand()%ROCK_APPEARANCE_RATE);
}

void moveRock(){
	rock.x += rx;
	rock.y += ry;	
}

void randomlyMoveRock(){
	if(rand()%2){
		rx = rand()%2 ? 1 : - 1;
		ry = 0;
	}
	else
	{
		rx = 0;
		ry = rand()%2 ? 1 : - 1;
	}
}

int isSamePoint(Point p1,Point p2){
	return p1.x == p2.x && p1.y == p2.y;
}

void InitGame(){
	gameover = 0;
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
	hideRock();
//	generateRock();
}

int outOfBound(Point p){
	return p.x < 0 || p.x >= BLOCKS_X || p.y < 0 || p.y >= BLOCKS_Y; 
}

int checkCollision(Point head){
	int i;
	for(i=1;i<snake.length;i++){ // if hit the body
		if(head.x == snake.body[i].x && head.y == snake.body[i].y)
			return 1;
	}
	if(head.x == rock.x && head.y == rock.y) // if hit the rock
		return 1;
	return outOfBound(head);
}

void gameOver(){
	gameover = 1;
}

void UpdateGame(){
	Point head = { snake.body[0].x + snake.dx , snake.body[0].y + snake.dy};
	if(checkCollision(head)){
		gameOver();
		return;
	}
	if(isRockActive()){
		moveRock();
		if(!(rand()%ROCK_TURN_RATE))
			randomlyMoveRock();
		if(outOfBound(rock)){
			hideRock();
		}
		if(rock.x == food.x && rock.y == food.y){ // rock hit the food
			generateFood();
		}
		int i;
		for(i=0;i<snake.length;i++){
			if(isSamePoint(rock,snake.body[i])){
				if(i){//hit the body
					snake.length = i;
				}
				else{//hit the head
					gameOver();
					return;
				}
				break;
			}
		}
	}
	else{
		if(canRockAppear()){
			generateRock();
			randomlyMoveRock();
		}
	}
	if(head.x == food.x && head.y == food.y){
		snake.length++;
		if(snake.length == BLOCKS_X*BLOCKS_Y){
			gameOver();
			return;
		}
		generateFood();
	}
	int i;
	for(i = snake.length - 1;i>0;i--){
		snake.body[i].x = snake.body[i-1].x;
		snake.body[i].y = snake.body[i-1].y;
	}
	snake.body[0] = head;
}

void AfterGameOver(HWND hwnd){
	KillTimer(hwnd,1);
	char* text[100];
	sprintf(text,"Your source:%d , try again?",snake.length);
	int result = MessageBox(hwnd,text,"Game Over!",MB_YESNO|MB_ICONINFORMATION);
	if(result == IDYES){
		InitGame();
		SetTimer(hwnd,1,150,0);
	}
	else{
		DestroyWindow(hwnd);
	}
}
