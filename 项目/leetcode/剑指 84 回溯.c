给定一个可包含重复数字的整数集合 nums ，按任意顺序 返回它所有不重复的全排列。

class Solution {
private:
    vector<vector<int>>fault;
public:
    void dfs(vector<int>& nums,int start){
        if(start==nums.size()){
            fault.push_back(nums);
        }else{
            set<int>s;
            for(int i=start;i<nums.size();i++){
                if(!s.count(nums[i])){
                    s.insert(nums[i]);
                swap(nums[i],nums[start]);
                dfs(nums,start+1);
                swap(nums[i],nums[start]);
                }   
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        dfs(nums,0);
        return fault;
    }
};
