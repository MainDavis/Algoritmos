#include <iostream>
#include <vector>
#include <algorithm>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

class Persona{
	long long x;
	long long y;
	
	public:
		Persona(int x=0; int y=0){
			this->x = x;
			this->y = y;
		}
		
		long long dist(const Persona &p){
			return 
		}
		
	
};


int main(int argc, char** argv) {
	long long n; cin >> n;
	vector<long long>coords;
	
	for(int i=0; i<n*4; i++){
		long long x; cin >> x;
		coords.push_back(x);		
	}
	
	
	
	return 0;
}
