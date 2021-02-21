TAR=hello
OBJ = hello.o
CC := gcc
#$@ 所有的目标文件
#$^ 所有的依赖文件
$(TAR):$(OBJ)
	$(CC) $^ -o $@
%.o:%c
	$(CC) -c %.c -o %.o
.PHONY:
clear: 
	rm -rf $(OBJ)

