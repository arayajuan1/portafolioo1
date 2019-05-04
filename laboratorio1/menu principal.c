#include "listadearreglos.h" 

int main()
{
	///////////////////////////////////////lista vacia
	int numero_maximo_de_arreglo=0,tamano_arreglo=0,numero_a_buscar,indice_de_numero_encontrado;
//	printf("escriba el tamaño del arreglo que desea\n");
//	scanf("%i",&tam);
	Lista *milista;
	milista=crear_lista_vacia(tamano_arreglo);
	eliminaLista(milista);
	///////////////////////////////////////lista lleno 
	printf("escriba tamaño del arreglo\n ");
	scanf("%i",&tamano_arreglo);
	printf("escriba tamaño el numero mas grande que quiere que le salga en el arreglo\n ");
	scanf("%i",&numero_maximo_de_arreglo);
	milista=lista_llena(tamano_arreglo,numero_maximo_de_arreglo);
	imprimir(milista);
	printf("ingrese numero a buscar\n");
	scanf("%i",&numero_a_buscar);
	indice_de_numero_encontrado = buscar_numero_en_lista_numeros(numero_a_buscar,milista);
	if(indice_de_numero_encontrado==-1)
	{
		printf("lo sentimos numero no encontrado\n");
	}
	else
	{
		printf("numero_a_buscar: %i\n",indice_de_numero_encontrado);
	}
	eliminaLista(milista);
	return 0;
}
