ifeq ($(m),)
commit:
	@echo Usage: make m="Your commit message."
else
commit:
	git add --all .
	git commit -a -m "$(m)"
	git push
endif

pull:
	git pull