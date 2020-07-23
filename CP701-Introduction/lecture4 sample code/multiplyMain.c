#pragma warning(disable: 4996)

#include "multiply.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main()
{
	srand((unsigned)time(NULL));

	do
	{
		int n1 = getNumber();
		int n2 = getNumber();
		int answer;

		askUser(n1, n2);
		answer = getAnswer();

		if (isAnswerCorrect(n1, n2, answer))
		{
			printf("Excellent - your answer is correct\n");
		}
		else
		{
			printf("\b");
			printf("Wrong - the correct answer is: %d\n", n1 * n2);
		}
	} while (doContinue());
}