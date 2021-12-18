#include <stdio.h>

int main(){
	int i;i = fprintf(stdin, "Hello!");
	printf("%d", i==EOF);
	return 0;
}
