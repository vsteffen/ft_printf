
#include "ft_printf.h"
#include <math.h>

char *newfmt(const char *fmt, ...)
{
				char *p;
				va_list ap;
				if ((p = malloc(128)) == NULL)
								return (NULL);
				va_start(ap, fmt);
				(void) vsnprintf(p, 128, fmt, ap);
				va_end(ap);
				return (p);
}


void			demoFunctions(const char *string)
{
	//	To print a date and time in the form ``Sunday, July 3, 10:02'', where weekday and month are pointers to strings:
					fprintf(stdout, "%s, %s %d, %.2d:%.2d\n", "Sunday", "Mars", 6, 13, 37);

	//	To print pi to five decimal places:
					fprintf(stdout, "pi = %.5f\n", 4 * atan(1.0));

					newfmt(string);
		//To allocate a 128 byte string and print into it:
}
