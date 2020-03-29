#include<iostream>
using namespace std;
struct node{
	int data;
	node *lchild;
	node *rchild;
	node()
	{
		lchild = NULL;
		rchild = NULL;
	}
};
struct queue{
	node **q;
	int size;
	int front;
	int rear;
	queue(int size)
	{
		q = new node*[size];
		front = -1;
		rear = -1;
	}
	void enqueue(node *ptr);
	node* dequeue();
	void display();
	bool isEmpty();
};
void queue::enqueue(node *ptr)
{	
	q[++rear] = ptr;
	if(front == -1)
		front = 0;
}
node *queue::dequeue()
{
	node *ptr = NULL;
	if(front == -1 || rear == -1 || front > rear)
	{
		cout << "Queue is empty" << endl;
		return ptr;
	}
	else
	{
		ptr = q[front++];
		return ptr;
	}
}
void queue::display()
{
	if(rear == -1 || front == -1 || front > rear)
	{
		cout << "The queue is empty" << endl;
		return;
	}
	int i;
	for(i=front;i<=rear;i++)
		cout << q[i]->data << " ";
	cout << endl;	
}
bool queue::isEmpty()
{
	if(front == -1 || rear == -1 || front > rear)
		return false;
	else
		return true;	
}
void preorder(node *root)
{
	if(root!=NULL)
	{
		cout << root->data << " ";
		preorder(root->lchild);
		preorder(root->rchild);
	}
}
void postorder(node *root)
{
	if(root != NULL)
	{
		postorder(root->lchild);
		postorder(root->rchild);
		cout << root->data << " ";
	}
}
void inorder(node *root)
{
	if(root != NULL)
	{
		inorder(root->lchild);
		cout << root->data << " ";
		inorder(root->rchild);
	}
}
int main()
{
	int temp1,size;
	node *ptr1,*ptr2,*root;
	root = new node();
	cout << "Enter the number of nodes" << endl;
	cin >> size;
	queue q(size);
	cout << "Enter the data of the root" << endl;
	cin >> root->data;
	q.enqueue(root);
	while(q.isEmpty())
	{
		ptr1 = q.dequeue();
		cout << "Enter the left child of " << ptr1->data << endl;
		cin >> temp1;
		if(temp1!=-1)
		{
			ptr2 = new node();
			ptr2->data = temp1;
			ptr1->lchild = ptr2;
			q.enqueue(ptr2);
		}
		cout << "Enter the right child of " << ptr1->data << endl;
		cin >> temp1;
		if(temp1!=-1)
		{
			ptr2 = new node();
			ptr2->data = temp1;
			ptr1->rchild = ptr2;
			q.enqueue(ptr2);
		}
	}
	preorder(root);
	cout << endl;
	postorder(root);
	cout << endl;
	inorder(root);
	cout << endl;
	return 0;
}
