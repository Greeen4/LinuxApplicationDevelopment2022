bin_PROGRAMS=main

lang:
	xgettext -c -k_ main.c -o po/guess.pot
	msgmerge -U po/guess.po po/guess.pot
	mkdir -p ru_RU.UTF-8/LC_MESSAGES
	msgfmt po/guess.po -o ru_RU.UTF-8/LC_MESSAGES/guess.mo
	LANG=ru_RU.UTF-8
	

clean-gen: gitclean

gitclean:
	git clean -f
