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
    
    // FrontEnqueue 

    std::cout << "\n FrontEnqueue \n";
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

    // Funsión BackDequeue
    // 
    // 
  
    std::cout << "\nFunsión BackDequeue\n";
    // Ejecutar otros métodos y operaciones en la Deque

    // Imprimir la Deque antes de BackDequeue
    std::cout << "Deque antes de BackDequeue: ";
    myDeque.PrintDeque();

    // Utilizar BackDequeue() para quitar el último elemento de la Deque
    myDeque.BackDequeue();

    // Imprimir la Deque después de BackDequeue
    std::cout << "Deque después de BackDequeue: ";
    myDeque.PrintDeque();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
