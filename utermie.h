#define	ESCAPE              27
#define UT_CLEAR_SCREEN()   printf("\e[1;1H\e[2J")

/* UT bit fields */
enum {          UT_RESET     = 0,
		UT_BOLD      = 1<<0,
		UT_LOW       = 1<<1,
		UT_UNDER     = 1<<2,
		UT_BLINK     = 1<<3,
		UT_REV 	     = 1<<4,
		UT_NATTR     = 6};

/* Colors */
enum {  UT_BLACK=0, UT_RED, UT_GREEN, UT_YELLOW, UT_BLUE, UT_MAGENTA, UT_CYAN,
	UT_WHITE, UT_NCOLORS };

extern int term;

int center_lin(char *str);
//TODO mirar on van els const
int set_attr(const unsigned char attr);
int set_fcolor(unsigned const int color);
int set_bcolor(unsigned const int color);
