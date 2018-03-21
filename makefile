ifeq ($(m),)
commit:
	@echo This makefile stages all files for commit, commits with a user-defined message, and pushes upstream.
	@echo
	@echo Usage: make m='"Your commit message."'
else
commit:
	git add --all .
	git commit -a -m "$(m)"
	git push
endif
