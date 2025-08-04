#pragma once

const int L = 10;	//Максимальный размер массива змейки

const char tail_symbol = '#';	//Символ для хвоста змейки
const char head_symbol = '@';	//Символ для головы змейки

const char field_symbol = ' ';	//Символ для заполнения поля игры
const char border_symbol = '*';	//Символ для границы поля игры

const enum KEYS { UP = 119, DOWN = 115, LEFT = 97, RIGHT = 100, ESCAPE = 27 }; //Константы для обработки клавиатурного ввода

const char food_symbol = '+';	//Символ еды