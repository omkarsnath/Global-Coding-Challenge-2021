#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int group(vector<int> &parent, int v) {
    if(v == parent[v]) {
        return v;
    } else {
        return parent[v] = group(parent, parent[v]);
    }
}

void theHackathon(int n, int m, int a, int b, int f, int s, int t) {
    // Participant code here
    map <int, string> names;
    map <string, int> code;
    map <int, int> department;
    set <string> results;

    vector<int> size(n, 0);
    vector<int> parent(n);
    vector<vector<int>> depSize(n);
    string s1, s2;
    int p, g1, g2;

    for(int i=0; i<n; i++) {
        cin >> s1 >> p;
        names[i] = s1;
        code[s1] = i;
        department[i] = p;
        size[i] = 1;
        parent[i] = i;
        depSize[i] = {0, (p==1), (p==2), (p==3)};
    }

    for(int i=0; i<m; i++) {
        cin >> s1 >> s2;
        g1 = group(parent, code[s1]);
        g2 = group(parent, code[s2]);
        if((g1!=g2) && ((size[g1]+size[g2]) <= b) && ((depSize[g1][1]+depSize[g2][1]) <= f) && ((depSize[g1][2]+depSize[g2][2])<=s) && ((depSize[g1][3] + depSize[g2][3])<=t)) {
            if(g2>g1) {
                swap(g1,g2);
            }
            size[g1] = size[g1] + size[g2];
            depSize[g1][1] = depSize[g1][1] + depSize[g2][1];
            depSize[g1][2] = depSize[g1][2] + depSize[g2][2];
            depSize[g1][3] = depSize[g1][3] + depSize[g2][3];
            parent[g2] = g1;
        }
    }   

    p = -1;
    for(int i=0; i<n; i++) {
        if(size[i]>=a) {
            p = max(p, size[i]);
        }
    }
    for(int i=0; i<n; i++) {
        g1 = group(parent, i);
        if(size[g1]==p) {
                results.insert(names[i]);
        }
    }
    if(results.empty()) {
        results.insert("no groups");
    }
    for (auto x: results) {
        cout << x << endl;
    }
    return;
}

/*
// Using Adjacency List (TLE)
void theHackathon(int n, int m, int a, int b, int f, int s, int t) {
    // Participant code here
    map <int, string> names;
    map <string, int> code;
    map <int, int> group;
    map <int, int> department;
    set <string> results;

    vector<int> size(n, 0);
    map<int, unordered_set<int>> adjList;
    vector<vector<int>> depSize(n);
    string s1, s2;
    int p, g1, g2, gmax, gmin;

    for(int i=0; i<n; i++) {
        cin >> s1 >> p;
        names[i] = s1;
        code[s1] = i;
        department[i] = p;
        group[i] = i;
        size[i] = 1;
        depSize[i] = {0, (p==1), (p==2), (p==3)};
        adjList[i].insert(i);
    }

    for(int i=0; i<m; i++) {
        cin >> s1 >> s2;
        g1 = group[code[s1]];
        g2 = group[code[s2]];
        if((g1!=g2) && ((size[g1]+size[g2]) <= b) && ((depSize[g1][1]+depSize[g2][1]) <= f) && ((depSize[g1][2]+depSize[g2][2])<=s) && ((depSize[g1][3] + depSize[g2][3])<=t)) {
            gmax = max(g1, g2);
            gmin = min(g1, g2);
            size[gmax] = size[g1] + size[g2];
            size[gmin] = 0;
            depSize[gmax][1] = depSize[g1][1] + depSize[g2][1];
            depSize[gmax][2] = depSize[g1][2] + depSize[g2][2];
            depSize[gmax][3] = depSize[g1][3] + depSize[g2][3];
            for(auto j: adjList[gmin]) {
                group[j] = gmax;
                adjList[gmax].insert(j);
            }
            adjList[gmin].clear();
        }
    }   

    p = -1;
    for(int i=0; i<n; i++) {
        if(size[i]>=a) {
            p = max(p, size[i]);
        }
    }
    for(int i=0; i<n; i++) {
        if(size[i]==p) {
            for(auto x: adjList[i]) {
                results.insert(names[x]);
            }
        }
    }
    if(results.empty()) {
        results.insert("no groups");
    }
    for (auto x: results) {
        cout << x << endl;
    }
    return;
}
*/

int main()
{
    string inputdata_temp;
    getline(cin, inputdata_temp);

    vector<string> inputdata = split_string(inputdata_temp);

    int n = stoi(inputdata[0]);

    int m = stoi(inputdata[1]);

    int a = stoi(inputdata[2]);

    int b = stoi(inputdata[3]);

    int f = stoi(inputdata[4]);

    int s = stoi(inputdata[5]);

    int t = stoi(inputdata[6]);
    
    theHackathon(n, m, a, b, f, s, t);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int group(vector<int> &parent, int v) {
    if(v == parent[v]) {
        return v;
    } else {
        return parent[v] = group(parent, parent[v]);
    }
}

void theHackathon(int n, int m, int a, int b, int f, int s, int t) {
    // Participant code here
    map <int, string> names;
    map <string, int> code;
    map <int, int> department;
    set <string> results;

    vector<int> size(n, 0);
    vector<int> parent(n);
    vector<vector<int>> depSize(n);
    string s1, s2;
    int p, g1, g2;

    for(int i=0; i<n; i++) {
        cin >> s1 >> p;
        names[i] = s1;
        code[s1] = i;
        department[i] = p;
        size[i] = 1;
        parent[i] = i;
        depSize[i] = {0, (p==1), (p==2), (p==3)};
    }

    for(int i=0; i<m; i++) {
        cin >> s1 >> s2;
        g1 = group(parent, code[s1]);
        g2 = group(parent, code[s2]);
        if((g1!=g2) && ((size[g1]+size[g2]) <= b) && ((depSize[g1][1]+depSize[g2][1]) <= f) && ((depSize[g1][2]+depSize[g2][2])<=s) && ((depSize[g1][3] + depSize[g2][3])<=t)) {
            if(g2>g1) {
                swap(g1,g2);
            }
            size[g1] = size[g1] + size[g2];
            depSize[g1][1] = depSize[g1][1] + depSize[g2][1];
            depSize[g1][2] = depSize[g1][2] + depSize[g2][2];
            depSize[g1][3] = depSize[g1][3] + depSize[g2][3];
            parent[g2] = g1;
        }
    }   

    p = -1;
    for(int i=0; i<n; i++) {
        if(size[i]>=a) {
            p = max(p, size[i]);
        }
    }
    for(int i=0; i<n; i++) {
        g1 = group(parent, i);
        if(size[g1]==p) {
                results.insert(names[i]);
        }
    }
    if(results.empty()) {
        results.insert("no groups");
    }
    for (auto x: results) {
        cout << x << endl;
    }
    return;
}

int main()
{
    string inputdata_temp;
    getline(cin, inputdata_temp);

    vector<string> inputdata = split_string(inputdata_temp);

    int n = stoi(inputdata[0]);

    int m = stoi(inputdata[1]);

    int a = stoi(inputdata[2]);

    int b = stoi(inputdata[3]);

    int f = stoi(inputdata[4]);

    int s = stoi(inputdata[5]);

    int t = stoi(inputdata[6]);
    
    theHackathon(n, m, a, b, f, s, t);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}