
#include <stdio.h>
#include <stdarg.h>

#if 1
#define CHECK_FMT(a, b) __attribute__((format(printf, a, b)))
#else
#define CHECK_FMT(a, b)
#endif

void TRACE(const char *fmt, ...) CHECK_FMT(1, 2);

int main(void)
{
	int i = 1;
	TRACE("iValue = %d\n", i);
	TRACE("iValue = %d\n", "test");
	return 0;
}

void TRACE(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	(void)printf(fmt, ap);
	va_end(ap);
}
