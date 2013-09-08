class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i=0;

        while(i<n){
            if(i==n-1) return true;
            if(A[i]==0)
                return false;
            i = i + A[i];
        }
        if(i==n)
        return true;
    }
};
