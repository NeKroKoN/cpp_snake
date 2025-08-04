#pragma once
#include "const.h"
#include "field.h"

const enum DIRECTION { noDir = 0, D_Up = 1, D_Down = 2, D_Left = 3, D_Right = 4 };	//Перечисление «направление движения»

struct Snake
{
	int size;	//Текущий размер змейки
	unsigned int x[L];	//Массив координат змейки по горизонтали(X)
	unsigned int y[L];	//Массив координат змейки по вертикали(Y)
	DIRECTION direction;	//Направление движения змейки
	bool setStartPos;		//для установки начальной позиции змейки в зависимости от направления
};

void init_snake(Snake& snake, Field& field);
void move_snake(Snake& snake);