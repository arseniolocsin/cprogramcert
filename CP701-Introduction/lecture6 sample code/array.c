#include <stdio.h>

main()
{
	printf("%c\n", 7["0123456789"]);
}

#define NELEMENT(x) (sizeof(x) / sizeof(x[0]))

void f(int a[], int nElements)
{
	int i;

	printf("NELEMENT(a) %d\n", NELEMENT(a));

	for (i = 0; i < NELEMENT(a); ++i)
	{
		a[i] = i;
	}
}

int main()
{
	int x[2] = { 66, 77 };
	int y[] = { 4, 6, 7, 8, 0 };
	int i;
	int ySize = NELEMENT(y);
	printf("ySize: %d\n", ySize);

	f(x, NELEMENT(x));

	printf("%d, %d\n", x[0], x[1]);

	for (i = 0; i < ySize; ++i)
	{
		printf("%d\n", y[i]);
	}

	f(y, ySize);

	for (i = 0; i < ySize; ++i)
	{
		printf("%d\n", y[i]);
	}
}

#include <stdio.h>

int main()
{
	int x[3] = {33, 66, 99};
	int i;

	for (i = 0; i < 3; ++i)
	{
		printf("%d\n", i[x]); /* -> *(i + x) */
	}

	printf("%p\n", x);

	for (i = 0; i < 3; ++i)
	{
		printf("%d\n", x + i);
	}

	for (i = 0; i < 3; ++i)
	{
		printf("%d\n", *(i + x));
	}
}