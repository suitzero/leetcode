class Solution {
public:
    string countAndSay(int n) {
        if( n == 1 ) return "1";
        string say = countAndSay(n-1),res="";
        char last_chr='a';
        int cnt;
        for( int i = 0 ; i < say.size() ; ++i)
        {
            if ( last_chr != say[i]){
                if( i != 0 )
                {
                    res += to_string(cnt);
                    res += last_chr;
                }
                cnt = 1;
                last_chr = say[i];
            }else{
                cnt++;
            }
        }
        res += to_string(cnt);
        res += last_chr;        
        return res;
    }
};
