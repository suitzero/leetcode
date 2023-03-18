#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Trie {
public:
    Trie() : isWord(false){
        
    }
    
    void insert(string word) {
			if(m[word[0]] == nullptr)
				m[word[0]] = new Trie;
			if( word.size() > 0 )
				m[word[0]]->insert(word.substr(1,word.size()-1)); 
			else if( word.size() == 0 )
				isWord = true;
    }
    
    bool search(string word) {
			if(word.size() == 0) return isWord;
			if( m[word[0]] == nullptr ) return false;
			if( word.size() > 0 && m[word[0]] != nullptr)
				return m[word[0]]->search(word.substr(1,word.size()-1)); 
			return false;
    }
    
    bool startsWith(string prefix) {
			if(prefix.size() == 0) return true;
			if( m[prefix[0]] == nullptr ) return false;
			if( prefix.size() > 0 )
				return m[prefix[0]]->startsWith(prefix.substr(1,prefix.size()-1)); 
			return false;
    }
		unordered_map<char,Trie*> m;
		bool isWord;
};


int main()
{
	string word = "helloworld", prefix="hello";
	Trie* obj = new Trie();
	obj->insert(word);
	bool param_2 = obj->search(word);
	bool param_3 = obj->startsWith(prefix);
	cout << param_2 << "," << param_3 << endl;
	obj->insert("apple");
	cout << obj->search("apple") << endl;
	
	cout << obj->search("app") << endl;
	cout << obj->startsWith("app") << endl;
}
