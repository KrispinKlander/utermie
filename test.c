#include <stdio.h>
#include "utermie.h"

#define MENU_H	 7
#define MENU_ON  0xFF
#define MENU_OFF 0x00


#define TAB_STOP 4
#define PG_WIDTH 80


typedef struct {
	char key[3];
	char label[20];
}menu_entry_t;

typedef struct {
	char *caption;
	unsigned char ncols;
	menu_entry_t cols[][sizeof(menu_entry_t)>>3];
}menu_t;

int
makeRuler(void)
{
	int i;

	putchar('R');
	for (i = PG_WIDTH; i; i--) {
		if (i%4)
			putchar('-');
		else
			putchar('!');
	}
	putchar('L');
}

int
makeCaption(char *str)
{
	ut_box(0, 0, ws.ws_col, 7, UT_REV|UT_BOLD);
	ut_goto(0,0);
	ut_set_attr(UT_REV | UT_BOLD);
	ut_center_lin(str);
	ut_set_attr(UT_RESET);

	return 0;
}

int
makeMenu(menu_t *menu)
{
	unsigned char col, entry, end;
	unsigned int margin;

	ut_winsize();

	makeCaption(menu->caption);
		
	margin = (ws.ws_col / menu->ncols);
	/* i need to iterate over the columns, and entrys, 'til there isnt't any entry left */
	/* TODO: end of entries check broken, rethink it */
	for (entry = 0, end = 0; !end; entry++)
		{
			for (col = 0; col < menu->ncols; col++) {
					if (*(menu->cols[col][entry].key)) {
						ut_goto(margin * col + 1, entry+2);
						ut_set_attr(UT_BOLD|UT_REV);
						printf("%s\t", (menu->cols)[col][entry].key);
						ut_set_attr(UT_REV);
						printf("%s", (menu->cols)[col][entry].label);
						ut_set_attr(UT_RESET);
					}
					else
						end = 1;
			}
		}

	for (entry = MENU_H; entry>1; entry--) {
		ut_goto(margin, entry);
		ut_set_attr(UT_BOLD);
		putchar('|');
	}
}

static menu_t menu = {"TEST MENU", 2,
						{
							{{"^A", "control A"}, {"^C", "control c"}},
							{{"^B", "control B"}, {0}}
						}
			  		 };

int
main(int argc, char *argv[])
{
	char c;
	/* Get terminal file pointer */
	UT_CLEAR_SCREEN();
	ut_get_term("/dev/tty");

	makeMenu(&menu);
	ut_goto(0,MENU_H+1);
	makeRuler();

	while((c=getchar())!='q')
	{
		//putchar(c);
	}

	return 0;
}
