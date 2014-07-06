#include <iostream>
#include <stack>

using std::cin;
using std::cout;
using std::stack;
using std::endl;

char *board = NULL;
int width, height;

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

char &pixel(int x, int y)
{
	return board[x - 1 + (y - 1)*width];
}

void clear()
{
	for (int i = 0; i < width*height; i++)
		board[i] = 'O';
}

void freeBoard()
{
	if (board != NULL)
		delete[]board;
}

void create()
{
	freeBoard();
	cin >> width >> height;
	board = new char[width*height];
	clear();
}

void color()
{
	int x, y;
	char c;
	cin >> x >> y >> c;
	pixel(x, y) = c;
}

void vLine()
{
	int x, y1, y2;
	char c;
	cin >> x >> y1 >> y2 >> c;
	if (y1 > y2)
		swap(y1, y2);
	for (int i = y1; i <= y2; i++)
		pixel(x, i) = c;
}

void hLine()
{
	int x1, x2, y;
	char c;
	cin >> x1 >> x2 >> y >> c;
	if (x1 > x2)
		swap(x1, x2);
	for (int i = x1; i <= x2; i++)
		pixel(i, y) = c;
}

void fillRect()
{
	int x1, x2, y1, y2;
	char c;
	cin >> x1 >> y1 >> x2 >> y2 >> c;
	for (int i = x1; i <= x2; i++)
		for (int j = y1; j <= y2; j++)
			pixel(i, j) = c;
}

struct Point
{
	int x, y;

	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

void checkAndAddPoint(int x, int y, stack<Point> &points, char originalColor, char newColor)
{
	if (x >= 1 && x <= width && y >= 1 && y <= height)
	{
		char &c = pixel(x, y);
		if (c == originalColor)
		{
			c = newColor;
			points.push(Point(x, y));
		}
	}
}

void fillRegion()
{
	int x, y;
	char c;
	cin >> x >> y >> c;

	int originalColor = pixel(x, y);
	if (originalColor == c)
		return;

	stack<Point> points;
	pixel(x, y) = c;
	points.push(Point(x, y));
	while (!points.empty())
	{
		Point p = points.top();
		points.pop();
		checkAndAddPoint(p.x - 1, p.y, points, originalColor, c);
		checkAndAddPoint(p.x + 1, p.y, points, originalColor, c);
		checkAndAddPoint(p.x, p.y + 1, points, originalColor, c);
		checkAndAddPoint(p.x, p.y - 1, points, originalColor, c);
	}
}

void write()
{
	char name[80];
	cin >> name;
	cout << name << endl;
	for (int y = 1; y <= height; y++)
	{
		for (int x = 1; x <= width; x++)
			cout << pixel(x, y);
		cout << endl;
	}
}

int main()
{
	board = NULL;
	char cmd;
	while ((cin >> cmd) && cmd != 'X')
	{
		switch (cmd)
		{
		case 'I':
			create();
			break;
		case 'C':
			clear();
			break;
		case 'L':
			color();
			break;
		case 'H':
			hLine();
			break;
		case 'V':
			vLine();
			break;
		case 'K':
			fillRect();
			break;
		case 'F':
			fillRegion();
			break;
		case 'S':
			write();
			break;
		default:
			cin.ignore(100000, '\n'); // Invalid command. Ignore the rest of the line.
			break;
		}
	}

	return 0;
}