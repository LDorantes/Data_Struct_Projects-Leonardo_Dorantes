// Array.h La extension de este archivo (header file) indica que es aqui donde se contenen las funciones y clases.  
#pragma once

// Aqui se esta declarando una clase "RawArray" que representa un arreglo de enteros, en este caso, de tamano variable 
class RawArray

{
	// public indica que los miembros (funciones y atributos) dentro de public son accesibles desde cualquier parte del programa.  
public:

	//Este es el constructor de la clase. tiene un parametro "in_Size" el cual indica el tamano del arreglo.
	//Se utilizara para asignar memoria dinamica para el arreglo.	
	RawArray(int in_Size);

	//Este es el destructor de la clase. Se utiliza para liberar la memoria dinamica asignada al arreglo anteriormente. 
	~RawArray();

	//Es una funcion que se encarga de iniciarizar todos los elementos del arreglo. 
	//El parametro InitialValue funciona para indicar el valor deseado para inicializar los elementos.  
	void Initial(int InitialValue = 0);

	//Su funcion es imprimir en la consola todos los elementos del arreglo. 
	void Print();
	//Su funcion es buscar en un arreglo todos los elementos con valor X y remplazarlos por Y. 
	void Replace(int X, int Y);

	//Funciones para el examen

	void AssignEveryXElements(int v, int x);

	void SortFunction();

	void AppendArray(RawArray& arrayToAppend);

	void SetSize(int newSize);

	void Insert(RawArray& arrayToInsert, int startIndex);

	void SumArrays(RawArray& A);

	int GetIndexOf(int x);

	int GetLastOf(int x);

	RawArray GetIndicesOf(int x);

	void TestCaseReplace(int Values);

	void DeleteMemory();

	//Es un puntero que apunta a la primera posicion del arreglo. Sirve como referencia 
	int* InitialElement;

	// Este atributo indica el tamano del arreglo. 
	int Size;
	int newSize;

};

