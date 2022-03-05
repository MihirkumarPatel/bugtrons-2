/*
  * Here comes our Abir Pal, one of the organizers and speakers of BUGTRONS 2.0. Since, after the session, he felt very amazing and enthusisatic. He thought of bits present in the binary representation of the number `n`. He designed a problem to all our amazing participants and want to challenge them. The problem is as follows:

  * You will be given an integer `n` and your task is to count the number of one bits in the binary representations of integers between 1 and `n`. But, he want to make task something easy for our participants, so he gave you the sample solution of problem. But, he has produced unknown errors and bugs in the code. Since, he hasn't time to correct it, he gave it to you to debug it. Will you do it for him?

  ! Input:
  ! The only input line has an integer n.

  ! Output:
  ! Print the number of one bits in the binary representations of integers between 1 and n.

  ? Constraints: 1 <= n <= 10^15

  * Examples:
  ? Input:
  7

  ? Output:
  12

*/

// ! Driver Code starts. You should not change this
#include <bits/stdc++.h>
using namespace std;
// ! Driver Code ends.

// TODO: Code Implementation of above Problem
long long int Abir(long long int n)
{
    long long int pre[50] = {0};
    pre[0] = 0;

    for(long long i = 1 ; i < 50 ; i++){
        pre[i] = (1LL<<(i-1)) + (2*pre[i-1]);
    }

    long long int ans = 0;
    while (n > 0)
    {
        long long int b = log2(n);
        ans += pre[b];
        b = 1LL << b;
        ans += n - b + 1;
        b = log2(n);
        n = n % (1LL << b);
    }
    return ans;
}
// TODO: Code Implementation Ends here

// ! Driver Code starts. You should not change this
int main()
{
    long long int n;
    cin >> n;
    long long int ans = Abir(n);
    cout << ans << endl;
    return 0;
}
// ! Driver Code ends.
