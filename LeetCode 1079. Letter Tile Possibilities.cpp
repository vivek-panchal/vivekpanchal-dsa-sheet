class Solution {
public:
    void solve( string tiles, string &output, set<string>& result, map<int,bool>&flag){
        
        for(int i=0; i<tiles.length() ; i++) {
            if(flag[i] == 0 ){
                char ch = tiles[i];
                output.push_back(ch);
                flag[i]=1;
                
                result.insert(output);
                solve(tiles,output,result,flag);
                output.pop_back();
                flag[i]=0;  
            }
               
        }
    }
    int numTilePossibilities(string tiles) {
        string output="";
        set<string> result;
        map<int,bool> flag;
        solve(tiles,output,result,flag);
        return result.size();
    }
};
