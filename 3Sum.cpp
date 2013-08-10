class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        unordered_map<int,vector<pair<int,int>>> sum2;
        unordered_map<int,vector<int>> hashnum;
        for(int it1 = 0; it1!=num.size();++it1){
            hashnum[num[it1]].push_back(it1);
            for(auto it2 = it1+1;it2!=num.size(); ++it2){
                sum2[num[it1]+num[it2]].push_back(make_pair(it1,it2));
            }
        }
        vector<vector<int>> rez;
        for(auto it =sum2.begin(); it!=sum2.end();++it){
            vector<int> p = hashnum[-it->first];
            vector<pair<int,int>> p2 = it->second;
            for(auto itt = p.begin();itt!=p.end();++itt){
                vector<int> sol;
                sol.push_back(0);
                sol.push_back(0);
                sol.push_back(0);
                for( auto ittt = p2.begin();ittt!=p2.end();++ittt){
                    sol[0]=*itt;
                    sol[1]=ittt->first;
                    sol[2]=ittt->second;
                    sort(sol.begin(),sol.end());
                    vector<int>::iterator aux;
                    aux = unique (sol.begin(), sol.end());   // 10 20 30 20 10 ?  ?  ?  ?
                    sol.resize( std::distance(sol.begin(),aux) ); // 10 20 30 20 10
                    if(sol.size()==3){                  
                        sol[0]=num[*itt];
                        sol[1]=num[ittt->first];
                        sol[2]=num[ittt->second];
                        sort(sol.begin(),sol.end());
                        rez.push_back(sol);
                    }
                }
            }
        }
        sort(rez.begin(),rez.end());
        vector<vector<int>>::iterator aux;
        aux = unique (rez.begin(), rez.end());   // 10 20 30 20 10 ?  ?  ?  ?
        rez.resize( std::distance(rez.begin(),aux) ); 
        return rez;
    }
};
