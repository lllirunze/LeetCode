class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int cnt = 0;
        for(int i = 0;i + 1 < timeSeries.size();i++){
            if(timeSeries[i] + duration <= timeSeries[i+1]) cnt += duration;
            else cnt += (timeSeries[i+1] - timeSeries[i]);
        }
        cnt += duration;
        return cnt;
    }
};