class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        cursor = 0;
        history.push_back(homepage);
    }
    void visit(string url) {
        if(history.size() <= cursor+1)
        {
            history.push_back(url);
            ++cursor;
        }else{
            history[++cursor] = url;
            history.resize(cursor+1);
        }
    }
    
    string back(int steps) {
        int cnt = 0;
        cout << steps << "," << cursor;
        for(auto i = cursor  ; i >= 0 ; --i )
        {
            if(steps == 0)
            { 
                cursor = i;
                cout << "b:" << history[i] ;
                return history[i];
            }
            --steps;
        }
        cursor = 0;
        return history[0];
    }
    
    string forward(int steps) {
        while(cursor+steps >= history.size())
        {
            --steps;
        }
        cursor = cursor+steps;
        return history[cursor];
    }
    vector<string> history;
    int cursor;
};

