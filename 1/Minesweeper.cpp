#include <iostream>
#include <vector>
#include <string>

void incCellValue(char &cellChar)
{
	if (cellChar >= '0' && cellChar <= '9')
		cellChar++;
}

void incAdjacents(std::vector<std::string>& board, int row, int col)
{
	bool hasLeft = col > 0;
	bool hasRight = col < board[row].size() - 1;
	bool hasAbove = row > 0;
	bool hasBelow = row < board.size() - 1;
	if (hasLeft)
	{
		incCellValue(board[row][col - 1]);
		if (hasAbove)
			incCellValue(board[row - 1][col - 1]);
		if (hasBelow)
			incCellValue(board[row + 1][col - 1]);
	}
	if (hasRight)
	{
		incCellValue(board[row][col + 1]);
		if (hasAbove)
			incCellValue(board[row - 1][col + 1]);
		if (hasBelow)
			incCellValue(board[row + 1][col + 1]);
	}
	if (hasAbove)
		incCellValue(board[row - 1][col]);
	if (hasBelow)
		incCellValue(board[row + 1][col]);
}

int main()
{
	int m, n;
	int fieldNumber = 1;
	while (true)
	{
		std::cin >> n >> m;
		if (n == 0 || std::cin.fail())
			break;
		std::cin.ignore();
		std::vector<std::string> board(n);
		for (int i = 0; i < n; i++)
			std::getline(std::cin, board[i]);

		for (int i = 0; i < n; i++)
		{
			std::string &line = board[i];
			for (int j = 0; j < line.size(); j++)
			{
				if (line[j] == '.')
					line[j] = '0';
			}
		}

		for (int i = 0; i < n; i++)
		{
			std::string &line = board[i];
			for (int j = 0; j < line.size(); j++)
				if (line[j] == '*')
					incAdjacents(board, i, j);
		}

		if (fieldNumber > 1)
			std::cout << std::endl;

		std::cout << "Field #" << fieldNumber << ":" << std::endl;
		for (int i = 0; i < board.size(); i++)
			std::cout << board[i] << std::endl;
		fieldNumber++;
	}
}

