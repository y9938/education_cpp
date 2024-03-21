#include <iostream>
using namespace std;

int main() 
{
	double feet, kilometers;
	cout << "Введите 2 растояния (1 - футы, 2 - км)\n";
	cin >> feet >> kilometers;

	feet *= 0.0003048;

	if (feet < kilometers) cout << "Первое меньше: " << feet;
	else cout << "Второе меньше: " << kilometers;
}
