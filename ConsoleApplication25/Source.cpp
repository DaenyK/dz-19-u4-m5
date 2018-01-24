#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <stdint.h>
#include <time.h>

using namespace std;

int q;

int main()

{
	setlocale(LC_ALL, "Russian");
start:
	int nz;

	do
	{
		cout << "Введите номер задания: ";
		cin >> nz;
		switch (nz)
		{
		case 1:
		{
			cout << "Дано целое число в двоичной системе счисления, т.е.последовательность" << endl
				<< "цифр  0 и 1. Составить программу перевода этого числа в восьмеричную" << endl
				<< "систему счисления.\n\n";
			cout << "число будет сгенерировано рандомно:\n";
			int a = rand() % 99;
			int A = a;
			int ch, ost;
			int mas[15] = { 0 };
			int count = 0;

			do
			{
				ch = a / 2;
				ost = a - ch * 2;
				//cout << ost << " ";
				a = ch;
				count++;
				mas[count] = ost;

			} while (ch >= 1);

			for (int i = count; i > 0; i--)
			{
				cout << mas[i] << " ";
			}
			cout << endl << endl;


			cout << "это же число в десятичной системе счисления:\n";
			cout << A << endl;
			int CH, OST, COUNT = 0, MAS[10] = { 0 };
			do
			{
				CH = A / 8;
				OST = A % 8;
				A = CH;

				MAS[COUNT] = OST;
				COUNT++;

				if (CH < 8)
				{
					MAS[COUNT] = CH;
					COUNT++;
					break;
				}

			} while (CH >= 1);

			cout << endl;
			cout << "это же число в восьмеричной системе счисления:\n";
			for (int i = COUNT - 1; i >= 0; i--)
				cout << MAS[i];

			cout << endl << endl;
		}break;

		case 2:
		{
			cout << "Ввести два массива действительных чисел, состоящих из 7 и  9 элементов." << endl
				<< "Сформировать третий массив из упорядоченных по убыванию значений обоих массивов.\n";
			int a[9] = { 0 };
			int b[7] = { 0 };
			int count = 0, q;
			int c[16] = { 0 };

			cout << "первый массив:\n";
			for (int i = 0; i < 9; i++)
			{
				a[i] = 1 + rand() % 100;
				cout << a[i] << "  ";
				c[count] = a[i];
				count++;
			}

			cout << "\n\nвторой массив:\n";
			for (int i = 0; i < 7; i++)
			{
				b[i] = 1 + rand() % 100;
				cout << b[i] << "  ";
				c[count] = b[i];
				count++;
			}

			cout << "\n\nСформировать третий массив из упорядоченных по убыванию значений обоих массивов\n\n";

			cout << "третий массив до сортировки:\n";
			for (int i = 0; i < 16; i++)
				cout << c[i] << "  ";
			cout << endl;

			for (int i = 0; i < 16; i++)
			{
				for (int j = 0; j < 15; j++)
				{
					if (c[j] < c[j + 1])
					{
						q = c[j];
						c[j] = c[j + 1];
						c[j + 1] = q;
					}
				}
			}


			cout << "\n\nтретий массив после сортировки:\n";
			for (int i = 0; i < 16; i++)
				cout << c[i] << "  ";

			cout << endl << endl;
		}break;

		case 3:
		{
			cout << "Ввести массив, в котором только два одинаковых элемента." << endl
				<< "Определить их местоположение.\n";
			int count;

			do {
				int mas[10] = { 0 };
				count = 0;
				for (int i = 0; i < 10; i++)
				{
					mas[i] = rand() % 20;
					cout << "mas[" << i << "] = " << mas[i] << endl;
				}

				cout << endl;

				for (int i = 0; i < 10; i++)
				{
					for (int j = i + 1; j < 10; j++)
					{
						if (mas[i] == mas[j])
						{
							cout << "индексы повторяющихся элементов: " << i << " и " << j << endl;
							count++;
						}
					}
				}
				if (count > 1)
				{
					int a;

					cout << "\nбудет сформирован новый массив,\nтак как в этом больше двух повторяющихся элементов";
					cout << "\nok?1/0 "; cin >> a;
					switch (a)
					{
					case 1:
						system("cls"); break;
					case 0:
					{
						system("cls");
						goto start;
					}break;

					}
				}
			} while (count > 1);
		}break;

		case 4:
		{
			cout << "Задан целочисленный массив. Определить, образуют ли значения его" << endl
				<< "элементов геометрическую прогрессию." << endl
				<< "Если «да» – вывести знаменатель прогрессии," << endl
				<< "если «нет» – ответ «не образуют». \n\n";
			int mas[6] = { 0 };

			cout << "введите 6 чисел для того, чтобы узнать является ли эта последовательность \nгеометрической последовательностью\n";
			cout << "лучше не вводите ноль\n";
			//не помимаю почему вылетает через раз, если вводить 0 за место любого элемента массива

			for (int i = 0; i < 6; i++)
			{
				cin >> mas[i];
			}

			int q = mas[1] / mas[0];

			//if (q>1)
			//cout<<"возрастающая"<<endl;

			int count = 0;
			if (mas[0] != 0)
			{
				for (int i = 0; i < 6; i++)
				{
					if
						(mas[i] / mas[i - 1] == q)
					{
						count++;
					}

				}
			}

			if (count == 5)
				cout << "это геометрическая прогрессия и ее знаменатель равен: " << q << endl;
			else
				cout << "массив не образует геометрическую прогрессию\n";
		}break;

		case 5:
		{
			cout << "Отсортировать по убыванию элементов последнего столбца" << endl
				<< "целочисленный двухмерный массив 5x4\n\n";
			int a[5][4] = { { 0 },{0} };
			int b[5] = { 0 }, w;

			cout << "до сортировки:\n";
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					a[i][j] = rand() % 50;
					cout << a[i][j] << "\t";
					if (j == 3)
						b[i] = a[i][j];
				}
				cout << endl;
			}

			cout << endl << endl;


			for (int i = 0; i < 5; i++)			//сама сортировка
			{
				for (int j = 0; j < 4; j++)
				{
					if (b[j] < b[j + 1])
					{
						w = b[j];
						b[j] = b[j + 1];
						b[j + 1] = w;
					}
				}
			}

			cout << "после сортировки:\n";
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (j == 3)
					{
						a[i][j] = b[i];
					}
					cout << a[i][j] << "\t";
				}
				cout << endl;
			}

		}break;

		case 6:
		{
			cout << "В матрице А(3 - строки, 4 - столбца) поменять местами наименьшие" << endl
				<< "элементы в первой и третей строке.\n\n";
			int a[3][4] = { { 0 },{ 0 } };
			int min1 = 50, mn1, min3 = 50, mn3;
			int w;

			cout << "до сортировки:\n";
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					a[i][j] = rand() % 50;
					cout << a[i][j] << "\t";
					if (i == 0)
					{
						if (a[i][j] < min1)
						{
							min1 = a[i][j];
							mn1 = j;
						}

					}
					if (i == 2)
					{
						if (a[i][j] < min3)
						{
							min3 = a[i][j];
							mn3 = j;
						}

					}
				}
				cout << endl;
			}

			cout << endl << endl;

			w = a[0][mn1];
			a[0][mn1] = a[2][mn3];
			a[2][mn3] = w;

			cout << "минимальный элемент в 1-ой строке: " << min1 << endl;
			cout << "минимальный элемент в 3-ой строке: " << min3 << endl << endl;


			cout << "после сортировки:\n";
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					cout << a[i][j] << "\t";
				}
				cout << endl;

			}

			cout << endl << endl;

		}break;

		case 7:
		{
			cout << "Дан двухмерный массив 5 x 6.Определить среднее арифметическое" << endl
				<< "каждого столбца, определить максимум и минимум каждой строки.\n\n";
			int a[5][6] = { { 0 },{ 0 } };
			float sum = 0;
			int max, min;


			for (int i = 0; i < 5; i++)
			{
				max = 0, min = 50;
				for (int j = 0; j < 6; j++)
				{
					a[i][j] = rand() % 50;
					cout << a[i][j] << "\t";
					if (a[i][j] < min)
						min = a[i][j];
					if (a[i][j] > max)
						max = a[i][j];
				}
				cout << "макс и мин в этой строке: " << max << " " << min << endl;
			}

			cout << endl << endl;

			for (int j = 0; j < 6; j++)
			{
				sum = 0;
				for (int i = 0; i < 5; i++)
				{
					sum += a[i][j];
				}
				cout << "среднее арифметическое " << j + 1 << " столбца: " << sum / 5 << endl;
			}
			cout << endl;


		}break;

		case 8:
		{
			cout << "Дан двухмерный массив nxm элементов, найти количество" << endl
				<< "четных и нечетных чисел в массиве.\n\n";
			int a[5][5] = { { 0 },{ 0 } };
			int chet = 0, nechet = 0;

			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					a[i][j] = rand() % 50;
					cout << a[i][j] << "\t";

					if (a[i][j] % 2 == 0)
						chet++;
					if (a[i][j] % 2 == 1)
						nechet++;
				}
				cout << endl;
			}

			cout << endl << endl;

			cout << "кол-во четных элементов: " << chet << endl;
			cout << "кол-во нечетных элементов: " << nechet << endl << endl;
		}break;

		case 9:
		{
			cout << "Дан двухмерный массив nxm элементов.Определить, сколько" << endl
				<< "раз встречается число 7 среди элементов массива.\n\n";
			int a[5][5] = { { 0 },{ 0 } };
			int countSeven = 0;

			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					a[i][j] = rand() % 20;
					cout << a[i][j] << "\t";

					if (a[i][j] == 7)
						countSeven++;
				}
				cout << endl;
			}

			cout << endl << endl;

			cout << "кол-во элементов, равных числу 7: " << countSeven << endl;
		}break;

		case 10:
		{
			cout << "Дан массив из n x m элементов.\nНайти индексы первого наименьшего  элемента массива\n\n";

			int a[5][5] = { { 0 },{ 0 } };
			int min = 50, I, J;

			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					a[i][j] = rand() % 50;
					cout << a[i][j] << "\t";
					if (a[i][j] < min)
					{
						min = a[i][j];
						I = i;
						J = j;
					}
				}
				cout << endl;
			}

			cout << endl << endl;

			cout << "минимальный элемент массива: " << min << " его инденксы: [" << I << "] [" << J << "]\n";
		}break;

		}


		cout << "Хотите продолжить 1/0?";
		cin >> q;


		switch (q)
		{
		case 1:
			system("cls");
			goto start;
			break;
		default:
		{
			cout << "ошибка" << endl;
		}
		}
	} while (nz > 0);

}