#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>

#include "field.h"
#include "snake.h"
#include "food.h"

struct Game
{
	int timeout; //Таймаут задержки между шагами игры
	bool game_on; //Признак продолжения игры
	bool do_exit;	//Переключатель на выход из игры
};

void hello_game(Game& game, Field& field, Food& food);
void init_game(Game& game, unsigned int& getInput);	//Инициализация параметров игры
void set_snake(Game& game, Field& field, Snake& snake, const char& head_symbol, const char& tail_symbol);	//Установка змейки на поле игры
void check_eating(Food& food, Snake& snake, const int& L);	//Проверка, что змейка съела еду
//void set_food();	//Установка еды на поле игры
void check_game(Game& game, Snake& snake, const int& L);	//Проверка конца игры
void check_snake(Game& game, Field& field, Snake& snake);	//Проверка столкновения змейки с границей
//void clear_snake();	//Очистка позиций змейки в игровом поле
void handle_cmd(unsigned int& getInput, Game& game, Snake& snake, Field& field);	//Обработка пользовательского ввода