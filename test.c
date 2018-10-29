/* test file for utermie library development */
#include <stdio.h>
#include "utermie.h"

#define M_HEIGHT        6

int
main(int argc, char *argv[])
{

	ut_box(0, 0, 80, 1, UT_REV|UT_BOLD);
	ut_goto(0, 0);
	ut_set_attr(UT_REV | UT_BOLD);
	ut_center_lin("test of utermie fucntionalities");
	ut_set_attr(UT_RESET);

	return 0;
}
