#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    
    Node* links[26];
    int endsWord = false;

    bool containsKey(char c){

        return links[c-'a'] != NULL;
    } 

    bool insertKey(char c){

         links[c-'a'] = new Node();
    }

    Node* getKey(char c){

        return links[c-'a'];
    }

    void setEndWord(){

        endsWord = true;
    }

    bool isEndWord(){
  
        return endsWord;
        
    }

    void removeWord(char c){

        delete links[c-'a'];
    }
};

class Trie
{
    public:
    Node *root;
   
    Trie()
    {
      root = new Node();
    }

    void insert(string s){
         
         Node* curr = root;

         for(int i =0 ;i<s.size() ;i++){

            if(!curr->containsKey(s[i])){

                curr->insertKey(s[i]);
            }

            curr = curr->getKey(s[i]);
         }

         curr->setEndWord();
        
    }

    bool search(string s){
        
         Node* curr = root;

         for(int i =0 ;i<s.size() ;i++){

            if(!curr->containsKey(s[i])) return false;

            curr = curr->getKey(s[i]);

         }

         return curr->isEndWord();
       
    }

    bool startsWith(string s){

         Node* curr = root;

         for(int i =0 ;i<s.size() ;i++){

            if(!curr->containsKey(s[i])) return false;

            curr = curr->getKey(s[i]);

         }

         return true;
       
    }

//     void deleteWord(string s){

//         Node* curr = root;

//         Node* wordEndNode = NULL;

//         for(int i =0 ;i<s.size() ;i++){

//             if(!curr->containsKey(s[i])) return;

//             curr = curr->getKey(s[i]);
//          }

//          if(curr->isEndWord() == false) return;

//          Node* secondLastWordEndNode = NULL;
//          char secondLastChar;
//          curr = root;

//          for(int i =0 ;i<s.size() ;i++){


//             if(curr->isEndWord() == true){

//                 secondLastWordEndNode = curr;
//                 secondLastChar = s[i];
//             } 
            
//             curr = curr->getKey(s[i]);
//          }
         
//          if(secondLastWordEndNode == wordEndNode){

//              root->removeWord(s[0]);

//              return ;
//          }
         

//          secondLastWordEndNode->removeWord(s[secondLastChar]);
//     }
};

int main()
{   

    Trie tr;

    tr.insert("apple");
    tr.insert("app");
    tr.insert("appler");
    tr.insert("ronaldo");

    cout<<tr.search("app")<<endl;
    cout<<tr.search("appx")<<endl;
    cout<<tr.startsWith("rona")<<endl;
    cout<<tr.startsWith("yoyo")<<endl;
    
    // tr.deleteWord("app");
    // cout<<tr.search("app")<<endl;
    return 0;
}