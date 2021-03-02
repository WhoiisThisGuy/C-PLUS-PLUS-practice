#include <cmath>

double mipow(const double base, const double exp) {

	if (base == 0)
		return 0;
	if (exp == 0)
		return 1;
	{
		double result = base; //power of 1
		for (int i = 1; i < abs(exp); ++i)
		{
			result *= base;
		}
		return exp > 0 ? result : 1/result;
	}
}