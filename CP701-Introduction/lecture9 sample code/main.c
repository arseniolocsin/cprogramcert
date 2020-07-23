#include "Test.h"

#include <string.h>

/* maximum numbers that may be on the
** stack at any one time */
#define STACK_MAX 256

typedef struct
{
	char firstName[256];
	char lastName[256];
	int id;
	int insuranceId;
} Patient;

typedef struct
{
	/* array used to build the stack */
	int stack[STACK_MAX];

	/* global index of current top of the stack */
	int currentStackIndex;
} Stack;

void initStack(Stack* s);

/* function prototype for function to push a
** value onto the stack */
int push(Stack* s, int val);

/* function prototype for function to pop
** a value off the stack */
int pop(Stack* s);

/* function prototype for function to print all
** the values currently on the stack */
void printStack(Stack* s);

int isEmpty(Stack* s);

main()
{
	Stack firstStack;
	Stack stack2;
	int i;

	initStack(&firstStack);
	initStack(&stack2);

	CHECK(isEmpty(&firstStack));
	if (!isEmpty(&firstStack))
	{
		pop(&firstStack);
		CHECK(firstStack.currentStackIndex == 0)
	}

	push(&stack2, 45);
	push(&firstStack, 34);
	CHECK(!isEmpty(&firstStack));
	CHECK(pop(&firstStack) == 34);
	CHECK(pop(&stack2) == 45);

	push(&firstStack, 56);
	CHECK(pop(&firstStack) == 56);

	push(&firstStack, 67);
	push(&firstStack, 120);
	printStack(&firstStack);
	CHECK(pop(&firstStack) == 120);
	CHECK(pop(&firstStack) == 67);

	for (i = 0; i < 256; ++i)
	{
		push(&firstStack, i);
	}

	for (i = 255; i >= 0; --i)
	{
		CHECK(pop(&firstStack) == i);
	}

	for (i = 0; i < 256; ++i)
	{
		CHECK(push(&firstStack, i));
	}

	CHECK(push(&firstStack, 1000) == 0);
}

void initStack(Stack* s)
{
	s->currentStackIndex = 0;
}

int push(Stack* s, int val)
{
	if (s->currentStackIndex == STACK_MAX)
	{
		return 0;
	}

	s->stack[s->currentStackIndex] = val;
	s->currentStackIndex++;

	return 1;
}

int pop(Stack* s)
{
	if (s->currentStackIndex != 0)
	{
		s->currentStackIndex--;
		return s->stack[s->currentStackIndex];
	}

	return 0;
}

int isEmpty(Stack* s)
{
	return s->currentStackIndex == 0;
}

void printStack(Stack* s)
{
	int i;
	for (i = 0; i < s->currentStackIndex; ++i)
	{
		printf("%d\n", s->stack[i]);
	}
}
