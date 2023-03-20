class Trie {
    struct TrieNode
    {
        char val;
        int count;
        int endsHere;
        TrieNode *child[26];

    };
    TrieNode *root;
    TrieNode* getNode(int index)
    {
        TrieNode *newnode = new TrieNode;
        newnode->val = 'a' + index;
        newnode->count = newnode->endsHere = 0;
        for (int i = 0; i < 26; ++i)
            newnode->child[i] = NULL;
        return newnode;
    }

public:
    Trie() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        root = getNode('/' - 'a');
    }

    void insert(string word) {
        TrieNode *curr = root;
        int index;
        for (int i = 0; i < word.length(); i++)
        {
            index = word[i] - 'a';
            if (curr->child[index] == NULL)
                curr->child[index] = getNode(index);
            curr->child[index]->count += 1;
            curr = curr->child[index];
        }
        curr->endsHere += 1;
    }

    bool search(string word) {
        TrieNode *curr = root;
        int index;
        for (int i = 0; i < word.length(); i++)
        {
            index = word[i] - 'a';
            if (curr->child[index] == NULL)
                return false;
            curr = curr->child[index];
        }
        return (curr->endsHere > 0);
    }

    bool startsWith(string prefix) {
        TrieNode *curr = root;
        int index;
        for (int i = 0; i < prefix.length(); i++)
        {
            index = prefix[i] - 'a';
            if (curr->child[index] == NULL)
                return false;
            curr = curr->child[index];
        }
        return (curr->count > 0);
    }
};
