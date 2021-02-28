#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	vector<int>v;
	
	cin >> n;
	while(n != 0){
		int max;
		cin >> max;
		for(int i=1; i<n; i++){
			int x; cin >> x;
			v.push_back(x);
			max = (x>max) ? x : max;
		}
		
		int sum=0;
	
		for(auto& it : v){
			sum+=max-it;
		}
		
			
		cout << sum << "\n";
		v.clear();
		cin >> n;
	}
		
	return 0;
}

				
	

