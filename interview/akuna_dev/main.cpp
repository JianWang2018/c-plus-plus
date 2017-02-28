#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> remove_n_duplicates(int n, vector<int> int_array)
{
    unordered_map<int, int> res;
    for (int i =0;i<int_array.size();++i)
    {
        if (res.find(int_array[i])!=res.end())
        {
            res[int_array[i]]+=1;
        }
        
        else res[int_array[i]]=1;
        
    }
    set<int> myset;
    
    for (auto it=res.begin(); it!=res.end(); ++it)
    {
        if (it->second!=n)
            myset.insert(it->first);
            
    }
    vector<int> result( myset.begin(), myset.end() );
    
    return  result;
    
    
}

bool has_non_intersecting_path(int n,pair<int,int>A,pair<int,int>B,pair<int,int>P,pair<int,int>Q)
{
    return 0;
    
}

int get_second_most_freq(vector<int> the_list) {
    unordered_map <int,int> m;
    for (auto i: the_list){
        m[i]++;
    }
    int max1 = 0;
    int max2 = 0;
    int res = 0;
    for (auto i=m.begin(); i!=m.end();++i){
        max1 = max((*i).second,max1);
    }
    cout<<max1<<endl;
    for (auto i=m.begin(); i!=m.end();++i){
        if ((*i).second != max1) {
            max2 = max((*i).second,max2);
            res = (*i).first;
        }
    }
    return res;
}

int find_two_closet_and_sum(vector<int> int_list, int target_num)
{
    
    return 0;
    
}

int main(){
    
    vector <int> test={1,1,1,22,2};
    vector<int> res =remove_n_duplicates(3,test);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    cin.get();
    return 0;
}