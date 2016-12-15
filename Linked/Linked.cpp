#include <iostream>
#include <time.h>
#include <Windows.h>
#include <string>
#include "Linked.h"
void List(nodeType<int> * start)//, nodeType end)
{
	while (start != NULL)
	{
		std::cout << start->info;
		start = start->link;
	}
}
int main()
{
	//nodeType<int> * head;
	//nodeType<int> a, b, c;
	//a.info = 0;
	//b.info = 2;
	//c.info = 4;
	//c.link = &b;
	//b.link = &a;
	//a.link = NULL;
	//head = &c;
	//List(head);
	linkedListType<int> * A = new linkedListType<int>();
	linkedListType<int> * B = new linkedListType<int>();
	A->insertLast(1);
	A->insertLast(3);
	A->insertLast(2);
	A->insertFirst(54);
	*B = *A;
	//A->print();
	linkedListIterator<int> tmp = linkedListIterator<int>(A->begin());
	++tmp;
	A->front();
	//A->destroyList();
	A->deleteNode(54);
	A->print();
	bool test = A->search(53);
	if (test == true)
		std::cout << "\nTrue \n\n";
	else
		std::cout << "\nFalse \n\n";
	system("pause");
	return 0;
}