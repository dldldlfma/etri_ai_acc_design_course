#LIBS=`pkg-config --cflags --libs opencv`
LIBS=`pkg-config --cflags --libs opencv4`

OBJS = conv.o pool.o activation.o fc.o main.o

lenet: $(OBJS)
	g++ -o lenet $(OBJS) $(LIBS)

main.o: main.cpp
	g++ -c main.cpp $(LIBS)

conv.o: conv.cpp
	g++ -c conv.cpp $(LIBS)

pool.o: pool.cpp
	g++ -c pool.cpp $(LIBS)

activation.o: activation.cpp
	g++ -c activation.cpp $(LIBS)

fc.o: fc.cpp
	g++ -c fc.cpp $(LIBS)

clean:
	rm -rf lenet
	rm -rf *.o
