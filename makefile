SHELL = /bin/sh
TARGET = algorithm_reference
EXCLUDE_DIRS = 
SECTIONS = $(basename $(patsubst ./%, %, $(shell find . -maxdepth 1 -type d)))
CLEAN_SUFFIXS =\
	acn  acr alg aux bbl blg     dvi fdb_latexmk    glg glo\
	gls  idx ilg ind ist lof     log lot            maf mtc\
	mtc0 nav nlo out pdf pdfsync ps  snm synctex.gz toc tdo\
	vrb  xdy
CLEAR_TARGETS = $(addsuffix _clean, $(CLEAN_SUFFIXS))
XELATEX = texify.exe --pdf --engine=xetex --tex-option=-synctex=1

all: build

build: pdf

clean: $(CLEAR_TARGETS)

rebuild: clean build

pdf: $(TARGET).pdf

$(TARGET).pdf: $(TARGET).tex
	$(XELATEX) $^
	
$(TARGET).tex: $(foreach section, $(SECTIONS), $(shell find $(section) -name "*.tex" -type f -o -name "*.cpp" -type f))

$(CLEAR_TARGETS): %_clean:
	find . -name '*.$*' -type f -print -exec rm -rf {} \;

.PHONY: all build clean rebuild