#include "draw.h"

void DrawGame(HDC hdc){
	HBRUSH hBrush = CreateSolidBrush(RGB(0, 255, 0));
    HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
	int i;
    for (i = 0; i < snake.length; i++) {
        Rectangle(hdc,
                  snake.body[i].x * PIXEL_PER_BLOCK,
                  snake.body[i].y * PIXEL_PER_BLOCK,
                  snake.body[i].x * PIXEL_PER_BLOCK + PIXEL_PER_BLOCK,
                  snake.body[i].y * PIXEL_PER_BLOCK + PIXEL_PER_BLOCK);
    }

    hBrush = CreateSolidBrush(RGB(255, 0, 0));
    SelectObject(hdc, hBrush);

    Rectangle(hdc,
              food.x * PIXEL_PER_BLOCK,
              food.y * PIXEL_PER_BLOCK,
              food.x * PIXEL_PER_BLOCK + PIXEL_PER_BLOCK,
              food.y * PIXEL_PER_BLOCK + PIXEL_PER_BLOCK);

    SelectObject(hdc, oldBrush);
    DeleteObject(hBrush);
}
