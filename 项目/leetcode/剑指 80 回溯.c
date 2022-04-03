给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

class Solution {
private:
    vector<vector<int>>fault;
public:
    void dfs(int n,int k,int start,vector<int>&tmp){
        if(tmp.size()==k){
            fault.push_back(tmp);
        }
        if(start>n){
            return ;
        }
        for(int i=start;i<=n;i++){
            tmp.push_back(i);
            dfs(n,k,i+1,tmp);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>tmp;
        dfs(n,k,1,tmp);
        return fault;
    }
};
