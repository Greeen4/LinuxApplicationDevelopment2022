#define _GNU_SOURCE
#include <string.h>
#include <dlfcn.h>
#include <errno.h>


int remove(const char *fname)
{
	if (strstr(fname, "PROTECT")){
		errno = EPERM;
		return 1;
	}

	typedef int (*first_remove_type)(const char *fname);

	first_remove_type first_remove = (first_remove_type)dlsym(RTLD_NEXT, "remove");

	return first_remove(fname);

}

