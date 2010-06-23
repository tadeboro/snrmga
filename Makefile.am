# Copyright (C) 2009 Tadej Borovšak <tadeboro@gmail.com>
#  
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without 
# modifications, as long as this notice is preserved.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = -I macros ${ACLOCAL_FLAGS}

SUBDIRS = po

# Defines
snrmga_defines = -DDATADIR=\""$(datadir)"\" \
		 -DLOCALEDIR=\""$(localedir)"\" \
		 -DPKGDATADIR=\""$(pkgdatadir)"\"

# Application
bin_PROGRAMS = src/snrmga
src_snrmga_SOURCES = src/snrmga.c
src_snrmga_CPPFLAGS = $(snrmga_defines) $(SNRMGA_CFLAGS)
src_snrmga_LDADD = $(SNRMGA_LIBS)

# Icon
themedir = $(datadir)/icons/hicolor
icon16dir = $(themedir)/16x16/apps
dist_icon16_DATA = data/icons/16x16/snrmga.png

icon22dir = $(themedir)/22x22/apps
dist_icon22_DATA = data/icons/22x22/snrmga.png

icon24dir = $(themedir)/24x24/apps
dist_icon24_DATA = data/icons/24x24/snrmga.png

icon32dir = $(themedir)/32x32/apps
dist_icon32_DATA = data/icons/32x32/snrmga.png

icon48dir = $(themedir)/48x48/apps
dist_icon48_DATA = data/icons/48x48/snrmga.png

iconscdir = $(themedir)/scalable/apps
dist_iconsc_DATA = data/icons/scalable/snrmga.svg

# .desktop file
desktopdir = $(datadir)/applications
desktop_DATA = data/snrmga.desktop

# (un)installation hooks
up_icon_cache = gtk-update-icon-cache -tf

install-data-hook: in-update-icon-cache
uninstall-hook: un-update-icon-cache

in-update-icon-cache:
	@$(POST_INSTALL)
	test -n "$(DESTDIR)" || $(up_icon_cache) "$(themedir)"

un-update-icon-cache:
	@$(POST_UNINSTALL)
	test -n "$(DESTDIR)" || $(up_icon_cache) "$(themedir)"

# Misc
dist_noinst_SCRIPTS = autogen.sh

dist_intltool = intltool-extract.in intltool-update.in intltool-merge.in
dist_noinst_DATA = $(dist_intltool)

CLEANFILES = $(desktop_DATA)
DISTCLEANFILES = intltool-extract intltool-merge intltool-update
MAINTAINERCLEANFILES = $(dist_intltool)

@INTLTOOL_DESKTOP_RULE@

.PHONY: in-update-icon-cache un-update-icon-cache

.DELETE_ON_ERROR:
