#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double l, R, S;
    cout << "Enter l \n";
    cin >> l;
    R = l / (2 * M_PI);
    S = M_PI * pow(R, 2);
    cout << "S = " << S;
}
