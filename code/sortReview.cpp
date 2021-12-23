#include<iostream>
using namespace std;
#include<stdio.h>
#define MAXSIZE 16
int num[MAXSIZE] = { 44,35,56,67,423,334,39,54,656,765,857,42,43,23,55,23 };

void bubble(int* a) {
    int i, j;
    for (i = 0; i < MAXSIZE - 1; i++) {
        for (j = i + 1; j < MAXSIZE; j++) {
            if (a[i] > a[j]) {
                int temp;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
void insert(int* a) {
    int i, j;
    for (i = 1; i < MAXSIZE; i++) {
        for (j = 0; j < i; j++) {
            if (a[i] < a[j]) {
                int temp;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void select(int* a) {

    int i, j, min;

    for (i = 0; i < MAXSIZE; i++) {
        min = i;
        for (j = i + 1; j < MAXSIZE; j++) {
            if (a[j] <= a[min]) {
                min = j;
            }
        }
        int temp;
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

}
void hell(int* a) {
    int gen = MAXSIZE >> 1;
    int i, j;
    for (gen; gen > 0; gen = gen >> 1) {
        for (i = gen; i < MAXSIZE; i++) {
            int temp = a[i];
            for (j = i - gen; j >= 0 && a[j] >= temp; j = j - gen) {
                a[j + gen] = a[j];
            }
            a[j + gen] = temp;
        }
    }
}
void merge(int* arr) {
    int* a = arr;
    int* b = (int*)malloc(sizeof(int) * 100);
    int gen = 1;
    int start1, end1, start2, end2;
    int low, mid, high;
    for (gen = 1; gen < MAXSIZE; gen = gen + gen) {
        int k = 0;
        int start;
        for (start = 0; start < MAXSIZE; start = start + gen + gen) {
            low = start; mid = min(start + gen, MAXSIZE); high = min(start + gen + gen, MAXSIZE);
            start1 = low; end1 = mid; start2 = mid; end2 = high;
            while (start1 < end1 && start2 < end2) {
                b[k++] = a[start1] <= a[start2] ? a[start1++] : a[start2++];
            }
            while (start1 < end1) {
                b[k++] = a[start1++];
            }
            while (start2< end2) {
                b[k++] = a[start2++];
            }
        }
        int* temp;
        temp = a;
        a = b;
        b = temp;
    }
    if (a != arr) {
        for (int i = 0; i < MAXSIZE; i++) {
            b[i] = a[i];
        }
        b = arr;
    }
    free(b);
}

int getindex(int* a, int low, int high) {
    int i = (low - 1);
    int index = a[high];
    for (int j = low; j < high; j++) {
        if (a[j] <= index) {
            i++;
            int temp; temp = a[i]; a[i] = a[j]; a[j] = temp;
        }
    }
    int temp2; temp2 = a[i + 1]; a[i + 1] = a[high]; a[high] = temp2;
    return (i + 1);
}

void quick(int* a, int low, int high) {
    if (low < high) {
        int pi = getindex(a, low, high);
        quick(a, low, pi - 1);
        quick(a, pi + 1, high);
    }
}

int main() {

    //bubble(num);
    //insert(num);
    //select(num);
    //hell(num);
    //merge(num);
    quick(num, 0, MAXSIZE-1);
    for (int i = 0; i < MAXSIZE; i++) {
        printf("%d<", num[i]);
    }
    printf("\n");
    //printf("%d", min(1, 2));
    return 0;
}