#include "tiemposdebusqueda.h"

////////////////////////////
void main()
{
	int tamano_inicial_lista=tamanoinicial;
	double tiemp_de_busqueda;
	
	int i=0,num=0,op=0;
	printf("ingrese opcion que desea realizar \n");
	printf("1: tomar tiempo busqueda secuencial \n");
	printf("2:tomar tiempo busqueda binaria \n");
	scanf("%d",&op);
	switch(op)
	{
		case 1: busqueda_secuencial(tamano_inicial_lista,tiemp_de_busqueda);
		case 2: busqueda_binaria(tamano_inicial_lista,tiemp_de_busqueda);
	 } 
	
}
