# include <stdio.h>

int main(){
	
	int option = 0;
	printf("Program Menu\n");
	printf("1. Factorial (Solution with While)\n");
	printf("2. Average between n numbers (Solution with do-While)\n");
	printf("3. Average of 5 numbers (Solution with for)\n");
	printf("Pick an option: ");
	scanf("%d", &option);
	
	// add variables when needed (make them global to avoid problems)
	
	// variables for case 1
	int n=0, cnt=1; // n -> number, cnt -> counter
	double fact=1; // fact -> final mutiplication

	// variables for case 2
	float result=0, x=0, num=0, avgCnt=0; // result -> variable to assign the final result
								  		  // x -> variable that keeps the sum of the numbers
								  	   	  // num -> a place to assign the scanf values
										  // avgCnt -> keeps track of how many numbers there are

	// variables for case 3
	int a=0, i=5; // a -> variable to hold the number input
				// i -> holds the counter used in the for loop
	float avg, sum=0; // sum -> variable to hold the sum of the numbers
					  // avg -> variable to hold the final result
	
	//Implement options menu
	switch(option){
		case 1: // factorial
			printf("\nPick a number: ");
			scanf("%d", &n);
			while(cnt<=n){
				fact*=cnt;
				cnt++;
			}
			printf("%d! = %.lf", n, fact);
			break;
			
		case 2: // average between n numbers
			do{
				printf("Enter the numbers one by one (-1 if you want to stop entering): ");
				scanf("%f", &num);
				x += num;
				avgCnt++;
			}while(num!=-1);
			result = (x+1)/(avgCnt-1);
			printf("\nThe average is: %.2f ", result);
			break;
				
			
		case 3: // average between 5 numbers
			for(i; i>0; i--){
				printf("Enter one of the 5 numbers to find the average of: ");
				scanf("%d", &a);
				sum += a;
			}
			avg = sum/5;
			printf("The average is %.1f", avg);
			break;
			
		default:
			printf("Option not available");
			break;
	}
	
	return 0;
}
