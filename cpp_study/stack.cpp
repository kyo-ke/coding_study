#include<iostream>
#include<vector>
using namespace std;
class mystack
{
    vector<int> buf;
    int place;
    int max_size = 100;//Staticクラス変数的なのないかなあ？
    public:
    mystack()
    {
        place = -1;
        buf.reserve(max_size);
    }
    int pop()
    {
        if (place == -1)
        {
            return INT8_MAX;
        }else
        {
            place -= 1;
            return buf[place + 1];
        }
    }
    void push(int a)
    {
        place += 1;
        buf[place] = a;
    }
    int cat()
    {
        return buf[place];
    }
};

int main()
{
    mystack st;
    st.push(6);
    cout << st.cat() << endl;
    st.push(7);
    st.push(8);
    mystack st_;
    st_.push(100);
    cout << st.pop() << endl;//8
    cout << st.pop() << endl;//7
    cout << st_.pop() << endl;//100
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    st.push(30);
    cout << st.pop() << endl;
    return 0;
}