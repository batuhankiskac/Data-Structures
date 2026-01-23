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

	/*
	Eğer node null ise ya ekleyeceğimiz yeri bulduk ya da ağaç boş.
	Bu durumda yeni bir node oluşturup değeri atıyoruz. Eğer ekleyeceğimiz değer mevcut node'un
	değerinden küçükse sol alt ağaca, büyükse sağ alt ağaca gitmesi için fonksiyonu
	tekrar çağırıyoruz. Bu sayede doğru pozisyonu bulana kadar ilerliyoruz.
	*/
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

	/*
	Eğer node null ise aranan değer ağaçta yok demektir. Eğer mevcut node'un değeri
	aranan değere eşitse true döndürüyoruz. Eğer aranan değer mevcut node'un değerinden küçükse
	sol alt ağaca, büyükse sağ alt ağaca gitmesi için fonksiyonu tekrar çağırıyoruz.
	Bu sol sağ olayı BST'lerin temel özelliğinden dolayı.
	*/
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

	/*
	Minimum değeri bulmak için en sola doğru ilerliyoruz çünkü BST'de en küçük değer
	sol en uçtaki node'da bulunur.
	*/
	Node* findMin(Node *node) {
		while (node != nullptr && node->left != nullptr)
			node = node->left;
		return node;
	}

	/*
	İlk olarak aranan değeri bulana kadar ağacı dolaşıyoruz. Değer bulunduğunda
	üç durumla karşılaşıyoruz:
	1. Silinecek node'un tek çocuğu varsa, o çocuğu silinecek node'un yerine geçiriyoruz.
	2. Silinecek node'un iki çocuğu varsa, sağ alt ağacın en küçük değerini (inorder successor)
	bulup silinecek node'un değerini onunla değiştiriyoruz. Sonra inorder successor'ı siliyoruz.
	3. Silinecek node'un çocuğu yoksa (yaprak node), doğrudan siliyoruz.
	*/
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

	/*
	Üç farklı dolaşma yöntemi var: pre-order, in-order ve post-order.
	Pre-order'da önce node'un kendisi, sonra sol alt ağaç, en son sağ alt ağaç ziyaret edilir.
	In-order'da önce sol alt ağaç, sonra node'un kendisi, en son sağ alt ağaç ziyaret edilir.
	Post-order'da ise önce sol alt ağaç, sonra sağ alt ağaç, en son node'un kendisi ziyaret edilir.
	Bu fonksiyonlar rekürsif olarak çalışır ve her node'u belirtilen sırayla ziyaret eder.
	Ekstra bilgi olarak, in-order dolaşma BST'de sıralı bir çıktı verir.
	*/
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
