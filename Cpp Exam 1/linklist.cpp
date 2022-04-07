#include<iostream>
using namespace std;

class node{
    private:
    int num;
    node * next;
    public:
    node(){
        num=0;
        next=NULL;
    }
    friend class linklist;
};

class linklist{
    private:
    node *head;
    node *tail;
    public:
    linklist(){
        head=NULL;
        //tail=NULL;
    }
    bool is_Full(){
        if(head!=NULL){
            return true;
        }
        else {
            return false;
        }
    }
    bool is_Empty(){
        if(head==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    void addtohead(int num){
        node * tmp=new node;
        tmp->num=num;
        if(head==NULL){
            tmp->next=NULL;
        }
        else{
            tmp->next=head;
        }
        head=tmp;
    }
    void addtotail(int num){
        node * tmp=new node;
        tmp=head;
        while(tmp->next!=NULL){
            tmp=tmp->next;
        }
        node *tail=new node;
        tmp->next=tail;
        tail->next=NULL;
        tail->num=num;
    }
    void deletfromtail(){
        node* tmp = new node;
		tmp = head;
		if (tmp->next == NULL) {
			head = NULL;
			delete tmp;
			cout << "List is now empty!\n";
		}
		else {
			while (tmp->next->next != NULL) {
				tmp = tmp->next;
			}
			node* tail = new node;
			tail = tmp->next;
			tmp->next=NULL;
			delete tail;
		}
    }
    void addtolocation(int num,int pos){
        node *tmp=new node;
        tmp->num=num;
        tmp->next=NULL;
        if(pos==1){
            tmp->next=head;
            head=tmp;
            return;
        }
        node *temp=head;
        for(int i=0;i<pos-2;i++){
            temp=temp->next;
        }
        tmp->next=temp->next;
        temp->next=tmp;
    }
    void deletfromlocation(int pos){
        node * tmp=new node;
        tmp=head;
        if(pos==1){
            head=tmp->next;
            delete tmp;
            return;
        }
        for(int i=0;i<pos-2;i++){
            tmp=tmp->next;
        }
        node * temp=tmp->next;
        tmp->next=temp->next;
        delete temp;
    }
    void display(){
        node * tmp=new node;
        tmp=head;
        while(tmp!=NULL){
            cout<<tmp->num<<" ";
            tmp=tmp->next;
        }
        cout<<"\n";
    }
};

int main(){
    linklist ll;
    ll.addtohead(22);
    ll.addtohead(23);
    ll.addtohead(12);
    ll.addtohead(2);
    ll.addtohead(62);
    ll.addtotail(28);
    ll.addtotail(4);
    ll.addtotail(7);
    ll.display();
    ll.addtolocation(45, 2);
    ll.addtolocation(5, 10);
    ll.display();
    ll.deletfromlocation(2);
    ll.deletfromlocation(1);
    ll.display();
    ll.deletfromtail();
    ll.display();
    return 0;
}