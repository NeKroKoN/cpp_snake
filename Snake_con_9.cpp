#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

#include "const.h"
#include "field.h"
#include "snake.h"
#include "game.h"
#include "food.h"
#include "winconsole.h"

#define stop __asm nop
//#define AUTOMATIC

int main()
{
	srand(time(0));

//Объявление переменных
	Snake snake;
	Food food;
	Field field;
	Game game;

	unsigned int getInput_m;	//Ввод с помощью _getch()
	bool skipScreenManual_m = false;	//нужно для первого пропуска нажатия клавиши, если режим ручной, это необходимо для того, чтобы змейка сразу начала движение

	hello_game(game, field, food);	//В данной версии здесь происходит инициализация field

// СТАРТОВЫЙ ЭКРАН

//1) «Очистка» всего игрового поля
	system("cls");

	//инициализация индексов поля символами
	init_field(field, field_symbol, border_symbol);

//2) Задание начального положения змейки
	init_snake(snake, field);

//3) “Установка” змейки в поле игры
	set_snake(game, field, snake, head_symbol, tail_symbol);

//4) Вывод на экран поля игры
	print_field(field);

//5) Вывод приглашения к игре
	init_game(game, getInput_m);

// ИГРА

	while (game.game_on)
	{
	//1) Очистка позиций змейки на экране

		clear_field(field, field_symbol);

	//2) Изменение положения змейки (продвижение в нужном направлении)

#ifdef AUTOMATIC

		Sleep(timeout_m);	//7) «Задержка» выполнения игры

		if (_kbhit())
		{
			getInput_m = _getch();
		}
#else
		if (skipScreenManual_m)
		{
			getInput_m = _getch();
		}
		else
		{
			skipScreenManual_m = true;
		}
#endif
		//std::cout << getInput << "\n" << snake_size;	//для отладки

		handle_cmd(getInput_m, game, snake, field);

		//После задания 6 перенес ПЕРВУЮ генерацию еды после первого ввода с клавиатуры, т.к. он учитывает размеры змейки и направление, чтобы еда появлялась в пустом поле
		init_food(food, field, snake, L, food_symbol);
 
	//3) Проверка столкновения с границей поля
 		check_snake(game, field, snake);

	//4) Установка новых позиций змейки в поле игры

		//Установка змейки
		set_snake(game, field, snake, head_symbol, tail_symbol);

		//Проверка на съедение
		check_eating(food, snake, L);

		//Генерация еды при перерисовке, если еда съедена
		init_food(food, field, snake, L, food_symbol);

	//5) Вывод поля игры на экран
		print_field(field);

	//Проверка конца игры
		check_game(game, snake, L);
	}

	//Удаление поля из памяти
	destroy_field(field);

	stop
}