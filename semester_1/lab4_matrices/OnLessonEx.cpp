#include <iostream>
#include <random>

void Create_Matrix(int**& matrix, int m, int n)
{
	if (n < 0 && m < 0) throw "InvalidValueInMatrix\n";

	else {
		matrix = new int* [m];
		for (int i = 0; i < m; i++)
		{
			matrix[i] = new int[n];
		}
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

void FillMatrixRandomAtoB(int** matrix, int n, int m, int a, int b)
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
	for (int row = 0; row < n; ++row)
	{
		int left = 0;
		int right = m - 1;
		while (left < right)
		{
			for (int i = left; i < right; ++i)
			{
				if (matrix[row][i] < matrix[row][i + 1])
					std::swap(matrix[row][i], matrix[row][i + 1]);
			}
			--right;
			for (int i = right; i > left; --i)
			{
				if (matrix[row][i] > matrix[row][i - 1])
					std::swap(matrix[row][i], matrix[row][i - 1]);
			}
			++left;
		}
	}
}


void Merge(int* arr, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int* L = new int[n1];
	int* R = new int[n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2)
	{
		if (L[i] >= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}

	delete[] L;
	delete[] R;
}

void MergeSort(int* arr, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		Merge(arr, left, mid, right);
	}
}

void SortMerge(int** matrix, int n, int m)
{
	for (int row = 0; row < n; ++row)
	{
		MergeSort(matrix[row], 0, m - 1);
	}
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
		if (n <= 0) throw "InvalidValueInMatrix\n";

		std::cout << "Введите число m: ";
		std::cin >> m;
		if (m <= 0) throw "InvalidValueInMatrix\n";

		int** matrix{};
		Create_Matrix(matrix, n, m);

		int choice_2;
		std::cout << "Выберите, как заполнить матрицу" << std::endl;
		std::cout << "1 - Заполнить матрицу вручную" << std::endl;
		std::cout << "2 - заполнить случайными числами от a до b. Где a < b." << std::endl;
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

			FillMatrixRandomAtoB(matrix, n, m, a, b);
		}
		else
		{
			std::cout << "Некорректный выбор!!!\n";
			DeletMatrix(matrix, n);
			return 0;
		}

		int sort_type, order;
		std::cout << "\nВыберите метод сортировки:\n";
		std::cout << "1 - Пузырьковая сортировка\n";
		std::cout << "2 - Шейкерная сортировка\n";
		std::cout << "3 - Сортировка слиянием\n";
		std::cout << "Ваш выбор: ";
		std::cin >> sort_type;

		std::cout << "\nВыберите порядок сортировки строк:\n";
		std::cout << "1 - От большего к меньшему\n";
		std::cout << "2 - От меньшего к большему\n";
		std::cout << "Ваш выбор: ";
		std::cin >> order;

		if (sort_type == 1)
		{
			if (order == 1)
				SortBubble(matrix, n, m, CompareByB);
			else if (order == 2)
				SortBubble(matrix, n, m, CompareByS);
			else
				throw "InvalidSortOrder\n";
		}
		else if (sort_type == 2)
		{
			if (order == 1)
			{
				SortShaker(matrix, n, m);
			}
			else if (order == 2)
			{
				SortShaker(matrix, n, m);
				for (int i = 0; i < n; ++i)
					for (int j = 0; j < m / 2; ++j)
						std::swap(matrix[i][j], matrix[i][m - 1 - j]);
			}
			else
				throw "InvalidSortOrder\n";
		}
		else if (sort_type == 3)
		{
			if (order == 1)
			{
				SortMerge(matrix, n, m);
			}
			else if (order == 2)
			{
				SortMerge(matrix, n, m);
				for (int i = 0; i < n; ++i)
					for (int j = 0; j < m / 2; ++j)
						std::swap(matrix[i][j], matrix[i][m - 1 - j]);
			}
			else
				throw "InvalidSortOrder\n";
		}
		else
		{
			std::cout << "Неверный выбор метода сортировки!\n";
			DeletMatrix(matrix, n);
			return 0;
		}

		PrintMatrix(matrix, n, m);
		DeletMatrix(matrix, n);
	}
	catch (const char* msg)
	{
		std::cout << "Ошибка: " << msg;
	}

	return 0;
}

