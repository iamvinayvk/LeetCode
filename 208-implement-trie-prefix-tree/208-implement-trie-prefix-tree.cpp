class Trie {
public:
    vector<string> tri;
    Trie() {
        // tri.resize(0);
    }
    
    void insert(string word) {
        tri.push_back(word);
    }
    
    bool search(string word) {
       for(int i=0;i<tri.size();i++){
           if(word==tri[i])
               return true;
       } 
        return false;
    }
    
    bool startsWith(string prefix) {
        for(int i=0;i<tri.size();i++){
            string val;
            for(int j=0;j<tri[i].size();j++){
                val+=tri[i][j];
                if(val==prefix)
                    return true;
            }
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */