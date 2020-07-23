#pragma warning(disable: 4996)

#include "multiply.h"

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int getNumber()
{
	return rand() % 13;
}

void askUser(
	 int a,
	 int b)
{
	printf("What is the product of %d x %d: ", a, b);
}

int getAnswer()
{
	int answer;
	scanf("%d", &answer);

	return answer;
}

int isAnswerCorrect(n1, n2, answer)
{
	return (n1 * n2) == answer;
}

int doContinue()
{
	char doAnother[256];
	printf("Do another one? (Y/N)");
	scanf("%s", doAnother);

	if (toupper(doAnother[0]) == 'Y')
	{
		return 1;
	}

	return 0;
}