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

    // Imprimimos el recorrido en preorden del árbol.
    std::cout << "Recorrido PostOrder del arbol: ";
    myBT.PostOrder(myBT.GetRoot());
    std::cout << std::endl;

    // Predecesor Function
    std::cout << "\n\nPredecesor Function\n";


    int valueToFindPredecessor = 5;
    int predecessorValue;

    if (myBT.GetPredecessorValue(valueToFindPredecessor, predecessorValue))
    {
        std::cout << "El predecesor de " << valueToFindPredecessor << " es: " << predecessorValue << std::endl;
    }

    // Imprimimos el recorrido en orden del árbol.
    std::cout << "Recorrido InOrder del arbol: ";
    myBT.InOrder(myBT.GetRoot());
    std::cout << std::endl;

    // Funciones iterativas
    // InOrder de forma iterativa
    // Fuentes: https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
    std::cout << "\nRecorrido InOrder de forma iterativa  ";
    myBT.InOrderIterative(myBT.GetRoot());

    //PreOrder de forma iterativa
    //fuentes: https://www.geeksforgeeks.org/iterative-preorder-traversal/
    std::cout << "\nRecorrido PreOrder de forma iterativa  ";
    myBT.PreOrderIterative(myBT.GetRoot());

    //PostOrder de forma iterativa
    //fuentes: https://www.geeksforgeeks.org/postorder-traversal-binary-tree-without-recursion-without-stack/
    std::cout << "\nRecorrido PostOrder de forma iterativa  ";
    myBT.PostOrderIterative(myBT.GetRoot()); 
   



    return 0;
}
