#include <iostream>
#include <random>


int** localeMatrix(int& len)
{
	int** matrix = new int* [len];
	for (int i = 0; i < len; ++i)
		matrix[i] = new int[len];
	return matrix;
}

void DeletMatrix(int** matrix, int& len)
{
	for (int i = 0; i < len; ++i)
		delete[] matrix[i];
	delete[] matrix;
}


void FillMatrix(int** matrix, int& len)
{
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			std::cout << "Введите [" << i + 1 << "][" << j + 1 << "] элемент матрицы: ";
			std::cin >> matrix[i][j];
		}

	}
}

void FillMatrixRandom(int** matrix, int& len, int a, int b)
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<int> distrib(a, b);

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			matrix[i][j] = distrib(gen);
		}
	}
}

int** PrintMatrix(int** matrix, int& len)
{
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			std::cout << " " << matrix[i][j];
		}
		std::cout << "\n";
	}
	return matrix;

}

int findNullInCol(int** matrix, int& len)
{
	int col_with_zero = -1;
	for (int j = 0; j < len; j++) {
		if (matrix[0][j] == 0) {
			col_with_zero = j;
			return col_with_zero;
		}
	}
	return -1;
}


void SwapColInMat(int** matrix, int& len, int& col_with_zero)
{
	if (col_with_zero != -1 && col_with_zero != 0)
	{
		for (int i = 0; i < len; ++i)
		{
			int temp = matrix[i][0];
			matrix[i][0] = matrix[i][col_with_zero];
			matrix[i][col_with_zero] = temp;
		}
	}
}

int FindMaxInRightTriangle(int** matrix, int& len)
{
	if (len <= 1)
	{
		return 0;
	}

	bool found_first = false;
	int max_value = 0;

	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (!found_first)
			{
				max_value = matrix[i][j];
				found_first = true;
			}
			else if (matrix[i][j] > max_value)
			{
				max_value = matrix[i][j];
			}
		}
	}
	return max_value;
}


int main()
{
	int len;
	setlocale(LC_ALL, "Russian");
	std::cout << "Введите размерность квадратной матрицы: ";
	std::cin >> len;

	if (len <= 0)
	{
		std::cout << "Размер матрицы должен быть строго больше нуля!!!\n";
		return 0;
	}

	if (len == 1)
	{
		std::cout << "Выполнить задание при текущей размерности матрицы невозможно! Рекомендую размерность от 2 и более!\n";
		return 0;
	}

	int** matrix = localeMatrix(len);


	int choice;
	std::cout << "Как заполнить матрицу?\n";
	std::cout << "1 - Ввести вручную\n";
	std::cout << "2 - Сгенерировать случайно\n";
	std::cout << "Ваш выбор (1 или 2): ";
	std::cin >> choice;

	bool input_successful = false;
	if (choice == 1)
	{
		FillMatrix(matrix, len);
	}
	else if (choice == 2)
	{
		int a, b;
		std::cout << "Введите нижнюю границу (a) для случайных чисел: ";
		std::cin >> a;
		std::cout << "Введите верхнюю границу (b) для случайных чисел: ";
		std::cin >> b;

		if (a > b) {
			std::cout << "Нижняя граница больше верхней!!!\n";
			DeletMatrix(matrix, len);
			return 1;
		}

		FillMatrixRandom(matrix, len, a, b);
		input_successful = true;
		std::cout << "Матрица заполнена случайными числами от " << a << " до " << b << ".\n";
	}
	else
	{
		std::cout << "Неверный выбор!!\n";
		DeletMatrix(matrix, len);
		return 1;
	}


	PrintMatrix(matrix, len);

	int zero_col = findNullInCol(matrix, len);

	if (zero_col == -1)
	{
		std::cout << "Столбца с нулём в первой строке нет!\n";
	}
	else
	{
		SwapColInMat(matrix, len, zero_col);
		std::cout << "\nНовая матрица с перенесённым столбцом:\n\n";
		PrintMatrix(matrix, len);
	}

	std::cout << "\nНайдём максимальный элемент в верхнем правом треугольнике\n";
	int max = FindMaxInRightTriangle(matrix, len);
	std::cout << "\nМаксимальный элемент - " << max << "\n";

	DeletMatrix(matrix, len);
	return 0;
}
