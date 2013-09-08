class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if(n==0) 
            return n;
        int i=0,j=n-1;
        while(i<=j){
            if(A[j]==elem){
                --j;
            }else{
                if(A[i]==elem){
                    swap(A[i],A[j]);
                    --j;
                }else {
                    ++i;
                }                
            }            
        }
        return j+1;        
    }
};
