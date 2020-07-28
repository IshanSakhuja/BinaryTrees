#include<iostream>
#include<stdint.h>
using namespace std;
struct node{
	int data;
	node *left;
	node *right;
	node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
}*root,*p,*temp,*l;
void create();
void preorder(node *);
void postorder(node *);
void inorder(node *);
class queue{
	public:
		node **ishan;
		int front;
		int rear;
		queue()
		{
			rear = front = 0;
			ishan = new node*[100];
			for(int i=0;i<100;i++)
			{
				ishan[i] = NULL;
			}
		}
		void enqueue(node *ptr)
		{
			ishan[front++] = ptr;
		}
		node * dequeue()
		{
			return ishan[rear++];
		}
		bool isEmpty()
		{
			if(front == rear)
				return true;
			else 
				return false;
		}
};
class stack{
	public:
		node **ishan;
		int index;
		stack()
		{
			ishan = new node*[100];
			index = -1;
			for(int i=0;i<100;i++)
				ishan[0] = NULL;
		}
		void push(node *ptr)
		{
			ishan[++index] = ptr;
		}
		node* pop()
		{
			return ishan[index--];
		}
		bool isEmpty()
		{
			if(index == -1)
				return true;
			else
				return false;
		}
};
int main()
{
	int a;
	root = p = temp = NULL;
	cout << "Enter the operation to be performed" << endl;
	while(1)
	{
		cout << "1.Create BT\n2.Preorder\n3.Inorder\n4.Postorder\n5.Exit" << endl;
		cin >> a;
		switch(a)
		{
			case 1:
				create();
				break;
			case 2:
				preorder(root);
				break;
			case 3:
				inorder(root);
				break;
			case 4:
				postorder(root);
				break;
			case 5:
				exit(0);
			default:
				cout << "Enter the right key" << endl;		
		}
	}
	return 0;
}
void create(){
	queue Queue;
	int ishan,left,right;
	cout << "Enter the value of the root node" << endl;
	cin >> ishan;
	temp = new node(ishan);
	if(root == NULL)
	{
		root = temp;
		Queue.enqueue(root);
	}
	while(!(Queue.isEmpty()))
	{
		p = Queue.dequeue();
		cout << "Enter the left child of " << p->data << endl;
		cin >> left;
		if(left != -1)
		{
			temp = new node(left);
			p->left = temp;
			Queue.enqueue(temp);
		}
		cout << "Enter the right child of " << p->data << endl;
		cin >> right;
		if(right != -1)
		{
			temp = new node(right);
			p->right = temp;
			Queue.enqueue(temp);
		}
	}
}
void postorder(node *root)
{
	uintptr_t temp;
	stack Stack;
	while(root != NULL || !(Stack.isEmpty()))
	{
		if(root != NULL)
		{
			Stack.push(root);
			root = root->left;	
		}else{
			temp = (intptr_t)Stack.pop();
			if(temp > 0)
			{
				Stack.push((node*)-temp);
				root = ((node*)temp)->right;
			}else{
				cout << ((node *)temp)->data << endl;
				root = NULL;
			}
		}
	}
}
void preorder(node *root){
	stack Stack;
	while(root != NULL || !(Stack.isEmpty()))
	{
		if(root != NULL)
		{
			cout << root->data << endl;
			Stack.push(root);
			root = root->left;
		}else{
			root = Stack.pop();
			root = root->right;
		}
	}
}
void inorder(node *root)
{
	stack Stack;
	while(root != NULL || !(Stack.isEmpty()))
	{
		if(root != NULL)
		{
			Stack.push(root);
			root = root->left;
		}else{
			root = Stack.pop();
			cout << root->data << endl;
			root = root->right;
		}
	}
}
