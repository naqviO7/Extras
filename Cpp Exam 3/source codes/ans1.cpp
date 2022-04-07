#include<iostream>
#include<stack>
#include<queue>

using namespace std;


stack<int> stack1, stack2;
void enqueue(int queue[], int rear, int new_val){
	// Move all elements from s1 to s2 
	while (!stack1.empty()) {
		stack2.push(stack1.top());
		stack1.pop();
	}
	if (front == NULL || priority < front->priority) {
		tmp->rear = front;
		front = tmp;
	}
	else {
		queue = front;
		while (queue->rear != NULL && queue->rear->priority <= priority)
			queue = queue->rear;
		tmp->rear = queue->rear;
		queue->rear = tmp;
	// Push item into s1 
	stack1.push(new_val);
	// Push everything back to s1 
	while (!stack2.empty()) {
		stack1.push(stack2.top());
		stack2.pop();
	}
}