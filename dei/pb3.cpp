#include <iostream>
// se citeste un n nr nat, sa se afis suma

using namespace std;

int n;

int dei(int s, int d)
{
	if (s == d)
		return s;
	int mij = (s + d) / 2;
	return dei(s, mij) + dei(mij+1, d);	
}

int main()
{
	cin >> n;
	cout << "1 + 2 + .. + n = " << dei(1, n);
	return 0;
}
