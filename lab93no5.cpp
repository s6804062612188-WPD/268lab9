#include <stdio.h>
#include <ctype.h>
#define size 100

int sumDigits(char text[]) {
	int sum=0;
	for (int i=0; text[i]!='\0'; i=i+1) {
		if ( isdigit(text[i]) ) sum = sum+text[i] - '0';
	} return sum;
}

int main() {
	char text[size];
	printf("Enter input:\t");	fgets(text, size, stdin);
	
	printf("Sum of digit char:\t%d\n", sumDigits(text) );
	return 0;
}
