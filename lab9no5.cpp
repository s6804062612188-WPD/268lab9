#include <stdio.h>
#define NMAX 10

//functions prototype
void inputArray(int array[], int N);
void showArray2D(int matrix[][10], int N);
void constructMatrix(int P[][10], int N, int A[ ], int B[ ]);

int main() {  
   int a[NMAX], b[NMAX], p[NMAX][NMAX], n;
   printf("Enter N = ");       	
   scanf("%d", &n);
   printf("Input array A \n"); 	
   inputArray(a, n);
   printf("Input array B \n");
   inputArray(b, n);
   constructMatrix(p, n, a, b);
   printf("Matrix P \n");
   showArray2D(p, n);   
   return 0;
}
//functions definition

void inputArray(int array[], int N) {
	printf("Enter %d integers: ", N);
	for (int i=0; i<N; i=i+1) {
		int t;
		scanf("%d", &t);
		array[i] = t;
	}
}

void showArray2D(int matrix[][10], int N) {
	for (int i=0; i<N; i=i+1) {
		for (int j=0; j<N; j=j+1) {
			printf("%2d", matrix[i][j]);
			((j+1)%N==0)? printf("\n"):printf("\t");
		}
	}
}
void constructMatrix(int P[][10], int N, int A[ ], int B[ ]) {
	for (int i=0; i<N; i=i+1) {
		int t = A[i];
		for (int j=0; j<N; j=j+1) {
			P[i][j] = t*B[j];
		}
	}
}

