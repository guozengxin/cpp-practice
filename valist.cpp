#include <cstdarg>
#include <iostream>
#include <stdlib.h>

using namespace std;

const char * Null_cp = 0;

const char *itoa(int i, char buf[])
{
	sprintf(buf, "%d", i);
	return buf;
}

void error(int severity ...)
{
	va_list ap;
	va_start(ap, severity);
	while (true) {
		char *p = va_arg(ap, char*);
		if (p == 0) break;
		cerr << p << ' ';
	}
	va_end(ap);
	cerr << '\n';
	if (severity) exit(severity);
}

int main(int argc, char* argv[])
{
	switch (argc) {
		case 1:
			error(0, argv[0], Null_cp);
			break;
		case 2:
			error(0, argv[0], argv[1], Null_cp);
			break;
		default:
			char buffer[8];
			error(1, argv[0], "with", itoa(argc-1, buffer), "arguments", Null_cp);
	}
}
