#include <iostream>
using namespace std;

int height(int n) {
  int height = 1;
  for(int i = 0; i < n; i++)
  {
    if (i % 2 == 0)
      height = 2 * height;
    else
      height++;
  }
    return height;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    cout << height(n) << endl;
  }
}
