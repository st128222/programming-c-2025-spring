#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Matrix.h"

int main(int argc, char* argv[])
{
	Matrix matr(3);
	for (int i = 0; i < matr.getR(); ++i)
	{
		for (int j = 0; j < matr.getC(); ++j)
		{
			matr.set(i, j, 3 * i + j);
		}
	}
	matr.print(std::cout);
	std::cout << matr.det() << "\n";
	matr.transpose();
	matr.print(std::cout);
	return 0;
}