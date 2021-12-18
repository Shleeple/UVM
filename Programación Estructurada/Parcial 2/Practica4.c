# include <stdio.h>
# include <string.h>

struct car{
	char s[30];
};

void leers(const char *mensaje, char s[], int n){
	printf(mensaje);
	printf("(max %d): ", n-1);
	fflush(stdin);
	fgets(s, n, stdin);
	if(s[strlen(s)-1]=='\n'){
		s[strlen(s)-1] = '\0';
	}
}

int main(){
	struct car s1, s2, sc;
	leers("Enter a string: ", s1.s, sizeof(s1.s));
	strcpy(sc.s, s1.s); 						// func strcpy
	printf("\nString 2, a copy, is %s", sc.s); 
	printf("\nThe length is %d", strlen(sc.s)); // func strlen
	printf("\nIn uppercase: %s", strupr(sc.s)); // func strupr
	printf("\nIn lowercase: %s", strlwr(sc.s)); // func strlwr #1
	leers("\n\nEnter another string to compare alphabetically ", s2.s, sizeof(s2.s));
	if(strcmp(s1.s, s2.s)==0){ 					// func strcmp #2
		printf("<%s> es igual a <%s>\n", sc.s, s2.s);
	}
	else if (strcmp(s1.s, s2.s)>0){
		printf("<%s> is greater than <%s>\n", sc.s, s2.s);
	}
	else{
		printf("<%s> is lees than <%s>\n", sc.s, s2.s);
	}
	printf("\nThe first letter of s2 at the end of s1: <%s>", strncat(sc.s, s2.s, 1)); // func strncat #3
	printf("\nThe concatenated string is <%s>", strcat(sc.s, s2.s)); // func strcat #4
	printf("\nThe string in reverse: <%s>", strrev(sc.s));			 // func strrev #5
	
	return 0;
}
