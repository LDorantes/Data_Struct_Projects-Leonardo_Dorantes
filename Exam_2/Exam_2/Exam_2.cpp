// Exam_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LQueue.h"
#include "LStack.h"
#include "Triague.h"

int main()
{
    std::cout << "Hello Professor!\n";
    std::cout << "Examen segundo parcial \n";
    // Parte de la clase LQueue
    LQueue<int> myQueue;

    myQueue.Enqueue(10);
    myQueue.Enqueue(20);
    myQueue.Enqueue(30);
    std::cout << "\n Enqueue Function \n";
    std::cout << "Añade elementos al inicio de de la Queue, en este caso 10,20,30 \n ";
    myQueue.PrintQueue();
    std::cout << "Dequeue Function \n";
    std::cout << " Quita el elemento al inicio de la Queue \n";
    myQueue.Dequeue();
    myQueue.PrintQueue();  
    std::cout << "Front: " << myQueue.front() << std::endl;
    std::cout << "Back: " << myQueue.back() << std::endl;
   


    std::cout << "Queue elements: ";
    myQueue.PrintQueue();

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
