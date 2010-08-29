# Copyright (C) 2009 Tadej Borovšak <tadeboro@gmail.com>
#  
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without 
# modifications, as long as this notice is preserved.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

AC_INIT([Snrmga], [0.0.2], [tadeboro@gmail.com], [snrmga])
  # This line initializes autoconf and tells it that our package is named
  # "Snrmga", current version is "0.0.1", bugs can be reported to
  # "tadeboro@gmail.com" and that tarball should be named snrmga.tar.gz

AC_PREREQ(2.63)
  # This line simply sets required version of autoconf.

AC_CONFIG_SRCDIR([src/snrmga.c])
  # This is safety check that can catch bad source directory being passed to
  # configure script via --srcdir switch.

AC_CONFIG_MACRO_DIR([macros])
  # This line informs build system where additional macros can be found.

AC_CONFIG_AUX_DIR([build-aux])
  # This line instructs build system to place auxiliary files in separate folder
  # (this keeps toplevel directory a bit cleaner).

AC_CONFIG_HEADERS([config.h])
  # This line instructs build system to create config.h header file instead of
  # passing all macros on command line.

AM_INIT_AUTOMAKE([1.10])
  # Initialize automake (we require 1.10 version here).

m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])
  # This line turns on silent rules if they are supported (this needs
  # automake-1.11).

AC_PROG_CC
  # This line searches for C compiler and sets CC variable.

AM_PROG_CC_C_O
  # This macro is needed in order to be able to build objects in subdirs (this
  # will be explained in greater detail later when we come to Makefile.am).

IT_PROG_INTLTOOL([0.40])
AC_SUBST([GETTEXT_PACKAGE], [snrmga])
AM_GNU_GETTEXT_VERSION([0.11])
AM_GLIB_GNU_GETTEXT
AC_DEFINE([GETTEXT_PACKAGE], [PACKAGE_TARNAME], [Define to the package name.])
  # These lines enable support for multiple languages in application. They
  # initialize intltool and gettext (used to extract translatable strings) and
  # set some macros that we need in sources to init translations.

AC_ARG_ENABLE([debug],
	      [AS_HELP_STRING([--enable-debug],
			      [Build with debugging support])])
AM_CONDITIONAL([ENABLE_DEBUG], [test "x$enable_debug" = "xyes"])
AS_IF([test "x$enable_debug" = "xyes"],
      [AC_DEFINE([ENABLE_DEBUG], [1],
		 [Define to enable debugging])])
  # This code snippet adds configure switch that turns on debug support.

SNRMGA_MODS="gtk+-2.0 >= 2.14 gmodule-2.0"
PKG_CHECK_MODULES([SNRMGA], [$SNRMGA_MODS])
  # These two lines specify our application's dependencies and provide proper
  # compiler and linker flags.

AC_CONFIG_FILES([Makefile
		 po/Makefile.in
		 data/snrmga.desktop.in])
AC_OUTPUT
  # These two macros specify which files should be produced by configure script.
