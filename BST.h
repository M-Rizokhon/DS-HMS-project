// Implementation of Binary Search Tree data structure

#pragma once
#include <iostream>



struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


class BST {
private:
	Node* root;

	// insert a new node (recursive)
	Node* insert(Node* node, int key) {
		if (node == nullptr) 
			return new Node(key);
		
		if (key > node->data)
			node->right = insert(node->right, key);
		else
			node->left = insert(node->left, key);

		return node;		
	}


	// search for a value (recursive)
	Node* search(Node* node, int key) {
		if (!node) return nullptr;

		if (node->data == key)
			return node;

		if (key > node->data)
			search(node->right, key);
		else
			search(node->left, key);

		return node;
	}


	// find a min node (iterative for better performance) 
	Node* findMin(Node* node) {
		while (node && node->left) {
			node = node->left;
		}

		return node;
	}

	// find a max node (iterative for better performance)
	// (inorder succeessor)
	Node* findMax(Node* node) {
		while (node && node->right) {
			node = node->right;
		}

		return node;
	}


	// delete a node 
	Node* remove(Node* node, int key) {
		if (!node) return nullptr;

		if (key > node->data)
			node->right = remove(node->right, key);
		else if (key < node->data)
			node->left = remove(node->left, key);

		else {
			// Case 1: No child
			if (node->left == nullptr && node->right == nullptr) {
				delete node;
				return nullptr;
			}


			// Case 2: One child
			if (node->left == nullptr) {
				Node* temp = node->right;
				delete node;
				return temp;
			}

			else if (node->right == nullptr) {
				Node* temp = node->left;
				delete node;
				return temp;
			}

			// case 3: Two children
			// replace with inorder predecessor (personal choice)
			Node* pred = findMax(node->left);
			node->data = pred->data;
			node->left = remove(node->left, pred->data);
		}

		return node;
	}



	// tree traversals
	// left - root - right
	void inorder(Node* node) {
		if (!node) return;
		inorder(node->left);
		std::cout << node->data << " ";
		inorder(node->right);
	}


	// root - left - right
	void preorder(Node* node) {
		if (!node) return;
		std::cout << node->data << " ";
		preorder(node->left);
		preorder(node->right);
	}


	// left - right - root
	void postorder(Node* node) {
		if (!node) return;
		postorder(node->left);
		postorder(node->right);
		std::cout << node->data << " ";
	}


public:
	BST() : root(nullptr) {}

	void insert(int key) {
		root = insert(root, key);
	}

	void remove(int key) {
		root = remove(root, key);
	}

	bool search(int key) {
		return search(root, key) != nullptr;
	}

	void printPreorder() {
		preorder(root);
		std::cout << std::endl;
	}

	void printInorder() {
		inorder(root);
		std::cout << std::endl;
	}

	void printPostorder() {
		postorder(root);
		std::cout << std::endl;
	}

};



