#include <iostream>

using namespace std;

void printTriangle(const int height)
{
	int spaces = height - 1;
	int width = height;
	for (int i = 0;i<height;++i)
	{
		for (int j = 0;j<width;++j)
		{
			if (j < spaces)
			{
				cout << ' ';
			}
			else
			{
				cout << '*';
			}
		}
		cout << '\n';
		++width;
		--spaces;
	}
}

void printDiamond(const int height)
{

	int nuOfSpaces = height - 1;
	int rowWidth = height;
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < rowWidth; ++j)
		{
			if (j < nuOfSpaces)
			{
				cout << ' ';
			}
			else
			{
				cout << '*';
			}
		}
		cout << '\n';
		++rowWidth;
		--nuOfSpaces;
	}

	nuOfSpaces = 0;
	--rowWidth;
	for (int i = height-1; i >= 0; --i)
	{
		for (int j = 0; j< rowWidth; ++j)
		{
			if (j < nuOfSpaces)
			{
				cout << ' ';
			}
			else
			{
				cout << '*';
			}
		}
		cout << '\n';
		--rowWidth;
		++nuOfSpaces;
	}
}

void printPresentBow(int height)
{
	for (int i = 0; i < height/2; i++)
	{	
		for (int j = 0; j < height; j++)
		{
			if (j <= i || j >= ((height - 1) - i))
			{
				cout << '*';
			}
			else
			{
				cout << '-';
			}
		}
		cout << '\n';
	}

	for (int i = (height / 2)-1; i >=0; --i)
	{
		for (int j = height-1; j >=0; --j)
		{
			if (j <= i || j >= ((height - 1) - i))
			{
				cout << '*';
			}
			else
			{
				cout << '-';
			}
		}
		cout << '\n';
	}
}