#include "LevenshteinDistance.h"

#include <algorithm>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

int levenshteinDistance(const string &str1, const string &str2)
{

  int m = str1.size();
  int n = str2.size();

  vector<vector<int>> dp(m + 1, vector<int>(n + 1));

  for (int i = 0; i <= m; i++)
  {

    for (int j = 0; j <= n; j++)
    {

      if (i == 0)
      {

        dp[i][j] = j;
      }
      else if (j == 0)
      {

        dp[i][j] = i;
      }
      else
      {

        int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
        dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost});
      }
    }
  }

  return dp[m][n];
}