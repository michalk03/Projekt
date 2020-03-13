#include <iostream>
#include <fstream>
#include<string>
#include<vector>
#define N 1000000
using namespace std;
bool tab[N];

void sitoEratostenesa()
{
	tab[0] = 1;
	tab[1] = 1;
	for (int i = 2; i * i <= N; i++)
		{
		    if (tab[i] == 0)
                for (int j = i * i; j < N; j += i)
                    tab[j] = 1;
		}
}
int main()
{
	int n;
	cin >> n;
	fstream sitoe;
	sitoe.open("sito.txt", ios::out);
	sitoEratostenesa();
	int l = 0;
	for (int i = 2; i < n; i++)
	{
		if (tab[i] == 0)
			{
			    sitoe << i << endl;
                l++;
			}
	}
	sitoe.close();
	sitoe.open("sito.txt", ios::in);
	fstream liczbyb;
	vector<int>lp;
	lp.resize(l);
	for(int e=0;e<l;e++)
    {
        sitoe>>lp[e];
    }
    sitoe.close();
    liczbyb.open("liczbyb.txt", ios::out);
	long long int licz=0;
	for(int j=0;j<l;j++)
    {
        if(lp[j]+2==lp[j+1])
        {
            licz++;
        }
    }
    liczbyb<<"Liczba par bliŸniaczych: "<<licz<<endl;
    liczbyb<<"Liczba liczb bliŸniaczych: "<<2*licz-1<<endl;
	liczbyb.close();

	return 0;
}
