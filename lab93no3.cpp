#include <stdio.h>
#define size 64

int checkLogin(char *login, char *passwd, char *logindb, char *passdb); 

int stringCmp(char *str1, char *str2) {
	int i=0;
	while (str1[i]==str2[i]) {
		if (str1[i]=='\0') return 1;
		i=i+1;
	} return 0;
}

int main() {
	char login[5][size]={"user1","user2","user3","user4","user5"};
	char password[5][size]={"pass1","pass2","pass3","pass4","pass5"};
	
	char user[size], pass[size];
	printf("Enter your username:\n");	scanf("%s", user);
	printf("Enter your password:\n");	scanf("%s", pass);
	
	checkLogin(user, pass, login[0], password[0]);
}

int checkLogin(char *login, char *passwd, char *logindb, char *passdb) {
	int id=-1;
	for (int i=0; i<5; i=i+1) {
		if ( stringCmp( login, logindb+i*size ) ) {
			id=i; break;
		}
	}
	
	if (id>=0) {
		if ( stringCmp( passwd, passdb+id*size) ) {
			printf("Welcome\n"); return 0;
		}
	}
	printf("Incorrect login or password\n");
	return 0;
}
