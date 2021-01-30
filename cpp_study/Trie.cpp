#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<set>
#include<cmath>
#include<stack>
#include<random>
#include<iterator>
#include <algorithm>
#include <functional>
#include <cassert>
#include <iomanip>
#include<unordered_map>
#include<bitset>
using namespace std;


struct TrieNode{
    vector<TrieNode*> next;
    bool isfinish;
    TrieNode(){
        isfinish = false;
        next.resize(26);
        for(int i=0;i<26;i++){
            next[i] = NULL;
        }
    }
};

struct Trie{
    TrieNode head;
    void insert(string s){
        int i=0;
        TrieNode *node;
        node = &head;
        while(i < s.size()-1){
            if(node->next[s[i] - 'a'] == NULL){
                TrieNode *n_node = new TrieNode;
                node->next[s[i] - 'a'] = n_node;
            }
            node = node->next[s[i] - 'a'];
            i++;
        }
        if(node->next[s[i] - 'a'] == NULL){
            TrieNode *n_node = new TrieNode;
            node->next[s[i] - 'a'] = n_node;
        }
        node->next[s[i] - 'a']->isfinish = true;
    }
    bool find(string s){
        int i=0;
        TrieNode *node;
        node = &head;
        while(i < s.size()){
            if(node->next[s[i]-'a'] != NULL){
                node = node->next[s[i]-'a'];
                i++;
            }else{
                return false;
            }
        }
        return node->isfinish;
    }
    void search_helper(TrieNode *node, string s, vector<string> &ans){
        if(node->isfinish){
            ans.push_back(s);
        }
        char c;
        for(int i=0;i<26;i++){
            if(node->next[i] != NULL){
                c = ('a'+i);
                search_helper(node->next[i], s+c, ans);
            }
        }
    }
    vector<string> prefix_search(string s){
        int i(0);
        TrieNode *node;
        node = &head;
        while(i < s.size()){
            if(node->next[s[i]-'a'] != NULL){
                node = node->next[s[i]-'a'];i++;
            }else{
                cout << "number of match : " << 0 << endl;
                return vector<string>();
            }
        }
        vector<string> ans;
        search_helper(node, "", ans);
        cout << "number of match : " << ans.size() << endl;
        for(auto &st:ans){
            st = s + st;
        }
        return ans;
    }
};


int main(){
    Trie t;
    t.insert("hello");
    t.insert("hell");
    t.insert("helapple");
    t.insert("apple");
    vector<string> v = t.prefix_search("hel");
    for(auto &s:v){
        cout << s << endl;
    }
}