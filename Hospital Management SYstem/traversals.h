#pragma once
#include "BST.h"
#include <iostream>

// implementation of tree traversals



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
