#include <iostream>
#include <fstream>

using namespace std;

int st[4];

void afisare() {
	for(int i = 1; i < 4; ++i)
		cout << st[i];

	cout << '\n';
}

int verif(int k, int val)
{
	if (k == 1 && val == 0)
		return 0;

	return 1;
}

void back(int k)
{
	if (k == 4) {
		afisare();
		return;
	}

	for (int i = 0; i <= 9; ++i)
	{
		if (verif(k, i) == 1)
		{
			st[k] = i;
			back(k + 1);
		}
	}
}

int main()
{
	back(1);
	return 0;
}
