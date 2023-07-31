#pragma once

#include <iostream>
#include<stack>
// BinaryTree::Node


template<typename T>
class BinaryTree
{
private:
	
	// Definici�n de la estructura del nodo del �rbol
	template <typename U>
	struct Node
		
	{
	public: // por defecto en una struct, todo es p�blico, pero lo pongo por claridad.
		Node(U in_data, Node<U>* in_parent, Node<U>* in_left = nullptr, Node<U>* in_right = nullptr) :
			data(in_data), parent(in_parent), left(in_left), right(in_right)
		{
		}

		~Node()
		{
		}

		U data; // datos que va a guardar este nodo.
		Node<U>* parent; // referencia al nodo padre de este nodo dentro del �rbol.
		Node<U>* left; // Hijo izquierdo
		Node<U>* right; // Hijo derecho.
	};

	Node<T>* root; // Nodo ra�z del �rbol.

public: 
	BinaryTree() : root(nullptr) 
	{
	}

	~BinaryTree()
	{
		// Aqu� es donde s� tenemos que destruir los nodos restantes
		// PENDIENTE.
		while (root != nullptr)
		{
			DeleteNode(root);
		}
	}
	// Obtenemos el nodo ra�z del �rbol
	Node<T>* GetRoot()
	{
		return root;
	}

	// regresa el m�nimo de un Sub�rbol a partir del nodo ra�z de dicho sub�rbol.
	Node<T>* MinimumFromNode(Node<T>* in_root)
	{
		Node<T>* temp = in_root;
		while (temp->left != nullptr)
		{
			temp = temp->left;
		}
		return temp;
	}

	// regresa el m�nimo desde la ra�z del �rbol
	Node<T>* Minimum()
	{
		return MinimumFromNode(root);
	}

	T MinimumValue()
	{
		Node<T>* temp = Minimum();
		if (temp != nullptr)
		{
			return temp->data;
		}
	}

	// M�ximo de un sub�rbol con ra�z en in_root
	Node<T>* MaximumFromNode(Node<T>* in_root)
	{
		Node<T>* temp = in_root;
		while (temp->right != nullptr)
		{
			temp = temp->right;
		}
		return temp;
	}

	// M�ximo de todo el �rbol.
	Node<T>* Maximum()
	{
		return MaximumFromNode(root);
	}

	T MaximumValue()
	{
		Node<T>* temp = Maximum();
		if (temp != nullptr)
		{
			return temp->data;
		}
	}

	// B�squeda de un valor en el �rbol
	Node<T>* Search(T value)
	{
		Node<T>* temp = root;
		while (temp != nullptr && temp->data != value)
		{
			if (value < temp->data)
			{
				temp = temp->left;
			}
			else
			{
				// Los valores repetidos, se a�adir�n como nodos en el sub�rbol derecho
				// porque as� lo establece el pseudoc�digo del libro.
				// Pero hay otras variantes que lo pueden manejar de otra manera,para obtener ciertos beneficios.
				temp = temp->right;
			}
		}
		// temp puede ser nullptr si no se encontr� un nodo con data==value; si s� se encontr�, pues temp es 
		// dicho nodo.
		return temp;
	}

	void Insert(T value)
	{
		Node<T>* temp = root;
		Node<T>* temp_parent = nullptr;
		while (temp != nullptr)
		{
			if (value < temp->data)
			{
				temp_parent = temp;
				temp = temp->left;
			}
			else
			{
				// Los valores repetidos, se a�adir�n como nodos en el sub�rbol derecho
				// porque as� lo establece el pseudoc�digo del libro.
				// Pero hay otras variantes que lo pueden manejar de otra manera,para obtener ciertos beneficios.
				temp_parent = temp;
				temp = temp->right;
			}
		}

		// Cuando se salga de este while, ya estamos donde deber�amos de insertar Value
		// Necesitamos decirle a este nodo nuevo, qui�n es su nodo padre.		
		Node<T>* newNode = new Node<T>(value, temp_parent);
		// Ahora hacemos la conexi�n de padre a hijo, dependiendo de si es hijo izquierdo o derecho.
		if (temp_parent == nullptr)
		{
			// entonces el �rbol estaba vac�o.
			root = newNode;
		}
		else if (value < temp_parent->data)
		{
			temp_parent->left = newNode;
		}
		else
		{
			temp_parent->right = newNode;
		}
	}

	Node<T>* Sucessor(Node<T>* in_x)
	{
		if (in_x->right != nullptr)
		{
			// entonces s� tiene un sub�rbol derecho. Necesitamos el nodo m�s chico de dicho sub�rbol derecho
			return MinimumFromNode(in_x->right);
		}
		else
		{
			// empezamos con el padre del nodo al cual queremos encontrar su sucesor.
			Node<T>* current = in_x;  // current es 9
			Node<T>* temp_parent = in_x->parent; // temp parent es 8
			while (temp_parent != nullptr && temp_parent->right == current)
			{
				// Si seguimos siendo el hijo derecho de nuestro padre, todav�a no vamos a romper este while.
				current = current->parent; // ahora current es 5
				temp_parent = current->parent; // ahora el padre de current es nullptr
			}
			return temp_parent; // se regresa el nodo nullptr
		}
	}

	// Funci�n para encontrar el predecesor de un nodo dado
	Node<T>* Predecessor(Node<T>* in_x)
	{
		if (in_x->left != nullptr)
		{
			// Caso 1: Si el nodo in_x tiene un hijo izquierdo,
			// el predecesor es el nodo m�s a la derecha del sub�rbol izquierdo.
			return MaximumFromNode(in_x->left);
		}
		else if (in_x->parent != nullptr && in_x == in_x->parent->left)
		{
			// Caso 2: Si el nodo in_x no tiene hijo izquierdo
			// y es un hijo izquierdo de su padre,
			// entonces el predecesor es el nodo padre.
			return in_x->parent;
		}
		else
		{
			// Caso 3: Si el nodo in_x no tiene hijo izquierdo
			// y es un hijo derecho de su padre,
			// entonces el predecesor se encuentra buscando recursivamente
			// el predecesor del nodo padre (es decir, llamando a Predecessor(in_x->parent)).
			return Predecessor(in_x->parent);
		}
	}

	bool GetPredecessorValue(T value, T& predecessorValue)
	{
		Node<T>* node = Search(value);
		if (node == nullptr)
		{
			std::cout << "El nodo con valor " << value << " no se encuentra en el �rbol." << std::endl;
			return false;
		}

		Node<T>* predecessorNode = Predecessor(node);
		if (predecessorNode != nullptr)
		{
			predecessorValue = predecessorNode->data;
			return true;
		}
		else
		{
			std::cout << "No se encontr� un predecesor para el nodo con valor " << value << std::endl;
			return false;
		}
	}



	/*
	*	In Order
		Viaja al sub-�rbol izquierdo de este nodo, recursivamente.
		Visita el nodo actual.
		Viaja al sub-�rbol derecho de este nodo, recursivamente.
	*/
	void InOrder(Node<T>* in_x)
	{
		if (in_x != nullptr)
		{
			InOrder(in_x->left);
			std::cout << in_x->data << ", ";
			InOrder(in_x->right);
		}
		// Si no, no se hace nada, y solo se sale de la funci�n.
	}
	// Funci�n para realizar el recorrido InOrder de forma iterativa
	void InOrderIterative(Node<T>* root)
	{
		if (root == nullptr)
		{
			return;
		}

		std::stack<Node<T>*> stack;
		Node<T>* current = root;

		while (!stack.empty() || current != nullptr) 
		{
			if (current != nullptr)
			{
				stack.push(current);
				current = current->left;
			}
			else
			{
				current = stack.top();
				stack.pop();
				std::cout << current->data << ", ";
				current = current->right;
			}
		}
	}



	/*
	*	Pre-Order
	Visita el nodo actual.
	Viaja al sub-�rbol izquierdo de este nodo, recursivamente.
	Viaja al sub-�rbol derecho de este nodo, recursivamente.
	*/
	void PreOrder(Node<T>* in_x)
	{
		if (in_x != nullptr)
		{
			std::cout << in_x->data << ", ";
			PreOrder(in_x->left);
			PreOrder(in_x->right);
		}
		// Si no, no se hace nada, y solo se sale de la funci�n.
	}
	void PreOrderIterative(Node<T>* root) 
	{
		std::stack<Node<T>*> stdStack;
		if (root == nullptr)
			return;

		stdStack.push(root);

		while (!stdStack.empty())
		{
			Node<T>* current = stdStack.top();
			stdStack.pop();

			std::cout << current->data << ", ";

			if (current->right != nullptr)
				stdStack.push(current->right);

			if (current->left != nullptr)
				stdStack.push(current->left);
		}
	}

	/*
	*	Post-Order
	Viaja al sub-�rbol izquierdo de este nodo, recursivamente.
	Viaja al sub-�rbol derecho de este nodo, recursivamente.
	Visita el nodo actual.
	*/
	void PostOrder(Node<T>* in_x)
	{
		if (in_x != nullptr)
		{
			PostOrder(in_x->left);
			PostOrder(in_x->right);
			std::cout << in_x->data << ", ";
		}
		// Si no, no se hace nada, y solo se sale de la funci�n.
	}
	void PostOrderIterative(Node<T>* in_x)
	{
		if (root == nullptr)
		{
			std::cout << "El arbol esta vacio." << std::endl;
			return;
		}

		std::stack<Node<T>*> firstStack;
		std::stack<Node<T>*> secondStack;
		Node<T>* current = root;

		// Realizar el recorrido PreOrder inverso utilizando la primera pila
		firstStack.push(current);
		while (!firstStack.empty())
		{
			Node<T>* temp = firstStack.top();
			firstStack.pop();
			secondStack.push(temp);

			if (temp->left)
				firstStack.push(temp->left);
			if (temp->right)
				firstStack.push(temp->right);
		}

		// Recorrer la segunda pila para obtener el recorrido PostOrder
		while (!secondStack.empty())
		{
			Node<T>* temp = secondStack.top();
			secondStack.pop();
			std::cout << temp->data << ", ";
		}
	}


	void Transplant(Node<T>* in_u, Node<T>* in_v)
	{
		if (in_u->parent == nullptr)
		{
			// Entonces U es el nodo ra�z. Actualizamos la ra�z del �rbol
			root = in_v;
		}
		else if (in_u == in_u->parent->left)
		{
			// Si U es el hijo izquierdo de su padre, 
			// le dices al padre que ahora su hijo izquierdo 
			// ser� V
			in_u->parent->left = in_v;
		}
		else
		{
			// Si no era el hijo izquierdo, entonces era el derecho
			// y hay que actualizarlo de U a V
			in_u->parent->right = in_v;
		}
		if (in_v != nullptr)
		{
			// Si V s� es un nodo, pone que el padre de V
			// es el mismo que el padre de U
			in_v->parent = in_u->parent;
		}
	}

	void DeleteNode(Node<T>* in_z)
	{

		if (in_z->left == nullptr)
		{
			// Si el hijo izquierdo de Z es nullptr,
			// entonces remplazamos Z por su hijo derecho.
			Transplant(in_z, in_z->right);
		}
		else if (in_z->right == nullptr)
		{
			// Si el hijo derecho de Z es nullptr,
			// entonces remplazamos Z por su hijo izquierdo.
			Transplant(in_z, in_z->left);
		}
		else
		{
			// Todo esto es para el caso 3, que es el complicado del Delete
			// Primero, obtenemos el sucesor de Z
			Node<T>* Y = MinimumFromNode(in_z->right);
			// Checamos que Y no sea el sucesor inmediato a la derecha
			if (Y != in_z->right)
			{
				// Entonces este es el caso engorroso.
				Transplant(Y, Y->right);
				// Despu�s, le decimos a Y que su derecha es ahora la 
				// derecha del Nodo Z que estamos quitando.
				Y->right = in_z->right;
				// Y le decimos al hijo derecho de Z que ahora su padre debe ser Y
				Y->right->parent = Y;
			}
			// Mover al sucesor al espacio de Z (al que vamos a quitar)
			Transplant(in_z, Y);
			// Quitarle el sub�rbol izquierdo a Z y d�rselo a Y
			Y->left = in_z->left;
			// Decirle al sub�rbol izquierdo de Y, que ponga a Y como su padre
			Y->left->parent = Y;
		}

		// finalmente, sin importar cu�l caso de Delete se us�, es necesario borrar al nodo Z.
		delete in_z;
	}

};

