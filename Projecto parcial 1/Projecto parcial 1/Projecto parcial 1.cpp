// Projecto parcial 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Array.h"
#include "Array.cpp"


#define MY_NULL 0 

int main()
{
// Para la realizacion no se incluyo una restriccion en el codigo si se intenta ingresar valores distintos de int debido a que no se considero necesario
// Pues esta restriccion se encuentra implicita en la declaracion del RawArray el cual unicamente recibe valores int.
    std::cout << "Hello Everyone\n";


    RawArray myArray(10);

    myArray.TestCaseReplace(1);
 
    std::cout << " \nArray Original: \n";

    myArray.Print(); 

    myArray.Replace(9, 0);

    std::cout << " \nArray Modificado: \n"; 

    myArray.Print();
    
    //APARTADO PARA EL EXAMEN 

    //AssignEveryXElements
    std::cout << "\nApartado examen \n";
    std::cout << "Funcion AssignEveryXElements \n";
    std::cout << " \nArray Original: \n";
    myArray.Print();
    myArray.AssignEveryXElements(5, 2);
    std::cout << " \nArray Modificado: \n";
    myArray.Print();

    //SortFunction
    std::cout << "\nSortFunction\n";
    std::cout << " \nArray Original: \n";
    myArray.Print();
    myArray.SortFunction();
    std::cout << " \nArray Ordenado: \n";
    myArray.Print();
    
    //GetIndexOf Function
    std::cout << "\nGetIndexOf Function \n";
    std::cout << "Array Original: \n";
    myArray.Print(); 
    int index = myArray.GetIndexOf(5);
    std::cout << "La posicion del elemento elegido es: " << index << std::endl;
    
    //GetLastOf Function 
    std::cout << "\nGetLastOf Function \n";
    myArray.Print();
    myArray.GetLastOf(5);
    
    //GetIndicesOf
    std::cout << "\nGetIndicesOf Function \n";
    myArray.GetIndicesOf(5);

    //AppendArray Function 
    std::cout << " \nArray Original: \n";
    myArray.Print();
    RawArray test = RawArray(3);
    test.Initial(0);
    std::cout << " \nArreglo a agregar \n";
    test.Print();
    myArray.AppendArray(test);
    std::cout << " \nArray Final: \n";
    myArray.Print();
    
    //Función Insert
    std::cout << " \n Insert Function\n";
    myArray.Initial(0);

    RawArray toBeInserted = RawArray(3);
    toBeInserted.Initial(1);

    int currentStartIndex = 3;
    myArray.Insert(toBeInserted, currentStartIndex);

    myArray.Print();

    
    //SetSize function
    std::cout << " \n SetSize Function\n";
    std::cout << " Original Array\n";
    myArray.Print(); 
    myArray.SetSize(5); 
    std::cout << " Modified Arrays\n";
    myArray.Print();
    myArray.SetSize(8);
    myArray.Print();

    //SumArrays Function
    std::cout << "\nSumArrays Function\n";
    std::cout << "Array A\n";
    RawArray arrayA(3);
    arrayA.Initial(3);
    arrayA.Print(); 
    std::cout << "Array B\n";
    RawArray arrayB(3);
    arrayB.Initial(2);
    arrayB.Print();
    arrayB.SumArrays(arrayA);
    std::cout << "Resultado:\n";
    arrayB.Print();

    return 0;
}
