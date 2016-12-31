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

/*
 * Complete the function below.
 */
string electionWinner(vector < string > votes)
{
    unordered_map<string,int> name_counts;
    for (int i = 0; i < votes.size(); ++i)
    {
        name_counts[votes.at(i)]++;
    }

    int currentMax = 0;
    for(auto it = name_counts.cbegin(); it != name_counts.cend(); ++it )
    {
        if (it ->second > currentMax)
        {
            currentMax = it->second;
        }
    }
    set<string> sorted_tied_names;
    for(auto it = name_counts.cbegin(); it != name_counts.cend(); ++it )
    {
        if (it -> second == currentMax)
        {
            sorted_tied_names.insert(it -> first);
        }
    }
    return *sorted_tied_names.rbegin();
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    string res;

    int _votes_size = 0;
    cin >> _votes_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    vector<string> _votes;
    string _votes_item;
    for(int _votes_i=0; _votes_i<_votes_size; _votes_i++)
    {
        getline(cin, _votes_item);
        _votes.push_back(_votes_item);
    }

    res = electionWinner(_votes);
    fout << res << endl;

    fout.close();
    return 0;
}
