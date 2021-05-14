#include <iostream>
using namespace std;

bool comprobar(int n);

int main(){
    int n;
    cin >> n;
    
    while(n!=0){
        
        cout << ( comprobar(n) ? "Si\n" : "No\n" ) ;
        
        cin >> n;
    }

    return 0;
}

bool comprobar(int n){
    
    while(true){
        
        if(n==1 || n==6) return true;
        else if(n<1) return false;

        n = (n%3 == 0) ? n/3 : n-5;
    }
}