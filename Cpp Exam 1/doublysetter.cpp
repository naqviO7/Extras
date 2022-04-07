#include<iostream>
using namespace std;

class node{
    private:
    int num;
    node*next;
    node * prev;
    public:
    node(int num=0,node *next=NULL,node*prev=NULL){
        this->num=num;
        this->next=next;
        this->prev=prev;
    }
    void setnum(int num){
        this->num=num;
    }
    void setnext(node *next){
        this->next=next;
    }
    void setprev(node *prev){
        this->prev=prev;
    }
    int getnum(){
        return num;
    }
    node *getnext(){
        return next;
    }
    node *getprev(){
        return prev;
    }
    friend class doublylinklist;
};
class doublylinklist{
    private:
    node *head;
    node *tail;
    public:
    doublylinklist(){
        head=NULL;
        tail=NULL;
    }
    bool isEmpty(){
        if(head==NULL)
            return true;
        return false;
    }
    void addtohead(int num){
        node *tmp=new node;
        tmp->setnum(num);
        if(head==NULL){
            tmp->setnext(NULL);
        }
        else{
            tmp->setnext(head);
            head->setprev(tmp);
        }
        tmp->setprev(NULL);
        head=tmp;
    }
    void addtotail(int num) {
		node* tmp = new node;
		if (head == NULL) {
			tmp->setnum(num);
			tmp->setnext(NULL);
			tmp->setprev(NULL);
			head = tmp;
		}
		else {
			tmp = head;
			while (tmp->getnext() != NULL) {
				tmp = tmp->getnext();
			}
			node* tail = new node;
			tail->setnum(num);
			tail->setnext( NULL);
			tail->setprev(tmp);
			tmp->setnext(tail);
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
				if (temp->getnum() == pos) {
					break;
				}
				temp = temp->getnext();
			}
			if (temp == NULL) {
				//cout << pos << " not found in List!\n";
			}
			else {
				node* newnode = new node;
				newnode->setnum(num);
				newnode->setprev(temp);
				newnode->next = temp->next;
				temp->next->prev = newnode;
				temp->setnext(newnode);
			}
		}
	}
    void deletfromhead() {
		if (head == NULL) {
			return;
		}
		node* temp = new node;
		temp = head;
		head = head->getnext();
		head->setprev(NULL);
		temp->setnext(NULL);
		delete temp;
	}
	void deletfromtail() {
		node* temp = new node;
		temp = head;
		while (temp->getnext() != NULL)
			temp = temp->getnext();
		temp->prev->next = NULL;
		temp->setprev(NULL);
		delete temp;
	}
	void display() {
		node* temp = new node;
		temp = head;
		while (temp != NULL) {
			cout << temp->getnum() << " ";
			temp = temp->getnext();
		}
		cout << endl;
	}
    void reversedisplay() {
		node* temp = new node;
		temp = head;
		while (temp->getnext() != NULL) {
			temp = temp->getnext();
		}
		while (temp != NULL) {
			std::cout << temp->getnum() << " ";
			temp = temp->prev;
		}
		cout << endl;
	}
};

int main(){
    doublylinklist dll;
    dll.addtohead(1);
    dll.addtohead(2);
    dll.addtohead(3);
    dll.addtohead(4);
    dll.addtohead(5);
    dll.addtotail(6);
    dll.addtopos(11, 2);
    dll.addtotail(7);
    dll.addtotail(8);
    dll.addtotail(9);
    dll.display();
    dll.reversedisplay();
    return 0;
}