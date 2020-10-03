#include <bits/stdc++.h>

using namespace std;

typedef struct node
{
    struct node* children[26];
    bool isEndOfWord=false;
    
    node()
    {
        for(int i=0; i<26; i++)
            children[i] = NULL;
    }
}node;

void insert(node* root, string newStr)
{
    node* curr = root;
    
    for(int i=0; i<newStr.length(); i++)
    {
        int index = newStr[i] - 'a';
        if(curr->children[index] == NULL)
            curr->children[index] = new node;
        curr = curr->children[index];
    }
    curr->isEndOfWord = true;
}

bool search(node* root, string key)
{
    node* curr = root;
    for(int i=0; i<key.length(); i++)
    {
        int index = key[i] - 'a';
        if(curr->children[index] == NULL)
            return false;
        curr = curr->children[index];
    }
    if(curr!=NULL && curr->isEndOfWord)
        return true;
    return false;
}


int main()
{
    vector<string> list_of_words { "bear", "bell", "bid", "bull", "buy", "sell", "stock", "stop" };
   
    node* root = new node;
    for(int i=0; i<list_of_words.size(); i++)
        insert(root, list_of_words[i]); 
        
    
    cout<<"Is bell presnt in trie : " << search(root, "bell") << endl;
    cout<<"Is belly present in trie : "<< search(root, "belly") << endl;
   
   return 0;
}