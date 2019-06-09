// a[n][n] - nr nat, afis mesaj preciz daca toate val de pe diag princ au c imp ord strict desc
// mesaj preciz daca elem diag sec sunt ord cresc
// afis toate per alaturate de pe ult col cu prop ca primul el e egal cu suma cifrelor urmatorului elem
#include <iostream>

using namespace std;

int n, m, a[50][50], l;

void citire(int i, int j)
{
	if (i == n) return;
	if (i == j) 
	{
		citire(i+1, 0);
		return;
	}
	cin >> a[i][j];	
	citire(i, j+1);
}

int verif(int x)
{
	int cif = -1;
	
	while(x)
	{
		if(x % 10 % 2 == 0)
			cif = x % 10;
		x /= 10;	
	}
	
	if (cif == -1)
		return 0;
	
	while(x)
	{
		if(x % 2 == 0 && x % 10 == cif)
			return 0;
		x /= 10
	}
	return 1;
}

int dei(int s, int d)
{
	if (s == d)
		if (verif(a[l][s]) == 1)
			return 1;
		else
			return 0;
	int mij = (s + d) / 2
	return dei(s, mij) + dei(mij+1, d);
}

int main()
{
	citire(0, 0);
	cout << dei(d, m-1);
	return 0;	
}
