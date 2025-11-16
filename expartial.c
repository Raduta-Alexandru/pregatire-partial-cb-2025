#include "string.h"
#include "stdlib.h"
#include "stdio.h"

int compara(const void *a, const void *b) {
	// imi iau adresa de stringurilor
	char** student1 = (char**)a;
	char** student2 = (char**)b;
	char grupa1[6];
	char grupa2[6];
	// pun in 2 vectori auxiliari grupele
	strncpy(grupa1, *student1, 5);
	strncpy(grupa2, *student2, 5);
	// compar grupele si returnez rezultatul
	return strcmp(grupa1, grupa2);
}

int* studenti_op(char **students, int num_students) {
	// sortez studentii
	qsort(students, num_students, sizeof(char*), compara);
	// ii afisez sortati
	for(int i = 0; i < num_students; i++) {
		printf("%s\n", students[i]);
	}
	// numar grupele, incepand de la 1, pentru ca eu numar
	// verificand daca e diferit de precedenta
	int nr_grupe = 1;
	for(int i = 0; i < num_students - 1; i++) {
		if(strncmp(students[i], students[i + 1], 5) != 0) {
			nr_grupe++;
		}
	}
	// vad cate grupe am
	printf("%d\n", nr_grupe);
	// al
	int* vector_grupe = malloc(nr_grupe * sizeof(int));
	if (vector_grupe == NULL) {
		perror("Eroare la alocare");
		return NULL;
	}
	// parcurg in paralel vectorul alocat
	int pozitie = 0;
	// din nou, incep de la 1, pentru ca numar verificand
	// ca e diferita grupa de cel precedent
	vector_grupe[pozitie] = 1;
	for (int i = 0; i < num_students - 1; i++) {
		// daca e la fel inseamna ca e un student in plus in grupa
		if (strncmp(students[i], students[i + 1], 5) == 0) {
			(vector_grupe[pozitie])++;
		} else {
			// daca e diferit trec la urmatoarea grupa
			pozitie++;
			vector_grupe[pozitie] = 1;
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
