class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==1)return 1;
        int l=0;int r=0;
        int arr[128]={0};
        int sm=0;
        for(int i=0;i<s.size();i++){
            
            arr[s[i]]++;
            r=i;
            
            if(arr[s[i]]>1){
               while(arr[s[i]]>1){
                arr[s[l]]--;
                l++;
               }
            }
            sm=max(sm,r-l+1);
        }
        return sm;
    }
};