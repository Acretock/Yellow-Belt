#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <memory>
using namespace std;

class Figure {
public:
	virtual string Name() = 0;
	virtual double Perimeter() = 0;
	virtual double Area() = 0;
};

class Rect : public Figure {
public:
	Rect (int w, int h);
	double Perimeter() {
		return (2*(width+height));
	}
	double Area() {
		return (width * height);
	}
	string Name()  { return "Recrangle"; }

private:
	int width;
	int height;
};

class Circle : public Figure {
public:
	Circle(int r);
	double Perimeter() {
		return 2*3.14*radius;
	}
	double Area() {
		return 3.14*radius*radius;
	}
	string Name()  { return "Circle"; }

private:
	int radius;
};

class Triangle : public Figure {
public:
	Triangle(int side1,int side2, int side3);
	double Perimeter() {
		return a+b+c;
	}
	double Area() {
		double p = static_cast<double>(a + b + c) / 2.0;
		return sqrt(p*(p-a)*(p-b)*(p-c));
	}
	string Name()  { return "Triangle"; }

private:
	int a;
	int b;
	int c;
};

Rect::Rect(int w, int h) {
	width = w;
	height = h;
}

Triangle::Triangle(int side1, int side2, int side3) {
	a = side1;
	b = side2;
	c = side3;
}

Circle::Circle(int r) {
	radius = r;
}


shared_ptr<Figure> CreateFigure(istringstream& in) {
	string fig;
	int a, b, c;
	in >> fig;
	in >> a;
	if (in.good()) {
		in >> b;
		if (in.good()) {
			in >> c;
			return make_shared<Triangle>(a, b, c);
		}
		else {
			return make_shared<Rect>(a, b);
		}
	} else {
		return make_shared<Circle>(a);
	}
}

int main() {
	vector<shared_ptr<Figure>> figures;
	for (string line; getline(cin, line); ) {
		istringstream in(line);
		string command;
		in >> command;
		if (command == "ADD") {
			in >> ws;
			figures.push_back(CreateFigure(in));
		}
		else if (command == "PRINT") {
			for (const auto& current_figure : figures) {
				cout << fixed << setprecision(3)
					<< current_figure->Name() << " "
					<< current_figure->Perimeter() << " "
					<< current_figure->Area() << endl;
			}
		}
	}
	return 0;
}
