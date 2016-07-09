#include "stdafx.h"	
#include <math.h>		
#include <string.h>		
#include <fstream>
struct TNode {
	char Sym;
	TNode *Next;
};
typedef TNode * PNode;
void InsertToHead(char AItem, PNode * Head);
void WriteList(PNode P, char *f, int i);
void bigr(char alph[73], char a, char b, int *k, int *j);
int main() {
	setlocale(LC_ALL, ".1251");
	PNode phrase = NULL;
	char *list, *last, *word, *word1;
	FILE *fsr;
	FILE *fsr1;
	FILE *code;
	int i, j, k, l, m, n, x, y, a, pryam, b;
	char P;
	char alph[73] = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ .,!?-";
	fsr = fopen("list.bin", "rt");
	code = fopen("code.txt", "rt");
	fsr1 = fopen("output.bin", "wt");
	i = 0;
	while (fread(&P, sizeof(char), 1, fsr)) {
		InsertToHead(P, &phrase);
		i++;
	};
	list = (char *)malloc(2 * i + 1);		//выделение нужного объёма памяти		
	last = (char *)malloc(2 * i + 1);
	WriteList(phrase, list, i);
	list[i] = '\0';
	i = 0;
	while (fread(&P, sizeof(char), 1, code)) {
		InsertToHead(P, &phrase);
		i++;
	};
	word = (char *)malloc(i + 1);		//выделение нужного объёма памяти		
	word1 = (char *)malloc(i + 1);
	WriteList(phrase, word, i);
	word[i] = '\0';
	strcat(word, alph);					//составление таблицы шифрования
	k = 0;
	l = 0;
	//удаление повторяющихся символов из таблицы шифрования
	for (i = 0; i<strlen(word); i++)
	{
		k = 0;
		for (j = 0; j < i; j++)
		{
			if (word[i] == word1[j]) {
				k = k + 1;
			};
		};
		if (k == 0) {
			word1[l] = word[i];
			l++;
		};
	};
	word1[l] = '\0';
	for (a = 0; a < 73; a++) {
		printf("%c ", alph[a]);
		if (a % 8 == 7) { printf("\n"); }
	};
	//разбиение биграммов из одинаковых символов
	for (i = 0; i < strlen(list); i = i + 2) {
		if (list[i] == list[i + 1]) {
			m = strlen(list);
			for (n = m; n > i; n--) {
				list[n + 1] = list[n];
			};
			list[i + 1] = '-';
		};
	};
	if (int(strlen(list) % 2) == 1) {
		b = strlen(list);
		list[b] = '-';
		list[b + 1] = '\0';
	};
	puts(list);
	//шифрование
	for (i = 0; i < strlen(list); i = i + 2) {
		x = -1;
		y = -1;
		bigr(alph, list[i], list[i + 1], &x, &y);
		printf("%3i %3i %c%c     ", x, y, list[i], list[i + 1]);
		if (int(x / 8) == int(y / 8)) {
			if (int((x + 1) / 8) == int(x / 8)) { x++; }
			else { x = x - 6; };
			if (int((y + 1) / 8) == int(y / 8)) { y++; }
			else { y = y - 6; }
			printf("1");
		}
		else {
			if (int(x % 8) == int(y % 8)) {
				x = x + 8;
				y = y + 8;
				if (x > 72) {
					x = x - 72;
				};
				if (y > 72) {
					y = y - 72;
				};
				printf("2");
			}
			else {
				pryam = (int(x % 8) - int(y % 8));
				x = x - pryam;
				y = y + pryam;
				printf("3");
			};
		};
			last[i] = alph[x];
			last[i + 1] = alph[y];
		printf("     %3i %3i %c%c\n", x, y, alph[x], alph[y]);
	};
		last[strlen(list)] = '\0';
	printf(last);
	fprintf(fsr1, "%s", list);
	fclose(fsr);
	fclose(fsr1);
	fclose(code);
	system("pause");
}
void InsertToHead(char AItem, PNode * Head) {		//чтение из файла в динамические массив
	PNode Q;
	Q = (PNode)malloc(sizeof(TNode));
	Q->Next = *Head;
	Q->Sym = AItem;
	*Head = Q;
}
void WriteList(PNode P, char *f, int i) { //запись в статический массив
	while (P != NULL) {
		i--;
		f[i] = P->Sym;
		P = P->Next;
	}
}
void bigr(char alph[73], char a, char b, int *k, int *j) { //получение номеров элементов биграмма в таблице
	int i;
	for (i = 0; i < 73; i++) {
		if (alph[i] == a) {
			*k = i;
		};
		if (alph[i] == b) {
			*j = i;
		};
	};
}