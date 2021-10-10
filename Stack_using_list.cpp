#include<bits/stdc++.h>
using namespace std;
// Implementation using list
class stacknode
{
	public:
	int data;
	class stacknode *next;
};
void push(class stacknode **head,int x)
{
	if(*head==NULL)
	{
		(*head)=new stacknode;
		(*head)->data=x;
		(*head)->next=NULL;
		return;
	}
	class stacknode *temp;
	temp = new stacknode;
	temp->data = x;
	temp->next=(*head);
	(*head)=temp;
}
int pop(class stacknode **head)
{
	if(*head==NULL)
		return -1;
	if((*head)->next==NULL)
	{
		int x = (*head)->data;
		(*head) = NULL;
		return x;
	}
	int x = (*head)->data;
	(*head)=(*head)->next;
	return x;
}
int peek(class stacknode *head)
{
	if(head==NULL)
		return -1;
	return (head->data);
}
bool isEmpty(class stacknode *head)
{
	if(head==NULL)
		return true;
	return false;
}
int main()
{
	class stacknode *head;
	head=NULL;
	cout <<"Now an operation shall be performed where 1_x means pushing x\n2 means poping\n3 means asking for top element\n4 means asking whether stack is empty or not\nEnter the number of times u want to perform the operation\n";
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
			push(&head,x);
		}
		else if(k==2)
			cout<<pop(&head)<<"\n";
		else if(k==3)
			cout<<peek(head)<<"\n";
		else if(k==4)
		{
			if(isEmpty(head))
				cout<<"Empty\n";
			else
				cout<<"Not empty\n";
		}
		else
			cout<<"case does not exist\n";
	}
}
