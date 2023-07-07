// ListProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "List.h"

int main()
{
   // List<char> myList = List<char>();
   // myList.PushBack('a');
    //myList.GetByValue('a');
    //myList.PopFront();
    //////////
    //Parte Tarea
 
    //Constructor list
    std::cout << "Constructor list \n";
    const int arraySize = 10;
    int myArray[arraySize] = { 1, 1, 4, 3, 4, 5, 7, 9, 7, 0 };
    List<int> myList = List<int>(myArray, arraySize);

    myList.Print(); 
   // Imprime: 1, 3, 5, 7, 9
   // 
    //Reverse Function
    std::cout << "Reverse Function \n";
    myList.Reverse(); 

    myList.Print(); 

    // Unique Function
    std::cout << "Unique Function \n";
    myList.Unique();

    myList.Print();
    // Imprime: 1, 2, 3, 4
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
