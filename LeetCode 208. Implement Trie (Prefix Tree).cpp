class Trienode{
    public:
        char data;
        bool isterminal;
        Trienode *children[26];
    Trienode(char data)
    {
        this->data = data;
        for(int i=0;i<26;i++)
        {
            this->children[i]=NULL;
        }
        this->isterminal = false;
    }    
};
class Trie {
public:
    Trienode *root;
    Trie() {
        root = new Trienode('\0');
    }
    void insertUtil(Trienode *root,string word)
        {
            if(word.size()==0)
            {
                root->isterminal = true;
                return;
            }
            int index = word[0]-'a';
            Trienode *temp ;
            if(root->children[index]!=NULL)
            {
                temp = root->children[index];
            }    
            else{
                temp = new Trienode(word[0]);
                root->children[index]=temp;
            }
            insertUtil(temp,word.substr(1));
        }
    /** Inserts a word into the trie. */
    void insert(string word) {
        insertUtil(root,word);
    }
    bool searchUtil(Trienode *root,string word)
        {
            if(word.length()==0)
            {
                return root->isterminal;
            }
            int index = word[0]-'a';
            Trienode *temp;
            if(root->children[index]!=NULL)
            {
                temp = root->children[index];
            }
            else
            {
                return false;
            }
            return searchUtil(temp,word.substr(1));
        }
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchUtil(root,word);
    }
    bool startUtil(Trienode *root,string word)
        {
            if(word.length()==0)
            {
                return true;
            }
            int index = word[0]-'a';
            Trienode *temp;
            if(root->children[index]!=NULL)
            {
                temp = root->children[index];
            }
            else
            {
                return false;
            }
            return startUtil(temp,word.substr(1));
        }
    bool startsWith(string prefix) {
        return startUtil(root,prefix);
    }
};
