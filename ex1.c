#include <stdio.h>

void f1(int **cerc, int **patrat) {
	int* temp = *cerc;
	*cerc = *patrat;
	*patrat = temp;
}

void f2(int **cerc,int **patrat) {
	int temp = **cerc;
	**cerc = **patrat;
	**patrat = temp;
}

int main() {
	int i = 3;
	int j = 4;
	int *di = &i;
	int *dj = &j;
	f2(&di, &dj);
	f1(&di, &dj);
	printf("%d %d\n", i, j);
	printf("%d %d\n", *di, *dj);
}