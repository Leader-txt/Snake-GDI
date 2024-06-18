#include "draw.h"

void DrawGameOver(HDC hdc){
	char* gameover_text = "Game Over!";
	TextOut(hdc,WIDTH/3,HEIGHT/2,gameover_text,strlen(gameover_text));
}

void DrawGame(HDC hdc){
	char* text[20];
	sprintf(text,"Your source:%d",snake.length);
	TextOut(hdc,0,0,text,strlen(text));
	HBRUSH hBrush = CreateSolidBrush(RGB(0, 255, 0));
    HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
    Rectangle(hdc,
            snake.body[0].x * PIXEL_PER_BLOCK,
            snake.body[0].y * PIXEL_PER_BLOCK,
            snake.body[0].x * PIXEL_PER_BLOCK + PIXEL_PER_BLOCK,
            snake.body[0].y * PIXEL_PER_BLOCK + PIXEL_PER_BLOCK);
    
    hBrush = CreateSolidBrush(RGB(0, 0, 255));
    SelectObject(hdc, hBrush);
	int i;
    for (i = 1; i < snake.length; i++) {
        Rectangle(hdc,
                  snake.body[i].x * PIXEL_PER_BLOCK,
                  snake.body[i].y * PIXEL_PER_BLOCK,
                  snake.body[i].x * PIXEL_PER_BLOCK + PIXEL_PER_BLOCK,
                  snake.body[i].y * PIXEL_PER_BLOCK + PIXEL_PER_BLOCK);
    }

    hBrush = CreateSolidBrush(RGB(224, 111, 228));
    SelectObject(hdc, hBrush);

    Rectangle(hdc,
              food.x * PIXEL_PER_BLOCK,
              food.y * PIXEL_PER_BLOCK,
              food.x * PIXEL_PER_BLOCK + PIXEL_PER_BLOCK,
              food.y * PIXEL_PER_BLOCK + PIXEL_PER_BLOCK);
    
    hBrush = CreateSolidBrush(RGB(255, 0, 0));
    SelectObject(hdc, hBrush);

    Rectangle(hdc,
              rock.x * PIXEL_PER_BLOCK,
              rock.y * PIXEL_PER_BLOCK,
              rock.x * PIXEL_PER_BLOCK + PIXEL_PER_BLOCK,
              rock.y * PIXEL_PER_BLOCK + PIXEL_PER_BLOCK);

    SelectObject(hdc, oldBrush);
    DeleteObject(hBrush);
}
