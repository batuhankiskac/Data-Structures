#ifndef BST_HPP
#define BST_HPP

#include <iostream>

struct Node {
	int data;
	Node* left;
	Node* right;
};

class BST {
private:
	Node *root;

	Node* insertHelper(Node *node, int value) {
		if (node == nullptr) {
			Node* newNode = new Node();
			newNode->data = value;
			newNode->left = nullptr;
			newNode->right = nullptr;
			return newNode;
		}
		if (value < node->data)
			node->left = insertHelper(node->left, value);
		else if (value > node->data)
			node->right = insertHelper(node->right, value);
		return node;
	}

	bool searchHelper(Node *node, int value) {
		if (node == nullptr)
			return false;

		if (node->data == value)
			return true;

		if (value < node->data)
			return searchHelper(node->left, value);
		else
			return searchHelper(node->right, value);
	}

	Node* findMin(Node *node) {
		while (node != nullptr && node->left != nullptr)
			node = node->left;
		return node;
	}

	Node* removeHelper(Node *node, int value) {
		if (node == nullptr)
			return nullptr;

		if (value < node->data) {
			node->left = removeHelper(node->left, value);
		} else if (value > node->data) {
			node->right = removeHelper(node->right, value);
		} else {
			if (node->left == nullptr) {
				Node* temp = node->right;
				delete node;
				return temp;
			} else if (node->right == nullptr) {
				Node* temp = node->left;
				delete node;
				return temp;
			}

			Node* temp = findMin(node->right);
			node->data = temp->data;
			node->right = removeHelper(node->right, temp->data);
		}
		return node;
	}

	void preOrderHelper(Node *node) {
		if (node != nullptr) {
			std::cout << node->data << " ";
			preOrderHelper(node->left);
			preOrderHelper(node->right);
		}
	}

	void inOrderHelper(Node *node) {
		if (node != nullptr) {
			inOrderHelper(node->left);
			std::cout << node->data << " ";
			inOrderHelper(node->right);
		}
	}

	void postOrderHelper(Node *node) {
		if (node != nullptr) {
			postOrderHelper(node->left);
			postOrderHelper(node->right);
			std::cout << node->data << " ";
		}
	}
public:
	BST() : root(nullptr) { }

	void insert(int value) { root = insertHelper(root, value); }
	bool search(int value) { return searchHelper(root, value); }
	void remove(int value) { root = removeHelper(root, value); }

	void preOrder() {
		preOrderHelper(root);
		std::cout << "\n";
	}

	void inOrder() {
		inOrderHelper(root);
		std::cout << "\n";
	}

	void postOrder() {
		postOrderHelper(root);
		std::cout << "\n";
	}
};

#endif
