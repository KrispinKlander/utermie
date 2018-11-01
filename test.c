#include <stdio.h>
#include "utermie.h"

int
main(int argc, char *argv[])
{
	/* Get terminal file pointer */
	ut_get_term("/dev/tty");

	ut_winsize();

	ut_box(0, 0, ws.ws_col, 1, UT_REV|UT_BOLD);
	ut_set_attr(UT_REV | UT_BOLD);
	ut_center_lin("test of utermie fucntionalities");
	ut_set_attr(UT_RESET);
	return 0;
}
