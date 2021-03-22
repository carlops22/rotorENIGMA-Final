#include<stdio.h>
#include<stdlib.h>
#include"rotores.h"
 /* Funcion main de la maquina des/encriptadora enigma
	Explicacion breve: Usa arreglos de rotores y rota usando funciones implementadas en rotores.c/rotores.h
	Programa final recibe 2 primeros argumentos: archivo a leer y archivo donde se escribira el mensaje encriptado
	
	Dado que el metodo de encriptacion es identico a desencriptar, 
	para desencriptar solo basta ingresar como archivo de lectura el mensaje encriptado y en segundo archivo 
 se obtendra archivo desencriptado.
 
 nota: para el correcto funcionamiento es necesario compilar main.c y rotores.c o linkear sus archivos objetos.
 (ej: gcc main.c rotores.c -o enigma.o)
 y tener el archivo lectura en la misma carpeta desde donde se ejecuta el programa enigma.
 
 
 
 */
int main(int argc, char **argv){
	/* Definicion arreglos de rotor y reflector iniciales */

	char rot1og[26]={'B','D','F','H','J','L','C','P','R','T','X','V','Z','N','Y','E','I','W','G','A','K','M','U','S','Q','O'};
	char rot2og[26]={'A','J','D','K','S','I','R','U','X','B','L','H','W','T','M','C','Q','G','Z','N','P','Y','F','V','O','E'};
	char rot3og[26]={'E','K','M','F','L','G','D','Q','V','Z','N','T','O','W','Y','H','X','U','S','P','A','I','B','R','C','J'};
	char reflector[26]={'Y','R','U','H','Q','S','L','D','P','X','N','G','O','K','M','I','E','B','F','Z','C','W','V','J','A','T'};
	
	/* Declaracion de caracter y stream de archivos de lectura y escritura */
	char c;
	FILE *read_txt=fopen(argv[1],"r"); 
	FILE *coded_txt=fopen(argv[2],"w"); 
	
	if(read_txt == NULL ) {
      perror("Error abriendo archivo de lectura");
      return(-1);
	}
	
	do{
		c=fgetc(read_txt); //recibe un caracter del primer archivo
		
		if( feof(read_txt)){ //evita bucle infinito, termina al leer/encriptar el primer archivo
		break;
		}
		
		if(c>='A' && c<='Z') //si esta entra A y Z encripta el caracter
		{
			c=encript(c,rot1og,rot2og,rot3og,reflector);  //funcion des/encriptadora (ver rotores.c)
			fputc(c,coded_txt); //se escribe el caracter des/encriptado en segundo archivo
		}
		
		else{
			fputc(c,coded_txt); //de todas maneras se escriben caracteres no encriptados
		}
		
	}while(1);
	//Cierre de archivos de lectura/escritura
	fclose(read_txt);
	fclose(coded_txt);
	return 1;
	
}
