#include <stdio.h>
#include <stdlib.h>
#include<time.h>


#define tamanoinicial 1000000
#define incremento 100000
#define tamano_final 100000000
struct timespec tInicio, tFin;


typedef struct lista
{
	int longitud;
	int cantidad_de_datos;
	int *array;
}Lista;
////////////////////////////
int tamano_inicial(int *tamano_inicial_lista)
{
	*tamano_inicial_lista=*tamano_inicial_lista+incremento;
	
	return *tamano_inicial_lista;
}
//////////////////////////7/
Lista *crear_lista(int tamano_inicial_lista)
{
	Lista *aux=malloc(sizeof(Lista));
	aux->cantidad_de_datos=0;
	aux->longitud=tamano_inicial_lista;
	aux->array=malloc(sizeof(int)*tamano_inicial_lista);
	return aux;	
}
////////////////////////////
Lista *lista_llena(Lista *lista_de_numeros,int tamano_inicial_lista)
{
	int i=0;
	Lista *aux;
	lista_de_numeros->cantidad_de_datos=tamano_inicial_lista;
	lista_de_numeros->longitud=tamano_inicial_lista;
	srand(time(NULL));
	while(i<lista_de_numeros->longitud)
	{
		lista_de_numeros->array[i]=rand()%(tamano_inicial_lista+1);
		i++;
	}
	return lista_de_numeros;
}
/////////////////////////////
void imprimir_lista(Lista *lista_de_numeros)
{
	int i=0;
	while(i<lista_de_numeros->longitud)
	{
		printf("%d ",lista_de_numeros->array[i]);
		i++;
	}
	printf("\n \n ");
}
//////////////////////////////
int eliminar_lista(Lista *lista_de_numeros)
{
	free(lista_de_numeros->array);
	free(lista_de_numeros);
//	printf("elementos eliminados\n");
	return 0;
}
//////////////////////////////
int buscar_ultimo_numero_secuencialmente(Lista *una_lista_numeros,int num)
{
	int i=0;

	while(i<una_lista_numeros->longitud)
	{
	    if(una_lista_numeros->array[i]==num)
	    {
	    //	printf("numero : %d encontrado, en la posición : %d \n ",num,i+1);
	    
	    	return (i+1);
		}
		i++;
	}
	printf("numero no encontrado\n");
	return 0;
	
}
/////////////////////////////
int insertar(Lista *lista_de_numeros)//funcion encargada de insertar numero al final de la lista
{
	int num= lista_de_numeros->longitud+5;
     lista_de_numeros->array[lista_de_numeros->longitud-1]=num;
	return num;
}
/////////////////////////////
int medir_tiempo(Lista *lista_de_numeros)//secuencial
{
	int num=0,i=0;
	int tiempo_de_busqueda,suma_de_busquedas=0,promedio_de_busquedas=0;
	while(i<40)
	{
		clock_gettime(CLOCK_REALTIME,&tInicio);	
	
			num=insertar(lista_de_numeros);
	
			buscar_ultimo_numero_secuencialmente(lista_de_numeros,num);
	clock_gettime(CLOCK_REALTIME,&tFin);
	tiempo_de_busqueda=(tFin.tv_nsec-tInicio.tv_nsec);
//	printf("tiempo de busqueda %d \n",tiempo_de_busqueda);system("pause");
		if(tiempo_de_busqueda>0)
		{
			suma_de_busquedas=suma_de_busquedas+tiempo_de_busqueda;
		}
		else
		{
			i--;
		}	
		i++;
	}	
	promedio_de_busquedas=suma_de_busquedas/40;
//	printf("tiempo de busqueda %d \n",promedio_de_busquedas);
	return promedio_de_busquedas;
}
////////////////////////////
int buscar_numero_en_ultima_posicion_binario(Lista *lista_de_numeros,int numero_a_buscar)
{
	int posicion_inferior=0,posicion_superior=lista_de_numeros->longitud-1,punto_medio=(posicion_inferior+posicion_superior)/2;
	while( posicion_inferior<=posicion_superior)//mientras posicion
	{
		punto_medio=(posicion_inferior+posicion_superior)/2;
	//	printf("posicion inferior %d posicion superior %d medio %d ",posicion_inferior,lista_de_numeros->longitud-1,punto_medio);//system("pause");

		if(lista_de_numeros->array[punto_medio]==numero_a_buscar)
		{

			return 1;//dato encontrado
		}
	    if(lista_de_numeros->array[punto_medio]>numero_a_buscar)
	    {
	    	posicion_superior=punto_medio-1;
	    	punto_medio=(posicion_superior+posicion_inferior)/2;
		}
		else
		{
			posicion_inferior=punto_medio+1;
			punto_medio=(posicion_superior+posicion_inferior)/2;		
	


		}
		
	}

	return 0;//dato no encontrado
}
////////////////////////////
 int medir_tiempo_busqueda_binaria(Lista *lista_de_numeros)//se recibira una lista ordenada y un numero a buscar
 {
 	int i=0,j=0,numero_a_buscar=0,tiempo_de_busqueda=0,suma_de_busquedas=0,promedio_de_busquedas=0;
 	while(i<10)//cantidad de repeticiones para obtener un promedio mas certero y con valores no tan erraticos
 	{
 	
 			clock_gettime(CLOCK_REALTIME,&tInicio);	
 				numero_a_buscar = insertar(lista_de_numeros);//se inserta numero en ultima posicion y se retorna valor de ese numero
 				while(j<1000000)//mientras no se tome la misma busqueda 1 millon de veces no se captura tiempo
 				{//esto se hace debido a que al crecer tan lentamente el tiempo  de busqueda de una busqueda binaria cuesta tomar el tiempo de una busqueda individualmente
 					
 					
 				buscar_numero_en_ultima_posicion_binario(lista_de_numeros,numero_a_buscar);j++;
				}
 		j=0;
 			clock_gettime(CLOCK_REALTIME,&tFin);
 			tiempo_de_busqueda=(tFin.tv_nsec-tInicio.tv_nsec);
 			tiempo_de_busqueda=tiempo_de_busqueda/1000000;
 		//	printf("promedio : %d \n , tiempo de busqueda %d  tiempo_de_busqueda %d \n",promedio_de_busquedas,promedio_de_busquedas,tiempo_de_busqueda);
 		//	system("pause");
 		if(tiempo_de_busqueda>0)
		{
			suma_de_busquedas=suma_de_busquedas+tiempo_de_busqueda;
			
		}
		else
		{
			i--;
		}		
			 		i++;
	}
	promedio_de_busquedas=suma_de_busquedas/10;
	return promedio_de_busquedas;
 }
 ///////////////////////////////////////
 int comparar_enteros(const void *p, const void *q)
 {
 	int x,y;
 	x= *(int *) p;
 	y= *(int *)q;
 	if(x>y) return -1;
 	if(x==y) return 0;
 	return -1;
 	
 }
////////////////////////////
void crear_archivo(int dato)
{
	FILE *op;
	 op=fopen("tiempo_de_busqueda_binaria.txt","a");
	if(op==NULL)
	{
		printf("error al crear archivo\n");
	}
	else
	{
		fprintf(op,"%d,",dato);
		printf("archivo creado correctamente\n");
	}
	fclose(op);
}
////////////////////////////////////////////////
Lista *lista_ordenada_de_numeros(Lista *lista_de_numeros, int tamano_inicial)
{
	lista_de_numeros->cantidad_de_datos=tamano_inicial;
	lista_de_numeros->longitud=tamano_inicial;

	int i=0,num=0;
//	srand(time(NULL));
//	rand()%(tamano_inicial*5)+20;
	while(i<lista_de_numeros->longitud)//meintras no se recorra la lista de numeros completa se hara esto 
	{
		lista_de_numeros->array[i]=i;//se le asigna a cada posicion el valor de la posicion que le corresponde , asi los numeros estan ordenados de menor a mayor
		
		i++;
	}
	return lista_de_numeros;
}
////////////////////////////
void main()
{
	int tamano_inicial_lista=tamanoinicial;
	double tiemp_de_busqueda;
	
	int i=0,num=0;
	while(i<1000)//cantidad de datos necesarios para generar el grafico, mientras no se obtenga 1000 entramos en el ciclo
	{
		Lista *lista_de_numeros;
		lista_de_numeros=crear_lista(tamano_inicial_lista);
		lista_de_numeros=lista_llena(lista_de_numeros,tamano_inicial_lista);//se usa en secuencial
	//	imprimir_lista(lista_de_numeros);
	//	lista_de_numeros=lista_ordenada_de_numeros(lista_de_numeros,tamano_inicial_lista);//se usa en binaria
	//	tiemp_de_busqueda=medir_tiempo_busqueda_binaria(lista_de_numeros);
	 //   qsort(lista_de_numeros->array,tamano_inicial_lista,sizeof(int),&comparar_enteros);
//	imprimir_lista(lista_de_numeros);system("pause");
		tiemp_de_busqueda=medir_tiempo(lista_de_numeros);//se usa en medir tiempo de busqueda secuencial
			
			eliminar_lista(lista_de_numeros);
	//	
		tamano_inicial(&tamano_inicial_lista);
		printf("tamaño inicial lista \n :%d \n",tamano_inicial_lista);
		// system("pause");
		 crear_archivo(tiemp_de_busqueda);
		 printf("i:%d \n",i);
		i++;
	}
	
}
