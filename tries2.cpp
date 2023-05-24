#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    Node *links[26];
    int wordEnds = 0;
    int prefixes = 0;

    bool containsKey(char c)
    {

        return links[c - 'a'] != NULL;
    }

    void insertKey(char c)
    {

        links[c - 'a'] = new Node();
    }

    void increaseWordEnds()
    {

        wordEnds++;
    }

    void increasePrefixes()
    {

        prefixes++;
    }

    void decreaseWordEnds()
    {

        wordEnds--;
    }

    void decreasePrefixes()
    {

        prefixes--;
    }

    Node *getKey(char c)
    {

        return links[c - 'a'];
    }

    int getWordEnds()
    {

        return wordEnds;
    }

    int getPrefixes()
    {

        return prefixes;
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

    void insert(string s)
    {

        Node *curr = root;

        for (int i = 0; i < s.size(); i++)
        {

            if (!curr->containsKey(s[i]))
            {

                curr->insertKey(s[i]);
            }

            curr->increasePrefixes();

            curr = curr->getKey(s[i]);
        }

        curr->increaseWordEnds();
    }

    int countWord(string s)
    {

        Node *curr = root;

        for (int i = 0; i < s.size(); i++)
        {

            if (!curr->containsKey(s[i]))
                return 0;

            curr = curr->getKey(s[i]);
        }

        return curr->getWordEnds();
    }

    int countPrefix(string s)
    {

        Node *curr = root;

        for (int i = 0; i < s.size(); i++)
        {

            if (!curr->containsKey(s[i]))
                return 0;

            curr = curr->getKey(s[i]);
        }

        return curr->getPrefixes();
    }

    void removeWord(string s)
    {

        if (countWord(s) == 0)
            return;

        Node *curr = root;

        for (int i = 0; i < s.size(); i++)
        {

            curr = curr->getKey(s[i]);

            curr->decreasePrefixes();
        }

        curr->decreaseWordEnds();
    }
};

int main()
{

    Trie tr;

    tr.insert("apple");
    tr.insert("apple");
    tr.insert("apple");
    tr.insert("appx");
    tr.insert("appler");
    tr.insert("ronaldo");

    tr.removeWord("appl");
    tr.removeWord("apple");


    cout << tr.countWord("apple") << endl;
    cout << tr.countPrefix("app") << endl;

    return 0;
}