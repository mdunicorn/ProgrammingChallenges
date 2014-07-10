#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int registers[10];
int ram[1000];
int ip = 0;

bool runNextInstruction()
{
	int instruction = ram[ip];

	if (instruction == 100)
		return false;
	else
	{
		int o1 = instruction / 10 % 10;
		int o2 = instruction % 10;
		switch (instruction / 100)
		{
		case 2:
			registers[o1] = o2;
			break;
		case 3:
			registers[o1] = (registers[o1] + o2) % 1000;
			break;
		case 4:
			registers[o1] = (registers[o1] * o2) % 1000;
			break;
		case 5:
			registers[o1] = registers[o2];
			break;
		case 6:
			registers[o1] = (registers[o1] + registers[o2]) % 1000;
			break;
		case 7:
			registers[o1] = (registers[o1] * registers[o2]) % 1000;
			break;
		case 8:
			registers[o1] = ram[registers[o2]];
			break;
		case 9:
			ram[registers[o2]] = registers[o1];
			break;
		case 0:
			if (registers[o2] != 0)
				ip = registers[o1] - 1;
			break;
		}
		ip++;
		return true;
	}
}

int main()
{
	int testcases;
	cin >> testcases;
	cin.ignore();
	char line[10];
	cin.getline(line, 9); // skip the blank line

	for (int testcase = 0; testcase < testcases; testcase++)
	{
		int addr = 0;
		while (addr < 1000 && (cin.getline(line, 9)) && line[0] != '\0')
		{
			ram[addr++] = (line[0] - '0') * 100 + (line[1] - '0') * 10 + (line[2] - '0');
		}

		while (addr < 1000)
			ram[addr++] = 0;

		for (int i = 0; i < 10; i++)
			registers[i] = 0;

		ip = 0;
		int numInstructions = 1;
		while (runNextInstruction())
			numInstructions++;

		if (testcase > 0)
			cout << endl;
		cout << numInstructions << endl;
	}
	return 0;
}