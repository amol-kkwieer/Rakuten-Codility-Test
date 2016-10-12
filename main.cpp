#include <iostream>
using namespace std;

#include <cmath>
bool interSectionCheck(int K, int L, int M, int N, int X, int Y)
{
	if (K < X && X < M && L < Y && Y < N)
	{
		return true;
	}
	else
		return false;
}

long int RectArea(int X1, int Y1, int X2, int Y2)
{
	return abs((X1 - X2)*(Y1 - Y2));
}

int solution(int K, int L, int M, int N, int P, int Q, int R, int S) {
	// write your code in C++11 (g++ 4.8.2)

	long int AreaReat1 = (N - L)*(M - K);
	long int AreaReat2 = (S - Q)*(R - P);
	long int AreaInterSection = 0;
	long int AreaSum = 0;

	if (interSectionCheck(K, L, M, N, P, S)) AreaInterSection = RectArea(M, L, P, S);
	if (interSectionCheck(K, L, M, N, P, Q)) AreaInterSection = RectArea(M, N, P, Q);
	if (interSectionCheck(K, L, M, N, R, S)) AreaInterSection = RectArea(K, L, R, S);
	if (interSectionCheck(K, L, M, N, R, Q)) AreaInterSection = RectArea(K, N, R, L);

	AreaSum = AreaReat1 + AreaReat2 - AreaInterSection;

	if (AreaSum >= pow(2, 32))
		return -1;
	else
		return AreaSum;
}

class Rectangle
{
private:int X1, Y1, X2, Y2;

public:Rectangle(int X1, int Y1, int X2, int Y2)
{
	this->X1 = X1;
	this->X2 = X2;
	this->Y1 = Y1;
	this->Y2 = Y2;
}

public:int GetArea()
{
	return abs((X1 - X2)*(Y1 - Y2));
}

public:bool InterSectionCheck(Rectangle eachRect)
{
	//if (this->X1 < eachRect.X2 && this->X2 > eachRect.X1 &&
	//	this->Y1 < eachRect.Y2 && this->Y2 < eachRect.Y1)
	//if (this->X1 < X && X < this->X2 && this->Y1 < Y && Y <this->Y2)
	{
		return true;
	}
	//else
	//	return false;
}
};

int solution2(int K, int L, int M, int N, int P, int Q, int R, int S) {
	// write your code in C++11 (g++ 4.8.2)
	
	Rectangle* rect1 = new Rectangle(K, L, M, N);
	Rectangle* rect2 = new Rectangle(P, Q, R, S);



	long int AreaReat1 = (N - L)*(M - K);
	long int AreaReat2 = (S - Q)*(R - P);
	long int AreaInterSection = 0;
	long int AreaSum = 0;


	if (rect1->InterSectionCheck(*rect2))
	{
		if (interSectionCheck(K, L, M, N, P, S)) AreaInterSection = RectArea(M, L, P, S);
		if (interSectionCheck(K, L, M, N, P, Q)) AreaInterSection = RectArea(M, N, P, Q);
		if (interSectionCheck(K, L, M, N, R, S)) AreaInterSection = RectArea(K, L, R, S);
		if (interSectionCheck(K, L, M, N, R, Q)) AreaInterSection = RectArea(K, N, R, L);
	}

	AreaSum = rect1->GetArea() + rect2->GetArea() - AreaInterSection;

	if (AreaSum >= pow(2, 32))
		return -1;
	else
		return AreaSum;
}

int main()
{
	unsigned int BinaryInput =  0x55;
	unsigned int XOR_Result;
	unsigned int lastXOR = 0;
	int RShift = 1;

	while (1)
	{
		XOR_Result = BinaryInput ^ (BinaryInput >> RShift);
		printf("%X, %d\r\n", XOR_Result, RShift);

		if (XOR_Result <= lastXOR )
		{
			cout << RShift-1;
			break;
		}
		else
		{
			lastXOR = XOR_Result;
			RShift++;
		}
	}
	

	//cout << solution2(-4, 1, 2, 6, 0, -1, 4, 3);
	system("PAUSE");
}