//#include<iostream>
//#include<string>
//#include<set>
//
//using namespace std;
//int n;
//string s = "";
//set<string> t;
//
//int main()
//{
//	int T;
//	cin.ignore(0);
//	cin.sync_with_stdio(0);
//	cin >> T;
//	for (int k = 1; k <= T; k++)
//	{
//		cin >> n;
//		cin >> s;
//		string tmp = "";
//		for (int l = 1; l <= s.length(); l++) {
//			for (int i = 0; i < s.length(); i++)
//			{
//				tmp = "";
//				if (i + l <= s.length()) {
//					for (int j = i; j < i + l; j++)
//					{
//						tmp.push_back(s[j]);
//					}
//					t.insert(tmp);
//				}
//			}
//		}
//		int cnt = 0;
//		for (auto iter = t.begin(); iter != t.end(); iter++)
//		{
//			cnt++;
//			if (cnt == n)
//			{
//				tmp = *iter;
//			}
//		}
//		if (tmp == "")
//			tmp = "none";
//		cout << "#" << k << " " << tmp << "\n";
//		t.clear();
//	}
//}


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
int n;
string s;
string sa[400];
int lcp[400];

int main()
{
	int T;
	cin.ignore(0);
	cin.sync_with_stdio(0);
	cin >> T;
	for (int k = 1; k <= T; k++)
	{
		cin >> n;
		cin >> s;
		string tmp = "";
		int leng = s.length();
		for (int i = 0 ;i < leng;i++)
		{
			tmp = s.substr(i, leng-i);
			sa[i]=tmp;

		}

		sort(sa, sa+leng);
		lcp[0] = 0;
		for (int i = 1; i < leng; i++)
		{
			int cnt = 0;
			while (sa[i][cnt] == sa[i - 1][cnt])
			{
				cnt++;
			}
			lcp[i] = cnt;
		}

		int res = 0;
		bool flag = false;
		for (int i = 0; i < leng; i++)
		{
			res += sa[i].length() - lcp[i];
			if (res >= n)
			{
				res -= sa[i].length() - lcp[i];
				int sz = n - res + lcp[i];
				cout << "#" << k << " ";
				for (int j = 0; j < sz; j++)
				{
					cout << sa[i][j];
				}
				cout << "\n";
				flag = true;
				break;
			}
		}
		if(!flag)
			cout << "#" << k << " none"<<"\n";
	}
}