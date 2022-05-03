#include <iostream>
#include <string>

using namespace std;

void init() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.fixed;
  cout.precision(20);
}

int main(void) {
  init();

  string str;
  cin >> str;
  cout << str;

  return 0;
}