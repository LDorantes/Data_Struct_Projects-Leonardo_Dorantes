#include "Array.h"
#include <iostream>


//Constructor de la clase: el prametro "in_Size" se utiliza para determinar el tamano del array dinamico "InitialElement". 
//"New init " funciona para asignar la memoria "Size" que utilizara el arreglo
RawArray::RawArray(int in_Size) : Size(in_Size)
{
	InitialElement = new int[Size];

	// just added 

	InitialElement[0] = 1;
	InitialElement[1] = 5;
	InitialElement[2] = 9;
	InitialElement[3] = 0;
	InitialElement[4] = 1;
	InitialElement[5] = 5;


	// Restriccion del tamano del arreglo. 
	if (Size > 6)
	{
		std::cout << "Advertencia: El tamaÃ±o especificado es mayor que el nÃºmero de valores asignados. "\
			"Los valores restantes se inicializarÃ¡n a 0." << std::endl;



		// Inicializar los valores restantes en 0
		for (int i = 6; i < Size; i++)
		{
			InitialElement[i] = 0;
		}
	}
	else if  (Size < 6) {
        std::cout << "Error: El tamaño especificado es menor que el tamaño mínimo requerido (6)." << std::endl;
        Size = 6;
		for (int i = 6; i < Size; i++)
		{
			InitialElement[i] = 0;
		}
    }



		//Destructor de la clase. Se encarga de liberar la memoria asignada  dinamicamente apra el arreglo.
		RawArray::~RawArray()
		{
			std::cout << "Entrada destructor de RawArray" << '\n';
			delete[] InitialElement;
			std::cout << "Salida destructor" << '\n';
		}

			

		
	//Esta funcion se utiliza para inicializar todos los elementos del arreglo con un valor inicial. 
	//InitialValue representa el valor con el que se desea inicializar los elementos. 
	void RawArray::Initial(int InitialValue)
	{

		int* auxPosition = InitialElement;

		//Utilizamos el for para rrecorrer los elementos del arreglo y asignarles el valor "InitialValue"
		for (int i = 0; i < Size; i++)
		{
			*auxPosition = InitialValue;

			auxPosition++;
		}
	}
	//Esta funcion se utiliza para imprimir en la consola todos los valores de los elementos del arreglo.
	void RawArray::Print()
	{
		int* auxPosition = InitialElement;

		for (int i = 0; i < Size; i++)
		{
			std::cout << *auxPosition << ", ";

			auxPosition++;
		}
		std::cout << '\n';
	}

	//Utiliza un puntero auxPosition para recorrer los elementos del arreglo y compara el valor del contenido de cada espacio de memoria con utilizando el operador *. 
	//Si el valor X coincide, asigna Y al elemento mediante el operador de referencia *.
	//Luego, incrementa el puntero auxPosition para avanzar al siguiente elemento y realizar la misma accion.

	void RawArray::Replace(int X, int Y)
	{
		int* auxPosition = InitialElement;
		for (int i = 0; i < Size; i++)
		{
			if (*auxPosition == X)
			{
				*auxPosition = Y;
			}
			auxPosition++;
		}
	}
