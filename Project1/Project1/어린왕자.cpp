#include<iostream>
#include<string>

using namespace std;

string str = "";

int main()
{
	cin >> str;
	int cnt = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (i == str.length() - 1)
			cnt++;
		else if (str[i] == 'c')
		{
			if (str[i + 1] == '=' || str[i + 1] == '-')
			{
				i++;
				cnt++;
				continue;
			}
			else
			{
				cnt++;
				continue;
			}
		}
		else if (str[i] == 'd')
		{
			if (str[i + 1] == '-')
			{
				cnt++;
				i++;
				continue;
			}
			else if (str[i + 1] == 'z' && str[i + 2] == '=')
			{
				cnt++;
				i += 2;
				continue;
			}
			else
			{
				cnt++;
				continue;
			}
		}
		else if (str[i] == 'l')
		{
			if (str[i + 1] == 'j')
			{
				cnt++;
				i++;
				continue;
			}
			else
			{
				cnt++;
				continue;
			}
		}
		else if (str[i] == 'n' && str[i + 1] == 'j')
		{
			cnt++;
			i++;
			continue;
		}
		else if (str[i] == 's' && str[i + 1] == '=')
		{
			cnt++;
			i++;
			continue;
		}
		else if (str[i] == 'z' && str[i + 1] == '=')
		{
			cnt++;
			i++;
			continue;
		}
		else
			cnt++;
	}
	cout << cnt;
}