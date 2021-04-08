#include<iostream>
#include<vector>
using namespace std;
//| tail head | | 
//| tail 1 | 2 | 3 | head|
//  | 1 | head | tail
class myqueue
{
    vector<int> buf;
    int max_size = 3;
    int head, tail, return_val;
    public:
    myqueue(){
       head = 0;
       tail = 0;
       buf.reserve(max_size);
    }
    int pop(){
       if (!isempty()){
           return_val = buf[head];
           head = (head + 1)%max_size;
           return return_val;
       }else{
           cout << "error : no_value" << endl;
           return INT_MAX;
       }
    }
    void push(int val)
    {
        
        if(!ismax()){
            buf[tail] = val;
            tail = (tail + 1) % max_size;
        }else{
            cout << "error : no area for new value" << endl;
        }
    }
    int isempty()
    {
        if(head == tail){
            return true;
        }else{
            return false;
        }
    }
    int ismax()
    {
        if ((tail + 1) % max_size == head){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    myqueue mq;
    cout << mq.pop() << endl;
    mq.push(1);//ok
    mq.push(2);//ok
    mq.push(3);//no
    mq.push(4);//no
    cout << mq.pop() << endl;//1
    cout << mq.pop() << endl;//2
    mq.push(100);
    cout << mq.pop() << endl;//100
    mq.push(1);//ok
    mq.push(2);//ok
    mq.push(3);//no
    cout << mq.pop() << endl;//1
    cout << mq.pop() << endl;//2
    return 0;
}