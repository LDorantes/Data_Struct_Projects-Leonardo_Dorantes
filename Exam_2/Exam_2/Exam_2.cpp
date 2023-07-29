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

    triage.AddPatient("Leonardo", 1);
    triage.AddPatient("Brandon", 5);
    triage.AddPatient("Jose", 3);
    triage.AddPatient("Ana", 2);
    triage.AddPatient("Dafne", 1);
    triage.AddPatient("Morgan", 4);
    triage.AddPatient("Diego", 5);
    triage.AddPatient("Camila", 1);

    triage.Print(); 
    std::cout << "\nPasPatient (4) applied\n ";
    
    triage.PassPatient(); 
    triage.PassPatient(); 
    triage.PassPatient();
    triage.PassPatient(); 
    std::cout << "\n ";
    triage.Print(); 


   /*
    Para almacenar los pacientes y sus niveles de urgencia,
    Decidimos usar una estructura de tipo QUEUE (priority queue).
    Esto ya que nos permite que los elementos se ordenen automáticamente según su prioridad,
    en este caso, el nivel de urgencia. Cada vez que se atienda a un paciente, 
    y así el siguiente en la cola de prioridad será el paciente con el nivel de urgencia más bajo.

    Para almacenar los nombres de los pacientes,utilizamos una 
    estructura de tipo LIST para almacenar los nombres de los pacientes. 
    Que nos permite agregar elementos al final de la lista de manera eficiente
    y mantener un orden  de los pacientes atendidos.

    CORRECION: 
    sE SUSTITUYO lIST POR LQueue dado es una estructura de datos disenada para implementar una cola 
    LQueue tiene una complejiadad O(1) lo cual mejora nuestro rendimiento 
    Al tener una complejidad constante, no importa cuantos pacientes haya en la cola
    el tiempo de ejecución para agregar o eliminar un paciente siempre sera el mismo.
   */

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
