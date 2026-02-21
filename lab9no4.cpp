#include <stdio.h>

void swapValue(int *a, int *b, int *c);
void swapArray(int a[], int b[], int size); 

void printArray(int a[], int size) {
	for (int i=0; i<size; i=i+1) {
		printf("%d", a[i]);
		(i==size-1)? 0:printf(",");
	}
} 

int main() {
	int a = 1, b = 2, c = 3;
	printf("Before swap function:\ta=%d, b=%d, c=%d\n", a, b, c);
	swapValue( &a , &b , &c );
	printf("After swap function:\ta=%d, b=%d, c=%d\n", a, b, c);
	
	printf("\n------------------------------\n\n");
	
	int alpha[5]={1,2,3,5,6}, beta[5]={9,8,7,6,5};
	printf("BEFORE swapArray:\nA={"); printArray(alpha, 5);
	printf("},\tB={"); printArray(beta,5); printf("}\n");
	swapArray(alpha, beta, 5);
	printf("AFTER swapArray:\nA={"); printArray(alpha, 5);
	printf("},\tB={"); printArray(beta,5); printf("}\n");

}

void swapValue(int *a, int *b, int *c) {
	int t = *c;
	*c = *a;
	*a = *b;
	*b = t;
}

void swapArray(int a[], int b[], int size) {
	for (int i=0; i<size; i=i+1) {
		int t=a[i];
		a[i]=b[i];
		b[i]=t;
	}
}
