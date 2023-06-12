#include "Array.h"
#include <iostream>


//Constructor de la clase: el prametro "in_Size" se utiliza para determinar el tamano del array dinamico "InitialElement". 
//"New init " funciona para asignar la memoria "Size" que utilizara el arreglo
RawArray::RawArray(int in_Size) : Size(in_Size)
{
	InitialElement = new int[Size];

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

	//flag Es un indicador que usaremos para indicar si se realizo algun reemplazo 

	bool flag = false;

	for (int i = 0; i < Size; i++)
	{
		if (*auxPosition == X)
		{
			*auxPosition = Y;

			// Si Existe algun numero que deba ser sustituido, la bandera cambiara de estado a true
			flag = true;
		}
		auxPosition++;
	}

	// Si la bandera es true le deja saber al usuario que hubo un cambio, de lo contrario le hara saber que no habin cambios que realizar. 
	if (flag)
	{
		std::cout << " \nSe realizo el reemplazo de " << X << " por " << Y << std::endl;
	}
	else
	{
		std::cout << " \nNo se encontro ningun valor igual a " << X << ". No se realizo ningun cambio." << std::endl;
	}
}


void RawArray::TestCaseReplace(int Values)
{

	int* auxPosition = InitialElement;

	//Utilizamos el for para rrecorrer los elementos del arreglo y asignarles el valor "InitialValue"
	for (int i = 0; i < Size; i++)
	{
		*auxPosition = Values++;

		auxPosition++;
	}
}


// A PARTIR DE AQUI SE CONSTRUYERON LAS FUNCIONES PARA REALIZAR EL EXAMEN.

//Asignar valor V a uno de cada X elementos del RawArray, donde X y V son un entero.
void RawArray::AssignEveryXElements(int v, int x)
{
	int* auxPosition = InitialElement;
	int counter = 1;

	bool flag = false;

	for (int i = 0; i < Size; i++)
	{
		if (counter == x)
		{
			*auxPosition = v;
			counter = 1;

			flag = true;
		}
		else
		{
			counter++;
		}
		auxPosition++;
	}


	if (flag)
	{
		std::cout << " \nSe realizo el remplazo del valor original en cada " << x << " casillas por el valor de " << v << std::endl;
	}
	else
	{
		std::cout << "No se encontro ningun valor igual a " << x << ". No se realizo ningun cambio." << std::endl;
	}
}


//Ordena los elementos del RawArray de menor a mayor
void RawArray::SortFunction()
{
	int* auxPosition = InitialElement;

	bool flag = true;

	for (int i = 0; i < Size - 1; i++)
	{
		for (int j = 0; j < Size - 1; j++)
		{
			//Se hace una comparativa entre cada componente del arreglo para determinar cual es el mayor 
			if (InitialElement[j] > InitialElement[j + 1])
			{
				// se actualiza la variable auxiliar de acuerdo al valor que sea menor.
				int aux = InitialElement[j];
				InitialElement[j] = InitialElement[j + 1];
				InitialElement[j + 1] = aux;
			}
		}
	}
 
	if (flag)
	{
		std::cout << " \nSe realizo un ordenamiendo burbuja al array, ahora estan acomodados de menor a mayor  \n";
	}
}

//Añade al RawArray "A" todos los elementos del RawArray "B", Manteniendo los elementos de "A" al principio y despues agregando los elementos de "B"
void RawArray::AppendArray(RawArray& arrayToAppend)
{
	int* auxPointer = InitialElement;
	InitialElement = new int[Size + arrayToAppend.Size];

	// Copiar los elementos de myArray al nuevo arreglo
	for (int i = 0; i < Size; i++)
	{
		InitialElement[i] = auxPointer[i];
	}

	// Copiar los elementos de arrayToAppend al nuevo arreglo
	for (int i = 0; i < arrayToAppend.Size; i++)
	{
		InitialElement[Size + i] = arrayToAppend.InitialElement[i];
	}

	Size = Size + arrayToAppend.Size;
	// Liberar la memoria del objeto actual
	delete[] auxPointer;
	// Liberar la memoria del objeto arrayToAppend
}


//Modifica el tamaño del RawArray para igualar el numero de elementos de newSize. 
//Si newSize es mayor al Size actual del RawArray, Conserva el total de sus Size_elementos 
//Si newSize es menor al Size actual del RawArray; conserva los primeros elementos hasta newSize 

void RawArray::SetSize(int newSize)
{
// Crear un nuevo arreglo con el tamaño especificado
	int* newArray = new int[newSize];

	// Copiar los elementos del arreglo actual al nuevo arreglo
	int copies = std::min(Size, newSize);
	//La función std::min(X,Y) es una función de C++ que devuelve el valor mínimo entre dos valores, X y Y. 
	//https://barcelonageeks.com/std-min-en-c/ 
	//En el contexto, es para determinar la cantidad de elementos que se copiarán del arreglo original al nuevo arreglo.
	for (int i = 0; i < copies; i++)
	{
		newArray[i] = InitialElement[i];
	}

	// Si el nuevo tamaño es mayor que el tamaño actual, inicializar los elementos adicionales en 0
	if (newSize > Size)
	{
		for (int i = Size; i < newSize; i++)
		{
			newArray[i] = 0;
		}
	}

	// Liberar la memoria del arreglo actual
	delete[] InitialElement;

	// Asignar el nuevo arreglo y actualizar el tamaño
	InitialElement = newArray;
	Size = newSize;
}

//Añade los arrayToInsert.Size-elementos al RawArray que llamó la función Insert, a partir del elemento en startIndex.
void RawArray::Insert(RawArray& arrayToInsert, int startIndex)
{
// Obtener el tamaño del RawArray actual y el RawArray a insertar
	int currentSize = Size;
	int insertSize = arrayToInsert.Size;

	// Calcula el nuevo tamaño del RawArray después de la inserción
	int newSize = currentSize + insertSize;

	// Crea un nuevo RawArray con el nuevo tamaño
	int* newArray = new int[newSize];

	// Copia los elementos del RawArray actual hasta el índice 
	for (int i = 0; i < startIndex; i++) {
		newArray[i] = InitialElement[i];
	}

	// Copiar los elementos del RawArray a insert
	for (int i = 0; i < insertSize; i++) {
		newArray[startIndex + i] = arrayToInsert.InitialElement[i];
	}

	// Copiar los elementos restantes del RawArray actual
	for (int i = startIndex; i < currentSize; i++) {
		newArray[insertSize + i] = InitialElement[i];
	}

	
	delete[] InitialElement;

	// Actualizar el tamaño, el puntero y los elementos del RawArray actual
	Size = newSize;
	InitialElement = newArray;

	// Actualizar el tamaño y los elementos del RawArray a insertar
	arrayToInsert.Size = 0;
	delete[] arrayToInsert.InitialElement;
	arrayToInsert.InitialElement = nullptr;
}

//Suma elemento por elemento los valores del Array "A" con los valores del array "B". 
//A y B tienen el mismo Size. 
//Retorna un RawArray distinto de A y B con los resultados de la suma.
void RawArray::SumArrays(RawArray& A)
{
	for (int i = 0; i < Size; i++)
	{
		InitialElement[i] = InitialElement[i] + A.InitialElement[i];
	}
}

//Recibe un valor X, si encuentra un elemento con dicho valor dentro del RawArray, regresa la posición de dicho elemento.
//Si no encuentra el valor X dentro del RawArray, regresa -1.
int RawArray::GetIndexOf(int x)
{
	int* auxPosition = InitialElement;

	for (int i = 0; i < Size; i++)
	{
		if (*auxPosition == x)
		{
			 return i;  // Se encontró el elemento, se devuelve su posición

		}

		auxPosition++;
	}


	return -1;  // No se encontró el elemento, se devuelve -1auxPosition++;
}

//Regresar la posición del último elemento del RawArray con el valor X dado. 
//Si no encuentra ningun elemento con valor x, regresar -1.
int RawArray::GetLastOf(int x)
{
	int* auxPosition = InitialElement;
	int lastPosition = -1;

	for (int i = 0; i < Size; i++)
	{
		if (*auxPosition == x)
		{
			lastPosition = i;  // Actualizar la última posición encontrada
		}

		auxPosition++;
	}

	if (lastPosition == -1)
	{
		std::cout << " \n No se encontro ninguna posicion con valor " << x << std::endl;
	}
	else
	{
		std::cout << "La posicion del elemento elegido es: " << lastPosition << std::endl;
	}


	return lastPosition;
}

//Recibe un valor X; regresa el indice de todos los elementos con valor X
//Si no encuentra ningun elemento condicho valor, regresa un array cuyo primer y único elemento es -1.
RawArray RawArray::GetIndicesOf(int x)
{
	int cont = 0; 

	// establecemos la cantidad de elementos encontrados en el array. 

	for(int i = 0; i < Size; i++)
	{
		if (InitialElement[i] == x)
		{
			cont++;
		}

	}

	RawArray indices(cont); // Crea un objeto RawArray de tamaño Size para almacenar los índices

	int* auxPosition = InitialElement;
	int currentIndex = 0;

	for (int i = 0; i < Size; i++)
	{
		if (*auxPosition == x)
		{
			indices.InitialElement[currentIndex] = i; // Guarda el índice en el objeto indices
			currentIndex++;
		}
		auxPosition++;
	}

	indices.Size = currentIndex; // Actualiza el Size del objeto indices al numero de indices encontrados
	indices.Print(); // Imprime el objeto indices

	if (currentIndex > 0)
	{
		std::cout << "Se encontraron coincidencias del valor " << x << " en las casillas marcadas.\n";
	}
	else
	{
		std::cout << "No se encontró ninguna coincidencia del valor " << x << " en el arreglo.\n";
	}

	return indices;

}
