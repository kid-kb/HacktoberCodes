#include<bits/stdc++.h>
using namespace std;
// Array Implementation
class MyQueue {
private:
    int arr[10001];
    int front;
    int rear;
public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
    void show_queue()
	{
		for(int i=front;i<rear;++i)
			cout<<arr[i]<<" ";
		cout<<"\n";
	}
    int front1()
    {
    	if(front!=rear)
    	{
    		show_queue();
    		return arr[front];
    	}
    	return -1;
	}
	int rear1()
	{
		int x = rear-1;
		if(front!=rear)
		{
			show_queue();
    		return arr[x];
    	}
    	return -1;
	}
};
/* The method push to push element into the queue */
void MyQueue :: push(int x)
{
    arr[rear++] = x;
    show_queue();
}
/*The method pop which return the element 
  poped out of the queue*/
int MyQueue :: pop()
{
    if(rear==front)
        return -1;
    show_queue();    
    return arr[front++];
}
int main()
{
	class MyQueue q;
	cout <<"Now an operation shall be performed where 1_x means pushing x\n2 means poping\n3 means asking for front element\n4 means asking for rear\nEnter the number of times u want to perform the operation\n";
	int n,n1;
	cin>>n1;
	n=n1;
	while(n--)
	{
		cout <<"Enter the case code\n";
		int k;
		cin>>k;
		if(k==1)
		{
			int x;
			cin>>x;
			q.push(x);
		}
		else if(k==2)
			cout<<q.pop()<<"\n";
		else if(k==3)
			cout<<q.front1()<<"\n";
		else if(k==4)
		{
			cout<<q.rear1()<<"\n";
		}
		else
			cout<<"case does not exist\n";
	}
	return 0;	
}
/*
	Like Stack, Queue is a linear structure which follows a particular order in which the operations are performed. The order is First In First Out (FIFO). 
	A good example of queue is any queue of consumers for a resource where the consumer that came first is served first.
	The difference between stacks and queues is in removing. In a stack we remove the item the most recently added; in a queue, 
	we remove the item the least recently added.
	
	Applications of Queue:
	Queue is used when things don’t have to be processed immediately, but have to be processed in First In First Out 
	order like Breadth First Search. This property of Queue makes it also useful in following kind of scenarios.
	1) When a resource is shared among multiple consumers. Examples include CPU scheduling, Disk Scheduling.
	2) When data is transferred asynchronously (data not necessarily received at same rate as sent) between two processes. 
	Examples include IO Buffers, pipes, file IO, etc.
	
	Operations on Queue:
	Mainly the following four basic operations are performed on queue:
	
	Enqueue: Adds an item to the queue. If the queue is full, then it is said to be an Overflow condition.
	Dequeue: Removes an item from the queue. The items are popped in the same order in which they are pushed. If the queue is empty, 
	then it is said to be an Underflow condition.
	Front: Get the front item from queue.
	Rear: Get the last item from queue.
	Time Complexity: Time complexity of all operations like enqueue(), dequeue(), isFull(), isEmpty(), front() and rear() is O(1).
	Again it shall be implemented either by array or list.
*/
