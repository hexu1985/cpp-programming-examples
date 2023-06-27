SUBDIRS = algo cont fo i18n io iter memory num stl string util

.PHONY: all everything debug clean

all: everything

everything:
	@for dir in $(SUBDIRS); do \
		$(MAKE) $(T) --directory=$$dir || exit 1; \
	done

debug: T := debug
debug: all

profile: T := profile
profile: all

clean:	T := clean
clean: everything



