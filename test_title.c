#include <stdio.h>
#include <sys/ioctl.h>
#include "inc/colors.h"
#include <asm/termbits.h>

int main()
{
	struct winsize	win;


	if (!ioctl(1, TIOCGWINSZ, &win))
	{
		printf("%d\n", win.ws_col);
		printf()
	}

}
