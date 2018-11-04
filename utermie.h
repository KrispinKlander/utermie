#include <sys/ioctl.h>

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
		UT_NATTR     = 6
	 };

enum {
		UT_UP        = 0,
		UT_DOWN      = 1,
		UT_RIGHT     = 2,
		UT_LEFT      = 3
	 };

/* Colors */
enum {  UT_BLACK = 0, UT_RED, UT_GREEN, UT_YELLOW, UT_BLUE, UT_MAGENTA,
	UT_CYAN, UT_WHITE, UT_NCOLORS };
enum { UT_FG = 3, UT_BG = 4};

extern int term;
extern struct winsize ws;

int ut_move_cursor(int n, int dir);
int ut_center_lin(char *str);
int ut_set_attr(const unsigned char attr);
int ut_set_color(unsigned const char f, unsigned const int color);
int ut_box(unsigned char x1, unsigned char y1, unsigned char x2,
	unsigned char y2, unsigned char attr);
int ut_get_term(char *path);
void ut_winsize(void);
void ut_goto(unsigned int x, unsigned int y);
