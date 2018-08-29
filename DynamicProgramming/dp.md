#### 1. catalan number
![](https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-5caf1032c7225d073dd41cd7a9fa4e38_l3.svg)

[review](https://www.geeksforgeeks.org/program-nth-catalan-number/<br/>)

[video](https://www.youtube.com/watch?v=2NZF2UKyh0g&feature=youtu.be<br/>)
```
unsigned long catalan(unsigned n){ 
    unsigned long catalan[n + 1]; 
    catalan[0] = catalan[1] = 1;
    for(int i = 2; i <= n; i++){
        catalan[i] = 0;
        for(int j = 0; j < i; j++) {
            catalan[i] += catalan[j] * catalan[i - j - 1]; 
        }   
    }   
    return catalan[n];
}

```

#### 2. boll number
Let S(n, k) be total number of partitions of n elements into k sets. The value of n’th Bell Number is sum of S(n, k) for k = 1 to n.

 ![](https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-6ea5decd6aa25a444e0ed57bf5a1e856_l3.svg)

Value of S(n, k) can be defined recursively as, S(n+1, k) = k*S(n, k) + S(n, k-1)

[review](https://www.geeksforgeeks.org/bell-numbers-number-of-ways-to-partition-a-set/) 
```
int bollNumber(int n){
    int b[n + 1][n + 1];
    b[0][0] = 1;
    for(int i = 1; i <= n; i++)
        b[i][0] = 0;
    for(int i = 1; i <= n; i++)
        b[0][i] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++){
            b[i][j] = j * b[i - 1][j] + b[i - 1][j - 1];
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++)
        res += b[n][i];
    return res;
}

```

#### 3. Binomial Coefficient 
    C(n, k) = C(n-1, k-1) + C(n-1, k)
    C(n, 0) = C(n, n) = 1

***todo:* space optimized**

[review](https://www.geeksforgeeks.org/binomial-coefficient-dp-9/)

#### 4. Permutation Coefficient 
    P(n, k) = P(n-1, k) + k* P(n-1, k-1) 

***todo:* space optimized**

[review](https://www.geeksforgeeks.org/permutation-coefficient/)

#### 5. 0-1 Knapsack Problem
- recursive solution
```
int knapSack(int W, int n, int wt[], int val[]){
    // Base cases
    if(n == 0 || W == 0)
        return 0;

    if(wt[n - 1] > W)
        return knapSack(W, n - 1, wt, val);
    else
        return max(knapSack(W - wt[n - 1], n - 1, wt, val) + val[n - 1],
                knapSack(W, n - 1, wt, val));
}
```

- Dynamic Programming solution<br/>
    space: O(n * W)
    ```
    int knapSackDP(int W, int n, int wt[], int val[]){
        int k[n + 1][W + 1];
    
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= W; j++){
                if(i == 0 || j == 0)
                    k[i][j] = 0;
                else if(wt[i - 1] <= j){
                    k[i][j] = max(k[i - 1][j - wt[i - 1]] + val[i - 1], k[i - 1][j]);
                }
                else
                    k[i][j] = k[i - 1][j];
            }
        }
        return k[n][W];
    }
    ```
    space: O(2 * W)
    ```
    int knapSack2(int w[], int val[], int n, int W){
        int k[2][W + 1];
        memset(k, 0, sizeof(k));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i % 2 == 0){
                    if(j <= w[i])
                        k[0][j] = max(k[1][j - w[i]] + val[i], k[1][j]);
                    else
                        k[0][j] = k[1][j];
                } else {
                    if(j <= w[i])
                        k[1][j] = max(k[0][j - w[i]] + val[i], k[0][j]);
                    else
                        k[1][j] = k[0][j];
    
                }
            }
        }
        return n % 2 == 0 ? k[1][W] : k[0][W];
    }
    ```
    space: O(W)
    ```
    int knapSack3(int w[], int val[], int n, int W){
        int k[W + 1];
        memset(k, 0, sizeof(k));
        for(int i = 0; i < n; i++){
            for(int j = W; j >= w[i]; j--)
                k[j] = max(k[j], k[j - w[i]] + val[i]);
        }
        return k[W];
    }
    ```

#### 6. Longest Palindromic Substring
```
string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        int maxLength = 1, start = 0, n = s.size();
        bool dp[n][n];
        memset(dp, false, sizeof(dp) * n * n);
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
        }
        for(int i = 0; i <= n - 2; i++){
            if(s[i] == s[i + 1]){
                dp[i][i+1] = true;
                start = i;
                maxLength = 2;
            }
        }
        
        for(int k = 3; k <= n; k++){
            for(int i = 0; i <= n - k; i++){
                if(dp[i + 1][i + k - 2] && (s[i] == s[i + k - 1])){
                    dp[i][i + k - 1] = true;
                    start = i;
                    maxLength = k;
                }
            }
        }
        return s.substr(start, maxLength);
    }
```

#### 7. coins change
这道题跟01背包问题类似，这里每个item可以选取多次，算是普通01背包问题的升级，01背包问题其实也可以升级成每个物品可以选取多次。

解法的区别就是：
- 如果不能选取多次
> dp[i][j] = max(dp[i - 1][j - w[i]], dp[i - 1][j])
- 如果可以选取多次
> dp[i][j] = max(dp[i][j - w[i]], dp[i - 1][j])

同时做这道还有些其他的感悟：
1. 动态规划，初始值的设定，比如01背包，你可以设成0，dp[i][j] == 0 与 无法选取物品使得value达到j的情况等价；然而，像下面这道coin change求最少硬币，就不行了，dp[i][j] == 0表示最少硬币数为0， 而无法找零的情况不应该为0，通常要求返回-1，一个技巧就是，初始值设为amount + 1;
2. 对于 i = 0 或者 j = 0 时的初始化，可以在两层循环内部进行，伪代码：
    ```c++
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            // 这里先处理i == 0 还是先处理 j == 0得看情况
            if(i == 0) {
                //do something
            } else if(j == 0){
                //do something
            } else {
                //do something
            }
        }
    }
    ```

**coin change**

You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1

**Example:**
>Input: coins = [1, 2, 5], amount = 11<br/>
>Output: 3 <br/>
>Explanation: 11 = 5 + 5 + 1

```c++
int coinChange(vector<int>& coins, int amount) {
    int m = coins.size(), n = amount;
    vector<vector<int> > dp(m, vector<int>(n + 1, n + 1));
	for(int i = 0; i < m; i++){
        for(int j = 0; j <= n; j++){
            if(j == 0) dp[i][j] = 0;
            else {
                if(i - 1 >= 0)
                    dp[i][j] = dp[i - 1][j];
                if(j >= coins[i])
                    dp[i][j] = min(dp[i][j], dp[i][j - coins[i]] + 1);
            }
        }
    }
	return dp[m - 1][n] > amount ? -1 : dp[m - 1][n];
}
```

**space:** O(n)

```c++
int coinChange(vector<int>& coins, int n) {
    vector<int> dp(n + 1, n + 1);
    dp[0] = 0;
	for(int i = 0; i < m; i++){
        for(int j = coins[i]; j <= n; j++){
            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }
	return dp[n] > n ? -1 : dp[n];
}
```

**coin change 2**

You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

**Example:**
>Input: amount = 5, coins = [1, 2, 5]  
Output: 4  
Explanation: there are four ways to make up the amount:  
5=5  
5=2+2+1  
5=2+1+1+1  
5=1+1+1+1+1 

```c++
int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < coins.size(); i++){
        for(int j = coins[i]; j <= amount; j++){
            dp[j] = dp[j] + dp[j - coins[i]];
        }
    }
    return dp[amount];
}
```

#### 8. Friends Pairing Problem
Given n friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.
**Examples:**
>Input  : n = 3  
Output : 4  
Explanation  
{1}, {2}, {3} : all single  
{1}, {2,3} : 2 and 3 paired but 1 is single.  
{1,2}, {3} : 1 and 2 are paired but 3 is single.  
{1,3}, {2} : 1 and 3 are paired but 2 is single.  
Note that {1,2} and {2,1} are considered same.

**solution:**
>f(n) = ways n people can remain single or pair up.  
>For n-th person there are two choices:  
>1) n-th person remains single, we recur   
   for f(n - 1)  
>2) n-th person pairs up with any of the   
   remaining n - 1 persons. We get (n - 1) * f(n - 2)    
Therefore we can recursively write f(n) as:
f(n) = f(n - 1) + (n - 1) * f(n - 2)
```c++
int countFriendsPairings(int n)
{
    int dp[n + 1];
 
    // Filling dp[] in bottom-up manner using
    // recursive formula explained above.
    for (int i = 0; i <= n; i++)
    {
        if (i <= 2)
        dp[i] = i;
        else
        dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
    }
 
    return dp[n];
}
```

#### 9. Subset with sum divisible by m
Given a set of non-negative distinct integers, and a value m, determine if there is a subset of the given set with sum divisible by m.  
Input Constraints  
Size of set i.e., n <= 1000000, m <= 1000
**Example:**
>Input : arr[] = {3, 1, 7, 5};  
        m = 6;  
Output : YES  \
>Input : arr[] = {1, 6};  
        m = 5;  
Output : NO  

**solution:**
>bool dp[n][m],每行记录除以m可能的余数。比如m = 6, dp[n - 1][m]可以取余1，3，那么对于arr[7]， dp[(1 + 7) % 6] = true, dp[(3 + 7) % 6] = true, dp[arr[i] % m] = true;只要出现dp[][0] == true, 就表示可以找到这样的子集.
```c++
bool modularSum(int arr[], int n, int m)
{
    if (n > m)
        return true;
 
    bool DP[m];
    memset(DP, false, m);
    
    for (int i=0; i<n; i++)
    {
        if (DP[0])
            return true;
   
        bool temp[m];
        memset(temp,false,m);
 
        for (int j=0; j<m; j++)
        {
            if (DP[j] == true)
            {
                if (DP[(j+arr[i]) % m] == false)
                    temp[(j+arr[i]) % m] = true;
            }
        }
 
        for (int j=0; j<m; j++)
            if (temp[j])
                DP[j] = true;
 
        DP[arr[i]%m] = true;
    }
 
    return DP[0];
}
```

#### 10. Largest divisible pairs subset
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

**Example:**
>nums: [1,2,3]  
Result: [1,2] (of course, [1,3] will also be ok)<p>
>nums: [1,2,4,8]  
Result: [1,2,4,8]

**solution:**
>This can be solved using Dynamic Programming. We first sort the array so that the largest element is at the end. Then we traverse the sorted array from end. For every element a[i], we compute dp[i] where dp[i] indicates size of largest divisible subset where a[i] is the smallest element. We can compute dp[i] in a sorted array using values from dp[i+1] to dp[n-1]. Finally we return maximum value from dp[]. At the meanwhile, use pre[n] to record the pre idx.

```c++
vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    if(n == 0) return {};
    vector<int> dp(n, 0);
    vector<int> pre(n, -1);
    dp[n - 1] = 1;
    pre[n - 1] = -1;
    for(int i = n - 2; i >= 0; i--){
        int maxLength = 0;
        int maxPre = -1;
        for(int j = i + 1; j < n; j++){
            if(nums[j] % nums[i] == 0 && dp[j] > maxLength){
                maxLength = dp[j];
                maxPre = j;
            }
        }
        dp[i] = maxLength + 1;
        pre[i] = maxPre;
    }
    int max = INT_MIN, idx = -1;
    for(int i = 0; i < n; i++){
        if(dp[i] > max){
            max = dp[i];
            idx = i;
        }
    }
    vector<int> res;
    while(idx != -1){
        res.push_back(nums[idx]);
        idx = pre[idx];
    }
    return res;
}
```

#### 11. Longest Common Subsequence
**Examples:**
>LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.\
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.
```c++
int lcs( char *X, char *Y, int m, int n )
{
   int L[m+1][n+1];
   int i, j;

   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
  
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }

   return L[m][n];
}
```

**space:** O(n)
```c++
int lcs(string &X, string &Y)
{
    int m = X.length(), n = Y.length();
 
    int L[2][n + 1];

    bool bi;
 
    for (int i = 0; i <= m; i++)
    {
        bi = i & 1;
 
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[bi][j] = 0;
 
            else if (X[i-1] == Y[j-1])
                 L[bi][j] = L[1 - bi][j - 1] + 1;
 
            else
                L[bi][j] = max(L[1 - bi][j], 
                               L[bi][j - 1]);
        }
    }
    return L[bi][n];
}
```

#### 12. Longest Increasing Subsequence
Let us discuss Longest Increasing Subsequence (LIS) problem as an example problem that can be solved using Dynamic Programming.
The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order. For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}.

**solution:**
>Let arr[0..n-1] be the input array and L(i) be the length of the LIS ending at index i such that arr[i] is the last element of the LIS.  
Then, L(i) can be recursively written as:  
L(i) = 1 + max( L(j) ) where 0 < j < i and arr[j] < arr[i]; or  
L(i) = 1, if no such j exists.  
To find the LIS for a given array, we need to return max(L(i)) where 0 < i < n.  
Thus, we see the LIS problem satisfies the optimal substructure property as the main problem can be solved using solutions to subproblems.  

```c++
int lis( int arr[], int n )
{
    int *lis, i, j, max = 0;
    lis = (int*) malloc ( sizeof( int ) * n );

    for (i = 0; i < n; i++ )
        lis[i] = 1;

    for (i = 1; i < n; i++ )
        for (j = 0; j < i; j++ ) 
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;

    for (i = 0; i < n; i++ )
        if (max < lis[i])
            max = lis[i];

    free(lis);
 
    return max;
}
```

#### 13. LCS (Longest Common Subsequence) of three strings
Given 3 strings of all having length < 100,the task is to find the longest common sub-sequence in all three given sequences.
**Examples:**
>Input : str1 = "geeks"  
        str2 = "geeksfor"  
        str3 = "geeksforgeeks"  
>Output : 5  
>Longest common subsequence is "geeks"  
>i.e., length = 5<p>
>Input : str1 = "abcd1e2"  
        str2 = "bc12ea"  
        str3 = "bd1ea"  
>Output : 3  
>Longest common subsequence is "b1e"   
>i.e. length = 3.  

**solution:**
>The idea is to take a 3D array to store the 
length of common subsequence in all 3 given 
sequences i. e., L[m + 1][n + 1][o + 1]  <p>
1- If any of the string is empty then there
   is no common subsequence at all then  
           **L[i][j][k] = 0**  <p>
2- If the characters of all sequences match
   (or X[i] == Y[j] ==Z[k]) then  
        **L[i][j][k] = 1 + L[i-1][j-1][k-1]**  <p>
3- If the characters of both sequences do 
   not match (or X[i] != Y[j] || X[i] != Z[k] 
   || Y[j] !=Z[k]) then  
        **L[i][j][k] = max(L[i-1][j][k], 
                         L[i][j-1][k], 
                         L[i][j][k-1])**
                         
```c++
int lcsOf3( string X, string Y, string Z, int m, int n, int o)
{
    int L[m+1][n+1][o+1];

    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            for (int k=0; k<=o; k++)
            {
                if (i == 0 || j == 0||k==0)
                    L[i][j][k] = 0;
 
                else if (X[i-1] == Y[j-1] && X[i-1]==Z[k-1])
                    L[i][j][k] = L[i-1][j-1][k-1] + 1;
 
                else
                    L[i][j][k] = max(max(L[i-1][j][k],
                                         L[i][j-1][k]),
                                     L[i][j][k-1]);
            }
        }
    }

    return L[m][n][o];
}
```

#### 14. Maximum Sum Increasing Subsequence
>note: LIS的扩展

Given an array of n positive integers. Write a program to find the sum of maximum sum subsequence of the given array such that the intgers in the subsequence are sorted in increasing order. For example, if input is {1, 101, 2, 3, 100, 4, 5}, then output should be 106 (1 + 2 + 3 + 100), if the input array is {3, 4, 5, 10}, then output should be 22 (3 + 4 + 5 + 10) and if the input array is {10, 5, 4, 3}, then output should be 10

```c++
int maxSumIS( int arr[], int n )
{
    int i, j, max = 0;
    int msis[n];
 
    /* Initialize msis values for all indexes */
    for ( i = 0; i < n; i++ )
        msis[i] = arr[i];
 
    /* Compute maximum sum values in bottom up manner */
    for ( i = 1; i < n; i++ )
        for ( j = 0; j < i; j++ )
            if ( arr[i] > arr[j] && msis[i] < msis[j] + arr[i])
                msis[i] = msis[j] + arr[i];
 
    /* Pick maximum of all msis values */
    for ( i = 0; i < n; i++ )
        if ( max < msis[i] )
            max = msis[i];
 
    return max;
}
```

#### 15. Maximum subsequence sum such that no three are consecutive
Given a sequence of positive numbers, find the maximum sum that can be formed which has no three consecutive elements present.

**solution:**
```
sum[i] : Stores result for subarray arr[0..i], i.e.,
         maximum possible sum in subarray arr[0..i]
         such that no three elements are consecutive.

sum[0] = arr[0]

// Note : All elements are positive
sum[1] = arr[0] + arr[1]

// We have three cases
// 1) Exclude arr[2], i.e., sum[2] = sum[1]
// 2) Exclude arr[1], i.e., sum[2] = sum[0] + arr[2]
// 3) Exclude arr[0], i.e., sum[2] = arr[1] + arr[2] 
sum[2] = max(sum[1], arr[0] + arr[2], arr[1] + arr[2])

In general,
// We have three cases
// 1) Exclude arr[i],  i.e.,  sum[i] = sum[i-1]
// 2) Exclude arr[i-1], i.e., sum[i] = sum[i-2] + arr[i]
// 3) Exclude arr[i-2], i.e., sum[i-3] + arr[i] + arr[i-1] 
sum[i] = max(sum[i-1], sum[i-2] + arr[i],
             sum[i-3] + arr[i] + arr[i-1])
```

```c++
int maxSumWO3Consec(int arr[], int n)
{
    // Stores result for subarray arr[0..i], i.e.,
    // maximum possible sum in subarray arr[0..i]
    // such that no three elements are consecutive.
    int sum[n];
 
    // Base cases (process first three elements)
    if (n >= 1)
        sum[0] = arr[0];
 
    if (n >= 2)
        sum[1] = arr[0] + arr[1];
 
    if (n > 2)
        sum[2] = max(sum[1], max(arr[1] + arr[2], arr[0] + arr[2]));
 
    // Process rest of the elements
    // We have three cases
    // 1) Exclude arr[i], i.e., sum[i] = sum[i-1]
    // 2) Exclude arr[i-1], i.e., sum[i] = sum[i-2] + arr[i]
    // 3) Exclude arr[i-2], i.e., sum[i-3] + arr[i] + arr[i-1]
    for (int i = 3; i < n; i++)
        sum[i] = max(max(sum[i - 1], sum[i - 2] + arr[i]),
                     arr[i] + arr[i - 1] + sum[i - 3]);
 
    return sum[n - 1];
}
```