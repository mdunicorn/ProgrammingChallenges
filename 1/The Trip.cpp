#include <iostream>
#include <iomanip>

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int main()
{
	int n;
	while ((std::cin >> n) && n > 0)
	{
		long *amounts = new long[n];
		double d;
		long sum = 0;
		for (int i = 0; i < n; i++)
		{
			std::cin >> d;
			amounts[i] = d * 100;
			sum += amounts[i];
		}
		int average = sum / n;
		int rem = sum % n;
		long avgMin = average;
		long avgMax = average;
		if (rem > 0)
			avgMax++;
		int exchangeBelow = 0, exchangeAbove = 0;
		for (int i = 0; i < n; i++)
			if (amounts[i] >= avgMax)
				exchangeAbove += amounts[i] - avgMax;
			else if (amounts[i] <= avgMin)
				exchangeBelow += avgMin - amounts[i];
		int exchange = max(exchangeBelow, exchangeAbove);
		std::cout << "$" << std::setiosflags(std::ios::fixed) << std::setprecision(2) << exchange / 100.0 << std::endl;
		delete[] amounts;
	}

	return 0;
}