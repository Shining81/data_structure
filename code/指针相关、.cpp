#include<iostream>
using namespace std;

typedef struct node {
    int data;
    struct node* next;
}lnode, * linklist;

linklist init() {
    linklist l = new(node);
    l->next = NULL;
    return l;
}

void creat(linklist& l) {
    int i;
    linklist p = l;
    
    for (i = 0; i < 10; i++) {
        linklist newnode = new(node);
        newnode->data = i + 1;
        newnode->next = NULL;
        p->next = newnode;
        p = newnode;
    }
}

void printlist(linklist& l) {
    l = l->next;
    while (l) {
        printf("%d", l->data);
        l = l->next;
    }
}


linklist reverse(linklist &l) {
    
    linklist pre, cur, temp;
    cur = l->next;
    pre = NULL;
    while (cur) {
        temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    l->next = pre;
    return l;
}
int main() {
    linklist l1;
    l1 = init();
    creat(l1);
    reverse(l1);
    printlist(l1);
    return 0;
}