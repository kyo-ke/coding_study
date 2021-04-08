#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

string find_longest(string s, int k){
    int head(0), tail(0), ans_head(-1), ans_tail(-1), count(0);
    unordered_map<char, int> m;
    while(s.size() > tail){
        cout << tail << endl;
        while(s.size() > tail && count <= k){
            if(m.find(s[tail]) != m.end() && m[s[tail]] > 0){
                m[s[tail++]]++;
            }else if(count < k){
                m[s[tail++]]++;count++;
            }else{
                break;
            }
        }
        if(count == k && tail - head > ans_tail - ans_head){
            ans_tail = tail;ans_head = head;
        }
        if(tail == s.size())break;
        m[s[tail++]]++;count++;
        while(count > k){
            if(m[s[head]] == 1){
                count--;m[s[head++]]--;
            }else{
                m[s[head++]]--;
            }
        }
    }
    if(ans_head != -1){
        return s.substr(ans_head, ans_tail - ans_head);
    }else{
        return "";
    }
}

int main(){
    string s;
    int k;
    cin >> s >> k;
    cout << find_longest(s,k) << endl;
    return 0;
}
