#include <iostream>
#include <deque>
#include <map>

typedef unsigned long long ulong;

ulong next(ulong i);
int getMaxCLen(int m, int n);

const int maxNum = 1000000;

std::deque<ulong> toCalculate;
int cLengths[maxNum + 1];

int main()
{
	for (int i = 0; i <= maxNum; i++)
		cLengths[i] = 0;

	cLengths[1] = 1;

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
		int max = getMaxCLen(m, n);
		std::cout << om << " " << on << " " << max << std::endl;
	}
}

ulong next(ulong i)
{
	if (i <= 1)
		return 1;
	if (i % 2 == 0)
		return i / 2;
	return i * 3 + 1;
}


int getMaxCLen(int m, int n)
{
	for (int i = m; i <= n; i++)
	{
		ulong j = i;
		toCalculate.clear();
		while (j > maxNum || cLengths[j] == 0)
		{
			toCalculate.push_back(j);
			j = next(j);
		}
		int clen = cLengths[j];
		while (!toCalculate.empty())
		{
			clen++;
			j = toCalculate.back();
			toCalculate.pop_back();
			if (j <= maxNum)
				cLengths[j] = clen;
		}
	}

	int max = cLengths[m];
	for (int i = m + 1; i <= n; i++)
	{
		if (cLengths[i] > max)
			max = cLengths[i];
	}
	return max;
}
