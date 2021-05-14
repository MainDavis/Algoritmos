#include <iostream>
#include <cstring>

using namespace std;

int main(){

    string hey;
    cin >> hey;

    cout << "Hey: " << hey << "\n";

    hey.push_back('s');

    cout << "¿?: " << hey;

}