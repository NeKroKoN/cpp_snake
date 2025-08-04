#include "field.h"

void init_field(Field& field, const char& field_symbol, const char& border_symbol)
{
	for (size_t row = 0; row < field.rows; row++)
	{
		field.field[row] = new char[field.columns];
		for (size_t col = 0; col < field.columns; col++)
		{
			if (row == 0 || row == field.rows - 1 || col == 0 || col == field.columns - 1)
			{
				field.field[row][col] = border_symbol;
			}
			else
			{
				field.field[row][col] = field_symbol;
			}
		}
	}
}

void clear_field(Field& field, const char& field_symbol)
{
	for (size_t row = 1; row < field.rows - 1; row++)
	{
		for (size_t col = 1; col < field.columns - 1; col++)
		{
			field.field[row][col] = field_symbol;
		}
	}
}

void print_field(Field& field)
{
//—брос пол€
	setCursorPosition(0, 0);

	std::cout << "\n\n";
	for (size_t row = 0; row < field.rows; row++)
	{
		std::cout << "	";
		for (size_t col = 0; col < field.columns; col++)
		{
			std::cout << " " << field.field[row][col];
		} std::cout << std::endl;
	}
}

void destroy_field(Field& field)
{
	for (size_t i = 0; i < field.rows; i++)
	{
		delete[] field.field[i];
	}
	delete[] field.field;
}