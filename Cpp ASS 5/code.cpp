//this is a link list made for segregation of even and odd numbers
//this will print even numbers first and then odd numbers of link list
#include <iostream>
#include <utility>
#include <cassert>

using namespace std;

class LinkedList{
    struct Node{
        int data;
        Node* next = nullptr;
        Node(int value) : data(move(value)), next(nullptr) {}
    };
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    ~LinkedList(){
        Node* tmp = nullptr;
        while (head){
            tmp = head;
            head = head->next;
            delete tmp;
        }
        head = nullptr;
    }

    void insert(int);
    void exchangeEvenOdd();
    void printList() const;

private:
    static void advance(Node*& node){
        assert(node != nullptr);
        node = node->next;
    }

    Node* getLastNode(){
        Node* node = head;
        while (node->next != nullptr)
            node = node->next;

        return node;
    }

    bool isOdd(int num){
        if (num % 2 != 0)
            return true;
        else
            return false;
    }
};

void LinkedList::insert(int value){
    Node* node = new Node(std::move(value));
    Node* tmp = head;
    if (tmp == nullptr){
        head = node;
    }
    else{
        tmp = getLastNode();
        tmp->next = node;
    }
}

void LinkedList::exchangeEvenOdd(){
    Node* node = nullptr;
    Node* lastNodeToTest = getLastNode();
    Node* tail = lastNodeToTest;

    while (isOdd(head->data) == true){
        node = head;
        advance(head);
        tail->next = node;
        advance(tail);
    }

    Node* tmp = head;
    Node* curr = head;

    while (tmp->next != lastNodeToTest){
        if (isOdd(curr->next->data) == true){
            node = curr->next;
            curr->next = node->next;
            tail->next = node;
            advance(tail);
        }
        else{
            //advance "curr" and "tmp" only when next node to it is even
            advance(curr);
            advance(tmp);
        }
    }

    if (isOdd(curr->next->data) == true && tmp->next == lastNodeToTest){
        node = lastNodeToTest;
        curr->next = lastNodeToTest->next;
        tail->next = lastNodeToTest;
        advance(tail);
    }
    tail->next = nullptr;
    lastNodeToTest = nullptr;
    node = nullptr;
}

void LinkedList::printList() const {
    if (head == nullptr){
        cout << "Empty List \n";
        return;
    }
    Node* node = head;
    while (node != nullptr){
        cout << node->data << " ";
        advance(node);
    }
    cout << "\n";
}

int main(){

    system("cls");

    LinkedList ll1;
    ll1.insert(1);
    ll1.insert(2);
    ll1.insert(3);
    ll1.insert(4);
    ll1.insert(5);
    ll1.insert(6);
    ll1.insert(7);
    cout << "Original List : ";
    ll1.printList();

    ll1.exchangeEvenOdd();
    cout << "New List : ";
    ll1.printList();

    system("pause");
}