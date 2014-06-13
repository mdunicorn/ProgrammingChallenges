#include <iostream>
#include <deque>
#include <map>

typedef unsigned long long ulong;

int &readCycleLength(ulong number);
ulong next(ulong i);

const int maxNum = 1000000;

std::deque<ulong> toCalculate;
int cLengths[maxNum + 1];
std::map<ulong, int> largeNumsCLenths;

int main()
{
	for (int i = 0; i <= maxNum; i++)
		cLengths[i] = 0;

	cLengths[1] = 1;
	for (ulong i = 2; i <= maxNum; i++)
	{
		ulong j = i;
		toCalculate.clear();
		int clen;
		while ((clen = readCycleLength(j)) == 0)
		{
			toCalculate.push_back(j);
			j = next(j);
		}
		while (!toCalculate.empty())
		{
			clen++;
			j = toCalculate.back();
			toCalculate.pop_back();
			readCycleLength(j) = clen;
		}
	}

	int m, n;
	while ((std::cin >> m >> n) && m > 0 && n > 0)
	{
		int om = m, on = n;
		if (m > n)
		{
			int temp = m;
			m = n;
			n = temp;
		}
		int max = cLengths[m];
		for (int i = m + 1; i <= n; i++)
		{
			if (cLengths[i] > max)
				max = cLengths[i];
		}
		std::cout << om << on << max << std::endl;
	}
}

int &readCycleLength(ulong number)
{
	std::map<ulong, int>::iterator it;
	if (number <= maxNum)
		return cLengths[number];
	else
		return largeNumsCLenths[number];
}

ulong next(ulong i)
{
	if (i <= 1)
		return 1;
	if (i % 2 == 0)
		return i / 2;
	return i * 3 + 1;
}