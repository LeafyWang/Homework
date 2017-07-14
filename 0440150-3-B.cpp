#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int nums[12];
int abc;
int n;
int used;
vector<int> result;

bool if_equal(int a, int b);

void answ(int element, int sum) {
  if (sum == abc) {
    bool ok = true;

    for (int i = 0, sz = result.size(); i < sz; i++) {
      if (if_equal(result[i], used)) {
        ok = false;
        break;
      }
    }

    if (ok)
      result.push_back(used);

    return;
  }

  if (element == n) {
    return;
  }

  for (int i = element; i < n; i++) {
    if (sum + nums[i] <= abc) {
      used |= 1 << i;
      answ(i + 1, sum + nums[i]);
      used &= ~(1 << i);
    }
  }
}

bool if_equal(int a, int b) {
  if (__builtin_popcount(a) != __builtin_popcount(b))
    return false;

  int v1, v2;
  int count = __builtin_popcount(a);

  while (count) {
    for (int i = 0; i < 12; i++) {
      if ((a & 1<<i) != 0) {
        v1 = nums[i];
        a &= ~(1<<i);
        break;
      }
    }

    for (int i = 0; i < 12; i++) {
      if ((b & 1<<i) != 0) {
        v2 = nums[i];
        b &= ~(1<<i);
        break;
      }
    }
    count--;
    if (v1 != v2)
      return false;
  }

  return true;
}
void output(int a) {
  bool first = true;

  for (int i = 11; i >= 0; i--) {
    if ((a & (1<<i)) != 0) {
      if (!first)
        cout << "+";
      cout << nums[i];
      first = false;
    }
  }

  cout << endl;
}
bool finalt(int a, int b) {
  int x, y;
  for (int i = 11; i >= 0; i--)
  {
    x = a & (1 << i);
    y = b & (1 << i);
    if (a == b)
      continue;
    return a > b;
  }
}

int main()
{
  while (cin >> abc >> n) {
    if (n == 0)
      break;

    result.clear();
    used = 0;
    for (int i = n - 1; i >= 0; i--)
      cin >> nums[i];

    answ(0, 0);
    cout << "Sums of " << abc << ":" << endl;
    if (result.empty()) {
      cout << "NONE" << endl;
      continue;
    }
    sort(result.begin(), result.end(), finalt);
    for (int i = 0, sz = result.size(); i < sz; i++) {
      output(result[i]);
    }
  }
  return 0;
}
