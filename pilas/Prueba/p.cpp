#include <iostream>

bool func(int a){
    return (a == 1) ? 1: 0;
}

int main(){

    std::cout << func(1) << " " << func(2);

}