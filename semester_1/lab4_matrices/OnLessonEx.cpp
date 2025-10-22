#include <iostream>
#include <random>

void Excepts()
{
	if (n < 0 && m < 0) throw "InvalidValueInMatrix\n";

}


void Create_Matrix(int**& matrix, int m, int n)
{
	matrix = new int* [m];
	for (int i = 0; i < m; i++) {
	matrix[i] = new int[n];
	}
}

void DeletMatrix(int** matrix, int n)
{
    for (int i = 0; i < n; ++i)
        delete[] matrix[i];
    delete[] matrix;
}

void FillMatrix(int** matrix, int n, int m)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << "Введите [" << i + 1 << "][" << j + 1 << "] элемент матрицы: ";
			if (!(std::cin >> matrix[i][j]))
			{
				throw "InputErrorCodeNull\n";
			}
		}
	}
}

void FillMatrixRandom(int** matrix, int n, int m, int a, int b)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(a, b);
	if (a > b) throw "IncorrectValuesInRandom\n";

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = distrib(gen);
		}
	}

}

bool CompareByB(int x, int y)
{
	return x < y;
}

bool CompareByS(int x, int y)
{
	return x > y;
}

void SortBubble(int** matrix, int n, int m, bool(*compare)(int, int)) 
{
	for (int row = 0; row < n; ++row)
	{
		for (int i = 0; i < m - 1; ++i)
		{
			for (int j = 0; j < m - 1 - i; ++j)
			{
				if (compare(matrix[row][j], matrix[row][j + 1]))
				{
					std::swap(matrix[row][j], matrix[row][j + 1]);
				}
			}
		}
	}
}


void SortShaker(int** matrix, int n, int m)
{
	
}


void SortMerge(int** matrix, int n, int m)
{

}




void PrintMatrix(int** matrix, int n, int m)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << " " << matrix[i][j];
		}
		std::cout << "\n";
	}
}



int main()
{
	setlocale(LC_ALL, "Russian");
		int a, b;
		int n, m;
	try {
		std::cout << "Сейчас Вы создадите матрицу n x m" << std::endl;
		std::cout << "Введите число n: ";
		std::cin >> n;

		std::cout << "Введите число m: ";
		std::cin >> m;

		int** matrix{};
		Create_Matrix(matrix, n, m);

		int choice_2;
		std::cout << "Выберите, как заполнить матрицу" << std::endl;
		std::cout << "1 - Заполнить матрицу вручную" << std::endl;
		std::cout << "2 - заполнить сылучайными числами от a до b. Где a < b." << std::endl;
		std::cout << "Ваш выбор - ";
		std::cin >> choice_2;

		if (choice_2 == 1)
		{
			FillMatrix(matrix, n, m);
		}
		else if (choice_2 == 2)
		{
			std::cout << "Сейчас Вы заполните матрицу рандомными числами от a до b (a < b)" << std::endl;
			std::cout << "Введите число a: ";
			std::cin >> a;
			std::cout << "Введите число b: ";
			std::cin >> b;

			FillMatrixRandom(matrix, n, m, a, b);
		}
		else
		{
			std::cout << "Некоректный выбор!!!";
			DeletMatrix(matrix, n);
			return 0;
		}





		int choice_1;
		std::cout << "Выберите вариант сортировки строк в матрице" << std::endl;
		std::cout << "1 - От большего к меньшему" << std::endl;
		std::cout << "2 - От меньшему к большему" << std::endl;
		std::cout << "Ваш выбор - ";
		std::cin >> choice_1;
		if (choice_1 == 1)
		{
			SortBubble(matrix, n, m, CompareByB);
			PrintMatrix(matrix, n, m);
			DeletMatrix(matrix, n);
			return 0;
		}
		else if (choice_1 == 2)
		{
			SortBubble(matrix, n, m, CompareByS);
			PrintMatrix(matrix, n, m);
			DeletMatrix(matrix, n);
			return 0;
		}
		else
		{
			std::cout << "Неверный выбор!!!";
			DeletMatrix(matrix, n);
			return 0;
		}


	}
	catch (const char* msg)
	{
		std::cout << msg;
	}

	return 0;
}


