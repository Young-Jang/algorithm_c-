
#include <iostream>
#define MAX_LEN 9

char TEXT[] = "aabcedabcdabcdabcefaaa";
char PATTERN[] = "abacbbc";


void make_fail(char* P, int* F)
{
	int i = 0, j = -1;

	F[0] = -1;

	while (i < strlen(P))
	{
		while (j > -1 && P[i] != P[j])
			j = F[j];

		i++, j++;

		F[i] = j;
	}
}

int  KMP(char* Text, char* Pattern)
{
	int fail[MAX_LEN + 1];
	int i = 0, j = 0;

	make_fail(Pattern, fail);

	while (i < strlen(Text))
	{

		while (j >= 0 && Text[i] != Pattern[j])
			j = fail[j];

		i++, j++;

		if (j == strlen(Pattern))	return i - j;
	}

	return -1;
}

void main()
{
	int ret;
	ret = KMP(TEXT, PATTERN);

	if (ret == -1) printf("not found\n");
	else
		printf("0123456789\n%s\n%s\nfound at %d\n", TEXT, PATTERN, ret);
}

