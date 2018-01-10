#include <stdio.h>
#include <stdlib.h> // для использования функций system()
#include <iostream>
#include <locale.h>
#include <time.h>

using namespace std;

#define sizeArr 20

//Алгоритмы сортировки
//пузырьковая сортировка
void BubleSort()
{
	
	int arrNumber[sizeArr];
	srand(time(NULL));

	for (int i = 0; i <= sizeArr - 1; i++)
	{
		arrNumber[i] = 1 + rand() % 99;
	}

	cout << "До сортировки " << endl;
	for (int i = 0; i <= sizeArr - 1; i++)
	{
		cout << "arr[" << i << "] = " << arrNumber[i] << endl;
	}

	for (int i = 0; i < sizeArr - 1; i++)
	{
		// для всех элементов после i-ого
		for (int j = (sizeArr - 1); j > i; j--) 
		{
			if (arrNumber[j - 1] > arrNumber[j]) // если текущий элемент меньше предыдущего
			{
				int temp = arrNumber[j - 1]; // меняем их местами
				arrNumber[j - 1] = arrNumber[j];
				arrNumber[j] = temp;
			}
		}
	}
	cout << "После сортировки " << endl;
	for (int i = 0; i <= sizeArr - 1; i++)
	{
		cout << "arr[" << i << "] = " << arrNumber[i] << endl;
	}

}

//сортировка выбором
void selectionSort()
{
	int size = 20;

	int arrNumber[20];
	srand(time(NULL));

	for (int i = 0; i <= size - 1; i++)
	{
		arrNumber[i] = 1 + rand() % 99;
	}

	cout << "До сортировки " << endl;
	for (int i = 0; i <= size - 1; i++)
	{
		cout << "arr[" << i << "] = " << arrNumber[i] << endl;
	}

	//Организуем цикл для всех элементов кроме последнего
	int min, temp; // для поиска минимального элемента и для обмена
	for (int i = 0; i < size - 1; i++)
	{
		min = i; // запоминаем индекс текущего элемента
				 // ищем минимальный элемент чтобы поместить на место i-ого

		for (int j = i + 1; j < size; j++)  // для остальных элементов после i-ого
		{
			if (arrNumber[j] < arrNumber[min]) // если элемент меньше минимального,
				min = j;       // запоминаем его индекс в min
		}
		temp = arrNumber[i];      // меняем местами i-ый и минимальный элементы
		arrNumber[i] = arrNumber[min];
		arrNumber[min] = temp;

	}

	cout << "После сортировки " << endl;
	for (int i = 0; i <= size - 1; i++)
	{
		cout << "arr[" << i << "] = " << arrNumber[i] << endl;
	}
}

//сортировка вставками
void inclusionSort()
{
	int size = 20;

	int arrNumber[20];
	srand(time(NULL));

	for (int i = 0; i <= size - 1; i++)
	{
		arrNumber[i] = 1 + rand() % 99;
	}

	cout << "До сортировки " << endl;
	for (int i = 0; i <= size - 1; i++)
	{
		cout << "arr[" << i << "] = " << arrNumber[i] << endl;
	}

	// Для всех элементов кроме начального
	for (int i = 1; i < size; i++)
	{
		int value = arrNumber[i]; // запоминаем значение элемента
		int index = i;     // и его индекс

		while ((index > 0) 
			&& (arrNumber[index - 1] > value))
		{
			// смещаем другие элементы к концу массива пока они меньше index
			arrNumber[index] = 
				arrNumber[index - 1];
			index--;    // смещаем просмотр к началу массива
		}
		arrNumber[index] = value; // рассматриваемый элемент помещаем на освободившееся место
	}
	cout << "После сортировки " << endl;
	for (int i = 0; i <= size - 1; i++)
	{
		cout << "arr[" << i << "] = " << arrNumber[i] << endl;
	}

}


//Алгоритмы поиска 
//бинарный
void BinarySearch()
{
	int count = 0;
	int k[20];
	int r[20];
	int key, i;

	system("cls");

	// Инициализация ключевых полей упорядоченными значениями
	k[0] = 8;  k[1] = 14;
	k[2] = 26;  k[3] = 28;
	k[4] = 38;  k[5] = 47;
	k[6] = 56;  k[7] = 60;
	k[8] = 64;  k[9] = 69;
	k[10] = 70; k[11] = 78;
	k[12] = 80; k[13] = 82;
	k[14] = 84; k[15] = 87;
	k[16] = 90; k[17] = 92;
	k[18] = 98; k[19] = 108;

	// Ввод записей
	for (i = 0; i < 20; i++)
	{
		cout << "k[" << i << "]=" << k[i] << endl;
	}

	cout << "Введите key: ";
	cin >> key;

	int left = 0; // задаем левую и правую границы поиска
	int right = 19;

	int search = -1; // найденный индекс элемента равен -1 (элемент не найден)

	while (left <= right) // пока левая граница не "перескочит" правую
	{
		count++;
		int mid = (left + right) / 2; // ищем середину отрезка

		// если ключевое поле равно искомому
		// мы нашли требуемый элемент, выходим из цикла
		if (key == k[mid])
		{
			search = mid;
			break;
		}


		if (key < k[mid])     // если искомое ключевое поле меньше найденной середины
			right = mid - 1;  // смещаем правую границу, продолжим поиск в левой части
		else
			left = mid + 1;   // смещаем левую границу, продолжим поиск в правой части
	}

	if (search == -1)     // если индекс элемента по-прежнему -1, элемент не найден
		cout << "Элемент не найден!" << endl;
	else          // иначе выводим элемент, его ключ и значение
		cout << "k[" << search << "]=" << k[search] << " (за " << count << " проходов)" << endl;

	cout << endl;
}

//линейный
void LineSearch()
{
	int k[20];
	int key, i;

	system("cls");

	// Инициализация ключевых полей упорядоченными значениями
	k[0] = 8;  k[1] = 14;
	k[2] = 26;  k[3] = 28;
	k[4] = 38;  k[5] = 47;
	k[6] = 56;  k[7] = 60;
	k[8] = 64;  k[9] = 69;
	k[10] = 70; k[11] = 78;
	k[12] = 80; k[13] = 82;
	k[14] = 84; k[15] = 87;
	k[16] = 90; k[17] = 92;
	k[18] = 98; k[19] = 108;

	// Ввод записей
	for (i = 0; i < 20; i++)
	{
		cout << "k[" << i << "]=" << k[i] << endl;
	}

	cout << "Введите key: ";
	cin >> key;

	for (i = 0; i < 19; i++) // просматриваем все элементы в цикле
	{
		if (k[i] == key)      // если находим элемент со значением key,
		{
			cout << i << endl;     // возвращаем его индекс
			break;
		}

	}
	cout << "элемент не найден за " << i << " шагов" << endl;
}

void testFunc(); //прототип функции

void main()
{

	inclusionSort();



	testFunc();
	
	setlocale(LC_ALL, "Rus");
	int a = -5, b = 10;
	srand(time(NULL));
	float x = (float)rand()*(b - a) / RAND_MAX + a;
	cout << x <<endl;
	//Lesson 1
	/*
	Элементы массива так же могутинициализироваться при объявлении массива
	путем помещения всед за его объявлением  знака равенства
	и списка инициализирующих значений, разделенных запятыми.
	*/
	int myArr[10] = { 1,5,8,9,5,2,1 };
	cout << endl;
	cout << "Size of myArr[10] = " << sizeof(myArr) / sizeof(int) << endl;

	/*
	Если инициализирующих значений меньше, чем элементов массива, 
	остающиеся элементы автоматически инициализируються нулями
	*/
	int myArr2[10] = { 1,5,8,9,5,2 };
	int myArr3[100] = { 0 };
	cout << endl;
	cout << "Size of myArr[10] = " << sizeof(myArr3) / sizeof(int) << endl;
	
	/*
	Важно понимать что, что массивы не инициализируються нулями автоматически!
	Программист должен инициализировать хотя бы 1-й элемент,
	остальные инициализируются автоматически 0
	*/


	/*
	Следующее объявление массива 
	int myArr4[5] = { 32, 27, 64, 18, 95, 14 };
	вызвло бы синтаксическую ошибку, поскольку имеется 6 инициализирующих значений и только 5 элементов массива.
	*/

	/*
	Если размер массиваневключается в его объявление со списком инициализирующих значений
	то число элементов в массиве будет равно числу элементов в списке инициализации
	*/
	int myArr6[] = { 1,5,6,8,9 };
}

void testFunc()
{
	cout << "TEST" << endl;
}


