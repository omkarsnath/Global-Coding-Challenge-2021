#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int value = 1e6+1;

int primes[value];
int parent[value];
int size[value];
bool exists[value];

// Prime Factorization, and combining Prime Groups. 
// Modelling using DSJ, modified
int ancestor(int v) {
   if(v == parent[v]) {
      return v;
   } else {
      return parent[v] = ancestor(parent[v]);
   }
}

void unite(int a, int b) {
   a = ancestor(a);
   b = ancestor(b);
   if(a==b) {
      return;
   } else {
      if(size[a] < size[b]) {
         swap(a,b);
      }
      parent[b] = a;
      size[a] += size[b];
   }
}

void countStablePartitions(int n, vector<int>& values) {
   int count, groups, val, prime, previous;
   long long result, mod = 1e9+7;
   
   sort(values.begin(), values.end());

   for(int i=2; i<value; i+=2) {
      primes[i] = 2;
   }

   for(int i=3; i<value; i+=2) {
      if(primes[i] == 0) {
         primes[i] = i;
         for(int j=3; j*i<value; j+=2) {
            if(primes[j*i]==0) {
               primes[j*i] = i;
            }
         }
      }
   }
   
   for(int i=0; i<value; i++) {
      parent[i] = i;
      size[i] = 1;
   }

   for(int i=0; i<n; i++) {
      val = values[i];
      if(val==1) {
         exists[val] = true;
      }

      previous = 0;
      while(val>1) {
         prime = primes[val];
         exists[prime] = true;
         while(val%prime == 0) {
            val = val/prime;
         }
         if(previous) {
            unite(previous, prime);
         }
         previous = prime;
      }
   }

   groups = 0;
   for(int i=1; i<value; i++) {
      if(exists[i] && parent[i]==i) {
         groups++;
      }
   }

   //cout << "Groups:" << groups << endl;
   if(groups==1) {
      cout << "NO" << endl << "0" << endl;
   } else {
      result = 1;
      for(int i=0; i<groups; i++) {
         result *= 2;
         result %= mod;
      }
      result -= 2;
      if(result<0) {
         result += mod;
      }
      cout << "YES" << endl << result << endl;
   }

   return;
}

int main(){
   int n;
   cin >> n;
   vector<int> values(n);
   for (int i = 0; i < n; ++i) {
        cin >> values[i];
   }
   countStablePartitions(n, values);
   return 0;
}