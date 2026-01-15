USER = $(shell whoami)
DATE = $(shell date +%s)
FILE = $(USER).$(DATE)

all: data.txt
	cp data.txt $(FILE)

clean:
	rm $(USER).*
	rm data.txt

data.txt:
	echo qwerty > data.txt

