#pragma once
#include<iostream>
#include"BST.h"
using namespace std;

//Constructer of tree node
node::node()
{
	left = right = NULL;
}
//Constructert of tree
tree::tree()
{
	root = NULL;
}
//Insertion by using a value with the root in the tree
void tree::insert(int value, node*& rot)
{
	if (rot == NULL)
	{
		node* newnode = new node;
		newnode->data = value;;
		rot = newnode;
		if (root == NULL)
		{
			root = newnode;
		}
	}

	else if (rot->data < value)
	{
		insert(value, rot->right);
	}
	else if (rot->data > value)
	{
		insert(value, rot->left);
	}
	else
	{
		return;
	}
}

//Function to get root of the tree
node* tree::getRoot()
{
	return root;
}

/*Disfferent Traversals*/
void tree::preorder(node* t)
{
	if (t != NULL)
	{
		cout << t->data << " ";
		preorder(t->left);
		preorder(t->right);
	}
}

void tree::postorder(node* t)
{
	if (t != NULL)
	{
		postorder(t->left);
		postorder(t->right);
		cout << t->data << " ";
	}
}

void tree::BFS()
{
	if (root == NULL)
	{
		cout << "-------Empty--------------";
		return;
	}

	queue<node*> obj;
	obj.push(root);

	while (!obj.empty())
	{
		node* current = obj.front();
		obj.pop();
		cout << current->data << " ";

		if (current->left != NULL)
		{
			obj.push(current->left);
		}
		if (current->right != NULL) {
			obj.push(current->right);
		}
	}
}