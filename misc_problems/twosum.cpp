#include <iostream>
#include <vector>
using namespace std;

class solution{
    public:
    vector<int> twosum(vector<int>& nums,int target){
        vector<int> indices;
        vector<pair<int,int>> numindices;
        for(int i=0;i<nums.size();i++){
            int complement = target - nums[i];
            for(int j=0;j<numindices.size();j++){
                if(complement==numindices[j].first){
                    indices.push_back(i);
                    indices.push_back(numindices[j].second);
                    return indices;
                }
            }
            numindices.push_back({nums[i],i});
        }
        return indices;
    }
};