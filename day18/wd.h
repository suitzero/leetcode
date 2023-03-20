class WordDictionary_vec {
public:
    WordDictionary_vec() {
        // vector ? map? trie?
        // 
    }
    
    void addWord(string word) {
        dic.push_back(word);
    }
    
    bool search(string word) {
        for( int i = 0 ; i < dic.size() ; ++i )
        {
            bool diff = true;
            for( int j = 0 ; j < word.size() && j < dic[i].size() ; ++j )
            {
                if (word[j] != dic[i][j] && word[j] != '.' ) diff = false;
            }
            if( diff && word.size() == dic[i].size()){
                return true;
            }
        }
        return false;
    }
    vector<string> dic;
};

class WordDictionary_map {
public:
    WordDictionary_map() {
        // vector ? map? trie?
        // 
    }
    
    void addWord(string word) {
        function<void(string&,int)> perm = [&](string& w,int n_dots){
            if( dic[w] ) return;
            dic[w] = true;
            if( n_dots == 0 ) return;
            for( int i = 0 ; i < w.size(); ++i )
            {
                if ( w[i] != '.' ){
                    char tmp = w[i];
                    w[i] = '.';
                    perm(w,n_dots-1);
                    w[i] = tmp;
                }
            }
        };
        perm(word,word.size());
    }
    
    bool search(string word) {
        return dic[word];
    }
    unordered_map<string,bool> dic;
    ///   bad
    ///   dad
    //    mad
};

class WordDictionary {
public:
    WordDictionary() :isWord(false){
        dic = vector<WordDictionary*>(26, nullptr);
    }
    
    void addWord(string word) {
        if( word.size() == 0 ) isWord = true;
        else{
            if(!dic[word[0]-'a']) dic[word[0]-'a']=new WordDictionary();
            dic[word[0]-'a']->addWord(word.substr(1));
        }
    }
    
    bool search(string word) {
        if( word.size() == 0 && isWord) return true;
        if( word.size() > 0 )
        {
            if( word[0] != '.' && dic[word[0]-'a']) return dic[word[0]-'a']->search(word.substr(1,word.size()-1));
            else if(word[0] == '.'){
                for( char i = 'a' ; i <= 'z' ; ++i )
                {
                    if(dic[i-'a'] && dic[i-'a']->search(word.substr(1))) return true;
                }
                return false;
            }
        }
        return false;
    }
    vector<WordDictionary*> dic;
    bool isWord;
};
