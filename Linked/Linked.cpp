#include <iostream>
#include <time.h>
#include <Windows.h>
#include <string>
#include "Linked.h"
//void List(nodeType<int> * start)//, nodeType end)
//{
//	while (start != NULL)
//	{
//		std::cout << start->info;
//		start = start->link;
//	}
//}
int main()
{
	linkedListType<int> * A = new linkedListType<int>();
	linkedListType<int> * B = new linkedListType<int>();
	linkedListType<int> * C = new linkedListType<int>();
	A->insertLast(1);
	A->insertLast(3);
	A->insertLast(2);
	A->insertFirst(54);
	//A->destroyList();
	A->deleteNode(54);
	A->print();
	bool test, test2, test3;
	(test = A->search(53)) ? std::cout << "\nTrue \n" : std::cout << "\nFalse \n";
	(test2 = A->isEmptyList()) ? std::cout << "\nTrue \n" : std::cout << "\nFalse \n";
	(B = A) ? std::cout << "\nA and B are now equal\n\n" : std::cout << "\nFalse \n";
	std::cout << "Length: " << A->length() << "\n\n";
	std::cout << "Front: " << A->front() << "\n\n";
	std::cout << "Back: " << A->back() << "\n\n";
	(B == A) ? std::cout << "They are equal \n\n" : std::cout << "";
	(B != A) ? std::cout << "They are not equal \n \n" : std::cout << ":)\n";
	system("pause");
	return 0;
}