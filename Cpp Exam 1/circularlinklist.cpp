#include<iostream>
using namespace std;

class node{
    private:
    int num;
    node* next;
    public:
    node(){
        num=0;
        next=NULL;
    }
    friend class circularlinklist;
};

class circularlinklist{
    private:
    node *last;
    public:
    circularlinklist(){
        last=NULL;
    }
    bool isEmpty(){
        if(last==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    bool isFull(){
        if(last!=NULL){
            return true;
        }
        else{
            return false;
        }
    }
    void addtohead(int num) {
		node* temp = new node;
		temp->num = num;
		if (last == NULL) {
			temp->next = temp;
			last = temp;
		}
		else {
			temp->next = last->next;
			last->next = temp;
		}
	}
	void addtotail(int num) {
		if (last == NULL){
            node* temp = new node;
		    temp->num = num;
		    if (last == NULL) {
			    temp->next = temp;
			    last = temp;
		    }
		    else {
			    temp->next = last->next;
			    last->next = temp;
		    }
        }
		else {
			node* temp = new node;
			temp->num = num;
			temp->next = last->next;
			last->next = temp;
			last = temp;
		}
	}
	void deletfromhead() {
		if (last == NULL) {
			//cout << "Circular Linked List is Empty!\n";
            return;
        }
		else {
			node* temp = new node;
			temp = last->next;
			last->next = last->next->next;
			delete temp;
		}
	}
	void deletfromtail() {
		if (last == NULL) {
		    //cout << "Circular Linked List is Empty!\n";
            return;
        }
		else {
			node* temp = new node;
			temp = last->next;
			while (temp->next != last) {
				temp = temp->next;
			}
			node* newNode = new node;
			newNode = last;
			temp->next = last->next;
			last = temp;
			delete newNode;
		}
	}
	void display() {
		node* temp = new node;
		temp = last->next;
		do {
			cout << temp->num << " ";
			temp = temp->next;
		} while (temp != last->next);
		cout << endl;
	}
};

int main(){
    circularlinklist cll;
    cll.addtohead(1);
    cll.addtohead(2);
    cll.addtohead(3);
    cll.addtohead(4);
    cll.addtotail(8);
    cll.addtotail(5);
    cll.addtotail(7);
    cll.display();

    cll.deletfromhead();
    cll.deletfromtail();
    cll.display();
    
	return 0;
}