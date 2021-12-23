#include<iostream>
using namespace std;
#include<stdio.h>
#define N 10

int a[N] = { 1,2,3,4,5,6,7,8,9,10 };

int half(int* a, int x, int low, int high) {
    if (low > high) {
        printf("不存在！");
        return 0;
    }
    int mid = (low + high) / 2;
    int found[N];
    if (a[mid] == x) {
        return mid;
    }
    if (a[mid] < x) {
        low = mid+1;
        return half(a, x, low, high);
    }
    if (a[mid] > x) {
        high = mid-1;
        return half(a, x, low, high);
    }
    
    return 0;
}
int BAOLI(int* a, int x) {
    for (int i = 0; i < N; i++) {
        if (a[i] == x) {
            return i;
        }
    }
}
int main() {
    int i = 5;
    half(a, 6, 0, 9);
    cout << "8在数组中的位置是：" << half(a, 6, 0, 9) + 1 << endl;
    //cout<<"8在数组中的位置是："<<BAOLI(a,8)+1;
    return 0;
}
