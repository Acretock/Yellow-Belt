#include "rectangle.h"
#include <iostream>

int main()
{
	Rectangle a{ 3,4 };
	std::cout << a.GetArea() << ' ' << a.GetPerimeter() << ' ' << a.GetWidth() << ' ' << a.GetHeight();
}