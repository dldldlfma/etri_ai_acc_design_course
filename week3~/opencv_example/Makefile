CC=g++
LIBS=`pkg-config --libs opencv`

CODE=lenet.cpp
OBJS=lenet.o
TARGET=lenet.out

$(TARGET): $(OBJS)
	$(CC) -o $(CODE) $(OBJS) $(LIBS)

clean:
	rm -f $(TARGET) $(OBJS) $(OBJS2)


