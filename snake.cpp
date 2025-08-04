#include "snake.h"

void init_snake(Snake& snake, Field& field)
{
	snake.size = 2;
	snake.x[0] = field.columns / 2;
	snake.y[0] = field.rows / 2;
	snake.direction = noDir;
	snake.setStartPos = true;

	for (size_t i = 1; i < snake.size; i++)
	{
		if (snake.direction == D_Right)
		{
			snake.x[i] = snake.x[i - 1] - 1;
			snake.y[i] = snake.y[i - 1];
		}
		else if (snake.direction == D_Left)
		{
			snake.x[i] = snake.x[i - 1] + 1;
			snake.y[i] = snake.y[i - 1];			
		}
		else if (snake.direction == D_Up)
		{
			snake.y[i] = snake.y[i - 1] + 1;
			snake.x[i] = snake.x[i - 1];
		}
		else if (snake.direction == D_Down)
		{
			snake.y[i] = snake.y[i - 1] - 1;
			snake.x[i] = snake.x[i - 1];
		}
	}
}

void move_snake(Snake& snake)
{
	for (size_t i = snake.size - 1; i > 0; i--)
	{
		snake.x[i] = snake.x[i - 1];
		snake.y[i] = snake.y[i - 1];
	}

	if (snake.direction == D_Right)
	{
		snake.x[0]++;
	}
	else if (snake.direction == D_Left)
	{
		snake.x[0]--;
	}
	else if (snake.direction == D_Up)
	{
		snake.y[0]--;
	}
	else if (snake.direction == D_Down)
	{
		snake.y[0]++;
	}
}
