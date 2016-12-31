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


#include <unordered_set>

/*
 * Complete the function below.
 */
int maxStep(int n, int k)
{
    unordered_set<int>  forbidden_numbers;
    int sum = 0;
    // this range already covers k up to 4*10^6
    for (int i=1; i<3000; ++i)
    {
        sum += i;
        forbidden_numbers.insert(sum);
    }
    int sum_n = 0;

    for (int i=1; i<=n; ++i)
    {
        sum_n += i;
    }
    unordered_set<int>::const_iterator got = forbidden_numbers.find (k);
    if (got!=forbidden_numbers.end())
    {
        return sum_n-1;
    }
    else
    {
        return sum_n;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    int res;
    int _n;
    cin >> _n;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

    int _k;
    cin >> _k;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

    res = maxStep(_n, _k);
    fout << res << endl;

    fout.close();
    return 0;
}
