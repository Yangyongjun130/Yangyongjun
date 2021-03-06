#ifndef DisjSet_H
#define DisjSet_H
#define NumSets 22

typedef int DisjSet[NumSets + 1];
typedef int SetType;
typedef int ElementType;

void Initilialize(DisjSet S);
void SetUnion(DisjSet s, SetType root1, SetType root2);
SetType Find(ElementType X, DisjSet S);
#endif
#define _CRT_SECURE_NO_WARNINGS
#include "../ADT/head.h"
#include <stdio.h>



void initilialize(DisjSet s) {
	for (int i = NumSets; i > 0; i--)
		s[i] = 0;
}
//按高度
void setUnion(DisjSet s, SetType root1, SetType root2) {
	if (s[root2] < s[root1]) {
		s[root1] = root2;
	}
	else {
		if (s[root2] == s[root1])
			s[root1]--;
		s[root2] = root1;
	}
}


SetType find(ElementType X, DisjSet s) {
	if (s[X] <= 0)
		return X;
	else
		return s[X] = find(s[X], s);
}
int main() {
	DisjSet s;
	initilialize(s);
	int u, v;
	printf("enter the connection\n");
	while (scanf("%d%d", &u, &v) == 2)
	{
		SetType utype = find(u, s);
		SetType ttype = find(v, s);
		if (utype == ttype)
		{
			printf("has connected\n");
		}
		else
		{
			printf("conncet them\n");
			setUnion(s, utype, ttype);
		}
		printf("enter the connection\n");
	}
}
