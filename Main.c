#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 3			// ���-�� �����
#define M 4			// ���-�� ��������

// ������������� ����������
int menu;
FILE *F1;
FILE *F2;
int mas[N][M];		// ������ �������
int ind[N][M];		// ������ ��������
int min[M];			// ������ ��������� ���������
int k = 0;			// ������� ��������� ���������
int count = 0;		// ������� ������

int main() {

	// �������� �� ������ � ������
	if ((F1 = fopen("F1.txt", "w")) == NULL) {
		printf("Error! File doesn'r exist.");
		return 1;
	}
	if ((F2 = fopen("F2.txt", "w")) == NULL) {
		printf("Error! File doesn'r exist.");
		return 1;
	}

	// ��������� ���� � ������������
	do
	{
		// ���������������� ����
		printf("Choose action:\n");
		printf("[1] Enter matrix.\n");
		printf("[2] Exit.\n");
		scanf("%d", &menu);
		switch (menu) {
		case 1:

			// ���� ��������� �������
			printf("Enter matrix elements:\n");
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					printf("a%d%d = ", i, j);
					scanf("%d", &mas[i][j]);
				}
			}
			count++;

			// ������ ������(-�) � ���� F1
			fprintf(F1, "����� �������: %d\n�������:\n", count);
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					fprintf(F1, "%d", mas[i][j]);
				}
			}
			fprintf(F1, "\n\n");

			// ����� ���������� ��������
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if ((mas[i][j] < mas[i + 1][j]) && (mas[i][j] < mas[i][j + 1]) && (mas[i][j] < mas[i - 1][j]) && (mas[i][j] < mas[i][j - 1])) {
						min[k] = mas[i][j];
						ind[0][k] = i;
						ind[1][k] = j;
						k++;
					}
				}
			}
			
			// ������ �������� ������(-�) � ���� F2
			fprintf(F2, "� �������: %d\n", count);
			fprintf(F2, "���-�� ���������: %d\n��������: ", k);
			for (int i = 0; i < k; i++) {
				fprintf(F2, "[%d] ", min[i]);
			}
			fprintf(F2, "\n�������: ");
			for (int i = 0; i < k; i++) {
				fprintf(F2, "[%d][%d] ", ind[0][i], ind[1][i]);
			}
			fprintf(F2, "\n\n");
			break;
		case 2:

			// ������� ��� ������ �� �����
			menu = 2;
			break;
		}
		system("pause");
		system("cls");
	} while (menu != 2);
	return 0;
}