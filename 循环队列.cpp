#include<iostream>
using namespace std;
#define MAXSIZE 6


typedef struct {
	int data[MAXSIZE];
	int front, rear;
}queue;

void init(queue& q) {
	q.front = 0;
	q.rear = 0;

}
int i = 0;
bool push(queue& q, int x) {
	if ((q.rear+1) % MAXSIZE == q.front) {
		printf("������");
		return false;
	}
	q.data[q.rear] = x;
	q.rear = (q.rear + 1) % MAXSIZE;
	cout << ++i << endl;
	return true;
}

int getfront(queue& q) {
	return q.data[q.front];
}
int getrear(queue& q) {
	return q.data[q.rear];
}

bool pop(queue& q) {
	
	
	
	if (q.front == q.rear) { //q.rear ���Ǹ���Ч�Ŀ�ֵ
		printf("queue is empty");
		return false;
	}
	q.front = (q.front + 1) % MAXSIZE;
	return true;
}


int main() { //ֻ��������Ԫ�أ���Զ��һ���ռ�Ϊ��ֵ, 
	queue q1;
	init(q1);
	push(q1, 1);
	push(q1, 2);
	push(q1, 3);
	push(q1, 4);
	push(q1, 6);
	
	pop(q1); pop(q1); pop(q1); pop(q1);


	
	
	cout <<"��ǰԪ��Ϊ"<< getfront(q1) << endl;
	
}