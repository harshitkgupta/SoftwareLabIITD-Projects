RegularExpMatcher: matcher.o regex.o
	gcc -o RegularExpMatcher matcher.o regex.o
matcher.o: matcher.c regex.h
	gcc -Wall -c matcher.c
regex.o: regex.c regex.h
	gcc -Wall -c regex.c

