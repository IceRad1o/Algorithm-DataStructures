#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include<string>
using std::string;
#include"List.h"
template<typename T>
void testList(List<T> &listObject, const string &typeName)
{
	cout << "Testing a list of" << typeName << "values\n";
	instructions();
	int choice;
	T value;
	do
	{
		cout << "? ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "enter " << typeName << "";
			cin >> value;
			listObject.insertAtFront(value);
			listObject.print();
			break;
		case 2:
			cout << "enter" << typeName << "";
			cin >> value;
			listObject.insertAtBack(value);
			listObject.print();
			break;
		case 3:
			if (listObject.removeFromFront(value))
				cout << value << "removed from list\n";
			listObject.print();
			break;
		case 4:
			if (listObject.removeFromBack(value))
				cout << value << "removed from list\n";
			listObject.print();
			break
		
		}
	} while (choice != 5);
	
}
void instructions()
{
	cout << "enter one of the followings:\n"
		<< "1 to insert at beginning of list\n"
		<< "2 to insert at end of list\n"
		<< "3 to delete from beginning of list\n"
		<< "4 to delete from end of list\n"
		<< "5 to end list processing\n";
}
int main()
{
	List<int> integerList;
	testList(integerList, "integer");
	system("pause");
	return 0;
}