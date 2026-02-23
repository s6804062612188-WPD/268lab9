/*
 * C Program to Remove all Characters in Second String which are present in First String
 --- Any lines that is edited/added will have a //wp comment at the end of that line
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size 100

int unique(char c, char str[]) {//wp *
	for (int i = 0; str[i]!='\0'; i = i+1) {
		if (c==str[i]) return 0;
	} return 1;
}	//* wp

int main () {
    char str1[size], str2[size];
    int i = 0, j = 0, k = 0;
    int strRemoval[size]={0};	//wp
 
    printf ("Enter the First string:\n");
    fgets(str1, size, stdin);	//wp
    str1[strcspn(str1, "\n")] = '\0';	//wp
	
	str2[0] = '\0';	//wp *
	for (i = 0; str1[i]!='\0'; i++) {
        if ( unique(str1[i], str2) ) {
            str2[k] = str1[i];
            k++;
        }
    }
    str2[k] = '\0';
    strcpy(str1, str2);	//* wp
	
    printf("Enter the Second string:\n");
    fgets(str2, size, stdin);	//wp
    str2[strcspn(str2, "\n")] = '\0';	//wp

    for (i = 0; str1[i]!= '\0'; i++) {
    	char str_rem[size]; k = 0;
        for (j = 0; str2[j] != '\0'; j++) {
            if (str1[i] == str2[j]) {
            	strRemoval[i]++;	//wp
                continue;
            } else {
                str_rem[k] = str2[j];
                k++;
            }
        }
        str_rem[k] = '\0';
        strcpy(str2, str_rem);
        k = 0;
    }
 
    printf("On removing characters from *2nd string by 1st* string we get:\n%s\n", str2);	//wp *
    printf("Here are what has been removed:\n");
	for (i = 0; str1[i]!='\0'; i=i+1) {
    	printf("\t'%c':\t%d time", str1[i], strRemoval[i]);
    	if (strRemoval[i] != 1)	printf("s\n");
		else	printf("\n");
	}	//wp
    return 0;
}
