#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([FULL-PACKAGE-NAME], [VERSION], [BUG-REPORT-ADDRESS])
AM_INIT_AUTOMAKE([foreign subdir-objects])
AC_CONFIG_SRCDIR([rhasher.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([rhash], [rhash_library_init], [], ["Couldn't find rhash lib"])
AC_CHECK_LIB([readline], [readline], [], [])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h unistd.h rhash.h])

AC_ARG_WITH([readline],
    [AS_HELP_STRING([--without-readline],
        [Disable readline])],
    [with_readline="no"])

AS_IF([test "x$with_readline" = "xno"], [
    AC_DEFINE(NO_READLINE, [1], [readline])
])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_TYPE_SIZE_T

# Checks for library functions.
AC_CHECK_FUNCS([strerror])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
