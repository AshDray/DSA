class Solution {
public:
    int ladderLength(string b, string e, vector<string>& wl) {
       queue <pair<string,int>>q;
       q.push({b,1});
       unordered_set<string>st(wl.begin(),wl.end());
       st.erase(b);
       while(!q.empty()){
        string word=q.front().first;
        int steps=q.front().second;
        q.pop();
        if(word==e)return steps;
        for(int i=0;i<word.size();i++){
            string original = word;
            for(char j='a'; j<='z';j++){
               word[i]=j;
               if(st.find(word)!=st.end()){
                st.erase(word);
                q.push({word,steps+1});
               }
            }
            word=original;
        }

       } 
       return 0;
    }
};