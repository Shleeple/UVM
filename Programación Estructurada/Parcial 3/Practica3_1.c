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
# include <stdlib.h>

# define MAXIMO 20

// Variables Globales
int n=0, i, j;

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
void imprimir(struct alumno x[], int pos){
	printf("---------- A L U M N O ---------\n");
	printf("  Nombre: %s \n", x[pos].nombre);
	printf("    Dato: %d \n", x[pos].edad);
	printf("Promedio: %.2f \n", x[pos].prom);
	printf("--------------------------------\n\n");
}

// Funcion para agregar alumno al arreglo de alumnos
int agregar(struct alumno x[], struct alumno dato){
	int band = 0;
	if(n<MAXIMO){
		x[n]=dato;
		n++;
		band = 1;
	}
	return band;
}

// Funcion para introducir los datos de un alumno
struct alumno leer_alumno(){
	struct alumno a;
	printf("Datos del Alumno: \n");
	leers("Nombre: ", a.nombre, sizeof(a.nombre));
	a.edad=leeri("Edad: ");
	a.prom=leerf("Promedio: ");
	return a;
}

int menu(){
	int opcion;
	printf("--------------------------------\n");
	printf("Menu de Funciones\n");
	printf("--------------------------------\n");
	printf("0. Salir\n1. Agregar Alumnos\n2. Imprimir Listado\n3. Ordenar por promedio\n4. Buscar Alumno\n");
	printf("--------------------------------\n");
	printf("Introduce la opcion deseada: ");
	scanf("%d", &opcion);
	return opcion;
}

void listar(struct alumno x[]){
	float suma = 0;
	printf("\n---------- A L U M N O ---------\n");
	printf(" No. %-30s Edad    Prom  \n", "Nombre");
	for (i=0; i<n; i++){
		printf("%4d %-30s %4d %7.2f \n", i+1, x[i].nombre, x[i].edad, x[i].prom);
		suma+=x[i].prom;
	}
	printf("--------------------------------\n");
	printf("El promedio del grupo es %.2f\n", suma/n);
	printf("--------------------------------\n");
}

void ordenar(struct alumno x[]){
	struct alumno valor;
	for (i=0; i<n-1; i++){
		for (j=i+1; j<n; j++){
			if(x[i].prom<x[j].prom){
				valor=x[i];
				x[i]=x[j];
				x[j]=valor;
			}
		}
	}
	printf("Listar Ordenada Por Promedio: \n");
	listar(x);
}

int buscar(struct alumno x[], char nombre[]){
	int pos = -1;
	for (i=0; i<n; i++){
		if(strcmp(nombre, x[i].nombre)==0){
			pos = i;
			break;
		}
	}
	return pos;
}

int main(){
	struct alumno grupo[MAXIMO];
	struct alumno dato;
	int pos, opcion;
	char nombre[30]; // Declaracion de un arreglo de char para almacenar el nombre de hasta 30 caracteres
	do{
		opcion = menu();
		switch(opcion){
			case 0:
				printf("Adios...\n\n");
			break;
			
			case 1:
				dato=leer_alumno();
				//Validar que hay espacio
				if(agregar(grupo, dato)){
					printf("Alumno agregado exitosamente!\n\n");
				}
				else{
					printf("Alumno no agregado, grupo lleno!\n\n");
				}
			break;
			
			case 2:
				listar(grupo);
			break;
			
			case 3:
				ordenar(grupo);	
			break;
			
			case 4:
				printf("Busqueda de Alumnos\n");
				leers("Nombre a buscar: ", nombre, sizeof(nombre));
				pos = buscar(grupo, nombre);
				if(pos>=0){
					imprimir(grupo, pos);
				}
				else{
					printf("Alumno no encontrado. \n");
				}
			break;
			
			default:
				printf("Opcion no valida\n");
				system("pause");
		}
		if(opcion>0){
			system("pause");
			system("cls");
		}
	}while(opcion>0);
	
	return 0;
}
