#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char* data;
    int front, rear;
}queue;
void INITqueue(queue& q) {
    q.data = (char*)malloc(sizeof(char) * 10);
    q.front = q.rear = 0;
}
bool isempth(queue& q) {
    if (q.front == q.rear) {
        return true;
    }
    else {
        return false;
    }
}

bool enqueue(queue& q, char t) {
    if ((q.rear + 1) % 10 == q.front) {
        return false;
    }
    else {
        q.data[q.rear] = t;
        q.rear = (q.rear + 1) % 10;
        return true;
    }
}

char dequeue(queue& q, char x) {
    if (isempth(q)) {
        printf("This queue is empty");
    }
    else {
        x = q.data[q.front];
        q.front = (q.front + 1) % 10;
        return x;
    }
}

int main() {
    queue q1;
    INITqueue(q1);
    enqueue(q1, 'h');
    
    printf("%c\n", q1.data[q1.front]);
    char c = 'a';
    dequeue(q1, c);

    printf("%c\n", dequeue(q1, c));
    return 0;
}