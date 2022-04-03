/*以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>fault{};
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            if(fault.empty()){
                fault.push_back(intervals[i]);
            }else if((intervals[i][0]>=fault[fault.size()-1][0]&&intervals[i][0]<=fault[fault.size()-1][1])||(intervals[i][1]>=fault[fault.size()-1][0]&&intervals[i][0]<=fault[fault.size()-1][1])){
                fault[fault.size()-1][0]=min(fault[fault.size()-1][0],intervals[i][0]);
                fault[fault.size()-1][1]=max(fault[fault.size()-1][1],intervals[i][1]);
            }else{
                fault.push_back(intervals[i]);
            }
        }
        return fault;
    }
};
