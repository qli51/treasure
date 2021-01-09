//子线程循环 10 次，接着主线程循环 100 次，接着又回到子线程循环 10 次，接着再回到主线程又循环 100 次，如此循环50次，试写出代码
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;
int flag=10;
mutex mu;
condition_variable cv;
void process(int x,char c){
    for(int i=0;i<50;i++){
        unique_lock<mutex> lock(mu); //谁抢到锁把其他人都锁起来谁能执行(互斥锁，每次只有一个人能拿到锁)
        while(flag!=x){
            cv.wait(lock);//wait起到阻塞的作用
        }
    }
    for(int i=0;i<x;i++){
        cout<<c;
    }
    flag=(x==10)?100:10;
    cv.notify_one();//随即唤醒一个正在等待的线程
}
int main(){
    thread t1(process,10,'c');
    process(100,'a');
    t1.join();
}

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;
int flag=10;
mutex mu;
condition_variable cv;
void process(int x,char c){
    for(int i=0;i<50;i++){
        unique_lock<mutex> lock(mu);
        while(flag!=x) cv.wait(lock);
    }
    for(int i=0;i<flag;i++){
        cout<<c;
    }
    flag=(x==10)?100:10;
    cv.notify_one();
}