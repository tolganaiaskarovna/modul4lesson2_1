#include <stdio.h>
#include <stdlib.h> // ��� ������������� ������� system()
#include <iostream>
#include <locale.h>
#include <time.h>

using namespace std;

#define sizeArr 20

//��������� ����������
//����������� ����������
void BubleSort()
{
	
	int arrNumber[sizeArr];
	srand(time(NULL));

	for (int i = 0; i <= sizeArr - 1; i++)
	{
		arrNumber[i] = 1 + rand() % 99;
	}

	cout << "�� ���������� " << endl;
	for (int i = 0; i <= sizeArr - 1; i++)
	{
		cout << "arr[" << i << "] = " << arrNumber[i] << endl;
	}

	for (int i = 0; i < sizeArr - 1; i++)
	{
		// ��� ���� ��������� ����� i-���
		for (int j = (sizeArr - 1); j > i; j--) 
		{
			if (arrNumber[j - 1] > arrNumber[j]) // ���� ������� ������� ������ �����������
			{
				int temp = arrNumber[j - 1]; // ������ �� �������
				arrNumber[j - 1] = arrNumber[j];
				arrNumber[j] = temp;
			}
		}
	}
	cout << "����� ���������� " << endl;
	for (int i = 0; i <= sizeArr - 1; i++)
	{
		cout << "arr[" << i << "] = " << arrNumber[i] << endl;
	}

}

//���������� �������
void selectionSort()
{
	int size = 20;

	int arrNumber[20];
	srand(time(NULL));

	for (int i = 0; i <= size - 1; i++)
	{
		arrNumber[i] = 1 + rand() % 99;
	}

	cout << "�� ���������� " << endl;
	for (int i = 0; i <= size - 1; i++)
	{
		cout << "arr[" << i << "] = " << arrNumber[i] << endl;
	}

	//���������� ���� ��� ���� ��������� ����� ����������
	int min, temp; // ��� ������ ������������ �������� � ��� ������
	for (int i = 0; i < size - 1; i++)
	{
		min = i; // ���������� ������ �������� ��������
				 // ���� ����������� ������� ����� ��������� �� ����� i-���

		for (int j = i + 1; j < size; j++)  // ��� ��������� ��������� ����� i-���
		{
			if (arrNumber[j] < arrNumber[min]) // ���� ������� ������ ������������,
				min = j;       // ���������� ��� ������ � min
		}
		temp = arrNumber[i];      // ������ ������� i-�� � ����������� ��������
		arrNumber[i] = arrNumber[min];
		arrNumber[min] = temp;

	}

	cout << "����� ���������� " << endl;
	for (int i = 0; i <= size - 1; i++)
	{
		cout << "arr[" << i << "] = " << arrNumber[i] << endl;
	}
}

//���������� ���������
void inclusionSort()
{
	int size = 20;

	int arrNumber[20];
	srand(time(NULL));

	for (int i = 0; i <= size - 1; i++)
	{
		arrNumber[i] = 1 + rand() % 99;
	}

	cout << "�� ���������� " << endl;
	for (int i = 0; i <= size - 1; i++)
	{
		cout << "arr[" << i << "] = " << arrNumber[i] << endl;
	}

	// ��� ���� ��������� ����� ����������
	for (int i = 1; i < size; i++)
	{
		int value = arrNumber[i]; // ���������� �������� ��������
		int index = i;     // � ��� ������

		while ((index > 0) 
			&& (arrNumber[index - 1] > value))
		{
			// ������� ������ �������� � ����� ������� ���� ��� ������ index
			arrNumber[index] = 
				arrNumber[index - 1];
			index--;    // ������� �������� � ������ �������
		}
		arrNumber[index] = value; // ��������������� ������� �������� �� �������������� �����
	}
	cout << "����� ���������� " << endl;
	for (int i = 0; i <= size - 1; i++)
	{
		cout << "arr[" << i << "] = " << arrNumber[i] << endl;
	}

}


//��������� ������ 
//��������
void BinarySearch()
{
	int count = 0;
	int k[20];
	int r[20];
	int key, i;

	system("cls");

	// ������������� �������� ����� �������������� ����������
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

	// ���� �������
	for (i = 0; i < 20; i++)
	{
		cout << "k[" << i << "]=" << k[i] << endl;
	}

	cout << "������� key: ";
	cin >> key;

	int left = 0; // ������ ����� � ������ ������� ������
	int right = 19;

	int search = -1; // ��������� ������ �������� ����� -1 (������� �� ������)

	while (left <= right) // ���� ����� ������� �� "����������" ������
	{
		count++;
		int mid = (left + right) / 2; // ���� �������� �������

		// ���� �������� ���� ����� ��������
		// �� ����� ��������� �������, ������� �� �����
		if (key == k[mid])
		{
			search = mid;
			break;
		}


		if (key < k[mid])     // ���� ������� �������� ���� ������ ��������� ��������
			right = mid - 1;  // ������� ������ �������, ��������� ����� � ����� �����
		else
			left = mid + 1;   // ������� ����� �������, ��������� ����� � ������ �����
	}

	if (search == -1)     // ���� ������ �������� ��-�������� -1, ������� �� ������
		cout << "������� �� ������!" << endl;
	else          // ����� ������� �������, ��� ���� � ��������
		cout << "k[" << search << "]=" << k[search] << " (�� " << count << " ��������)" << endl;

	cout << endl;
}

//��������
void LineSearch()
{
	int k[20];
	int key, i;

	system("cls");

	// ������������� �������� ����� �������������� ����������
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

	// ���� �������
	for (i = 0; i < 20; i++)
	{
		cout << "k[" << i << "]=" << k[i] << endl;
	}

	cout << "������� key: ";
	cin >> key;

	for (i = 0; i < 19; i++) // ������������� ��� �������� � �����
	{
		if (k[i] == key)      // ���� ������� ������� �� ��������� key,
		{
			cout << i << endl;     // ���������� ��� ������
			break;
		}

	}
	cout << "������� �� ������ �� " << i << " �����" << endl;
}

void testFunc(); //�������� �������

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
	�������� ������� ��� �� ����������������������� ��� ���������� �������
	����� ��������� ���� �� ��� �����������  ����� ���������
	� ������ ���������������� ��������, ����������� ��������.
	*/
	int myArr[10] = { 1,5,8,9,5,2,1 };
	cout << endl;
	cout << "Size of myArr[10] = " << sizeof(myArr) / sizeof(int) << endl;

	/*
	���� ���������������� �������� ������, ��� ��������� �������, 
	���������� �������� ������������� ����������������� ������
	*/
	int myArr2[10] = { 1,5,8,9,5,2 };
	int myArr3[100] = { 0 };
	cout << endl;
	cout << "Size of myArr[10] = " << sizeof(myArr3) / sizeof(int) << endl;
	
	/*
	����� �������� ���, ��� ������� �� ����������������� ������ �������������!
	����������� ������ ���������������� ���� �� 1-� �������,
	��������� ���������������� ������������� 0
	*/


	/*
	��������� ���������� ������� 
	int myArr4[5] = { 32, 27, 64, 18, 95, 14 };
	������ �� �������������� ������, ��������� ������� 6 ���������������� �������� � ������ 5 ��������� �������.
	*/

	/*
	���� ������ ������������������� � ��� ���������� �� ������� ���������������� ��������
	�� ����� ��������� � ������� ����� ����� ����� ��������� � ������ �������������
	*/
	int myArr6[] = { 1,5,6,8,9 };
}

void testFunc()
{
	cout << "TEST" << endl;
}


