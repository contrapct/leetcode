class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int i;
        for(i=0;i<n;++i){
            if(A[i]>0 && A[i]<n){
                if(A[A[i]-1]!=A[i]){
                    swap(A[i],A[A[i]-1]);
                    --i;
                }
            }
        }
        for(i=0;i<n;++i){
            if(A[i]!=i+1)
                return i+1;
        }
        return n+1;
    }
};
