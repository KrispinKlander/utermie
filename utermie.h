/* utermie.h description */

#define	ESCAPE              27
#define UT_CLEAR_SCREEN()   printf("\e[1;1H\e[2J")

#define ut_set_fcolor(X)        ut_set_color(UT_FG, (X))
#define ut_set_bcolor(X)        ut_set_color(UT_BG, (X))

/* UT bit fields */
enum {          UT_RESET     = 0,
		UT_BOLD      = 1<<0,
		UT_LOW       = 1<<1,
		UT_UNDER     = 1<<2,
		UT_BLINK     = 1<<3,
		UT_REV 	     = 1<<4,
		UT_NATTR     = 6};

/* Colors */
enum {  UT_BLACK = 0, UT_RED, UT_GREEN, UT_YELLOW, UT_BLUE, UT_MAGENTA,
	UT_CYAN, UT_WHITE, UT_NCOLORS };
enum { UT_FG = 3, UT_BG = 4};

extern int term;

int ut_center_lin(char *str);
//TODO mirar on van els const
int ut_set_attr(const unsigned char attr);
//int set_fcolor(unsigned const int color);
//int set_bcolor(unsigned const int color);
int ut_set_color(unsigned const char f, unsigned const int color);
void ut_goto(unsigned int x, unsigned int y);
int ut_box(unsigned char x1, unsigned char y1, unsigned char x2,
	unsigned char y2, unsigned char attr);
