#include<iostream>
using namespace std;

class node{
    private:
    int num;
    node* next;
    public:
    node(int num=0,node*next=NULL){
        this->num=num;
        this->next=next;
    }
    void setnum(int num){
        this->num=num;
    }
    void setnext(node * next){
        this->next=next;
    }
    int getnum(){
        return num;
    }
    node * getnext(){
        return next;
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
        if(last==NULL)
            return true;
        return false;
    }
    void addtohead(int num){
        node* temp = new node;
        temp->setnum(num);
        if (last == NULL) {
            temp->setnext(temp);
            last = temp;
        }
        else {
            temp->next = last->next;
            last->setnext(temp);
        }
    }
    void addtotail(int num) {
        if (last == NULL){
            node* temp = new node;
            temp->setnum(num);
            if (last == NULL) {
                temp->setnext(temp);
                last = temp;
            }
            else {
                temp->next = last->next;
                last->setnext(temp);
            }
        }
        else {
            node* temp = new node;
            temp->setnum(num);
            temp->next = last->next;
            last->setnext(temp);;
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
            temp = last->getnext();
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
            while (temp->getnext() != last) {
                temp = temp->getnext();
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
        temp = last->getnext();
        do {
            cout << temp->getnum() << " ";
            temp = temp->getnext();
        } while (temp != last->getnext());
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