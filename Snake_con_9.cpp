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

//���������� ����������
	Snake snake;
	Food food;
	Field field;
	Game game;

	unsigned int getInput_m;	//���� � ������� _getch()
	bool skipScreenManual_m = false;	//����� ��� ������� �������� ������� �������, ���� ����� ������, ��� ���������� ��� ����, ����� ������ ����� ������ ��������

	hello_game(game, field, food);	//� ������ ������ ����� ���������� ������������� field

// ��������� �����

//1) �������� ����� �������� ����
	system("cls");

	//������������� �������� ���� ���������
	init_field(field, field_symbol, border_symbol);

//2) ������� ���������� ��������� ������
	init_snake(snake, field);

//3) ����������� ������ � ���� ����
	set_snake(game, field, snake, head_symbol, tail_symbol);

//4) ����� �� ����� ���� ����
	print_field(field);

//5) ����� ����������� � ����
	init_game(game, getInput_m);

// ����

	while (game.game_on)
	{
	//1) ������� ������� ������ �� ������

		clear_field(field, field_symbol);

	//2) ��������� ��������� ������ (����������� � ������ �����������)

#ifdef AUTOMATIC

		Sleep(timeout_m);	//7) ��������� ���������� ����

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
		//std::cout << getInput << "\n" << snake_size;	//��� �������

		handle_cmd(getInput_m, game, snake, field);

		//����� ������� 6 ������� ������ ��������� ��� ����� ������� ����� � ����������, �.�. �� ��������� ������� ������ � �����������, ����� ��� ���������� � ������ ����
		init_food(food, field, snake, L, food_symbol);
 
	//3) �������� ������������ � �������� ����
 		check_snake(game, field, snake);

	//4) ��������� ����� ������� ������ � ���� ����

		//��������� ������
		set_snake(game, field, snake, head_symbol, tail_symbol);

		//�������� �� ��������
		check_eating(food, snake, L);

		//��������� ��� ��� �����������, ���� ��� �������
		init_food(food, field, snake, L, food_symbol);

	//5) ����� ���� ���� �� �����
		print_field(field);

	//�������� ����� ����
		check_game(game, snake, L);
	}

	//�������� ���� �� ������
	destroy_field(field);

	stop
}