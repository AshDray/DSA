class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int targetArrival = times[targetFriend][0];
        
        sort(times.begin(), times.end());
        
        priority_queue<int, vector<int>, greater<int>> availableChairs;
        for (int i = 0; i < times.size(); ++i) {
            availableChairs.push(i);
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupiedChairs;
        
        for (const auto& time : times) {
            int arrival = time[0];
            int leaving = time[1];
            
            while (!occupiedChairs.empty() && occupiedChairs.top().first <= arrival) {
                availableChairs.push(occupiedChairs.top().second);
                occupiedChairs.pop();
            }
            
            int assignedChair = availableChairs.top();
            availableChairs.pop();
            
            if (arrival == targetArrival) {
                return assignedChair;
            }
            
            occupiedChairs.push({leaving, assignedChair});
        }
        
        return -1;
    }
};