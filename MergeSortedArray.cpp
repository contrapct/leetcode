class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i,counterA=m-1,counterB=n-1;
        for(i=m+n-1;i>=0;--i){
            if(counterA<0){
                A[i]=B[counterB];
                --counterB;
            }else
            if(counterB<0){
                A[i]=A[counterA];
                --counterA;
            }else
            if(A[counterA]>B[counterB]){
                A[i]=A[counterA];
                --counterA;
            }
            else{
                A[i]=B[counterB];
                --counterB;
            }
        }
        
    }
};
