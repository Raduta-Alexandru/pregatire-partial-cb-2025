#include "string.h"
#include "stdlib.h"
#include "stdio.h"

int compara(const void *a, const void *b) {
	char** student1 = (char**)a;
	char** student2 = (char**)b;
	char grupa1[6];
	char grupa2[6];
	strncpy(grupa1, *student1, 5);
	strncpy(grupa2, *student2, 5);
	return strcmp(grupa1, grupa2);
}

int* studenti_op(char **students, int num_students) {
	qsort(students, num_students, sizeof(char*), compara);
	for(int i = 0; i < num_students; i++) {
		printf("%s\n", students[i]);
	}
	int nr_grupe = 1;
	for(int i = 0; i < num_students - 1; i++) {
		if(strncmp(students[i], students[i + 1], 5) != 0) {
			nr_grupe++;
		}
	}
	printf("%d\n", nr_grupe);
	int* vector_grupe = calloc(nr_grupe, sizeof(int));
	int pozitie = 0;
	vector_grupe[pozitie]++;
	for (int i = 0; i < num_students - 1; i++) {
		if (strncmp(students[i], students[i + 1], 5) == 0) {
			(vector_grupe[pozitie])++;
		} else {
			pozitie++;
			vector_grupe[pozitie]++;
		}
	}
	return vector_grupe;
}

int main() {
	char *students[10];
	students[0] = strdup("314CB:Alex");
	students[1] = strdup("313CA:George");
	students[2] = strdup("311CD:Mihai");
	students[3] = strdup("314CB:Ana");
	students[4] = strdup("313CA:Ionut");
	students[5] = strdup("311CD:Erik");
	students[6] = strdup("313CA:Andreea");
	students[7] = strdup("311CD:Mihaela");
	students[8] = strdup("314CB:Diana");
	students[9] = strdup("311CA:Iulia");
	int* vector_grupe = studenti_op(students, 10);
	for(int i = 0; i < 4; i++) {
		printf("%d\n", vector_grupe[i]);
	}
}
