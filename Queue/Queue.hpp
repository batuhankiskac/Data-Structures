#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

class Queue {
private:
	int *q;
	int front;
	int rear;
	int size;

public:
	Queue(int s) : size(s), front(-1), rear(-1) {
		q = new int[size];
	}

	~Queue() {
		delete[] q;
	}

	bool isFull() const {
		/*
		İki senaryo var dolu olması için circular olduğundan dolayı ya front
		rear'ın hemen önünde olacak ya da front 0 ve rear size-1'de olacak.
		*/
		if (front == rear + 1 || (front == 0 && rear == size - 1))
			return true;
		return false;
	}

	bool isEmpty() const {
		// Herhangi bir eleman eklediğimiz frontu 0 yaptığımız için -1 ise boş demektir.
		return front == -1;
	}

	void enqueue(int item) {
		if (isFull) {
			std::cout << "Queue is full!\n";
			return;
		}

		// Eğer ilk elemanı ekliyorsak front'u 0 yapıyoruz.
		if (front == -1)
			front = 0;

		// Circular olarak rear'ı bir sonraki pozisyona getiriyoruz ve elemanı ekliyoruz.
		rear = (rear + 1) % size;
		q[rear] = item;
	}

	int dequeue() {
		if (isEmpty()) {
			std::cout << "Queue is empty!\n";
			return -1;
		}

		// Front'taki elemanı alıyoruz. Sonrasında front'u bir sonraki pozisyona getiriyoruz.
		int element = q[front];
		if (front == rear)
			front = rear = -1;
		else
			front = (front + 1) % size;

		// Kaydettiğimiz elemanı döndürüyoruz.
		return element;
	}
};

#endif
