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
    std::cout << "\nLQueue Class\n";

    myQueue.Enqueue(10);
    myQueue.Enqueue(20);
    myQueue.Enqueue(30);
    std::cout << "\n Enqueue Function \n";
    std::cout << "añade el elemento 'value' hasta el final de la Queue., en este caso 10,20,30 \n ";
    myQueue.PrintQueue();
    std::cout << "Dequeue Function \n";
    std::cout << " Quita el elemento al inicio de la Queue \n";
    myQueue.Dequeue();
    myQueue.PrintQueue();  
    myQueue.Enqueue(10);
    myQueue.PrintQueue(); 
    std::cout << "Front: " << myQueue.front() << std::endl;
    std::cout << "Back: " << myQueue.back() << std::endl;
   


    std::cout << "Queue elements: ";
    myQueue.PrintQueue();

    // Parte de la clase LStack
    LStack<int> myStack;
    std::cout << "\n LStack Class\n ";

    myStack.Push(5);
    myStack.Push(10);
    myStack.Push(15);
    myStack.Push(15);
    std::cout << "\nElementos en el stack:\n ";
    myStack.PrintStack();
    std::cout << "Top: " << myStack.Top() << std::endl;
    myStack.PrintStack();
    std::cout << "\nPop Function\n";
    std::cout << "Quita el elemento del tope de la Stack \n";
    myStack.Pop();
    myStack.PrintStack();
    std::cout << "Top: " << myStack.Top() << std::endl;
    myStack.Pop();
    std::cout << "\nPop Function \n";
    std::cout << "Quita el elemento del tope de la Stack \n";
    myStack.PrintStack();
    std::cout << "Top: " << myStack.Top() << std::endl;
    myStack.Pop();
    std::cout << "\nPop Function \n";
    std::cout << "Quita el elemento del tope de la Stack \n";
    myStack.PrintStack();
    std::cout << "Top: " << myStack.Top() << std::endl;
    myStack.PrintStack();

    //Parte de la clase Triague
    Triage triage;
    std::cout << "\n Triage Class \n";

    triage.AddPatient("Pablo", 1);
    triage.AddPatient("Maria", 5);
    triage.AddPatient("Luis", 3);
    triage.AddPatient("Pancho", 2);
    triage.AddPatient("Juan", 1);
    triage.AddPatient("Pepe", 4);
    triage.AddPatient("Ana", 5);
    triage.AddPatient("Pedro", 1);

   
    triage.Print(); 
    triage.PassPatient(); 
    triage.PassPatient(); 
    triage.PassPatient();
    triage.PassPatient(); 
    std::cout << "\n ";
    triage.Print(); 


    // Debe imprimir lo siguiente:
    // 1-> Juan, Pedro
    // 2->
    // 3-> Luis
    // 4-> Pepe
    // 5-> Maria, Ana

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
