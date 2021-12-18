// Programa para hacer parpadear un LED conectado en RA0

// Se declara el pic a utilizar
#INCLUDE <16F84A.H>
//SE DECLARA EL CRISTAL A UTILIZAR
#USE DELAY(CLOCK=4000000) //4MHz
//SE DECLARAN LOS FUSIBLES DEL PIC

/*
XT = OSCILADOR DE CRISTAL DE CUARZO
NOWDT = NO SE UTILIZARA EL WATCH DOG TIMER
PUT= SE USARA EL POWER UP TIPER
NOPROTECT = NO SE PROTEGERAL EL CODIGO CONTRA LECUTRA
*/
#FUSES XT, NOWDT, PUT, NOPROTECT

//SE DECLARAN LAS VARIABLES
//PARA ESTE CASO NO HAY VARIABLES

//SE DECLARA LA FUNCION PRINCIPAL
VOID MAIN (VOID){
    //SE DECLARA TODO EL PUERTO A Y B COMO SALIDA
    SET_TRIS_A(0B00000);

    SET_TRIS_b(0B00000000);

    //SE HACE EL BUCLE INFINITO PARA QUE EL PROGRAMA SE REPITA
    WHILE(TRUE){
        //SE ENCIENDE EL LED
        OUTPUT_HIGH(PIN_A0);
        //HAY UN RETARDO DE 1 SEG
        DELAY_MS(1000);
        //SE APAGA EL LED
        OUTPUT_LOW(PIN_A0);
        //HAY OTRO RETARDO DE 1 SEG
        DELAY_MS(1000);
    }
}