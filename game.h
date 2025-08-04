#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>

#include "field.h"
#include "snake.h"
#include "food.h"

struct Game
{
	int timeout; //������� �������� ����� ������ ����
	bool game_on; //������� ����������� ����
	bool do_exit;	//������������� �� ����� �� ����
};

void hello_game(Game& game, Field& field, Food& food);
void init_game(Game& game, unsigned int& getInput);	//������������� ���������� ����
void set_snake(Game& game, Field& field, Snake& snake, const char& head_symbol, const char& tail_symbol);	//��������� ������ �� ���� ����
void check_eating(Food& food, Snake& snake, const int& L);	//��������, ��� ������ ����� ���
//void set_food();	//��������� ��� �� ���� ����
void check_game(Game& game, Snake& snake, const int& L);	//�������� ����� ����
void check_snake(Game& game, Field& field, Snake& snake);	//�������� ������������ ������ � ��������
//void clear_snake();	//������� ������� ������ � ������� ����
void handle_cmd(unsigned int& getInput, Game& game, Snake& snake, Field& field);	//��������� ����������������� �����