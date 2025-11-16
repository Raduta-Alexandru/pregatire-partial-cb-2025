#include <stdio.h>
#include <stdlib.h>

unsigned char *toBytes(int ip) {
	// imi aloc un vector de lungime 4 in care sa tin ip-ul
	unsigned char *ip_char = malloc(4 * sizeof(unsigned char));
	if (ip_char == NULL) {
		perror("Nu a functionat alocarea\n");
		return NULL;
	}
	// imi iau pe rand octetii
	ip_char[3] = (char)ip;
	ip_char[2] = (char)(ip >> 8);
	ip_char[1] = (char)(ip >> 16);
	ip_char[0] = (char)(ip >> 24);
	return ip_char;
}

// return 1 - daca este masca 0 - daca nu este masca
char verificaMasca(unsigned int masca) {
	// elimina 0 de la inceput
	while (masca % 2 == 0) {
		masca = masca >> 1;
	}
	// va elimina toti 1
	while (masca != 0) {
		// daca ajung la un zero, nu mai e masca
		if (masca % 2 == 0) {
			return 0;
		}
		masca = masca >> 1;
	}
	return 1;
}

char verificaMasca2(unsigned int masca) {
	// numar cate comparatii fac
	int nr_interatii = 0;
	// merg pana raman cu primul 1
	// pentru ca shiftarea imi pune 0 si
	// ultimul check o sa pice si pe cazul bun
	while(masca != 1) {
		// pica doar la cazul "01"
		if (((masca >> 1) % 2) < (masca % 2)) {
			return 0;
		}
		masca = masca >> 1;
		nr_interatii++;
	}
	// trebuie sa am 31 de comparatii, daca nu, ies
	if (nr_interatii != 31) {
		return 0;
	}
	return 1;
}

int main() {
	int ip = 0xFFFEFDFC;
	unsigned char *vector = toBytes(ip);
	for(int i = 0; i < 4; i++) {
		printf("%d.", vector[i]);
	}
	printf("\n");
	free(vector);
	int masca_valida = 0xFFFFFC00;
	printf("%d %d\n", verificaMasca(masca_valida), verificaMasca2(masca_valida));
	int masca_invalida = 0xFFFFFB00;
	printf("%d %d\n", verificaMasca(masca_invalida), verificaMasca2(masca_invalida));
	return 0;
}