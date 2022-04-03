/*给定一个正整数数组 w ，其中 w[i] 代表下标 i 的权重（下标从 0 开始），请写一个函数 pickIndex ，它可以随机地获取下标 i，选取下标 i 的概率与 w[i] 成正比。

例如，对于 w = [1, 3]，挑选下标 0 的概率为 1 / (1 + 3) = 0.25 （即，25%），而选取下标 1 的概率为 3 / (1 + 3) = 0.75（即，75%）。

也就是说，选取下标 i 的概率为 w[i] / sum(w) 。
*/

class Solution {
private:
    vector<int>v;

public:
    Solution(vector<int>& w) {
        v.resize(w.size(),0);
        int sum=0;
        for(int i=0;i<w.size();i++){
            sum+=w[i];
            v[i]=sum;
        }
    }
    
    int pickIndex() {
        int rad=rand()%v.back()+1;
        int l=0;
        int r=v.size()-1;
        while(l<=r){
            int mid=l+((r-l)>>1);
            if(rad<=v[mid]){
                if(mid==0||rad>v[mid-1]){
                    return mid;
                }
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return -1;
    }
};
