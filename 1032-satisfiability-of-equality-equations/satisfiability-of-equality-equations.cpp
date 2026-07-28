class Solution {
public:
    int parent[26]={0};
    int find(int x){
        if(parent[x]==x)return x;
        else return parent[x]=find(parent[x]);
    }   
    void unite(int x,int y){
        int rootx=find(x);
        int rooty=find(y);
        if(rootx!=rooty)parent[rootx]=rooty;
    }

    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 26; ++i) {
            parent[i] = i;
        }

        for(auto it : equations){
           if(it[1]=='=')unite(it[0]-'a',it[3]-'a');
        }
        for(auto it : equations){
           if(it[1]=='!'){
            if(find(it[0]-'a')==find(it[3]-'a'))return false;
           }
        }
        return true;
    }
};