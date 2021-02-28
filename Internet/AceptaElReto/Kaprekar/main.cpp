#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main(int argc, char** argv) {
	
	int n; cin >> n;
	
	for(int i=0; i<n; i++){
		int m1,m2=0; cin >> m1;
	
		if(m1%1111==0){
			cout << 8 << endl;
		}else if(m1==6174){
			cout << 0 << endl;
		}else{
			vector<int>v;
			int *temp;
			temp = new int;
			*temp = m1;
		
			do{
    			v.push_back(*temp % 10);
    			*temp /= 10;
			} while  (*temp > 0);
		
			delete temp;
		
			sort(v.begin(), v.end());
			m1=0;
			for(int i=3; i>-1; i--){
				m2+=v[3-i]*pow(10,i);
				
				m1+=v[i]*pow(10,3-i);
			}
			
			int cont;
			for(cont=0; m1!=6174; cont++){
				cout << "[" << m1 << "," << m2 << "]\n";
				m1-=m2;
			}
			cout << "["<< cont <<"]\n";	
			
				
			//cout << "[" << m1 << "," << m2 << "]\n"; 
			
		}	
	}
	
	
	
	
	
	return 0;
}
