#include <iostream>
// a[n][m] sa se afis cate col au ult val un nr cu 2 cif alat pare

// sa se verif daca a[n][m] are cel putin o linie cu suma val impara

using namespace std;

int m, n, a[50][30];

void citire(int i, int j)
{
	if (i == n) return;
	if (j == m) 
	{
		citire(i+1, 0);
		return ;
	}
	cin >> a[i][j];	
	citire(i, j+1);
}

//fctie care verif daca o linie l are sval un nr impar 

int suma(int s, int d, int l)
{
	if (s == d) return a[l][s];
	else 
	{
		int mij = (s + d) / 2;
		return suma(s, mij, l) + suma(mij + 1, d, l);
	}
}

int verif2(int sus, int jos)
{
	if (sus == jos) 
	{
		if (suma(0, m-1, sus) % 2)
			return 1;
		else return 0;
	}
	else
	{
		int mij = (sus + jos) / 2;
		return verif2(sus, mij) + verif2(mij+1, jos);
	}
}

int verif(int x)
{
	while(x)
	{
		if (x % 10 % 2 == 0 && x / 10 % 10 % 2 == 0)
			return 1;
		x /= 10;
	}
	return 0;
}

int main()
{
	cin >> n >> m;
	citire(0, 0);
	cout << verif2(0, n-1);
}
