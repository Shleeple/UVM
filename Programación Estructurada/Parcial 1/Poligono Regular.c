#include <stdio.h>

int main(){
	int n;
	float a, b, A, P;
	printf("Calculo de Perimetro y Area de un Poligono Regular\n");
	printf("Introduce el numero de lados: ");
	scanf("%d", &n);
	printf("Introduce la dimension del apotema: ");
	scanf("%f", &a);
	printf("Introuce la dimension de un lado: ");
	scanf("%f", &b);
	P = n * b;
	A = P * a / 2;
	printf("El perimetro es %.3f y el Area es %.2f\n", P, A);
	
	return 0;		
}
