#include<iostream>
using namespace std;

int fact(int n){
    if(n < 0){
        return 0;
    }else if((n == 1) || (n==0)){
        return 1;
    }else{
        return (n*fact(n-1));
    }
}

int c(int n, int r){ 
  return (fact(n)/(fact(r)*fact(n-r)));    
}


int main(){
    int n , r;
    cin >> n >> r;
    if((n < 0) || (r < 0)){
        cout << "ERROR" << endl;
        return 0;
    }
    cout <<  c(n,r) << endl;
return 0;
}
