# include <stdio.h>
# include <math.h>
# include <stdlib.h>

int main(){
	
	int option;
	
	// Variables for case 1
	int A, B, C, M, D, E, N, K, P, Q, year;
	
	// Variables for case 2
	int hour, minute;
	
	// Variables for case 3
	int tmp, cnt=0;
	float sum=0, avg;
	
	// Variables for case 5:
	int sum5=0, num, cnt5 = 0;
	
	printf("Practica 8: Menu de Programa\n");
	do{
	//	system("cls");
		printf("\n1. Easter Sunday\n");
		printf("2. 24 Hour Notation\n");
		printf("3. Temperature Avg\n");
		printf("4. Paycheck Total\n");
		printf("5. Digit Quantity and Sum\n");
		printf("6. Succession\n");
		printf("7. Fibonacci\n");
		printf("8. Exit Program\n\n");
		printf("Pick an Option: ");
		scanf("%d", &option);
		
		switch(option){
			case 1:
				printf("\nPick a year: ");
				scanf("%d", &year);
				A = year % 19;
				B = year % 4;
				C = year % 7;
				K = A / 100;
				P = (13 + 8*K) / 25;
				Q = K / 4;
				M = (15 - P + K - Q) % 30;
				N = (4 + K - Q) % 7;
				D = (19*A+M) % 30;
				E = (2*B+4*C+6*D+N) % 7;
				
				if((D+E)<10){
					printf("Easter Sunday is the %d of March\n\n", (D+E+22));
				}
				else{
					printf("Easter Sunday is the %d of April\n\n", (D+E-9   ));
				}
				system("pause");
			break;
			
			case 2:
				printf("Enter a time in 24 hour format: ");
				printf("\nHours: ");
				scanf("%d", &hour);
				printf("Minutes: ");
				scanf("%d", &minute);
				if(hour>0 && hour<=24 && minute>=0 && minute<60){
					if(hour>12){
						printf(" %d:%02d PM\n", hour-12, minute);
					}
					else if(hour == 24){
						printf(" %d:%02d AM\n", hour-12, minute);
					}
					else if(hour == 12){
						printf(" %d:%02d PM\n", hour, minute);
					}
					else{
						printf(" %d:%02d AM\n", hour, minute);
					}
				}
				else{
					printf("Invalid input\n");
				}
				system("pause");
			break;
			
			/*case 3:
				printf("Enter n temperatures between 32F and 212F to find the average\n");
				printf("Enter them 1 by 1, enter a number outside the bounds to stop: \n");
				scanf("%d", tmp);
				while(tmp>=32 && tmp<=212){
					sum += tmp;
					cnt++;
					avg = sum/cnt;
					scanf("%d", tmp);
				}
				system("pause");
			break;*/
			
			/*case 4:
				
			break;*/
			
			case 5:
				printf("Enter a number: ");
				scanf("%d", num);
				while(num!=0){
					sum5+=(num%10);
					num/=10;
					cnt5++;
				}
				printf("\nDigits: ", cnt5);
				printf("\nSum: ", sum5);
			break;
		}
		
	}while(option!=8);
	
	return 0;
}
