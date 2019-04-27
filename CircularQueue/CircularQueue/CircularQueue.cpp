// CircularQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

class Queue {
	int front, rear;
	int size;
	int *arr;
public:
	Queue(int s){
		front = rear = -1;
		size = s;
		arr = new int[s];
	}
	void enqueue(int value);
	int deque();
	void display();
};
 
void Queue::enqueue(int value) {
	if ((front == 0 && rear == size - 1) || 
		(rear == (front - 1) % (size - 1))) {
		cout<<"Queue is full";
		return;
	}
	else if (front == -1) {
		front = rear = 0;
		arr[rear] = value;
	}
	else if (rear == size-1 && front !=0) {
		rear = 0; 
		arr[rear] = value;
	}
	else {
		rear++;
		arr[rear] = value;
	}

}

int Queue::deque() {
	if (front == -1) {
		cout << "Queue is empty";
		return INT_MIN;
	}
	int data = arr[front];
	arr[front] = -1;
	if (front == rear) {
		front = -1;
		rear = -1;
	}
	else if (front == size - 1) 
		front = 0;
	else
		front++;
	return data;
}

void Queue::display() {
	if (front == -1) {
		cout << "\n Queue is empty";
		return;
	}
	cout << "Elements in the circular queue are:\n";
	if (rear >= front) {
		for (int i = front; i <= rear; i++) {
			cout << arr[i] << endl;
		}
	}
	else {
		for (int i = front; i < size; i++)
			cout << arr[i] << endl;
		for (int i = 0; i <= rear; i++)
			cout << arr[i];
	}
}

int main()
{
	Queue q(5);
	
	//Inserting elememts in Circular Queue
	q.enqueue(14);
	q.enqueue(20);
	q.enqueue(5);
	q.enqueue(-2);
	//display the queue created 
	q.display();
	//delete the elements of circular queue
	cout << "Deleted value is: "<< q.deque() << endl;
	cout << "Deleted value is: " << q.deque() << endl;
	//entering values again
	q.enqueue(9);
	q.enqueue(20);
	//display queue
	q.display();
	q.enqueue(5);
	return 0;
}