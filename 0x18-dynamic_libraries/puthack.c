#include <unistd.h>
#include <string.h>

int rand()
{
	static int ct = -1;

	ct++;
	switch (ct)
	{
		case 0:
		case 1:
			return 8;
		case 2:
			return 7;
		case 3:
			return 9;
		case 4:
			return 23;
		case 5:
			return 74;
		default:
			return ct * ct % 30000;
	}
}
