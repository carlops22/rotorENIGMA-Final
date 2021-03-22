#include <stdio.h>
#include"rotores.h"
/* Codigo fuente de funciones utilizadas para la des/encriptacion de las letras   */

void rotateByOne(char arr[],int n) //arg: arreglo a rotar, tamaño del arreglo
{
    int i, last;

    /* Almacena el ultimo elemento del arreglo */
    last = arr[n - 1];

    for(i=n-1; i>0; i--)
    {
        /* Mueve cada elemento a la derecha */
        arr[i] = arr[i - 1];
    }

    /* Guarda el ultimo elemento al primero */
    arr[0] = last;
}
//transforma el numero de char a indice del arreglo de alfabeto (A es indice 0, Z indice 25)
int findchar(char c){ 
	return c-65; //util solo para caracteres entre A y Z
}

/* Busca caracter en posiciones de un arreglo alfabeto(tamaño 26)*/
int findindex(char c,char arr[]){ 
	for(int i=0; i<26;i++){
		if(c==arr[i])
			return i; //retorna indice de caracter encontrado
	}
}

/* Funcion principal para encriptar/desencriptar, como argumentos
 recibe la letra a des/encriptar, arreglo rotor1, arreglo rotor2, arreglo rotor3 y arreglo reflector
 y retorna el caracter des/encriptado
 */
char encript(char let,char rot1[],char rot2[], char rot3[],char refl[]){ 
	// valores estaticos para mantener la cuenta de giro de rotor
	static int  r2count=0, r3count=0; 
	
	/*Parte 1: Obtiene el caracter del rotor/reflector en la misma posicion del arreglo alfabeto  */
	let=rot1[findchar(let)];
	let=rot2[findchar(let)];
	let=rot3[findchar(let)];
	let=refl[findchar(let)];

    /* Parte 2: Busca indice del caracter en rotores y se le suma 65 para transformarlo
     a una letra del alfabeto mayuscula ( A-Z en ASCII: 65-90)	*/
	let=findindex(let,rot3)+65;
	let=findindex(let,rot2)+65;
	let=findindex(let,rot1)+65;
	
	
	// Una vez des/encriptado se rota 1 vez el rotor 3 y se aumenta el contador de rotaciones de rot3
	rotateByOne(rot3,26);
	r3count++;
	
	
	// Si ha rotado 26 veces el rotor 3, se resetea el contador y se rota 1 vez el rotor 2 
	if(r3count==26)
	{	
		rotateByOne(rot2,26);
		r3count=0;
		r2count++;
	}
	// Si ha rotado 26 veces el rotor 2, se resetea el contador y se rota 1 vez el rotor 1
	if(r2count==26)
	{
		rotateByOne(rot1,26);
		r2count=0;
	}
	return let; 
}