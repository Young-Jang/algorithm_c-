#include<iostream>

using namespace std;
int num[50];
int main()
{
	int cnt = 0;
	for (int i = 0; i < 10; i++)
	{
		int tmp;
		cin >> tmp;
		tmp = tmp % 42;
		if (!num[tmp])
		{
			num[tmp] = 1;
			cnt++;
		}
	}
	cout << cnt;
}