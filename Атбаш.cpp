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
	fsr = fopen("list.bin", "rb");
	fsr1 = fopen("output.bin", "w");
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
	while (P != NULL) {
		i--;
		f[i] = P->Sym;
		if (((int)(f[i]) >= -64) && ((int)(f[i]) <= -49)) {
			f[i] = (char)(-33 - ((int)(f[i]) + 64));
		}
		else if (((int)(f[i]) >= -48) && ((int)(f[i]) <= -33)) {
			f[i] = (char)(-64 + (-33 - (int)(f[i])));
		} 
		else if (((int)(f[i]) >= -32) && ((int)(f[i]) <= -17)) {
			f[i] = (char)(-1 - ((int)(f[i]) + 32));
		}
		else if (((int)(f[i]) >= -16) && ((int)(f[i]) <= -1)) {
			f[i] = (char)(-32 + (-1 - (int)(f[i])));
		}
		P = P->Next;
	}
}
