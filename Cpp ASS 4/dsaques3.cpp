#include<iostream>
#include<queue>

using namespace std;

template <typename T>

// Structure of the queue
class MinMaxQueue {
public:
    // Queue to store the element to maintain the order of insertion
    queue<T> Q;

    // Doubly ended queue to get the minimum element
    // in the O(1) time
    deque<T> D;

    // Function to push a element into the queue
    void enque_element(T element) {
        // If there is no element in the queue
        if (Q.size() == 0) {
            Q.push(element);
            D.push_back(element);
        }
        else {
            Q.push(element);

            // Pop the elements out until the element at back is greater than current element
            while (!D.empty() &&
                D.back() > element) {
                D.pop_back();
            }
            D.push_back(element);
        }
    }

    // Function to pop the element out from the queue
    void deque_element() {
        // Condition when the Minimum element is the element at the front of the Deque
        if (Q.front() == D.front()) {
            Q.pop();
            D.pop_front();
        }
        else {
            Q.pop();
        }
    }

    // Function to get the minimum element from the queue
    T getMin() {
        return D.front();
    }
};

// Driver Code
int main() {
    system("cls");

    MinMaxQueue<int> k;
    int example[3] = { 1, 2, 4 };

    // Loop to enque element
    for (int i = 0; i < 3; i++) {
        k.enque_element(example[i]);
    }

    cout <<"Minimum Element: " << k.getMin() << "\n";

    //dequing element then printing minimmum element
    k.deque_element();

    cout << "Minimum Element: " << k.getMin() << "\n";

    return 0;
}
