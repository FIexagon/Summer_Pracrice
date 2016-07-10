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
	int i, j, k, l, m, n, x, y, pryam, a, b;
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
	list = (char *)malloc(2 * i + 1);	
	last = (char *)malloc(2 * i + 1);
	WriteList(phrase, list, i);
	list[i] = '\0';
	i = 0;
	while (fread(&P, sizeof(char), 1, code)) {
		InsertToHead(P, &phrase);
		i++;
	};
	word = (char *)malloc(i + 1);	
	word1 = (char *)malloc(i + 1);
	WriteList(phrase, word, i);
	word[i] = '\0';
	strcat(word, alph);			
	k = 0;
	l = 0;
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
	for (i = 0; i < strlen(list); i = i + 2) {
		x = -1;
		y = -1;
		bigr(alph, list[i], list[i + 1], &x, &y);
		if (int(x / 8) == int(y / 8)) {
			if (int((x + 1) / 8) == int(x / 8)) { a=x+1; }
			else { a = x - 7; };
			if (int((y + 1) / 8) == int(y / 8)) { y++; }
			else { y = y - 7; }
			x = a;
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
			}
			else {
				pryam = (int(x % 8) - int(y % 8));
				x = x - pryam;
				y = y + pryam;
			};
		};
			last[i] = alph[x];
			last[i + 1] = alph[y];
	};
		last[strlen(list)] = '\0';
	fprintf(fsr1, "%s", last);
	fclose(fsr);
	fclose(fsr1);
	fclose(code);
}
void InsertToHead(char AItem, PNode * Head) {
	PNode Q;
	Q = (PNode)malloc(sizeof(TNode));
	Q->Next = *Head;
	Q->Sym = AItem;
	*Head = Q;
}
void WriteList(PNode P, char *f, int i) {
	while (P != NULL) {
		i--;
		f[i] = P->Sym;
		P = P->Next;
	}
}
void bigr(char alph[73], char a, char b, int *k, int *j) {
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
