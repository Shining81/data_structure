#include<iostream>
using namespace std;

#define MAXSIZE 10

typedef struct { //顺序队列
	int data[MAXSIZE];
	int front, rear;
}SQ_queue;

void initsqqueue(SQ_queue &q) {
	q.front = 0;
	q.rear = -1;
}

bool isempty(SQ_queue& q) {
	if (q.front > q.rear) {
		return true;
	}
	else {
		return false;
	}
}
bool push(SQ_queue &q, int x) {
	if (q.rear >= MAXSIZE) {
		cout << "队列已满" << endl;
		return false;
	}
	q.data[++q.rear] = x;
	return true;
	
}

bool pop(SQ_queue &q) {
	if (isempty(q)){
		printf("queue is empty\n");
		return false;
	}
	q.front++;
	return true;
}


int getfront(SQ_queue &q) {
	if (isempty(q)) {
		cout << "队空" << endl;
		return 0;
	}
	return q.data[q.front];
}

int getrear(SQ_queue &q){
	if (isempty(q)) {
		return 0;
	}
	return q.data[q.rear];
}

int main() {
	SQ_queue q1;
	initsqqueue(q1);
	push(q1, 3);
	push(q1, 6);
	push(q1, 4);
	pop(q1);
	cout << getfront(q1) << endl;
	cout << getrear(q1) << endl;
}
