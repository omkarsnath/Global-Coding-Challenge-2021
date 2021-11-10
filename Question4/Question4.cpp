#include <vector>
#include <iostream>
using namespace std;

int totalPairs(int n, vector<int>& values) {
    // Complete the total pairs function
    int max, count=0;
    bool flag;
    int i=0, n1=n-1;
    while(i<(n1)) {
        max = 0;
        count ++;
        flag = true;
        if(values[i+1]>=values[i]) {
            i++;
            continue;
        }
        for(int j=i+2; j<n; j++) {
            if(values[j] >= max) {
                max = values[j];
                if(max>=values[i+1]) {
                    count ++;
                }
                if (flag) {
                    count ++;
                }
            }
            if(max >= values[i]) {
                break;
            }
            if(max >= values[i+1]) {
                flag = false;
            }
        }
        i+=2;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }
	
	int answer = totalPairs(n, values);
    // Do not remove below line
    cout << answer << endl;
    // Do not print anything after this line
    
    return 0;
}