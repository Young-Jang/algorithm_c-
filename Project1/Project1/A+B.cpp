#include<iostream>

using namespace std;

int main()
{
	int a, b;
	char tmp;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> a >> tmp >> b;
		if (!a && !b)
			break;
		cout << a + b << "\n";
	}
} 