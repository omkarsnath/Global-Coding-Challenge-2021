#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

// Simulated Annealing using random arrangements
int bankersAndClients(int c, int b,vector< vector<int>> &time) {
    // Complete the bankersAndClients function .
    vector<int> banker(b);
    vector<int> previous(b);
    iota(banker.begin(), banker.end(),0);
    previous = banker;

    int minimum, result, sum, start, best, option, optimal, peak;
    int i, j, k, l, r, t;
    bool flag = false, change;

    vector<vector<int>> dist(b, vector<int> (c));

    start = 0;
    result = INT_MAX;

    // In case there is only one banker
    if(b==1) {
        result = 0;
        for(int i=0; i<c; i++) {
            result += time[0][i];
        }
        return result;
    }

    // Using simulated annealing to try 50 different starting random arrangements
    for(t=0; t<60; t++) {
        random_shuffle(banker.begin(), banker.end());
        peak = INT_MAX;
        change = true;

        // Swapping two elements in the arrangement provided they improve upon the minimum time result
        // This is done until no such swaps lead to an imrpovement
        while(change) {
            change = false;
            
            // Looping for all possible pairs to change
            for(l=0; l<b; l++) {
                for(r=l+1; r<b; r++) {
                    swap(banker[l], banker[r]);
                    optimal = INT_MAX;

                    // Dynamic Programming is used to calcualte optimal client allocation assuming a given banker order

                    // Checkcing how similar previous and current arrangement is (to avoid redundant computation)
                    if(flag) {
                        for(start = 0; start < b; start ++) {
                            if(previous[start] != banker[start]) {
                                break;
                            }
                        }
                    }
                    
                    // Intializing base case of Dynamic Programming
                    // dist[i][j] = min time to get to j client using only first i bankers of the given arrangement
                    if(start == 0) {
                        dist [0][0] = time[banker[0]][0];
                        for(int j=1; j<c; j++) {
                            dist[0][j] = time[banker[0]][j] + dist[0][j-1];
                        }
                        start ++;
                    }
                    
                    // Calulating minimum time for dp
                    for(i=start; i<b; i++) {
                        dist[i][0] = min(time[banker[i]][0], dist[i-1][0]);
                        for(j=1; j<c; j++) {
                            best = dist[i-1][j];
                            sum = 0;
                            for(k=j; k>0; k--) {
                                sum += time[banker[i]][k];
                                option = dist[i-1][k-1] + sum;
                                if(option < best) {
                                    best = option;
                                }
                            }
                            sum += time[banker[i]][0];
                            dist[i][j] = min(best, sum);
                        }
                        optimal = min(optimal, dist[i][c-1]);
                    }
                    flag = true;
                    previous = banker;

                    // If the swap gives an improvement, we keep running the loop, and keep the new arrangement
                    if(optimal < peak) {
                        change = true;
                        peak = optimal;
                    } else {
                        swap(banker[l], banker[r]);
                    }
                }
            }
        }

        result = min(result, peak);
    }

    return result;
}

int main(){
    int b,c;
    cin >> c>>b;
    int answer;
    vector<vector<int>> time(b,vector<int>(c));
    for(int i = 0; i < b; i++){
        
        for(int j = 0;j < c;j++){
          cin>>time[i][j];
        }
    }
	answer = bankersAndClients(c,b,time);
    // Do not remove below line
    cout << answer << endl;
    // Do not print anything after this line
        
    return 0;
}