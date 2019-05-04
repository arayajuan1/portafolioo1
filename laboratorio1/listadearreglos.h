#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct lista
{
	int *arreglo;
	int cantidad_datos_actuales;
	int longitud_maxima;
}Lista;
		
/////////////////////////////
Lista *crear_lista_vacia(int tam)
{
	Lista *aux=malloc(sizeof(Lista) );
	aux->cantidad_datos_actuales=0;
	aux->longitud_maxima=tam;
	aux->arreglo=malloc(sizeof(int)*tam);
	return aux;
}
//////////////////////////////
Lista *lista_llena(int tam,int max)
{
	int i=0;
	Lista *aux=malloc(sizeof(Lista) );
	aux->cantidad_datos_actuales=tam;
	aux->longitud_maxima=tam;
	aux->arreglo=malloc(sizeof(int)*tam);
	srand(time(NULL));
	for( i=0;i<tam;i++)
	{
		aux->arreglo[i]=rand()%(max+1);
	}
	return aux;
}
///////////////////////////////////
void imprimir(Lista *unaListaNumeros)
{
	int i = 0;
	for(i = 0;i < unaListaNumeros->cantidad_datos_actuales;i++)
	{
		printf("%i ",unaListaNumeros->arreglo[i]);
	}

}
///////////////////////////////////
void  eliminaLista(Lista *unaListaNumeros)
{
		free(unaListaNumeros->arreglo);
		free(unaListaNumeros);
}
////////////////////////////////////////////
int buscar_numero_en_lista_numeros(int un_numero,Lista *unaListaNumeros)
{
	int i = 0;
	//Lista *aux=malloc(sizeof(Lista) )
	while(i<(unaListaNumeros->cantidad_datos_actuales))
	{
		if(unaListaNumeros->arreglo[i]==un_numero)
		{
			return (i+1);
		}
		i++;	
	}
	return -1;
}
