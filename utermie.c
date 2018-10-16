#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "utermie.h"

static const unsigned char attributes[UT_NATTR] = {1, 2, 4, 5, 7, 0};
int term;

/* prints an scape sequence to set a char attribute */
int
set_attr(const unsigned char attr)
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

/*prints a centered line str, if line is too long returns nchars */
int
center_lin(char *str)
{
	struct winsize ws;
	unsigned int str_size;
	char *p;

	/* Get window geometry */
	ioctl(term, TIOCGWINSZ, &ws);
	/* Get string size */
	for (p=str, str_size=0; *p; p++, str_size++)
		;
	if (str_size <= ws.ws_col)
		/*move cursor to star of the centered line*/
		printf("%c[%dC", ESCAPE, ((ws.ws_col/2)-(str_size/2)));
	
	else
		return str_size - ws.ws_col;
	
	/* print line */
	puts(str);

	return 0;
}

/* Sets foreground color */
int
set_fcolor(unsigned const int color)
{
	if (color < UT_NCOLORS)
		printf("%c[3%dm", ESCAPE, color);
	else return -1;

	return 0;
}

/* Set background color */
int
set_bcolor(unsigned const int color)
{
	if (color < UT_NCOLORS)
		printf("%c[4%dm", ESCAPE, color);
	else return -1;

	return 0;
}

int
main(void)
{
	struct winsize ws;
	int n;

	/* Setup */
	term = open("/dev/tty", O_RDONLY); 
	/* CLEAR SCREEN */
	UT_CLEAR_SCREEN();

	set_attr(UT_BOLD | UT_UNDER);
	printf("terminal %d\n", term);
	set_attr(UT_BOLD);
	center_lin("Ieja perraco");
	set_attr(UT_RESET);
	center_lin("esto mola un huevaco nen");

	set_fcolor(UT_CYAN);
	puts("CYAN");
	set_fcolor(UT_RED);
	puts("RED");
	set_fcolor(UT_WHITE);
	puts("WHITE");
	set_fcolor(UT_BLUE);
	set_bcolor(UT_YELLOW);
	printf("Hola que ase\n");
	set_attr(UT_RESET);
	printf("locuuuura\n");


	/*
	printf("%c%s", ESCAPE, "[f");

	for (n=0; n<5; n++)
		printf("%d\n", n);
		*/

	return 0;
}

