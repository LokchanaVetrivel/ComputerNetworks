/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    *returnSize = n + 1;
    int *ans = (int *)malloc((n + 1) * sizeof(int));
    int i;
    for(i=0;i<=n;i++){
        int num=i;
        int count=0;
        while(num>0){
            int quo=num/2;
            int rem=num%2;
            if(rem==1){
                count++;
            }
            num=quo;
        }
        ans[i]=count;
    }
    return ans;
}
