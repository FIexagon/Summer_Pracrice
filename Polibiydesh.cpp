#include "stdafx.h"	
#include <math.h>		
#include <string.h>		
#include <fstream>
const char POLYBIUS[6][6] = {
	{ 'À', 'Á', 'Â' , 'Ã', 'Ä', 'Å' },
	{ '¨', 'Æ', 'Ç' , 'È', 'É', 'Ê' },
	{ 'Ë', 'Ì', 'Í' , 'Î', 'Ï', 'Ð' },
	{ 'Ñ', 'Ò', 'Ó' , 'Ô', 'Õ', 'Ö' },
	{ '×', 'Ø', 'Ù' , 'Ú', 'Û', 'Ü' },
	{ 'Ý', 'Þ', 'ß' , '-', '-', '-' }
};
struct TNode {
	char Sym;
	TNode *Next;
};
typedef TNode * PNode;
void encrypt(char *c, int x, int y);
void InsertToHead(char AItem, PNode * Head);
void WriteList(PNode P, char *f, int i);
int main() {
	setlocale(LC_ALL, ".1251");
	PNode phrase = NULL;
	char *list, *last;
	int *x;
	int*y;
	FILE *fsr;
	FILE *fsr1;
	int i, a, b;
	char P;
	fsr = fopen("list.txt", "rt");
	fsr1 = fopen("output.txt", "w");
	i = 0;
	while (fread(&P, sizeof(char), 1, fsr)) {
		InsertToHead(P, &phrase);
		i++;
	};
	list = (char *)malloc(2 * i + 1);
	WriteList(phrase, list, i);
	list[i] = '\0';
	x = (int *)malloc(strlen(list));
	y = (int *)malloc(strlen(list));
	last = (char *)malloc((strlen(list)-1) / 2 + 1);
	for (i = 0; i < strlen(list)/2; i++) {
		a = int(list[i])-48;
		b = int(list[i + (strlen(list)) / 2]-48);
		encrypt(&last[i], a, b);
	};
	last[i] = '\0';
	fprintf(fsr1, "%s", last);
	fclose(fsr);
	fclose(fsr1);
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
void encrypt(char *c, int x, int y) {
	int i, j;
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			if ((x==i)&&(y==j)) {
				*c = POLYBIUS[j][i];
			}
}