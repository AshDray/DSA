class DSU{
    public:
    unordered_map<int,int>parent;
    int find(int i){
        if(parent.find(i)==parent.end())parent[i]=i;
        if(parent[i]==i)return i;
        return parent[i]=find(parent[i]);
    }
    void unionn(int i,int j){
        int rti=find(i);
        int rtj=find(j);
        if(rti!=rtj)parent[rti]=rtj;
    }
};




class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        DSU dsu;
        int ofst=10001;
        for(const auto &stone:stones){
            int row=stone[0];
            int col=stone[1]+ofst;
            dsu.unionn(row,col);
        }
        unordered_map<int,bool>h;
        for(const auto &stone :stones)
        h[dsu.find(stone[0])]=true;
        int q=h.size();
    return stones.size()-q;
    }
    
};