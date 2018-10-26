/* test file for utermie library development */
#include <stdio.h>
#include "utermie.h"

int
main(int argc, char *argv[])
{

	ut_set_attr(UT_REV | UT_BOLD);
	ut_center_lin("test of utermie fucntionalities");
	ut_set_attr(UT_RESET);

	return 0;
}
