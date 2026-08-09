class Solution {
public:
int check(const string &s,int i,int j){
    while(i<j){
        if(s[i]==s[j]){i++;j--;}
        else return false;
    }
    return true;
}
int f(vector<int>&dp,int start,const string &s,int n){
    if(start==n || check(s,start,n-1))return 0;
    if(dp[start]!=-1)return dp[start];
    int tpt=INT_MAX;
    for(int end=start;end<n;end++){
        if(check(s,start,end)){
        int ans=1+f(dp,end+1,s,n);
        tpt=min(tpt,ans);}
    }
    return dp[start]=tpt;
}
    int minCut(string s) {
        int n=s.size();
        vector<int>v(n,-1);
        return f(v,0,s,n);
    }
};