#pragma once
#include <iostream>

#include "const.h"
#include "winconsole.h"

struct Field
{
	int columns, rows;	//Длины игрового поля по горизонтали и вертикали
	char** field; //Массив игрового поля
};

void init_field(Field& field, const char& field_symbol, const char& border_symbol);	//Инициализация поля игры, включая динамический массив
void clear_field(Field& field, const char& field_symbol);
void print_field(Field& field);
void destroy_field(Field& field);