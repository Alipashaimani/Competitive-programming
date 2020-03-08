#include <iostream>
int main () {int a,k[] = {6,8,4,2};std::cin >> a;std::cout << (a == 0 ? 1 : k[a%4]) << '\n';}