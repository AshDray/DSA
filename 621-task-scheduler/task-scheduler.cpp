class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>mp(26,0);
        for(auto it:tasks)mp[it-'A']++;
        priority_queue<int>pq;
        int time=0;
        for(auto it:mp){
            if(it)pq.push(it);
        }
        while(!pq.empty()){
            vector<int>temp;
            for(int i=0;i<n+1;i++){
                if(!pq.empty()){
                int t=pq.top();
                pq.pop();
                t--;
                
                temp.push_back(t);}
            }
            for(auto it:temp){if(it)pq.push(it);}
            if(pq.empty())time+=temp.size();
            else time+=n+1;

        }
        return time;
    }
};