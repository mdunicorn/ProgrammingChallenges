#include <iostream>
#include <iomanip>

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
		double average = (double)sum / n;
		long iAverage = (int)average;
		if (iAverage < average)
			iAverage++;
		int minExchange = 0;
		for (int i = 0; i < n; i++)
			if (amounts[i] > iAverage)
				minExchange += amounts[i] - iAverage;
		std::cout << "$" << std::setiosflags(std::ios::fixed) << std::setprecision(2) << minExchange / 100.0 << std::endl;
	}

	return 0;
}