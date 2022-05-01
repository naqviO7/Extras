#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

class List;
class AbstractList {
protected:
	int numElements;
public:
	Node* head;
	friend class List;

	AbstractList() {
		numElements = 0;
		head = NULL;
	};
	~AbstractList() {
		delete head;
	};

	virtual void append(int x) {
		Node* temp = new Node;
		temp->data = x;
		if (head == NULL)
			temp->next = NULL;
		else
			temp->next = head;
		head = temp;
	}

	virtual Node* remove(Node* head){
		if (head == NULL)
			return NULL;
		Node* temp = head;
		head = head->next;
		delete temp;
		return head;
	}

	bool isEmpty() {
		if (head == NULL)
			return true;
		return false;
	}
};

class List {
	Node* head;
public:
	List();
	bool isEmpty();
	void append(int x);
	void append_tail(int x);
	Node* remove(Node* head);
	void insert(int x, int pos);
	void remove_at(int pos);
	void display();
	Node& operator[](int i);
};

List::List() {
	head = NULL;
}

bool List::isEmpty() {
	if (head == NULL)
		return true;
	return false;
}

void List:: append(int x) {
	Node* temp = new Node;
	temp->data = x;
	if (head == NULL)
		temp->next = NULL;
	else
		temp->next = head;
	head = temp;
}

void List:: append_tail(int x) {
	Node* temp = new Node;
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	Node* tail = new Node;
	temp->next = tail;
	tail->next = NULL;
	tail->data = x;
}

Node* List::remove(Node* head) {
	if (head == NULL)
		return NULL;
	Node* temp = head;
	head = head->next;
	delete temp;
	return head;
}

void List:: insert(int x, int pos) {
	Node* newNode = new Node();
	newNode->data = x;
	newNode->next = NULL;
	if (pos < 1) {
		cout << "\nposition should be >= 1.";
	}
	else if (pos == 1) {
		newNode->next = head;
		head = newNode;
	}
	else {
		Node* temp = head;
		for (int i = 1; i < pos - 1; i++) {
			if (temp != NULL) {
				temp = temp->next;
			}
		}
		if (temp != NULL) {
			newNode->next = temp->next;
			temp->next = newNode;
		}
		else {
			cout << "\nThe previous node is null.";
		}
	}
}

void List::remove_at(int pos) {
	if (pos < 1) {
		cout << "\nposition should be >= 1.";
	}
	else if (pos == 1 && head != NULL) {
		Node* nodeToDelete = head;
		head = head->next;
		free(nodeToDelete);
	}
	else {
		Node* temp = head;
		for (int i = 1; i < pos - 1; i++) {
			if (temp != NULL) {
				temp = temp->next;
			}
		}
		if (temp != NULL && temp->next != NULL) {
			Node* nodeToDelete = temp->next;
			temp->next = temp->next->next;
			free(nodeToDelete);
		}
		else {
			cout << "\nThe node is already null.";
		}
	}
}

void List::display() {
	Node* temp = new Node;
	temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

Node& List:: operator[](int i) {
	List l;
	return l[i];
}
