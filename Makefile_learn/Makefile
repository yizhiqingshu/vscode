make_1:make_1.o
	gcc make_1.o -o make_1
make_1.o:make_1.S
	gcc -c make_1.S -o make_1.o
make_1.S:make_1.i
	gcc -S make_1.i -o make_1.S
make_1.i:make_1.c
	gcc -E make_1.c -o make_1.i
#伪目标
.PHONY:
clearall:
	rm -rf make_1.o make_1.S make_1.i make_1
clear:
	rm -rf make_1.o make_1.S make_1.i 
	
