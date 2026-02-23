#include <stdio.h>
#define MAX 100

int countVowel(char [], int cV[], char V[]);

int main() {
	char text[MAX];
	char vowel[] = {'a','e','i','o','u'};	int cVowel[5] = {0};
	printf("Enter text: ");
	scanf("%s", text);
	int tVowel = countVowel(text, cVowel, vowel);
	printf("Text: [%s] has %d vowels, break down as follows:\n", text, tVowel);
	for (int i=0; i<5; i=i+1) {
		printf("\t%c:\t%d\n", vowel[i], cVowel[i]);
	}
	return 0;
}

int countVowel(char t[], int cV[], char V[]) {
	int i=0;
	int occur=0;
	while (i<MAX && t[i]!='\0') {
		char cha=t[i];
		(65 <= cha && cha <=90)? cha=cha+32:0;
		for (int j=0; j<5; j=j+1) {
			if (cha==V[j]) {
				cV[j]++;
				occur++;
			}
		}
		i++;
	}
	return occur;
}
