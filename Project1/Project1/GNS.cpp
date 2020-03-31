#include<iostream>
#include<string>

using namespace std;

int num[10000];
int tt[10000];
int n;

void merge(int p, int r, int m)
{
	int t1 = p;
	int t2 = m + 1;
	int idx = p;
	while (t1 <= m && t2 <= r)
	{
		if (num[t1] > num[t2])
			tt[idx++] = num[t2++];
		else
			tt[idx++] = num[t1++];
	}
	while (t1 <= m)
		tt[idx++] = num[t1++];
	while (t2 <= r)
		tt[idx++] = num[t2++];
	for (int i = p; i <= r; i++)
	{
		num[i] = tt[i];
	}
}

void mergeSort(int p, int r)
{
	if (p < r)
	{
		int mid = (p + r) / 2;
		mergeSort(p, mid);
		mergeSort(mid + 1, r);
		merge(p, r, mid);
	}
}

int main()
{
	cin.ignore(0);
	cin.sync_with_stdio(0);
	int T;
	cin >> T;
	string tmp = "";
	for (int k = 1; k <= T; k++)
	{
		cin >> tmp;
		cin >> n;
		int cnt = 0;
		char t1[4];
		tmp.clear();
		for (int i = 0; i < n; i++)
		{
			for (int c = 0; c < 3; c++)
			{
				cin >> t1[c];
				if (c == 2) {
					tmp.push_back(t1[0]);
					tmp.push_back(t1[1]);
					tmp.push_back(t1[2]);
					if (tmp == "ZRO")
						num[i] = 0;
					else if (tmp == "ONE")
						num[i] = 1;
					else if (tmp == "TWO")
						num[i] = 2;
					else if (tmp == "THR")
						num[i] = 3;
					else if (tmp == "FOR")
						num[i] = 4;
					else if (tmp == "FIV")
						num[i] = 5;
					else if (tmp == "SIX")
						num[i] = 6;
					else if (tmp == "SVN")
						num[i] = 7;
					else if (tmp == "EGT")
						num[i] = 8;
					else if (tmp == "NIN")
						num[i] = 9;
					tmp="";
				}
			}
		}
		mergeSort(0, n-1);
		std::cout << "#" << k << "\n";
		for (int i = 0; i < n; i++)
		{
			if (num[i] == 0)
				std::cout << "ZRO" << " ";
			else if (num[i] == 1)
				std::cout << "ONE" << " ";
			else if (num[i] == 2)
				std::cout << "TWO" << " ";
			else if (num[i] == 3)
				std::cout << "THR" << " ";
			else if (num[i] == 4)
				std::cout << "FOR" << " ";
			else if (num[i] == 5)
				std::cout << "FIV" << " ";
			else if (num[i] == 6)
				std::cout << "SIX" << " ";
			else if (num[i] == 7)
				std::cout << "SVN" << " ";
			else if (num[i] == 8)
				std::cout << "EGT" << " ";
			else if (num[i] == 9)
				std::cout << "NIN" << " ";
		}
		std::cout <<"\n";
	}
}
