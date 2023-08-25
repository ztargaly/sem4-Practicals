#include <iostream>

using namespace std;

int sum_of_series(int n) {
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 0) {
      sum -= i;
    } else {
      sum += i;
    }
  }
  return sum;
}

int main() {
  int n;
  cout << "Enter the number of terms: ";
  cin >> n;

  int sum = sum_of_series(n);

  cout << "The sum of the first " << n << " terms of the series is " << sum << endl;

  return 0;
}
