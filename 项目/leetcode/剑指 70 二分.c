/*给定一个只包含整数的有序数组 nums ，每个元素都会出现两次，唯有一个数只会出现一次，请找出这个唯一的数字。*/


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0;
        int r=nums.size();
        while(l<r){
            int mid=l+r>>1;
            if(mid==0){
                return nums[mid];
            }
            if(mid==nums.size()-1){
                return nums[mid];
            }
            if(nums[mid]==nums[mid-1]){
                if(mid%2==0){
                    r=mid;
                }else{
                    l=mid+1;
                }
            }else if(nums[mid]==nums[mid+1]){
                if(mid%2==1){
                    r=mid;
                }else{
                    l=mid+1;
                }
            }else{
                return nums[mid];
            }
        }
        return nums[l];
    }
};
