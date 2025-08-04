#pragma once
#include "const.h"
#include "field.h"

const enum DIRECTION { noDir = 0, D_Up = 1, D_Down = 2, D_Left = 3, D_Right = 4 };	//������������ ������������ ���������

struct Snake
{
	int size;	//������� ������ ������
	unsigned int x[L];	//������ ��������� ������ �� �����������(X)
	unsigned int y[L];	//������ ��������� ������ �� ���������(Y)
	DIRECTION direction;	//����������� �������� ������
	bool setStartPos;		//��� ��������� ��������� ������� ������ � ����������� �� �����������
};

void init_snake(Snake& snake, Field& field);
void move_snake(Snake& snake);