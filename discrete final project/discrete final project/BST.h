//Tree Implementation to displau users Friends In inorder preorder and BST
#include<iostream>
#include<queue>
using namespace std;
class node
{
public:
	int data;
	node* left, * right;
	node();
};
class tree
{
	node* root;
public:
	tree();
	void insert(int value, node*& rot);
	node* getRoot();
	void preorder(node* rot);
	void postorder(node* rot);
	void BFS();
};