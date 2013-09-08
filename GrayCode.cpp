class Solution {
public:
    vector<int> Reconstruct(vector<list<int>> &greyCode){
        vector<int> result;
        int number = 0;
        for(auto it = greyCode.begin();it!=greyCode.end();++it){
            number = 0;
            for(auto itv = it->begin(); itv != it->end();++itv){
                number = number * 2 + (*itv);
            }
            result.push_back(number);
        }
        return result;
    }
    vector<int> grayCode(int n) {
        if(n==0){
            vector<int> auxx;
            auxx.push_back(0);
            return auxx;
        }
        
        vector<list<int>> greyCode;
        list<int> aux;
        aux.push_back(0);
       
        greyCode.push_back(aux);
        aux.front()=1;
        greyCode.push_back(aux);
        for(int i=2;i<=n;++i){
            //dublez
            int aux = greyCode.size();
            for(int j=aux-1;j>=0;--j){
                //adaug 1 in fata
                greyCode[j].push_front(1);
                greyCode.push_back(greyCode[j]);
                //schimb in 0
                greyCode[j].front()=0;
            }  
        }
        return Reconstruct(greyCode);
    }
};
