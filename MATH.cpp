#include<iostream>

// 三阶行列式的值

int arr[3][3] = { 1,1,1,1,1,1,1,1,1};

int getsum(int a[][3]) {
	int sum;
	sum = a[0][0] + a[1][1] + a[2][2];
	return sum;
}

int main() {
	int i, j;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 3; ++j) {
			std::cout << arr[i][j]<<" ";
		}
		std::cout << "\n";
	}
	
	std::cout << getsum(arr);



	return 0;
}