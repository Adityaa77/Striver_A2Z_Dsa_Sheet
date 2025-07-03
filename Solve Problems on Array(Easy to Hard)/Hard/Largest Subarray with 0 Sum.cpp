class Solution {
  public:
    int maxLen(vector<int>& arr) {
        int n=arr.size();
        int maxLen=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum=0;
        for(int j=i;j<n;j++){
            sum=sum+arr[j];
            if(sum==0 ){
                 maxLen = max(maxLen, j - i + 1);
            }
        }
        }
        return maxLen;
    }
};
