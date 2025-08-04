#include "food.h"

void init_food(Food& food, Field& field, Snake& snake, const int& L, const char& food_symbol)
{
	if (food.food_flag)
	{
		bool found;

		do
		{
			food.x = rand() % (field.columns - 2) + 1;
			food.y = rand() % (field.rows - 2) + 1;
			found = false;

			for (size_t i = 0; i < snake.size; i++)
			{
				if (food.x == snake.x[i] && food.y == snake.y[i])
				{
					found = true;
					break;
				}
			}
		} while (found);
		food.food_flag = false;
	}

	if (snake.size < L)
	{
		field.field[food.y][food.x] = food_symbol;
	}
}
