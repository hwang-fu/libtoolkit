
INCLUDE := ./include
LIB		:= ./lib

.PHONY: all clean test

all:
	@./build.sh
	@find . -type f -exec wc -l {} +

clean:
	rm -rf ${INCLUDE}/*
	rm -rf ${LIB}/*
