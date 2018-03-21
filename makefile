commit:
	@if "x%M%"=="x" (echo "Usage: set M='your message here.' make")
	@test "x$(M)" != 'x'
	git commit -a -m "%M%"
	git push

pull:
	git pull
