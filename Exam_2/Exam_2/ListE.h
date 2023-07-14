#pragma once
#ifndef LIST
#define LIST

#include <iostream>

template <typename T>
class ListNode
{
public:
	// Constructor
	ListNode(T in_data) : data(in_data), next(nullptr)
	{
	}

	T data; // Los datos
	ListNode<T>* next; // una referencia al nodo siguiente de este nodo, dentro de la lista.
};

template <typename T>
class List
{
private:
	ListNode<T>* firstNode;
	int size;

public:
	ListNode<T>* GetFirstNode() const
	{
		return firstNode;
	}
	ListNode<T>* begin()
	{
		return firstNode;
	}

	int GetSize() const
	{
		return size;
	}

	bool IsEmpty() const
	{
		return size == 0;
	}

	List() : firstNode(nullptr), size(0)
	{
	}

	List(T* in_data, int in_size) : firstNode(nullptr), size(0)
	{
		for (int i = 0; i < in_size; i++)
		{
			PushBack(in_data[i]);
		}
	}

	~List()
	{
		while (firstNode != nullptr)
		{
			PopFront();
		}
	}

	void PushBack(T element)
	{
		size++;

		if (firstNode == nullptr)
		{
			firstNode = new ListNode<T>(element);
			return;
		}

		ListNode<T>* currentNode = firstNode;
		while (currentNode->next != nullptr)
			currentNode = currentNode->next;

		ListNode<T>* newNode = new ListNode<T>(element);
		currentNode->next = newNode;
	}

	void PushBack(ListNode<T>* in_node)
	{
		if (in_node == nullptr)
			return;

		ListNode<T>* currentNode = firstNode;
		while (currentNode->next != nullptr)
			currentNode = currentNode->next;

		in_node->next = nullptr;
		currentNode->next = in_node;
	}

	void PopFront()
	{
		if (firstNode == nullptr)
		{
			throw std::runtime_error("Error: Trying to remove elements from an empty list.");
		}

		if (firstNode->next != nullptr)
		{
			ListNode<T>* auxNode = firstNode->next;
			delete firstNode;
			firstNode = auxNode;
		}
		else
		{
			delete firstNode;
			firstNode = nullptr;
		}

		size--;
	}

	void PopBack()
	{
		if (firstNode == nullptr)
			return;

		size--;

		if (firstNode->next == nullptr)
		{
			delete firstNode;
			firstNode = nullptr;
			return;
		}

		ListNode<T>* currentNode = firstNode;
		while (currentNode->next->next != nullptr)
			currentNode = currentNode->next;

		delete currentNode->next;
		currentNode->next = nullptr;
	}

	void InsertAfter(ListNode<T>* toBeInserted, ListNode<T>* existingNode)
	{
		if (existingNode == nullptr)
			return;

		if (existingNode->next != nullptr)
		{
			toBeInserted->next = existingNode->next;
		}

		existingNode->next = toBeInserted;
	}

	void DeleteNode(ListNode<T>* x)
	{
		ListNode<T>* auxPredecessor = Predecessor(x);

		if (auxPredecessor == nullptr)
		{
			ListNode<T>* auxPointer = firstNode;
			firstNode = firstNode->next;
			delete auxPointer;
			return;
		}

		auxPredecessor->next = x->next;
		delete x;
	}

	void DeleteByValue(T value)
	{
		ListNode<T>* toBeDeleted = GetByValue(value);
		if (toBeDeleted == nullptr)
			return;

		DeleteNode(toBeDeleted);
	}

	ListNode<T>* GetByValue(T value)
	{
		ListNode<T>* currentNode = firstNode;
		while (currentNode != nullptr)
		{
			if (currentNode->data == value)
			{
				return currentNode;
			}
			currentNode = currentNode->next;
		}

		throw std::runtime_error("Error: Node with the specified value not found.");
	}

	ListNode<T>* GetByIndex(int index)
	{
		if (firstNode == nullptr || index < 0 || index >= size)
		{
			throw std::runtime_error("Error: Invalid index.");
		}

		ListNode<T>* currentNode = firstNode;
		for (int i = 0; i < index; i++)
			currentNode = currentNode->next;

		return currentNode;
	}

	ListNode<T>* Successor(ListNode<T>* x)
	{
		return x->next;
	}

	ListNode<T>* Predecessor(ListNode<T>* x)
	{
		ListNode<T>* currentNode = firstNode;
		while (currentNode->next != nullptr)
		{
			if (currentNode->next == x)
			{
				return currentNode;
			}
			currentNode = currentNode->next;
		}

		return nullptr;
	}

	void Print()
	{
		if (firstNode == nullptr)
		{
			std::cout << "Empty list" << std::endl;
			return;
		}

		ListNode<T>* currentNode = firstNode;

		while (currentNode != nullptr)
		{
			std::cout << currentNode->data;

			if (currentNode->next != nullptr)
			{
				std::cout << ", ";
			}
			else
			{
				std::cout << std::endl;
			}

			currentNode = currentNode->next;
		}
	}

	void Reverse()
	{
		if (firstNode == nullptr || firstNode->next == nullptr)
		{
			return;
		}

		ListNode<T>* prevNode = nullptr;
		ListNode<T>* currentNode = firstNode;
		ListNode<T>* nextNode = nullptr;

		while (currentNode != nullptr)
		{
			nextNode = currentNode->next;
			currentNode->next = prevNode;

			prevNode = currentNode;
			currentNode = nextNode;
		}

		firstNode = prevNode;
	}

	void Unique()
	{
		if (firstNode == nullptr)
		{
			return;
		}

		ListNode<T>* currentNode = firstNode;
		while (currentNode != nullptr)
		{
			ListNode<T>* runnerNode = currentNode;
			while (runnerNode->next != nullptr)
			{
				if (runnerNode->next->data == currentNode->data)
				{
					ListNode<T>* duplicateNode = runnerNode->next;
					runnerNode->next = runnerNode->next->next;
					delete duplicateNode;
				}
				else
				{
					runnerNode = runnerNode->next;
				}
			}

			currentNode = currentNode->next;
		}
	}
};

#endif // LIST
