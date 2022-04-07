#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    string data;
    Node(string d){
        data = d;
    }
    Node *ptr;
};

// Function to check if the linked list
// is palindrome or not
string isPalin(Node* head){
    Node* slow= head;
    stack <string> s;
    while(slow != NULL){
        s.push(slow->data);
        slow = slow->ptr;
    }


    while(head != NULL ){
        string i=s.top();
        s.pop();
        if(head -> data != i){
            return "Not Palindrome";
        }
        head=head->ptr;
    }

    return "Palindorme";
}

int main(){

    //adding data to link list
    Node one =  Node("m");
    Node two = Node("a");
    Node three = Node("d");
    Node four = Node("a");
    Node five = Node("m");

    five.ptr = NULL;
    one.ptr = &two;
    two.ptr = &three;
    three.ptr = &four;
    four.ptr = &five;
    Node* temp = &one;

    string result = isPalin(&one);

    if(result == "1")
        cout<<"Srting is Palindrome\n";
    else
        cout<<"String is not Palindrome\n";

    return 0;
}