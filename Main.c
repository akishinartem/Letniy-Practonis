#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 3			// Кол-во строк
#define M 4			// Кол-во столбцов

// Инициализация переменных
int menu;
FILE *F1;
FILE *F2;
int mas[N][M];		// Массив матрицы
int indi[M];		// Массив индексов i
int indj[M];		// Массив индексов j
int min[M];			// Массив локальных минимумов
int k = 0;			// Счетчик локальных минимумов
int count = 0;		// Счетчик матриц

int main() {

	// Проверка на доступ к файлам
	if ((F1 = fopen("F1.txt", "w")) == NULL) {
		printf("Error! File doesn'r exist.");
		return 1;
	}
	if ((F2 = fopen("F2.txt", "w")) == NULL) {
		printf("Error! File doesn'r exist.");
		return 1;
	}

	// Замкнутый цикл с постусловием
	do
	{
		// Пользовательское меню
		printf("Choose action:\n");
		printf("[1] Enter matrix.\n");
		printf("[2] Exit.\n");
		scanf("%d", &menu);
		switch (menu) {
		case 1:

			// Ввод элементов матрицы
			printf("Enter matrix elements:\n");
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					printf("a%d%d = ", i, j);
					scanf("%d", &mas[i][j]);
				}
			}
			count++;

			// Запись матриц(-ы) в файл F1
			fprintf(F1, "Номер матрицы: %d\nМатрица:\n", count);
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					fprintf(F1, "%d", mas[i][j]);
				}
			}
			fprintf(F1, "\n\n");

			// Поиск локального минимума
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if ((mas[i][j] < mas[i + 1][j]) && (mas[i][j] < mas[i][j + 1]) && (mas[i][j] < mas[i - 1][j]) && (mas[i][j] < mas[i][j - 1])) {
						int ry1 = mas[i][j];
						_asm {
							mov esi, k
							mov eax, ry1
							mov ebx, i
							mov ecx, j
							inc esi
							mov indi[esi], ebx
							mov indj[esi], ecx
							xor ebx, ebx
							xor ecx, ecx
							mov k, esi
							mov min[esi], eax
							xor eax, eax
							xor esi, esi
						}
						/*min[k] = mas[i][j];
						ind[0][k] = i;
						ind[1][k] = j;
						k++;*/
					}
				}
			}
			/*
			_asm {
				mov ecx, N
				xor esi, esi
				mov ebx, k
			m1 :
				push ecx
				mov ecx, M
				xor edi, edi
			m2 :
				mov eax, mas[edi]
				cmp eax, mas[edi + 1]
				jl itog1
				mov eax, mas[edi]
				cmp eax, mas[edi - 1]
				jl itog1

			itog1 :
				mov min[ebx], eax
				mov ind[ebx], esi
				inc ebx

				inc edi
				loop m2

				mov eax, mas[esi]
				cmp eax, mas[esi + 1]
				jl itog2
				mov eax, mas[esi]
				cmp eax, mas[esi - 1]
				jl itog2

			itog2 :
				mov min[ebx], eax
				mov ind[ebx], edi
				inc ebx

				inc esi
				pop ecx
				loop m1
				mov k, ebx
			}
			printf("nomer matr %d\n", count);
			printf("kolvo min: %d\nznach: ", k);
			for (int i = 0; i < k; i++) {
				printf("[%d] ", min[i]);
			}
			printf("\nind: ");
			for (int i = 0; i < k; i++) {
				printf("[%d][%d] ", ind[0][i], ind[1][i]);
			}*/
			// Запись сведений матриц(-ы) в файл F2
			fprintf(F2, "№ матрицы: %d\n", count);
			fprintf(F2, "Кол-во минимумов: %d\nЗначения: ", k);
			for (int i = 0; i < k; i++) {
				fprintf(F2, "[%d] ", min[i]);
			}
			fprintf(F2, "\nИндексы: ");
			for (int i = 0; i < k; i++) {
				fprintf(F2, "[%d][%d] ", indi[i], indj[i]);
			}
			fprintf(F2, "\n\n");
			break;
		case 2:

			// Условие для выхода из цикла
			menu = 2;
			break;
		}
		system("pause");
		system("cls");
	} while (menu != 2);
	return 0;
}