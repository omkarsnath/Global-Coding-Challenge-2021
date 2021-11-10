#include <bits/stdc++.h>

using namespace std;
int calculateMaximizedReturns(int n, int k, int d, int m, vector<int> returns) {
    // Participant's code will go here
    int maximum, total;
    vector<int> multiplier(n, 1);
    vector<bool> order(n,false);
    fill(order.end() - k, order.end(), true);
    
    maximum = 0;
    do {
        total = 0;
        fill(multiplier.begin(), multiplier.end(),1);
        for(int i=0; i<n; i++) {
            if(order[i]) {
                multiplier[i] = 0;
                for(int j=i+1; j<n && j<=(i+d); j++) {
                    multiplier[j] = m;
                }
            }
            total += returns[i] * multiplier[i];
        }
        maximum = max(total, maximum);
    } while(next_permutation(order.begin(), order.end()));

    return maximum;
}

vector<string> split(const string& str, char delim) {
    vector<string> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        strings.push_back(str.substr(start, end - start));
    }
    return strings;
}

vector<int> splitStringToInt(const string& str, char delim) {
    vector<int> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        strings.push_back(stoi(str.substr(start, end - start)));
    }
    return strings;
}

void printVector(vector<int> vec) {
    for (vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
        cout << *i << ' ';
    }
    cout << endl;
}

void printVector(vector<string> vec) {
    for (vector<string>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
        cout << *i << ' ';
    }
    cout << endl;
}

int main() {
    string firstLine;
    getline(cin, firstLine);

    vector<int> firstLineVec = splitStringToInt(firstLine, ' ');
    int n = firstLineVec[0];
    int k = firstLineVec[1];
    int d = firstLineVec[2];
    int m = firstLineVec[3];

    string returns;
    getline(cin, returns);

    vector<int> returnsVec = splitStringToInt(returns, ' ');

    int result = calculateMaximizedReturns(n, k, d, m, returnsVec);

    // Do not remove below line
    cout << result << "\n";
    // Do not print anything after this line

    return 0;
}