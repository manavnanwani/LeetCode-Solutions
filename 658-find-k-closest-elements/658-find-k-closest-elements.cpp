class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // priority_queue<pair<int,int>> maxh;
        // for(int i=0; i<arr.size(); i++){
        //     int x = abs(arr[i] - x);
        //     maxh.push({x, arr[i]});
        //     if(maxh.size() > k)
        //         maxh.pop();
        // }
        vector<int> ans;
        // while(!maxh.empty()){
        //     ans.push_back(maxh.top().second);
        //     maxh.pop();
        // }
        // sort(ans.begin(), ans.end());
        
        int i=0, j=arr.size()-1;
        while(j-i+1 > k){
            if(abs(x-arr[i]) > abs(x-arr[j]))
                i++;
            else
                j--;
        }
        for(int a=i; a<=j;a++)
            ans.push_back(arr[a]);
        return ans;
    }
};