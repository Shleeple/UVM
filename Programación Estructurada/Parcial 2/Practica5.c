
// Practica No. 5 Estructuras
// Objetivo: Desdarrollar un programa que utiliza variables tipo structuras
/* Estructura: Tipo de datos que agrupa una o mas variables de cualquier tipo primitivo
			   (int, float, double, etc)*/
/* Sintaxis: struct identificador_estructura {
				tipo_dato idvariable1;
				tipo_dato idvariable2;
			 };		*/

# include <stdio.h>
# include <string.h>

// Declaracion Global del tipo estructura
struct alumno{
	char nombre[30];
	int edad;
	float prom;
};

void leers(const char *mensaje, char s[], int n){
	printf(mensaje);
	printf("(max %d): ", n-1);
	fflush(stdin);
	fgets(s, n, stdin);
	// Si el penultimo caracter es un enter, se suplanta por nulo
	if(s[strlen(s)-1]== '\n'){
		s[strlen(s)-1]= '\0';
	}
}

// Funcion para leer un entero
// Parametros: el mensaje a mostrar
// Retorna el numero entero leido por teclado
int leeri(const char *mensaje){
	int n;
	printf(mensaje);
	scanf("%d", &n);
	return n;
}

// Funcion para leer un flotante
// Parametros: el mensaje a mostrar
// Retorna el numero flotante leido por el teclado
float leerf(const char *mensaje){
	float n;
	printf(mensaje);
	scanf("%f", &n);
	return n;
}

// Funcion que imprime los datos de un alumno
void imprimir(struct alumno a){
	printf("---------- A L U M N O ----------\n");
	printf("  Nombre: %s \n", a.nombre);
	printf("    Dato: %d \n", a.edad);
	printf("Promedio: %.2f \n", a.prom);
	printf("---------------------------------\n\n");
}


int main(){
	
	struct alumno a1, a2;
	// Lectura de los datos
	printf("Alumno 1:\n");
	leers("Nombre: ", a1.nombre, sizeof(a1.nombre));
	a1.edad = leeri("Edad: ");
	a1.prom = leerf("Promedio: ");
	
	printf("\nAlumno 2:\n");
	leers("Nombre: ", a2.nombre, sizeof(a2.nombre));
	a2.edad = leeri("Edad: ");
	a2.prom = leerf("Promedio: ");
	
	// Impresion de los promedios alumnos ordenados de mayor a menor
	printf("\nAlumnos ordenados por Promedio \n\n");
	if(a1.prom>=a2.prom){
		imprimir(a1);
		imprimir(a2);
	}
	else{
		imprimir(a2);
		imprimir(a1);
	}
	
	// Impresion de los nombres alumnos ordenados por orden alfabetico
	printf("\nAlumnos ordenados alfabeticamente por Nombre \n\n");
	if(strcmp(a1.nombre, a2.nombre)>0){
		imprimir(a2);
		imprimir(a1);
	}
	else{
		imprimir(a1);
		imprimir(a2);
	}
	
	return 0;
}
