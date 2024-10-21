#include <iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* child[26];
    bool isTerminal;
    TrieNode(char data){
        data=ch;
        for(int i=0;i<26;i++){
            ch[i]=NULL;
        }
        isTerminal=false;
    }
};
class Trie{
    public:
    TrieNode* root;
    
    void insertutil(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal;
        }
    }
    void insertWord(String word){

    }

}