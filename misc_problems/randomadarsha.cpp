#include <bits/stdc++.h>
using namespace std;

int binarySearch(string *arr, string val, int size) {
  int low = 0;
  int high = size;

  while (high - low > 1) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == val) {
      return mid / x + 1;  // Return the page number
    } else if (val < arr[mid]) {
      high = mid;
    } else {
      low = mid;
    }
  }
  return (low / x + 1);  // Return the page number
}



int main() {
  int N, Q, x;
  string w;
  cin >> N >> Q;

  string *dic = new string[N];
  for (int i = 0; i < N; i++) {
    cin >> dic[i];
  }

  sort(dic->begin(), dic->end());



  int *op = new int[Q];
  for (int i = 0; i < Q; i++) {
    cout<<"w and x: ";
    cin >> w >> x;
    int no_of_pages = ceil((float)N / (float)x);
    int position = binarySearch(dic, w, N);
    // Search w in dic
    op[i] = ((position + 1) / no_of_pages + 1);
  }
  for (int i = 0; i < Q; i++) {
    cout << op[i] << endl;
  }

  return 0;
}