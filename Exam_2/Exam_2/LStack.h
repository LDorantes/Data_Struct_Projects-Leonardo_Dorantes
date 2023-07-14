#pragma once
#include "ListE.h"
#include <iostream>
// if not defined -> si no está definido
#ifndef LSTACK
#define LSTACK


template <typename T>
class LStack
{	//List<T> data; // es la única variable que tiene que tener dentro.
private:
	List<T> data; // Utilizamos la clase List como base para almacenar los elementos de la stack

public:
    void Push(T value)
    {
        data.PushBack(value); // Agrega el elemento al final de la lista (tope de la stack)
    }

    void Pop()
    {
        data.PopBack(); // Elimina el ultimo elemento de la lista (tope de la stack)
    }

    T Top()
    {
        return data.GetByIndex(0)->data; // Obtiene el ultimo elemento de la lista (tope de la stack)
    }

    void PrintStack()
    {
        data.Print(); // Utilizamos la función Print de la clase List para imprimir los elementos de la lista
    }

};

#endif // !LSTACK

