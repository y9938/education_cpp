#include <iostream>

int main()
{
	int d, w, commonY, leapY;
	d = 60 * 60 * 24;
	w = d * 7;
	commonY = d * 365;
	leapY = d * 366;
	std::cout << "Секунд в дне: " << d << "\n В неделе: " << w << "\n В обычном году: " << commonY << "\n В високосном году: " << leapY;
}
