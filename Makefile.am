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
  # This option instructs automake to generate rules that will keep object files
  # in the same subdirectory as source files. Without this, all object files
  # would end up clobbering toplevel directory.

ACLOCAL_AMFLAGS = -I macros ${ACLOCAL_FLAGS}
  # This line informs automake where to find additional macro definitions.

SUBDIRS = po
  # One would expect that non-recursive make would have no SUBDIRS, but since
  # contents of po folder is almost completelly controlled by intltool that
  # comes with it's own makefiles, we need to have this here.

# Defines
snrmga_defines = -DDATADIR=\""$(datadir)"\" \
		 -DLOCALEDIR=\""$(localedir)"\" \
		 -DPKGPIXMAPSDIR=\""$(pkgdatadir)/pixmaps"\" \
		 -DPKGUIDIR=\""$(pkgdatadir)/ui"\"
  # These defines are placed here because it's imposible to place them inside
  # config.h completelly expanded. If we were to use AC_DEFINE to define
  # PKGUIDIR for example, header would look like this:
  #
  # #define PKGUIDIR "$(pkgdatadir)/ui"
  #
  # Not exactly what we want;)

if ENABLE_DEBUG
  debug_flags = -g
else
  debug_flags =
endif

# Application
bin_PROGRAMS = src/snrmga
src_snrmga_SOURCES = src/snrmga.c
src_snrmga_CPPFLAGS = $(debug_flags) $(snrmga_defines) $(SNRMGA_CFLAGS)
src_snrmga_LDADD = $(SNRMGA_LIBS)
  # This part specifies program components of our package. SNRMGA_CFLAGS and
  # SNRMGA_LIBS variables are defined by PKG_CHECK_MODULES inside configure.ac.
  #
  # Binaries will be installed inside $(prefix)/bin.

# Pixmaps
pixmapsdir = $(pkgdatadir)/pixmaps
dist_pixmaps_DATA = data/pixmaps/image_a.png \
		    data/pixmaps/image_b.png
  # This part is similar to previous section, but files will be installed in
  # custom directory under package data directory (in this case subfolder
  # pixmaps).

# Glade file
uidir = $(pkgdatadir)/ui
dist_ui_DATA = data/ui/snrmga.glade
  # Same thing as above.

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
