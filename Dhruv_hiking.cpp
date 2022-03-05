/*
* Dhruv has gone for Hiking with his friends. While traveling, he saw a
beautiful farm of fruits on a roadside. He asked the farmer for some fruits from
his farm. Farmer gave him 2 baskets and some weird conditions on plucking fruits
from trees. Here's the problem:

* The Farm has a single row of fruit trees arranged from left to right. The
trees are represented by an integer array fruits where fruits[i] is the type of
fruit the ith tree produces. Dhruv want to collect as much fruit as possible.
However, the farmer has some strict rules that you must follow:

* - You only have two baskets, and each basket can only hold a single type of
fruit. There is no limit on the amount of fruit each basket can hold.
* - Starting from any tree of your choice, you must pick exactly one fruit from
every tree (including the start tree) while moving to the right. The picked
fruits must fit in one of your baskets.
* - Once you reach a tree with fruit that cannot fit in your baskets, you must
stop.

* Given the integer array fruits, print the maximum number of fruits you can
pick.

! Input:
! An integer vector `fruits` of length `n` where fruits[i] is the type of fruit
the ith tree produces

! Output:
! Print the maximum number of fruits you can pick.

? Constraints:
? 1 <= n <= 10^5
? 1 <= fruits[i] <= fruits.length

* Examples:
  1)
  ? Input:
  4
  0 1 2 2

  ? Output:
  3

  2)
  ? Input:
  5
  1 2 3 2 2

  ? Output:
  4

*/
#include <bits/stdc++.h>
using namespace std;

int Dhruv_Hiking(vector<int> &fruits) {

  int p = fruits.size();
  int ans = -1;
  int j = 0;
  map<int, int> fruits_map;
  for (int i = 0; i < p; i++) {
    fruits_map[fruits[i]]++;
    while (fruits_map.size() > 2) {
      fruits_map[fruits[j]]--;
      if (fruits_map[fruits[j]] == 0) {
        fruits_map.erase(fruits[j]);
      }
      j++;
    }
    ans = max(ans, i - j + 1);
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> fruits(n);
  for (int i = 0; i < n; i++)
    cin >> fruits[i];
  int ans = Dhruv_Hiking(fruits);
  cout << ans << endl;
}
