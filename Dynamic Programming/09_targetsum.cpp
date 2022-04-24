//TBD
/*
For those who has problem with test case  [0,0,0,0,0,0,0,0,1], target = 1.

The solution doesn't consider presence of "0"s in the array. Why the output is different ?

Because, if we have "0", then, it can have +0 and -0 and still will not effect the sum of a set. For example: Target value is = 2

1) {0,2} = {+0,2}, {-0,2}.  Ans: 2

But if we increase number of 0s,

2) {0,0,2} = {+0,+0,2}, {+0,-0,2}, {-0,+0,2},{-0,-0,2} . Ans: 4



So, if you observe, your answer increase by (2^number of 0s) i.e. pow(2,number of zeros).

So, make a small change as follows:

1) on count of subsetsum function, 

if(nums[i-1] > j )    => change to:  if (nums[i-1] > j || nums[i-1] == 0)

      dp[i][j] = dp[i-1][j];

 //make no change and put the previous value as it is in the next subproblem. (I.e. 2, in example above)

And then at the end, you answer will be

return (int)Math.pow(2, number of 0s) * dp[nums.length][target] ;

Also, other cases we need to handle is:
if (S > sum || (sum + S) % 2 != 0){ //S is target

            return 0;
*/










/*
The complete LEETCODE solution (including the case when we have 0 as an element in the array)

    int findTargetSumWays(vector<int>& nums, int S) 
   {        

        int sum = accumulate(nums.begin(),nums.end(),0);
        if(S>sum || (sum-S)%2!=0)
            return 0;
        
        int dp[nums.size()+1][((sum-S)/2)+1];
        
        int c=0;
        for(int i=0;i<nums.size();i++)
            if(nums[i]==0)
                c++;
        
        for(int i=0;i<nums.size()+1;i++)
            dp[i][0]=1;    
            
        for(int i=1;i<((sum-S)/2)+1;i++)
            dp[0][i] = 0;
        
        for(int i=1;i<nums.size()+1;i++)
            for(int j=1;j<((sum-S)/2)+1;j++)
            {
                if(nums[i-1]==0)
                    dp[i][j] = dp[i-1][j];
                else
                if(nums[i-1]<=j)
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        
        
        return pow(2,c)*dp[nums.size()][(sum-S)/2];
   
    }
*/