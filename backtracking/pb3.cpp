#include <iostream>
#include <fstream>
// de facut
using namespace std;

int st[5];

void afisare() {
	for(int i = 0; i < 4; ++i)
		cout << st[i];

	cout << '\n';
}

int verif(int k, int val)
{
  if(k == 0 && ("aeiou", val) == 0)
    return 0;

  return 1;
}

void back(int k)
{
  if (k == 4) {
    afisare();
    return;
  }
  for (char i = 'a'; i <= 'z'; i++) {
    if(verif(k, i))
    {
      st[k] = i;
      back(k+1);
    }
  }
}

int main()
{
  back(0);
  return 0;
}
