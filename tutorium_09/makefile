

all: folien.pdf aufgabenblatt.pdf

folien.pdf: folien.md aufgaben.md makefile graph.pdf
	pandoc folien.md aufgaben.md -fmarkdown -t beamer -o folien.pdf \
		--slide-level=2\
		-M lang:german\
		-V theme:Singapore\
		-V colortheme:beaver

aufgabenblatt.pdf: aufgaben.md feedback.md makefile graph.pdf
	pandoc aufgaben.md feedback.md -o aufgabenblatt.pdf \
		-M lang:german \
		-V documentclass:scrartcl\
		-V papersize:"a4paper"

graph.pdf:
