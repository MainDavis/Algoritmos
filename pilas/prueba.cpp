#include <iostream>
#include <vector>

using namespace std;

int main(){

    int v[]{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}; //Si
    int *v2 = new int[20]; //No
    int v3[20]; //Si

    for(int i=0; i<20; i++)
        v2[i]=i;
    for(int i=0; i<20; i++)
        v3[i]=i+3;

    for (int x : *v2){
        cout << x << ", ";
    }
    
    return 0;
}