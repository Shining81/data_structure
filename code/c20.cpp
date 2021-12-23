#include<iostream>
#include<ctime>
using namespace std;

class box {
	public:
		int length;
		int weith;
		int high;
		int getV();
		void set(int len, int wei,int hi);

};

int box::getV() {
	return length * weith * high;
}

void box::set(int len, int wei, int hi) {
	length = len;
	weith = wei;
	high = hi;
}


int main() {

	box b1;
	b1.set(6, 6, 6);
	int i = 1;
	cout << "第" << i << "个盒子的体积是:" << "\t";
	cout << b1.getV()<< endl;
	time_t now = time(0);
	
	cout << now << endl;
	struct tm t;
	time(&now);
	localtime_s(&t,&now);
	char tick[100];
	strftime(tick, _countof(tick), "%Y/%m/%d  %H:%M:%S", &t);
	printf("%s", tick);
	cout << endl;
	cout << t.tm_year+1900 << endl;
	cout << t.tm_mon+1<< endl;
	cout << t.tm_mday << endl;
	cout <<"礼拜" << t.tm_wday << endl;
	cout << "一年中第" << t.tm_yday << endl;
	cout << t.tm_hour << "点";
	cout << t.tm_min << "分";
	cout << t.tm_sec << "秒";
	return 0;	

}