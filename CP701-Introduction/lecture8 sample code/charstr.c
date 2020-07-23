#include <stdio.h>
#include <ctype.h>

#if 0
int main()
{
	int m[3] = {10, 20, 30};

	printf("%d\n", m[2]);
	printf("%d\n", *(m + 2));
}

#else

int myStrCmp(char* s1, char* s2)
{
	while (*s1 && *s2)
	{
		if (*s1 > *s2)
		{
			return 1;
		}
		else if (*s1 < *s2)
		{
			return -1;
		}

		++s2;
		++s1;
	}

	if (*s1)
	{
		return -1;
	}

	if (*s2)
	{
		return 1;
	}

	return 0;
}

int main()
{
	char* s = "Hello";
	char d[256];
	int result;

	scanf("%s", d);

	result = myStrCmp(s, d);
	if (result == 0)
	{
		printf("%s == %s\n", s, d);
	}
	else if (result > 0)
	{
		printf("%s is greater than %s\n", s, d);
	}
	else
	{
		printf("%s is less than %s\n", s, d);
	}
}
#endif