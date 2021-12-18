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

// Funcion para imprimir un archivo binario, utilizando instruccion fwrite()

int menu(){
	int opcion;
	printf("--------------------------------\n");
	printf("Menu de Funciones\n");
	printf("--------------------------------\n");
	printf("0. Salir\n1. Agregar Alumnos\n2. Imprimir Listado\n3. Guardar\n4. Cargar\n");
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

void guardar(struct alumno x[]){
	FILE *f;
	char filename[30];
	char mode[4];
	leers("Nombre del archivo: ", filename, sizeof(filename));
	leers("Modo de apertura del archivo: ", mode, sizeof(mode));
	
	f=fopen(filename, mode);
	if(f!=NULL){
		for(i=0; i<n; i++){
			fwrite(&x[i], sizeof(x[i]), 1, f);
		}
		fclose(f);
		printf("Datos guardos...\n");
	}
	else{
		printf("Error al tratar de guardar los datos...\n");
	}
}

//Funcion para leer un archivo binario, utilizando instruccion fread()
void cargar(struct alumno x[]){
	FILE *f;
	f=fopen("alumnos.txt", "r");
	n=0;
	if(f!=NULL){
		while(fread(&x[n], sizeof(x[n]), 1, f)==1){
			printf("%d %s %d %f \n", n, x[n].nombre, x[n].edad, x[n].prom);
			n++;
		}
		fclose(f);
		printf("==> %d registros leidos.\n", n);
	}
	else{
		printf("Error al tratar guardar los datos.\n");
	}
	guardar(x);
}

int main(){
	struct alumno grupo[MAXIMO]; //Arreglo de estructura (tipo alumno)
	struct alumno dato; // Variable tipo estructura (tipo alumno)
	int pos, opcion;
	//char nombre[30]; // Declaracion de un arreglo de char para almacenar el nombre de hasta 30 caracteres
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
				guardar(grupo);	
			break;
			
			case 4:
				cargar(grupo);
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
