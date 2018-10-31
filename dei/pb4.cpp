#include <iostream>

// s = 1 - a + a^2 - ... + (-1)^n - a^n

using namespace std;

int a[25], n;

int inter(int s, int mij, int d)
{
  int i = s, j = mij + 1, k = 0, b[40];
  while (i <= mij &&  j <= d) {
    if (a[i] > a[j]) {
      b[k++] = a[i++];
    } else {
      b[k++] = a[j++];
    }
  }
  while (i <= mij) b[k++] = a[i++];
  while (j <= d) b[k++] = a[j++];
  k = 0;
  for (i = s; i < d; i++) {
    a[i] = b[k++];
  }
}

void dei(int s, int d)
{
  if (s < d)
  {
    int mij = (s + d) / 2;
    dei(s, mij);
    dei(mij+1, d);
  }
}

void afisare(int s, int d)
{
  if (s == d) cout << a[s] << ' ';
  
}

int main()
{
  cin >> n;
  citire(0, n-1);
  dei(0, n-1);
  afisare(0, n-1);
  return 0;
}
