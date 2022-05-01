#include "List.h"
#include <iostream>

using namespace std;
int main() {
	//First part of the assignment
	//Uncomment this line and it should result on a compilation error. Reason : You cannot instantiate objects of an abstract class
	//AbstractList mylist(); 

	//Second part of the assignment
	List myintlist;
	Node* head = NULL;
	string result = myintlist.isEmpty() == 1 ? "Empty" : "Non-empty";
	cout << "Currently the list is " << result << endl;
	cout << "Inserting items to myList" << endl;
	for (int i = 0; i < 5; i++)
		myintlist.append(i);
	result = myintlist.isEmpty() == 1 ? "Empty" : "Non-empty";
	cout << "After some operations, the list is " << result << endl;
	//cout << "Current items on list :" << myintlist << endl;

	cout << "Removing items head by head " << endl;
	cout << "Removed " << myintlist.remove(head) << endl;
	cout << "Removed " << myintlist.remove(head) << endl;

	//cout << "Current items on list :" << myintlist << endl;

	cout << "Adding 30 to tail" << endl;
	myintlist.append_tail(30);
	cout << "Adding 50 to tail" << endl;
	myintlist.append_tail(50);


	cout << "Current items on list :"; 
	myintlist.display();
	cout << "Inserting 9999 at 4th position" << endl;
	myintlist.insert(9999, 3);

	cout << "Current items on list :";
	myintlist.display();
	cout << "Removing item at 2nd position" << endl;
	cout << "Removed value "; 
	myintlist.remove_at(2);
	cout<< endl;

	cout << "Current items on list :";
	myintlist.display();
	//Final part of the assignment

	cout << "Finally printing the entire list through cout" << endl;
	myintlist.display();

	cout << "===============" << endl;
	cout << "That should do it ! Bye" << endl;

	return 0;
}
