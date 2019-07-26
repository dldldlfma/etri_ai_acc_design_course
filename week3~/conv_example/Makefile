CC=g++
LIBS=`pkg-config --libs opencv`

CODE=lenet.cpp conv.cpp pool.cpp activation.cpp
OBJS=lenet.o conv.o pool.o activation.o
TARGET=lenet.out

$(TARGET): $(OBJS)
	$(CC) -o $(CODE) $(OBJS) $(LIBS)

clean:
	rm -f $(TARGET) $(OBJS) $(OBJS2)


conv.o: conv.cpp
pool.o: pool.cpp
activation.o: activation.cpp