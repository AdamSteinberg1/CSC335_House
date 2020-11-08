CC = g++
LDLIBS =  -lglut -lGL -lGLU -lm
HEADERS = opengl.h structs.h constants.h prototypes.h globals.h
OBJS = init.o defineHouse.o drawHouse.o drawAxes.o reshape.o display.o updateRotations.o keyboardmouse.o drawHelloWorld.o drawText.o menu.o

debug ?= n
ifeq ($(debug), y)
    CFLAGS += -g -DDEBUG
else
    CFLAGS += -O2
endif


house :	main.o $(OBJS)
	$(CC) $(CFLAGS) main.o $(OBJS) -o house $(LDLIBS)

main.o : main.cpp $(HEADERS)
	$(CC) $(CFLAGS) main.cpp -c

init.o : init.cpp $(HEADERS)
	$(CC) $(CFLAGS) init.cpp -c

defineHouse.o : defineHouse.cpp $(HEADERS)
	$(CC) $(CFLAGS) defineHouse.cpp -c

drawHouse.o : drawHouse.cpp $(HEADERS)
	$(CC) $(CFLAGS) drawHouse.cpp -c

drawAxes.o : drawAxes.cpp $(HEADERS)
	$(CC) $(CFLAGS) drawAxes.cpp -c

drawText.o : drawText.cpp $(HEADERS)
	$(CC) $(CFLAGS) drawText.cpp -c

drawHelloWorld.o : drawHelloWorld.cpp $(HEADERS)
	$(CC) $(CFLAGS) drawHelloWorld.cpp -c

reshape.o : reshape.cpp $(HEADERS)
	$(CC) $(CFLAGS) reshape.cpp -c

display.o : display.cpp $(HEADERS)
	$(CC) $(CFLAGS) display.cpp -c

updateRotations.o : updateRotations.cpp $(HEADERS)
	$(CC) $(CFLAGS) updateRotations.cpp -c

keyboardmouse.o : keyboardmouse.cpp $(HEADERS)
	$(CC) -c keyboardmouse.cpp

menu.o : menu.cpp $(HEADERS)
	$(CC) -c menu.cpp

clean:
	rm *.o

pristine:
	rm *.o
	touch *
