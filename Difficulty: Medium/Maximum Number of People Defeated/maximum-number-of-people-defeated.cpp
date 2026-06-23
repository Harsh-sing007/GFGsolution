class Solution {
  public:
    int maxPeopleDefeated(int p) {
        // Code Here
        long long lo=1, hi=2000;
        long long ans=0;
        while(lo<=hi){
            long long mid=lo+(hi-lo)/2;
            long long check=((mid)*(mid+1)*(2*mid+1))/6;
            if(check<=p){
                ans=mid;
                lo=mid+1;
            }else hi=mid-1;
        }
        return ans;        
    }
};