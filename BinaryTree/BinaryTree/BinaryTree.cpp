#include <iostream>
#include "BTree.h" 

int main()
{
    BinaryTree<int> myBT = BinaryTree<int>(); // Creamos un objeto BinaryTree que almacenará enteros.

    // Insertamos algunos valores en el árbol.
    myBT.Insert(5);
    myBT.Insert(3);
    myBT.Insert(8);
    myBT.Insert(2);
    myBT.Insert(4);
    myBT.Insert(7);
    myBT.Insert(9);

    // Imprimimos el recorrido en orden del árbol.
    std::cout << "Recorrido InOrder del arbol: ";
    myBT.InOrder(myBT.GetRoot());
    std::cout << std::endl;

    // Imprimimos el recorrido en preorden del árbol.
    std::cout << "Recorrido PreOrder del arbol: ";
    myBT.PreOrder(myBT.GetRoot());
    std::cout << std::endl;

    return 0;
}
