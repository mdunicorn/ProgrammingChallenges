#include <iostream>
#include <vector>

void output(char ch, int count)
{
	for (int i = 0; i < count; i++)
		std::cout << ch;
}

void dash(int count = 1)
{
	output('-', count);
}

void blank(int count = 1)
{
	output(' ', count);
}

void bar(int count = 1)
{
	output('|', count);
}


int main()
{
	int s, n;
	int tc = 0;
	while ((std::cin >> s >> n) && s > 0)
	{
		if (++tc > 1)
			std::cout << std::endl;

		std::vector<int> digits;
		if (n == 0)
		{
			digits.push_back(0);
		}
		else
		{
			while (n > 0)
			{
				digits.push_back(n % 10);
				n /= 10;
			}
		}

		int rows = 2 * s + 3;
		int midRow = s + 1;
		int lastRow = rows - 1;
		for (int row = 0; row < rows; row++)
		{
			bool first = true;
			for (std::vector<int>::reverse_iterator rit = digits.rbegin(); rit != digits.rend(); rit++)
			{
				if (!first)
					blank();
				else
					first = false;

				switch (*rit)
				{
				case 0:
					if (row == 0 || row == lastRow)
					{
						blank();
						dash(s);
						blank();
					}
					else if (row == midRow)
					{
						blank(s + 2);
					}
					else
					{
						bar();
						blank(s);
						bar();
					}
					break;
				case 1:
					if (row == 0 || row == midRow || row == lastRow)
					{
						blank(s + 2);
					}
					else
					{
						blank(s + 1);
						bar();
					}
					break;
				case 2:
					if (row == 0 || row == midRow || row == lastRow)
					{
						blank();
						dash(s);
						blank();
					}
					else if (row < midRow)
					{
						blank(s + 1);
						bar();
					}
					else
					{
						bar();
						blank(s + 1);
					}
					break;
				case 3:
					if (row == 0 || row == midRow || row == lastRow)
					{
						blank();
						dash(s);
						blank();
					}
					else
					{
						blank(s + 1);
						bar();
					}
					break;
				case 4:
					if (row == 0 || row == lastRow)
					{
						blank(s + 2);
					}
					else if (row == midRow)
					{
						blank();
						dash(s);
						blank();
					}
					else if (row < midRow)
					{
						bar();
						blank(s);
						bar();
					}
					else
					{
						blank(s + 1);
						bar();
					}
					break;
				case 5:
					if (row == 0 || row == midRow || row == lastRow)
					{
						blank();
						dash(s);
						blank();
					}
					else if (row < midRow)
					{
						bar();
						blank(s + 1);
					}
					else
					{
						blank(s + 1);
						bar();
					}
					break;
				case 6:
					if (row == 0 || row == midRow || row == lastRow)
					{
						blank();
						dash(s);
						blank();
					}
					else if (row < midRow)
					{
						bar();
						blank(s + 1);
					}
					else
					{
						bar();
						blank(s);
						bar();
					}
					break;
				case 7:
					if (row == 0)
					{
						blank();
						dash(s);
						blank();
					}
					else if (row == midRow || row == lastRow)
					{
						blank(s + 2);
					}
					else
					{
						blank(s + 1);
						bar();
					}
					break;
				case 8:
					if (row == 0 || row == midRow || row == lastRow)
					{
						blank();
						dash(s);
						blank();
					}
					else
					{
						bar();
						blank(s);
						bar();
					}
					break;
				case 9:
					if (row == 0 || row == midRow || row == lastRow)
					{
						blank();
						dash(s);
						blank();
					}
					else if (row < midRow)
					{
						bar();
						blank(s);
						bar();
					}
					else
					{
						blank(s + 1);
						bar();
					}
					break;
				}

			}
			std::cout << std::endl;
		}
	}
	return 0;
}