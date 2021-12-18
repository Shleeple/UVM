# include <stdio.h>
# include <math.h>

int main(){
	
	int x, i, p; 	// x -> number to be determined whether it's prime or not
			  	    // i -> counter used in for loop
			  	    // p -> variable to hold whether the number is prime or not
	float c;
	printf("Enter a value: ");
	scanf("%d", &x);
	for(i=2; i <= pow(x, 1/2); i++){
		if(x%i==0){
			p = 1;
		}
	}
	if(p==1){
		printf("El numero no es primo.");
	}
	else{
		printf("El numero si es primo.");
	}
	
	return 0;
}
