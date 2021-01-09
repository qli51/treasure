//编写一个程序，开启3个线程，这3个线程的ID分别为A、B、C，每个线程将自己的ID在屏幕上打印10遍，要求输出结果必须按ABC的顺序显示；如：ABCABC….依次递推。
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;
mutex mu;
condition_variable cv;
int flag=0;
void process(int n){
	for(int i=0;i<10;i++){
		unique_lock<mutex> lock(mu);
		while(n!=flag){
			cv.wait(lock);
		}
		char temp='A'+n;
		cout<<temp;
		flag=(flag+1)%3;
		cv.notify_all();
	}
}
int main(){
    thread t1(process,1);
    thread t2(process,2);
    process(0);
    t1.join();
    t2.join();
}