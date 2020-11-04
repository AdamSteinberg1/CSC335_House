CC = gcc
LDLIBS =  -lglut -lGL -lGLU -lm
HEADERS = opengl.h structs.h globals.h constants.h prototypes.h
OBJS = init.o defineBox.o drawBox.o drawAxes.o reshape.o display.o updateRotations.o

debug ?= n
ifeq ($(debug), y)
    CFLAGS += -g -DDEBUG
else
    CFLAGS += -O2
endif


house :	main.o $(OBJS)
	$(CC) $(CFLAGS) main.o $(OBJS) -o house $(LDLIBS)

main.o : main.c $(HEADERS)
	$(CC) $(CFLAGS) main.c -c

init.o : init.c $(HEADERS)
	$(CC) $(CFLAGS) init.c -c

defineBox.o : defineBox.c $(HEADERS)
	$(CC) $(CFLAGS) defineBox.c -c

drawBox.o : drawBox.c $(HEADERS)
	$(CC) $(CFLAGS) drawBox.c -c

drawAxes.o : drawAxes.c $(HEADERS)
	$(CC) $(CFLAGS) drawAxes.c -c

reshape.o : reshape.c $(HEADERS)
	$(CC) $(CFLAGS) reshape.c -c

display.o : display.c $(HEADERS)
	$(CC) $(CFLAGS) display.c -c

updateRotations.o : updateRotations.c $(HEADERS)
	$(CC) $(CFLAGS) updateRotations.c -c

clean:
	rm *.o

pristine:
	rm *.o
	touch *
