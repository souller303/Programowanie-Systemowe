USER = $(shell whoami)
DATE = $(shell date +%s)
FILE = $(USER).$(DATE)
OUTDIR = build

all: data.txt $(OUTDIR)
	cp data.txt $(OUTDIR)/$(FILE)

clean:
	rm -rf $(OUTDIR)
	rm data.txt

data.txt:
	echo qwerty > data.txt

$(OUTDIR):
	mkdir $(OUTDIR)
