class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int start =intervals[0][0];
        int end = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=end && end<intervals[i][1]){
                end =intervals[i][1];
            }else if(end<intervals[i][0]){
                vector<int> jp;
                jp.push_back(start);
                jp.push_back(end);
                ans.push_back(jp);
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        vector<int> jp;
        jp.push_back(start);
        jp.push_back(end);
        ans.push_back(jp);
        return ans;
    }
};