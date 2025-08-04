#include "game.h"

void hello_game(Game& game, Field& field, Food& food)
{
	game.timeout = 250;
	game.game_on = false;
	game.do_exit = false;

	food.food_flag = true;

	std::cout << "\n	 Welcome to SNAKE GAME\n";
	Sleep(1000);

	do
	{
		std::cout << "\n	 Enter the number of COLUMNS (10-30):\n     --->";
		std::cin >> field.columns;

		if (field.columns < 10 || field.columns > 30)
		{
			std::cout << "	 Wrong number!\n";
		}
	} while (field.columns < 10 || field.columns > 30);

	do
	{
		std::cout << "\n	 Enter the number of ROWS (10-30):\n     --->";
		std::cin >> field.rows;

		if (field.rows < 10 || field.rows > 30)
		{
			std::cout << "	 Wrong number!\n";
		}
	} while (field.rows < 10 || field.rows > 30);

	field.columns += 2;
	field.rows += 2;

	field.field = new char* [field.rows];
}

void init_game(Game& game, unsigned int& getInput)
{
	game.game_on = true;

	std::cout << std::endl << " = = = Press [W][A][S][D] to START = = =" << std::endl;
	do
	{
		getInput = _getch();
	} while (getInput != LEFT && getInput != RIGHT && getInput != UP && getInput != DOWN);
	system("cls");
}

void set_snake(Game& game, Field& field, Snake& snake, const char& head_symbol, const char& tail_symbol)
{
	if (game.game_on || game.do_exit)
	{
		for (size_t i = 1; i < snake.size; i++)
		{
			field.field[snake.y[i]][snake.x[i]] = tail_symbol;
		}
	}

	field.field[snake.y[0]][snake.x[0]] = head_symbol;
}

void check_eating(Food& food, Snake& snake, const int& L)
{
	if (snake.x[0] == food.x && snake.y[0] == food.y)
	{
		snake.size++;
		if (snake.size < L)
		{
			food.food_flag = true;
		}
		food.x = -1;
		food.y = -1;
	}
}

void check_game(Game& game, Snake& snake, const int& L)
{
	//Алгоритм именно такой, т.к. есть 2 варианта: победа и поражение
	std::cout << "	 Target: " << L << "\n	 Score: " << snake.size << "\n";

	if (game.do_exit)
	{
		std::cout << "\n	 = = = Game over! = = =\n";
		game.game_on = false;
	}

	if (snake.size == L)
	{
		std::cout << "\n	 = = = You win! = = =\n";
		game.game_on = false;
	}
}

void check_snake(Game& game, Field& field, Snake& snake)
{
	if (snake.direction != noDir)
	{
		for (size_t i = 0; i < snake.size; i++)
		{
			if (snake.x[i] == field.columns - 1)	//проверка правой границы
			{
				snake.x[i] = 1;
			}

			if (snake.x[i] == 0)	//проверка левой границы
			{
				snake.x[i] = field.columns - 2;
			}

			if (snake.y[i] == 0)	//проверка верхней границы
			{
				snake.y[i] = field.rows - 2;
			}

			if (snake.y[i] == field.rows - 1)	//проверка нижней границы
			{
				snake.y[i] = 1;
			}

			if (i > 0 && snake.x[0] == snake.x[i] && snake.y[0] == snake.y[i])
			{
				game.do_exit = true;
			}
		}
	}
}

void handle_cmd(unsigned int& getInput, Game& game, Snake& snake, Field& field)
{
	switch (getInput)
	{
	case 27:		//6) Проверка на конец игры 
		game.game_on = false;
		game.do_exit = true;
		break;

	case RIGHT:
		if (snake.direction != D_Left)
		{
			snake.direction = D_Right;
			if (snake.setStartPos)
			{
				init_snake(snake, field);
				snake.setStartPos = false;
			}

			move_snake(snake);
		}
		else if (snake.direction == D_Left)
		{
			getInput = LEFT;
		}
		break;

	case LEFT:
		if (snake.direction != D_Right)
		{
			snake.direction = D_Left;
			if (snake.setStartPos)
			{
				init_snake(snake, field);
				snake.setStartPos = false;
			}

			move_snake(snake);
		}
		else if (snake.direction == D_Right)
		{
			getInput = RIGHT;
		}
		break;

	case UP:
		if (snake.direction != D_Down)
		{
			snake.direction = D_Up;
			if (snake.setStartPos)
			{
				init_snake(snake, field);
				snake.setStartPos = false;
			}

			move_snake(snake);
		}
		else if (snake.direction == D_Down)
		{
			getInput = DOWN;
		}
		break;

	case DOWN:
		if (snake.direction != D_Up)
		{
			snake.direction = D_Down;
			if (snake.setStartPos)
			{
				init_snake(snake, field);
				snake.setStartPos = false;
			}

			move_snake(snake);
		}
		else if (snake.direction == D_Up)
		{
			getInput = UP;
		}
		break;

	default:
		break;
	}
}