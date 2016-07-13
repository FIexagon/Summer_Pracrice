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
int main() {
	setlocale(LC_ALL, ".1251");
	PNode phrase = NULL;
	char *list;
	FILE *fsr;
	FILE *fsr1;
	int i;
	char P;
	fsr = fopen("list.txt", "r");
	fsr1 = fopen("output.txt", "w");
	i = 0;
	while (fread(&P, sizeof(char), 1, fsr)) {
		InsertToHead(P, &phrase);
		i++;
	};
	list = (char *)malloc(i + 1);
	WriteList(phrase, list, i);
	list[i] = '\0';
	fprintf(fsr1, "%s", list);
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
	int b;
	while (P != NULL) {
		i--;
		f[i] = P->Sym;
		if (((int)(f[i]) >= -64) && ((int)(f[i]) <= -33)) {
			b = (int)(f[i]) + i;
			while (b > -33) {
				b = b - 32;
			}
			f[i] = (char)(b);
		}
		else {
			if (((int)(f[i]) >= -32) && ((int)(f[i]) <= -1)) {
				b = (int)(f[i]) + i;
				while (b > -1) {
					b = b - 32;
				}
				f[i] = (char)(b);
			};
		};
		P = P->Next;
	}
}