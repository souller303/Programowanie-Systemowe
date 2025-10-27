USER = $(shell whoami)
DATE = $(shell date +%s)
FILE = $(USER).$(DATE)

all:
	touch $(FILE)

clean:
	rm $(USER).*


