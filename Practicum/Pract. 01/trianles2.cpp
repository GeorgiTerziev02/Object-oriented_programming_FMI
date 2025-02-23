#include <iostream>

struct Point
{
	double x;
	double y;
};

struct Triangle
{
	Point A;
	Point B;
	Point C;
	double area;
};

double CalculateArea(const Triangle& T)
{
	return 0.5 * std::abs(
		T.A.x * (T.B.y - T.C.y) +
		T.B.x * (T.C.y - T.A.y) +
		T.C.x * (T.A.y - T.B.y)
	);
}
void ReadPoint(Point& p)
{
	std::cin >> p.x >> p.y;
}
void ReadTriangle(Triangle& T)
{
	ReadPoint(T.A);
	ReadPoint(T.B);
	ReadPoint(T.C);
	T.area = CalculateArea(T);
	
}
void PrintPoint(const Point& p)
{
	std::cout <<" (" << p.x << "," << p.y << ") ";
}
void PrintTrianlge(const Triangle& T)
{
	PrintPoint(T.A);
	PrintPoint(T.B);
	PrintPoint(T.C);
	std::cout << std::endl;
}
void  SortTriangles(Triangle* triangles,int n)
{
	int MinIndex;
	for (size_t i = 0; i < n-1; i++)
	{
		MinIndex = i;
		for (size_t j = i + 1; j < n; j++)
		{
			if (triangles[j].area < triangles[MinIndex].area)
			{
				MinIndex = j;
			}
			
		}
		std::swap(triangles[i], triangles[MinIndex]);
	}

}


int main()
{
	int n;
	std::cin >> n;
	Triangle *  triangles = new Triangle[n];
	for (size_t i = 0; i < n; i++)
	{
		 ReadTriangle(triangles[i]);
	}

	SortTriangles(triangles,n);


	for (size_t i = 0; i < n; i++)
	{
		PrintTrianlge(triangles[i]);
	}
	delete[] triangles;
}