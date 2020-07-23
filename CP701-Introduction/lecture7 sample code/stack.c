#include "stack.h"
#include <math.h>
#include <stdio.h>

/*
** New stuff introduced in this program
**
** __LINE__ is a preprocessor directive
** that is replaced with the current line
** number.
** __FILE__ is a preprocessor directive
** that is replaced with the current file name
*/

/*
** Refactor (definition)
** A code refactoring is any change to a computer program's
** code which improves its readability or simplifies its
** structure without changing its results.
**
** Function or variable name changes are common refactorings.
** Name changes are done to improve code readability be
** using a name that better expresses the code intent.
*/

/*
** In this class we refactored the stack API.
**
** First API problem. There is no way for the
** user of pop to know that they popped an empty stack
**
** So we changed pop from:
**
**     double pop();
**
** to
**
**     int pop(double* v);
**
** With this change we return a true value if the stack
** was not empty and we successfully returned the top of
** the stack value by reference using the v parameter.
**
** If the stack is empty, false is returned and the
** v parameter is not modified.
**
** We then refactored the name of pop to isPop. We
** want the name of pop to help us use it properly.
** It is common to name functions that return a boolean
** value (i.e., true or false) with is. Examples
** of this in the standard C library are the
** character type functions. (e.g., isascii, isdigit).
**
** Here we rename pop to isPop to enforce the idea
** that pop returns a boolean through its return value.
**
**
** We perform a similar refactoring to push so that
** we know when we tried to push onto a full stack.
*/

/* maximum numbers that may be on the
** stack at any one time */
#define STACK_MAX 256
 
/* global array used to build the stack */
double stack[STACK_MAX];

/* global index of current top of the stack */
int currentStackIndex = 0;

int areEqual(
	double d1,
	double d2)
{
	return fabs(d1 - d2) < 0.0001;
}

int main()
{
	double d;
	int i;

	isPush(56.6);
	isPush(67.5);
	isPush(66.8);

    /*
    ** isPop is TRUE on success. Thus test fails if FALSE is
    ** returned
    */
	if (isPop(&d) == FALSE)
	{
		printf("Could not isPop at line: %d\n", __LINE__);
		return;
	}

    /*
    ** areEqual returns true if the values are equal. Thus
    ** test fails if values are not equal
    */
	if (!areEqual(d, 66.8))
	{
		printf("Test failure at: %d\n", __LINE__);
		return;
	}

	if (isPop(&d) == FALSE)
	{
		printf("Could not isPop at line: %d\n", __LINE__);
		return;
	}

	if (!areEqual(d, 67.5))
	{
		printf("Test failure at: %d\n", __LINE__);
		return;
	}

	if (isPop(&d) == FALSE)
	{
		printf("Could not isPop at line: %d\n", __LINE__);
		return;
	}

	if (!areEqual(d, 56.6))
	{
		printf("Test failure at: %d\n", __LINE__);
		return;
	}

	if (isPop(&d) == TRUE)
	{
		printf("Test failed at line: %d\n", __LINE__);
		return;
	}

	for (i = 0; i < STACK_MAX; ++i)
	{
		isPush(i);
	}

	if (isPush(67.7) == TRUE)
	{
		printf("Test failed at line: %d\n", __LINE__);
		return;
	}

	printf("All tests pass\n");
}

int isPush(double d)
{
	if (currentStackIndex == STACK_MAX)
	{
		return FALSE;
	}

	stack[currentStackIndex] = d;
	currentStackIndex++;
	return TRUE;
}

int isPop(double* v)
{
	if (currentStackIndex == 0)
	{
		return FALSE;
	}

	currentStackIndex--;
	*v = stack[currentStackIndex];

	return TRUE;
}