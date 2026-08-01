#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
  public:
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode(){
      isEndOfWord = false;
      for(int i=0;i<26;i++) children[i] = nullptr;
    }
};

class Trie{
  private:
    TrieNode* root;
    public:
    Trie(){
      root = new TrieNode();
    }

    void insert(string& word){
      TrieNode* curr = root;
      for(auto x:word){
        int index = x - 'a';
        if(curr->children[index] == nullptr){
          curr->children[index] = new TrieNode(); 
        }
        curr = curr->children[index];
      }
      curr->isEndOfWord = true;
    }

    bool search(string& word){
      TrieNode* curr = root;
      for(auto x:word){
        int index = x - 'a';
        if(curr->children[index] == nullptr){
          // curr->children[index] = new TrieNode();
          return false;
        }
        curr = curr->children[index];
      }
      return (curr->isEndOfWord);
    }
    bool startsWith(string& word){
      TrieNode* curr = root;
      for(auto x:word){
        int index = x - 'a';
        if(curr->children[index] == nullptr){
          return false;
        }
        curr = curr->children[index];
      }
      return true;
    }
};

int main(){
  Trie *t = new Trie();
  string str = "apple";
  t->insert(str);
  string temp = "app";
  cout << t->startsWith(temp);

}