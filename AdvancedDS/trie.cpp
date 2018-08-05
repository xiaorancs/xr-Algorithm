/**
 * Author: xiaoran
 * Time: 2018-08-05 10:26
 * 
 * 这里使用所有的只有小写字母的单词进行构造字典树
 * 这只是一个例子，使用时候需要修改，特别是使用中文的时候
 */
#include <bits/stdc++.h>
using namespace std;

const int SIZE = 26;

struct TrieNode{
    struct TrieNode* children[SIZE];
    // 标记是单词的结尾
    bool isEndOfWord;
    TrieNode(){
        for(int i=0;i<SIZE;i++){
            children[i] = NULL;
        }
        isEndOfWord = false;
    }
};

class Trie{
public:
    Trie(){
        init();
    }
    void init(){
        root = new TrieNode();
        count = 0;
    }
    ~Trie(){
        delete root;
    }
    void insert(string key) {
        struct TrieNode *p = root;
        for(int i=0;i<key.size();i++){
            int index = key[i] - 'a';
            // if 当前的节点对应的这个子节点不存在, 初始化这个节点
            if(!p->children[index]) {
                p->children[index] = new TrieNode();
            }
            // 每过一个字符都要进行下一个字符继续使用
            p = p->children[index];
        }
        p->isEndOfWord = true;
        count ++;
    }

    bool search(string key) {
        struct TrieNode *p = root;
        for(int i=0;i<key.size();i++){
            int index = key[i] - 'a';
            // if 当前的节点对应的这个子节点不存在, 初始化这个节点
            if(!p->children[index]) {
                return false;
            }
            // 每过一个字符都要进行下一个字符继续使用
            p = p->children[index];
        }
        return (p!=NULL && p->isEndOfWord);
    }
    int size(){
        return count;
    }

    


private:
    TrieNode* root;
    int count;

};


int main()
{
    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);

    Trie *trie = new Trie();
    for(int i=0;i<n;i++){
        trie->insert(keys[i]);
    }

    cout<<"the number of words:"<<trie->size()<<endl;

    trie->search("the")?cout<<"Yes\n":cout<<"No\n";
    trie->search("these")?cout<<"Yes\n":cout<<"No\n";
    
    return 0;
}


