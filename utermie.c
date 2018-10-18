#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "utermie.h"

static const unsigned char attributes[UT_NATTR] = {1, 2, 4, 5, 7, 0};
int term;

/* prints an scape sequence to set a char attribute */
int
ut_set_attr(const unsigned char attr)
{
	unsigned char n = 0;

	printf("%c[0", ESCAPE);
	for (n=0; n<UT_NATTR; n++) {
		if ((1<<n) & attr) {
			printf(";%d", attributes[n]);
		}
	}
	putchar('m');

	return 0;
}

/* Sets a color */
int
ut_set_color(unsigned const char f, unsigned const int color)
{
	if (color < UT_NCOLORS)
		printf("%c[%d%dm", ESCAPE, f, color);
	else return -1;
	return 0;
}

/*prints a centered line str, if line is too long returns nchars */
int
ut_center_lin(char *str)
{
	struct winsize ws;
	unsigned int str_size;
	char *p;

	/* Get window geometry */
	ioctl(term, TIOCGWINSZ, &ws);
	/* Get string size */
	str_size = strlen(str);
	if (str_size <= ws.ws_col)
		/*move cursor to star of the centered line*/
		printf("%c[%dC", ESCAPE, ((ws.ws_col/2)-(str_size/2)));
	
	else
		return str_size - ws.ws_col;
	
	/* print line */
	puts(str);

	return 0;
}

void
ut_goto(unsigned int x, unsigned int y)
{
	printf("\e[%d;%dH", x, y);
}

int
ut_box(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2,
	unsigned char attr)
{
	int cols, lines;
	
	ut_goto(x1, y1);
	ut_set_attr(attr);
	
	for ( lines = (y2-y1); lines; lines--)
		for (cols = (x2-x1); cols; cols--)
			putchar(' ');
	
	ut_set_attr(UT_RESET);

	return 0;
}
