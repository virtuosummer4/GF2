#all: small.cc
#	g++ -std=c++11 -g -o small small.cc
#
check.o: check.cc check.h
	g++ -std=c++11 -g -c check.cc
small.o: small.cc check.h
	g++ -std=c++11 -g -c small.cc
check: check.o small.o
	g++ -std=c++11 -g -o check check.o small.o
