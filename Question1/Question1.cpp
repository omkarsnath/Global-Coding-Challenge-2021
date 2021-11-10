using namespace std;
#include <iostream>

int solution(int n){
    // code here
	if(n%3) {
	    return 2*(n/3) + 1;
    } else {
        return 2*(n/3);
    }
}

/*  Do not edit below code */
int main() {
	int n;
	cin >> n;	
    int answer=solution(n);
	cout << answer << endl;	
}