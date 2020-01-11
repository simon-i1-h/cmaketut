#include <stdio.h>

#include "conf.h"

#ifdef USE_MYMATH
#  include "mymath.h"
#endif

int
main(void)
{
	printf("major version: %d, minor version: %d\n", vermajor, verminor);
#ifdef USE_MYMATH
	printf("[use libmymath] mul3(6): %d\n", mul3(6));
#endif
	return 0;
}
