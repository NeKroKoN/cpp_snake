#pragma once
#include <cstdlib>
#include <ctime>

#include "const.h"
#include "snake.h"
#include "field.h"

struct Food
{
	bool food_flag;	//Наличие еды
	int x;	//Координата еды по горизонтали(X)
	int y;	//Координата еды по по вертикали(Y)
};

void init_food(Food& food, Field& field, Snake& snake, const int& L, const char& food_symbol);
//void generate_food();