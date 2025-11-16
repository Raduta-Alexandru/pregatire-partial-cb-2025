#include <stdio.h>

// functie care face swap intre pointeri, NU si intre valorile efective
// daca i = 3 j = 4 di = &i dj = &j
// rezultat -> i = 3 j = 4 di = &j dj = &i
void f1(int **cerc, int **patrat) {
	int* temp = *cerc;
	*cerc = *patrat;
	*patrat = temp;
}

// functie care face swap efectiv pe adrese
// daca i = 3 j = 4 di = &i dj = &j
// rezultat -> i = 4 j = 3 di = &i dj = &j
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