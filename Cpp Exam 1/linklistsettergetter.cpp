//#include<iostream>
//using namespace std;
//
//class node{
//private:
//    int num;
//    node* next;
//public:
//    node(int num=0, node* next=NULL){
//        this->num=num;
//        this->next=next;
//    }
//    void set_num(int num){
//        this->num=num;
//    }
//    void set_next(node * next){
//        this->next=next;
//    }
//    int get_num(){
//        return num;
//    }
//    node* get_next(){
//        return next;
//    }
//    friend class linklist;
//};
//
//class linklist{
//private:
//    node * head;
//public:
//    linklist(){
//        head=NULL;
//    }
//    bool isEmpty(){
//        if(head==NULL){
//            return true;
//        }
//        else{
//            return false;
//        }
//    }
//    void addtohead(int num){
//        node* tmp=new node;
//        tmp->set_num(num);
//        if(head==NULL){
//            tmp->set_next(NULL);
//        }
//        else{
//            tmp->set_next(head);
//        }
//        head=tmp;
//    }
//    void addtotail(int num){
//        node *tmp=new node;
//        tmp=head;
//        while(tmp->get_next()!=NULL){
//            tmp=tmp->get_next();
//        }
//        node *tail=new node;
//        tmp->set_next(tail);
//        tail->set_next(NULL);
//        tail->set_num(num);
//    }
//    void removefromtail() {
//        if (isEmpty()) {
//            //cout << "List is empty!\n";
//            return;
//        }
//        node* temp = new node;
//        temp = head;
//        if (temp->get_next() == NULL) {
//            head = NULL;
//            delete temp;
//            //cout << "List is now empty!\n";
//        }
//        else {
//            while (temp->get_next()->get_next() != NULL) {
//                temp = temp->get_next();
//            }
//            node* tail = new node;
//            tail = temp->get_next();
//            temp->set_next(NULL);
//            delete tail;
//        }
//    }
//    void display() {
//        if (isEmpty()) {
//            cout << "List is empty!\n";
//            return;
//        }
//        else {
//            node* temp = new node;
//            temp = head;
//            while (temp != NULL) {
//                cout << temp->get_num() << " ";
//                temp = temp->get_next();
//            }
//            cout << endl;
//        }
//    }
//};
//
//int main(){
//    linklist ll;
//    ll.addtohead(22);
//    ll.addtohead(23);
//    ll.addtohead(12);
//    ll.addtohead(2);
//    ll.addtohead(62);
//    ll.addtotail(28);
//    ll.addtotail(4);
//    ll.addtotail(7);
//    ll.display();
//    return 0;
//}