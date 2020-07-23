#include <stdio.h>

#define CHECK(condition) \
{\
    if (!(condition)) { \
	printf("Test %s Failed in file: %s at line: %d\n", #condition, __FILE__, __LINE__); \
    }\
}

#define CHECK_FAIL(text) \
{\
    printf("Test Failed %s in file %s at line: %d", (text), __FILE__, __LINE__); \
}
