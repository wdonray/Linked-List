#pragma once
#include <cassert>
template<class Type>
class linkedListIterator;
template<class Type>
struct nodeType
{
public:
	int info;
	nodeType<Type> * link;
};
template<class Type>
class linkedListType
{
public:
	linkedListType() {
		first = new nodeType<Type>;
		last = new nodeType<Type>;
		count = 0; 
	};
	//Initialize the list to an empty state
	//Postcondition: first = NULL, last = NULL, count = 0;
	void initializeList()
	{
		first = NULL;
		last = NULL;
		count = 0; 
	}
	//Function to determine whether the list is empty
	//Postcondition: Returns true if the list is empty otherwise it returns false
	bool isEmptyList() const
	{
		return (first == nullptr) ? true : false;
	}
	//Overload the assignment operator
	const linkedListType<Type>& operator= (const linkedListType<Type>& otherList)
	{
		copyList(otherList);
		return *this;
	}
	//Function to output the data contained in each node
	//Postcondition: Node
	void print() const
	{
		nodeType<Type> *current;
		current = first;
		while (current != NULL)
		{
			std::cout << current->info << std::endl;
			current = current->link;
		}
	}
	//Function to determine whether node is in the list
	//Postcondition: Returns true if node is in the list
	//otherwise teh value false is returned
	bool search(const Type& nodeInfo)
	{
		linkedListIterator<Type> tmp = linkedListIterator<Type>(begin());
		while (*tmp != NULL)
		{
			if (*tmp == nodeInfo)
			{
				return true;
			}
			++tmp;
		}
		return false;
	}
	//Function to delete all the nodes from the list
	//Postcondition: first = NULL, last = NULL, count = 0;
	void destroyList()
	{
		nodeType<Type> * iter = first;
		while (iter != NULL)
		{
			nodeType<Type> * tmp = iter;
			iter = iter->link;
			delete tmp;
		}
		first = NULL;
		last = NULL;
		count = 0;
	}
	//Function to delete node from the list
	//Postcondition: If found, the node containing the node is deleted from the list. first points to
	//the first node, last points to the last node of the update list, and count is decremented by 1
	void deleteNode(const Type& nodeInfo)
	{
		nodeType<Type>* node = first;
		if (node == nullptr)
		{
			return;
		}
		else if (node->info == nodeInfo)
		{
			nodeType<Type> *tmp = node;
			node = node->link;
			delete tmp;
			count--;
			first = node;
		}
		else
		{
			while (node->link != NULL)
			{
				if (node->link->info == nodeInfo)
				{
					nodeType<Type>* tmp = node->link;
					node->link = node->link->link;
					delete tmp;
					count--;
					break;
				}
				node = node->link;
			}
		}
	}
	//Deconstructor
	//Deletes all the nodes from the list
	//Postcondition: The list object is destroyed
	~linkedListType<Type>()
	{
		destroyList();
	}
	//Function to insert node at the end of the list
	//Postcondition: first points to the new list, node is inserted 
	//at the beginning of the list, last points to the last node in
	//the list, and count is incremented by 1;
	void insertLast(const Type& node)
	{
		nodeType<Type> * newNode;
		newNode = new nodeType<Type>;
		if (count == 0)
		{
			first->info = node;
			first->link = nullptr;
			last->info = node;
			last->link = nullptr;
			count++;
		}
		else
		{
			last->link = newNode;
			last = newNode;
			if (count == 1)
				first->link = newNode;
			last->info = node;
			last->link = nullptr;
			count++;
		}
	}
	//Copy constructor
	linkedListType<Type>(const linkedListType<Type> & otherList)
	{
		copyList(otherList);
	}
	//Function to insert node at the begining of the list
	//Postcondition: first points to the new list, node is inserted 
	//at the beginning of the list, last points to the last node in
	//the list, and count is incremented by 1;
	void insertFirst(const Type& node)
	{
		nodeType<Type> * newNode;
		newNode = new nodeType<Type>;
		if (count == 0)
		{
			first->info = node;
			first->link = nullptr;
			last->info = node;
			last->link = nullptr;
			count++;
		}
		else
		{
			newNode->link = first;
			first = newNode;
			first->info = node;
			count++;
		}
	}
	//Function to return the first element in the list
	//Precondition: The list must exist and must not be empty
	//Postcondition: If the list is empty, the program terminates; otherwise,
	//the first element of the list is returned
	Type front()const
	{
		assert(count != 0);
		return last->info;
	}
	//Function to return the last element in the list
	//Precondition: The list must exist and must not be empty
	//Postcondition: If the list is empty, the program terminates; otherwise,
	//the last element of the list is returned
	Type back()const
	{
		assert(count != 0);
		return first->info;
	}
	//Function to return an iterator at the begining of the linked list
	//Postcondition: Returns an iteratir such that the current is set to first
	linkedListIterator<Type> begin()
	{
		return linkedListIterator<Type>(first);
	}
	//Funcion to rturn an iterator at the end of the linked list
	//Postcondition: Returns an iterator such that current is set to NULL
	linkedListIterator<Type> end()
	{
		return linkedListIterator<Type>(last);
	}
	//Function to return the number of nodes in the list
	//Postcondition: The value of count is returned
	const int length()
	{
		return count;
	}
protected:
	int count; //Variable to store the number of elements in the list
	nodeType<Type> * first; //Pointer to the first node of the list
	nodeType<Type> * last; //Pointer to the last node of the list
private:
	//Function to make a copy of list
	//Postcondition: A copy of list is created and assigned to this list
	void copyList(const linkedListType<Type>& otherList)
	{
		first = otherList.first;
		last = otherList.last;
		count = otherList.count;
	}
};
template<class Type>
class linkedListIterator
{
private:
	nodeType<Type> *current;
public:
	linkedListIterator() {};
	linkedListIterator(nodeType<Type> *node) : current(node) {};
	//Function to overlaod the dereferencing operator *
	//Postcondition:Returns the info contained in the node
	Type operator *()
	{
		if (current == nullptr)
			return NULL;
		return current->info;
	}
	//Overload the pre-increment operator
	//Postcondition: The iterator is advanced to the next node
	linkedListIterator<Type> operator++ ()
	{
		current = current->link;
		return *this;
	}
	//Overlaod the equality operator
	//Postcondition: Returns true if this iterator is equal to the 
	//iterator specified by right otherwise returns false
	bool operator ==(const linkedListIterator<Type>& a)
	{
		return current == a.current;
	}
	//Overlaod the not equal operator
	//Postcondition: Returns true if this iterator is not equal to the 
	//iterator specified by right otherwise returns false
	bool operator !=(const linkedListIterator<Type>& a)
	{
		return current != a.current;
	}
};
