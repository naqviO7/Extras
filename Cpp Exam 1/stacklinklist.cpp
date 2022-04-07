#include<iostream>
using namespace std;

class node{
    private:
    int num;
    node *next;
    public:
    node(){
        num=0;
        next=NULL;
    }
    friend class StackusingLinklist;
};

class StackusingLinklist{
    private:
    node * top;
    public:
    StackusingLinklist(){
        top=NULL;
    }
    bool isEmpty(){
        if(top==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    void push(int num) {
		node* temp = new node;
		temp->num = num;
		if (top==NULL) {
			temp->next = NULL;
		}
		else {
			temp->next = top;
		}
		top = temp;
	}
    int pop(){
        if (top==NULL)
			return -1;
		node* temp = new node;
		temp = top;
		top = top->next;
		int ret = top->num;
		delete temp;
		return ret;
    }
    int peek() {
		if (top==NULL)
			return -1;
		return top->num;
	}
    void display(){
        if(top==NULL){
            return;
        }
        else{
            node * tmp=new node;
            tmp=top;
            while(tmp!=NULL){
                cout<<tmp->num<<" ";
                tmp=tmp->next;
            }
            cout<<endl;
        }
    }
};

int main(){
    StackusingLinklist st;
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(1);
    st.display();
    st.pop();
    st.display();
    return 0;
}