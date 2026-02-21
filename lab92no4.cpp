#include <stdio.h>
#include <ctype.h>
#include <string.h>

int checkLogin(char *login, char *passwd);

int checkValidPass(char *ps);

int main() {
	char login[64], password[64];
	printf("Enter login : "); gets(login);
	printf("Enter password : "); gets(password);
	if( checkLogin(login, password) == 1) {
		printf("Welcome\n");
	} else {
		printf("Incorrect login or password\n");
	}
	if (checkValidPass(password)) {
		//if Password is valid
		printf("Accepted\n");
	} else {
		printf("Reject\n");
	}
}
int checkValidPass(char *ps) {
	int accepted=0;
	
	int len=strlen(ps);
	int uc=0, dc=0;
	int unique[len], uindex=0;
	
	for (int i=0; i<len;i=i+1) {
		char ch=ps[i];
		if (isupper(ch)) {
			uc=uc+1;
			int u=1;
			for(int j=0; j<uindex; j=j+1) {
				if(unique[j]==ch) u=0;
			}
			if (u) {
				unique[uindex]=ch;
				uindex=uindex+1;
			}
		} else if (isdigit(ch)) {
			dc=dc+1;
		}
	}
	
	if (len==5 && dc>=1) {
			accepted=1;
	} else if (5 <= len && len <=8) {
		if (uc>=2 && dc>=2) {
			if (uc==uindex) accepted=3;
			if (!isdigit(ps[0])) accepted=2;
		}
	}
	
	//printf("uc:%d dc:%d uindex:%d crit%d\n", uc, dc, uindex, accepted);
	return accepted;
}

int checkLogin(char *login, char *passwd) {
	if( !strcmp(login, "student1") && !strcmp(passwd, "mypass"))
		return 1;
	return 0;
}
