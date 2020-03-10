all:	BulbsGame.exe
clean:
	rm Bulbs.o BulbsGame.exe
BulbsGame.exe: Bulbs.o
	clang -g -o BulbsGame Bulbs.o
Bulbs.o:
	clang -c -g Bulbs.c