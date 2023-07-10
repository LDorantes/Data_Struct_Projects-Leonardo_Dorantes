#pragma once
#include "ListE.h"
#include <iostream>
// if not defined -> si no está definido
#ifndef LQUEUE 
#define LQUEUE


template <typename T>
class LQueue
{
private:
    List<T> data; // Usamos la clase List en lugar de std::list

public:
   
    void Enqueue(T value)
    {
        data.PushBack(value); // Utilizamos la función PushBack de la clase List para agregar el elemento al final de la lista
    }

    void Dequeue()
    {
        data.PopFront(); // Utilizamos la función PopFront de la clase List para eliminar el primer elemento de la lista
    }

    T front()
    {
        return data.GetByIndex(0)->data; // Utilizamos la función GetByIndex de la clase List para obtener el primer elemento de la lista
    }

    T back()
    {
        return data.GetByIndex(data.GetSize() - 1)->data; // Utilizamos la función GetByIndex de la clase List para obtener el último elemento de la lista
    }

    void PrintQueue()
    {
        data.Print(); // Utilizamos la función Print de la clase List para imprimir los elementos de la lista
    }

};
#endif // LQUEUE

