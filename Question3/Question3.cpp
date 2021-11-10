#include <bits/stdc++.h>
using namespace std;

int portfolio_profit_maximisation(int maxSum, vector<int> a, vector<int> b) {
    //write your code here 
    int i=0, j=0;
    int n = a.size(), m = b.size();
    long sum = 0, count = 0, maxCount = 0;
    while(i<n) {
        if((sum + a[i]) <= maxSum) {
            sum += a[i++];
        } else {
            break;
        }
    }
    count = i;
    maxCount = i;
    for(int k=i-1; k>=0; k--) {
        while(j<m) {
            if((sum + b[j]) <= maxSum) {
                sum += b[j++];
                count ++;
            } else {
                break;
            }
        }
        maxCount = (maxCount > count) ? maxCount : count;
        sum -= a[k];
        count --;
    }
    while(j<m) {
        if((sum + b[j]) <= maxSum) {
            sum += b[j++];
            count ++;
        } else {
            break;
        }
    }
    maxCount = (maxCount > count) ? maxCount : count;
    return maxCount;
}

int main()
{
    ios::sync_with_stdio(false);

    int n, m, x;
    cin >> n >> m >> x;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int result = portfolio_profit_maximisation(x, a, b);
    cout << result;
    return 0;
}