#include <bits/stdc++.h>
using namespace std;
 
// In C++, when passing an array, it forgets the size of the array
// It is not possible to tell what the size is 
// Hence I changed it to pass the vector instead
int securitiesBuying(int z,vector<int> &security_value)
{
    int no_of_stocks=0;
    // participants code here
    int n = security_value.size();
    int m, price, k, j=0;
    vector <pair<int, int>> val(n);
    
    for(int i=0; i<n; i++) {
        val[i] = {security_value[i], i+1};
    }
    sort(val.begin(), val.end());
    
    while(j<n) {
        price = val[j].first;
        k = val[j].second;
        m = min(k, z/price);
        z -= price * m;
        no_of_stocks += m;
        j++;
        if(m==0) { 
            break;
        }
    }

    return no_of_stocks;
}
 
int main() {
    int z;
    cin>>z;
    vector<int> input_data;
    string buffer;
    int data;
    getline(cin, buffer);
    getline(cin, buffer);
    istringstream iss(buffer);
    
    while (iss >> data)
        input_data.push_back(data);
 
    int n = input_data.size();
    int security_value[n];
    for (int i = 0; i < n; i++) {
        security_value[i] = input_data[i];
    }
    
    // Modified to pass vector<int> input_data instead of array
    int no_of_stocks_purchased = securitiesBuying(z,input_data);
    
    cout << no_of_stocks_purchased;
}