using namespace std;
#include <string>
#include <iostream>

string solution(string n){
    // code here
    int count=0, maxCount=0, freq=0, nextMax=0;
    int len = n.size();
    string result = "A";

    for(int i=0; i<len; i++) {
        if(n[i] == '0') {
            count ++;
        } else if (count){
            if(count > maxCount) {
                nextMax = maxCount;
                maxCount = count;
                freq = 1;
                
            } else if(count == maxCount) {
                freq++;
            } else {
                nextMax = (count > nextMax) ? count : nextMax; 
            }
            count = 0;
        }
    }

    if(count > maxCount) {
        maxCount = count;
        freq = 1;
    } else if(count == maxCount) {
        freq++;
    }  else {
        nextMax = (count > nextMax) ? count : nextMax; 
    }
    
    if((freq > 1) || (maxCount%2==0) || (nextMax>maxCount/2)) {
        result = "B";
    }
    return result;
}

/*  Do not edit below code */
int main() {
	string  n;
	cin >> n;	
    string answer=solution(n);
	cout << answer << endl;	
}