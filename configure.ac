# Copyright (C) 2009 Tadej Borovšak <tadeboro@gmail.com>
#  
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without 
# modifications, as long as this notice is preserved.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

AC_INIT([Snrmga], [0.0.1], [tadeboro@gmail.com], [snrmga])
AC_PREREQ(2.63)

AC_CONFIG_SRCDIR([src/snrmga.c])
AC_CONFIG_MACRO_DIR([macros])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([1.10])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])
AM_MAINTAINER_MODE

AC_PROG_CC
AM_PROG_CC_C_O

IT_PROG_INTLTOOL([0.40])
AC_SUBST([GETTEXT_PACKAGE], [snrmga])
AM_GNU_GETTEXT_VERSION([0.11])
AM_GLIB_GNU_GETTEXT
AC_DEFINE([GETTEXT_PACKAGE], [PACKAGE_TARNAME], [Define to the package name.])

SNRMGA_MODS="gtk+-2.0 >= 2.14"
PKG_CHECK_MODULES([SNRMGA], [$SNRMGA_MODS])

AC_CONFIG_FILES([Makefile
		 po/Makefile.in
		 data/snrmga.desktop.in])
AC_OUTPUT
