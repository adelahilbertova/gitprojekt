
//#include "pch.h"
#include <stdio.h>

void n(char x[1000]) {
	FILE *fr;
	int i, pocet = 0;
	char c;
//	errno_t err = fopen_s(&fr, "sifra.txt", "r");
	fr = fopen("sifra.txt", "r");
	if (fr == NULL) {
		printf("Spravu sa nepodarilo nacitat.");
	}
	while ((c = getc(fr)) != EOF) {
		pocet++;
	}
	fseek(fr, 0, SEEK_SET);
	for (i = 0;i <= pocet;i++) {
		c = getc(fr);
		x[i] = c;
	}
	x[pocet] = '\0';
	fclose(fr);
}

void v(char x[1000]) {
	int i=0, pocet = 0;

	while (x[i] != '\0') {
		pocet++;
		i++;
	}
	for (i = 0; i < pocet; i++) {
		printf("%c", x[i]);
	}
	if (i == 0) {
		printf("Sprava nieje nacitana\n");
	}
	printf("\n");
}

void u(char x[1000], char b[1000]) {
	int i = 0, t = 0;

	while (x[i] != '\0') {
		if ((x[i] >= 'a' && x[i] <= 'z') || (x[i] >= 'A' && x[i] <= 'Z')) {
			if (x[i] >= 'a' && x[i] <= 'z') {
				b[t] = x[i] - 32;
                }else
                    b[t] = x[i];
            t++;
		}
		i++;
	}
	b[t] = '\0';
	if (i == 0) {
		printf("Sprava nieje nacitana\n");
	}
}
void s(char y[1000]) {
	int i=0, w=0;

	while (y[i] != '\0') {
		printf("%c", y[i]);
		i++;
		w++;
	}
	if (w == 0) {
		printf("Nie je k dispozicii upravena sprava\n");
		return;
	}
	printf("\n");
}

void d(char x[1000]) {
	int nacitanep, o, i = 0, pozicia = 0, pocetpismen = 0;
	char y[1000];

	scanf("%d", &nacitanep);
//	scanf_s("%d", &nacitanep);
	if (x[i] == '\0') {
		printf("Sprava nie je nacitana\n");
		return;
	}
	while (x[i] != '\0') {
		while (x[i] != ' ' && x[i] != '\0') {
			y[i] = x[i];
			pozicia++;
			pocetpismen++;
			i++;
		}
		if (pocetpismen == nacitanep) {
			for (o = pozicia - nacitanep; o < pozicia; o++) {
				printf("%c", y[o]);
			}printf(" ");
		}
		if (x[i] == '\0') {
			break;
		}
		pozicia++;
		y[i] = ' ';
		i++;
		pocetpismen = 0;
	}
	printf("\n");
	return;
}

void c(char x[1000]) {
	int i, nacitanep, pocet=0;
	char y[1000];
	i = 0;
	scanf("%d", &nacitanep);
//	scanf_s("%d", &nacitanep);
	while (x[i] != '\0') {
            pocet++;
		if (x[i] - nacitanep <= 'Z' && x[i] - nacitanep >= 'A') {
			y[i] =x[i]-nacitanep;
			printf("%c", y[i]);
		}
		else if (x[i] - nacitanep < 'A') {
			y[i] = x[i] - nacitanep;
			printf("%c", y[i] + 26);
		}
		i++;
	}
	if (pocet == 0){
        printf("Nie je k dispozicii upravena sprava\n");
	}else
	printf("\n");
}

void h(char x[1000]) {
	int y[1000];
	int i = 0, z = 0, n, f = 0, k, h, r = 0, d = 0, empty = 0, w, j = 0, m=0;
	float percento = 0, pocet = 0, u = 0;
	if (x[d] == '\0') {
		printf("Nie je k dispozicii upravena sprava\n");
		return;
	}
	n = 'Z' - 'A' + 1;

	for (i = 0; i <= n; i++) {
		y[i] = 0;
	}
	while (x[r] != '\0') {
		pocet++;
		r++;
	}
	//pocet -= 2;
	//printf("pocet: %.0lf\n", pocet);
	for (z = 0;z <= pocet;z++) {
		f = x[z] - 'A';
		y[f]++;
	}
	for (k = 0; k <= 10; k++) {
		percento = 100 - k * 10;
		if (percento == 0) {
			break;
		}
		for (w = 0;w <= n;w++) {
			if (y[w] != 0) {
				j = (y[w] / pocet * 100);
				if (j > percento) {
					empty = 1;
				}
			}
		}
		//printf("%.0lf%%:   ", percento);
		if (empty != 0) {
		for (h = 0;h <= n;h++) {
				u = (y[h] / pocet * 100);
				if (u >= percento) {
					printf("*");
				}
				else {
					printf(" ");
				}

			}printf("\n");
		}
		empty = 0;
	}
	for (m = 0;m <= n;m++) {
		if (y[m] > 0) {
			printf("*");
		}
		else printf(" ");
	}
	printf("\n");
	//printf("      ");
	for (k = 0;k < 26;k++) {
		printf("%c", 'A' + k);
	}
	printf("\n");
}

int main()
{
	char nacitanep, povodnytext[1000]={}, upravenytext[1000]={};
	scanf("%c", &nacitanep);
//	scanf_s("%c", &o);
	while (nacitanep != 'k') {
            switch (nacitanep){
        case 'n':n(povodnytext);break;
        case 'v':v(povodnytext); break;
        case 'u':u(povodnytext, upravenytext); break;
        case 's':s(upravenytext); break;
        case 'd':d(povodnytext); break;
        case 'c':c(upravenytext); break;
        case 'h':h(upravenytext); break;
            }
		scanf("%c", &nacitanep);}
//		scanf_s("%c", &o);
	}


