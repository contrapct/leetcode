/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct myclass {
  bool operator()  (Interval i, Interval j) {
        return ( i.start < j.start);
    }
} myobject;
class Solution {
public:
    bool myfunction (Interval i, Interval j) {
        return ( i.start < j.start);
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<Interval> result ;

        if(intervals.size()==0)
            return result;

        std::sort (intervals.begin(), intervals.end(), myobject);

        result.push_back(*intervals.begin());
        auto it = intervals.begin() +1;
        for(;it!=intervals.end();++it){
            if(result.back().end < it->start){
                result.push_back(*it);
            }else{
                if(result.back().end >= it->start){
                    //se intersecteaza 
                    if(result.back().end < it->end){
                        result.back().end = it->end;
                    }
                    if(result.back().start > it->start){
                        result.back().start = it->start;
                    }
                }
            }
        }
        return result;
    }
};
