// Queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Deque.h"
#include "queue.h"

int main()
{
    queue<char> MyQueue = queue<char>(6);
    MyQueue.Enqueue('a');
    MyQueue.Enqueue('b');
    MyQueue.Enqueue('c');
    MyQueue.Enqueue('d');
    MyQueue.Enqueue('e');
    MyQueue.Enqueue('f');

    MyQueue.Print(); 

    if (MyQueue.Full() == true)
    {
        std::cout << "La Queue está llena." << '\n';
    }

    MyQueue.Dequeue();
    MyQueue.Print();

    MyQueue.Enqueue('g');
    MyQueue.Enqueue('h');

    if (MyQueue.Full() == true)
    {
        std::cout << "La Queue está llena de nuevo." << '\n';
    }

    MyQueue.Print();

    //parte de la tarea //////////////////////////////////////////
    
    // FrontEnqueue Function 
    //
    //

    std::cout << "\n FrontEnqueue Function  \n";
    // Creamos una instancia de Deque<char>
    Deque<char> myDeque(5);

    // Agregar elementos a la cola
    myDeque.EnqueueBack('a');
    myDeque.EnqueueBack('b');
    myDeque.EnqueueBack('c');
    myDeque.EnqueueBack('d');
    myDeque.EnqueueBack('e');

    // Imprimir la cola antes de FrontEnqueue
    std::cout << "Cola antes de FrontEnqueue: ";
    myDeque.PrintDeque();
    std::cout << std::endl;

    // Agregar elementos al frente de la cola usando FrontEnqueue
    myDeque.FrontEnqueue('e');
    myDeque.FrontEnqueue('f');
    

    // Imprimir la cola después de FrontEnqueue
    std::cout << "Cola después de FrontEnqueue: ";
    myDeque.PrintDeque();
    std::cout << std::endl;

    // BackDequeue Funsión 
    // 
    // 
  
    std::cout << "\nBackDequeue Function \n";
    // Ejecutar otros métodos y operaciones en la Deque

    // Imprimir la Deque antes de BackDequeue
    std::cout << "Deque antes de BackDequeue: ";
    myDeque.PrintDeque();

    // Utilizar BackDequeue() para quitar el último elemento de la Deque
    myDeque.BackDequeue();

    // Imprimir la Deque después de BackDequeue
    std::cout << "Deque después de BackDequeue: ";
    myDeque.PrintDeque();

    //T Front function 
    //
    //
    // 
    std::cout << "\nT Front Function \n";
    // Imprimir la cola antes de Front()
    std::cout << "Cola antes de Front(): ";
    myDeque.PrintDeque(); 

    // Obtener el elemento en el frente de la cola usando Front()
    if (!myDeque.Empty())
    {
        char frontElement = myDeque.Front();
        std::cout << "Elemento en el frente de la cola: " << frontElement << std::endl;
    }
    else
    {
        std::cout << "La cola está vacía" << std::endl;
    }

    // T Back function 
    //
    //
    std::cout << "\nT Back Function\n";
    // Utilizamos la función Back() para obtener el elemento al final de la Queue
    std::cout << "Cola antes de Back(): ";
    myDeque.PrintDeque(); 
    char backElement = myDeque.Back();
    std::cout << "Elemento al final de la Queue: " << backElement << std::endl;


    return 0;
}

