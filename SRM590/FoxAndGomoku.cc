#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class FoxAndGomoku {
public:
  string win(vector <string>);
};

int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool is_in(int x, int y, int n, int m) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

string FoxAndGomoku::win(vector <string> board) {
  int n = board.size();
  int m = board[0].length();

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < 8; ++k) { // 8个方向
        int good = true;
        for (int cur = 0; cur < 5; ++cur) { // 5子
          if (!(is_in(i + cur * dx[k], j + cur * dy[k], n, m) && board[i + cur * dx[k]][j + cur * dy[k]] == 'o')) {
            good = false;
          }
        }
        if (good) return "found";
      }
    }
  }

  return "not found";
}
