#include <iostream>
#include <list>
#include <climits>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int coin_num(vector<int>& coins, int amount){
	sort(coins.begin(), coins.end());
	vector<int> dp(amount + 1, -1);
	dp[0] = 0;
	for (int i = 1; i < amount + 1; ++i)
	{
		int mincoin = INT_MAX;
		for (auto value:coins)
		{
			if (i - value < 0) 
				break;
			if (i - value >= 0 && dp[i - value] >= 0)
				mincoin = mincoin < dp[i - value] + 1 ? mincoin : dp[i - value] + 1;
		}
		if (mincoin != INT_MAX) 
			dp[i] = mincoin;
	}
	return dp[amount];
}


int main(int argc, char const *argv[])
{
	int coins[3] = { 1, 2, 5 };
	// int amount = 12;
	// //int result = -1;
	// vector<int> lc;


	//  for (int i = 0; i < 3; ++i)
	//  	lc.push_back(coins[i]);

	cout << sizeof(coins) << endl;

	return 0;
}










