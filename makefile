commit:
ifeq ($(m),)
	@echo This makefile stages all files for commit, commits with a user-defined message, and pushes upstream.
	@echo
	@echo Usage: make m='"Your commit message."'
else
	git add --all .
	git commit -m "$(m)"
	git push
endif
