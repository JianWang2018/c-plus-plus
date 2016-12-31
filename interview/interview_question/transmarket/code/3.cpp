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
const int MOD = 1000000007;

bool TestValid(int a, int b)
{
	if (a < 25) return false;
	else if (a == 25) return b <= 23;
	else return b == a - 2;
}

long long powmod(long long a, int n)
{
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = (res * a) % MOD;
		a = (a * a) % MOD;
		n /= 2;
	}
	return res;
}

long long f[50][50];

void init()
{
	for (int i = 0; i < 50; i++)
		f[i][0] = f[i][i] = 1;
	for (int i = 2; i < 50; i++)
		for (int j = 1; j < i; j++)
			f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % MOD;
}

int volleyball(int A, int B){
// first difine if the score is in the right format,  if not return 0
// swap a and b if a < b
    init();

	if (A < B) swap(A, B);
	if (!TestValid(A, B))
		return 0;
	else
	{
		if (A > 25)
		{
			int diff = B - 24;
			long long ans = (powmod(2, diff) * f[48][24]) % MOD;
			return ans;
		}
		else
		{
			return f[A + B - 1][B];
		}
	}
	return 0;

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
