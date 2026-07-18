class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int max_reach=0;
        int n=arr.size();
        int min_steps=0;
        int next=0;
        for(int i=0;i<n;i++){
            if(max_reach<i)return -1;
            if(i==max_reach){
                min_steps++;
                max_reach=max(next,i+arr[i]);
                next=max_reach;
            }
            else if(i<max_reach){
                if(next>=n-1)return min_steps; 
                next=max({max_reach,arr[i]+i,next});
                if(next>=n-1)return min_steps+1; 
            }
            
            if(next>=n-1)return min_steps; 
        }
        return min_steps;
    }
};