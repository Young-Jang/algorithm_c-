#include<iostream>
#include<string>

using namespace std;

string s = "";
string t = "";
string tmp = "";
int a = 0;
int b = 0;
bool flag = true;

int main()
{
	cin >> s >> t;
	for (int i = t.length()-1; i >=0; i--)
	{
		if (t.length() == s.length())
		{
			if (t == s)
				flag = false;
			break;
		}
		if (t[i] == 'B')
		{
			t.pop_back();
			tmp = "";
			for (int j = t.length() - 1; j >= 0; j--)
				tmp.push_back(t[j]);
			for (int j = 0; j < tmp.length(); j++)
				t[j] = tmp[j];
		}
		else
			t.pop_back();
	}
	if (flag)
		cout << 0;
	else
		cout << 1;
}