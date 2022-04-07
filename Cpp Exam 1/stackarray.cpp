//#include<iostream>
//using namespace std;
//
//class StackusingArray{
//    private:
//    int * stackarr;
//    int tsize;
//    int top;
//    public:
//    StackusingArray(int size){
//        tsize = size;
//		stackarr = new int[tsize];
//		top = 0;
//    }
//    bool isEmpty(){
//        if(top==0){
//            return true;
//        }
//        else{
//            return false;
//        }
//    }
//    bool isFull(){
//        if(top==tsize){
//            return true;
//        }
//        else{
//            return false;
//        }
//    }
//    void push(int num){
//        if(top!=tsize){
//            stackarr[top]=num;
//            top++;
//        }
//        else{
//            return;
//        }
//    }
//    int pop(){
//        if(top!=0){
//            int ret_val;
//            top--;
//            ret_val=stackarr[top];
//            stackarr[top]=0;
//            return ret_val;
//        }
//        else{
//            return 1;
//        }
//    }
//    int peek(){
//        if(top!=0){
//            return(stackarr[top - 1]);
//        }
//		return -1;
//    }
//    void display(){
//        if(top!=0){
//            for(int i=top;i>=0;i--){
//                cout<<stackarr[i]<<" ";
//            }
//        }
//        else {
//            return;
//        }
//    }
//};
//int main(){
//    StackusingArray st(6);
//    st.isEmpty();
//    st.push(0);
//    st.push(1);
//    st.push(2);
//    st.push(3);
//    st.push(4);
//    st.push(5);
//    st.display();
//    st.pop();
//    st.display();
//    st.push(5);
//    st.display();
//    return 0;
//}