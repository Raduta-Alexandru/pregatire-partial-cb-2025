#include <string.h>
#include <stdio.h>

int numaraRime(char **poezie, int nrVersuri) {
	// contor
	int count = 0;
	// parcurg de la primul la penultimul vers
	for (int i = 0; i < nrVersuri - 1; i++) {
		// imi iau versul i
		char *vers1 = poezie[i];
		// imi iau versul i + 1
		char *vers2 = poezie[i + 1];
		// imi iau lungimile
		int len1 = strlen(vers1);
		int len2 = strlen(vers2);
		// consider ca nu se termina in punctuatie si compar ultimile 2 caractere
		if ((vers1[len1 - 1] == vers2[len2 - 1]) && (vers1[len1 - 2] == vers2[len2 - 2])) {
			count++;
		}
		/*
		if (strcmp(&poezie[i][len1 - 2], vers2 + len2 - 2) == 0) {
			count++;
		}
		*/
		/*
		if (poezie[i][len1 - 1] == poezie[i + 1][len2 - 1]) {
			count++;
		}
		*/
		/*
		if ((poezie[i][strlen(poezie[i]) - 1] == poezie[i + 1][strlen(poezie[i + 1]) - 1]) && (poezie[i][strlen(poezie[i]) - 2] == poezie[i + 1][strlen(poezie[i + 1]) - 2])) {
			count++;
		}
		*/
	}
	return count;
}

int main() {
	char vers1[100];
	char vers2[100];
	char vers3[100];
	char vers4[100];
	char vers5[100];
	char *poezie[5];
	poezie[0] = vers1;
	poezie[1] = vers2;
	poezie[2] = vers3;
	poezie[3] = vers4;
	poezie[4] = vers5;
	strcpy(vers1, "A fost o data ca in povesti");
	strcpy(vers2, "Testarea aminti");
	strcpy(vers3, "Mergea Mihai la magazin");
	strcpy(vers4, "Si scria la std in");
	strcpy(vers5, "Si si-a cumparat aspacardin");

	printf("%d\n", numaraRime(poezie, 5));

	return 0;
}

