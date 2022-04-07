#include<iostream>
using namespace std;

class node{
    private:
    int num;
    node *next;
    node *prev;
    public:
    node(){
        num=0;
        next=NULL;
        prev=NULL;
    }
    friend class doublelinkliskt;
};

class doublelinkliskt{
    private:
    node *head;
    node *tail;
    public:
    doublelinkliskt(){
        head=NULL;
        tail=NULL;
    }
    bool isEmpty(){
        if(head==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    bool isFull(){
        if(head!=NULL){
            return true;
        }
        else{
            return false;
        }
    }
    void addtohead(int num){
        node *tmp=new node;
        tmp->num=num;
        if(head==NULL){
            tmp->next=NULL;
        }
        else {
			tmp->next = head;
			head->prev = tmp;
		}
		tmp->prev = NULL;
		head = tmp;
    }
    void addtotail(int num) {
		node* tmp = new node;
		if (head == NULL) {
			tmp->num = num;
			tmp->next = NULL;
			tmp->prev = NULL;
			head = tmp;
		}
		else {
			tmp = head;
			while (tmp->next != NULL) {
				tmp = tmp->next;
			}
			node* tail = new node;
			tail->num = num;
			tail->next = NULL;
			tail->prev = tmp;
			tmp->next = tail;
		}
	}
    void addtopos(int num, int pos) {
		if (head == NULL) {
			return;
		}
		else {
			node* temp = new node;
			temp = head;
			while (temp != NULL) {
				if (temp->num == pos) {
					break;
				}
				temp = temp->next;
			}
			if (temp == NULL) {
				//cout << pos << " not found in List!\n";
			}
			else {
				node* newnode = new node;
				newnode->num = num;
				newnode->prev = temp;
				newnode->next = temp->next;
				temp->next->prev = newnode;
				temp->next = newnode;
			}
		}
	}
    void deletfromhead() {
		if (head == NULL) {
			return;
		}
		node* temp = new node;
		temp = head;
		head = head->next;
		head->prev = NULL;
		temp->next = NULL;
		delete temp;
	}
	void deletfromtail() {
		node* temp = new node;
		temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->prev->next = NULL;
		temp->prev = NULL;
		delete temp;
	}
	void display() {
		node* temp = new node;
		temp = head;
		while (temp != NULL) {
			cout << temp->num << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	void reversedisplay() {
		node* temp = new node;
		temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		while (temp != NULL) {
			std::cout << temp->num << " ";
			temp = temp->prev;
		}
		cout << endl;
	}
};

int main(){
    doublelinkliskt dll;
    dll.addtohead(1);
    dll.addtohead(2);
    dll.addtohead(3);
    dll.addtohead(4);
    dll.addtohead(5);
    dll.addtotail(6);
    dll.addtotail(7);
    dll.addtotail(8);
    dll.addtotail(9);
    dll.display();
    dll.addtopos(10, 6);
    dll.display();
    dll.reversedisplay();
    return 0;
}