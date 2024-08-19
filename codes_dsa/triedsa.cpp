#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *links[26];
    bool flag = false;
};
class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->links[word[i] - 'a'] == NULL)
            {
                node->links[word[i] - 'a'] = new Node();
            }
            node = node->links[word[i] - 'a'];
        }
        node->flag = true;
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->links[word[i] - 'a'] == NULL)
            {
                return false;
            }
            node = node->links[word[i] - 'a'];
        }
        return node->flag;
    }

    bool startsWith(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->links[word[i] - 'a'] == NULL)
            {
                return false;
            }
            node = node->links[word[i] - 'a'];
        }
        return true;
    }
};