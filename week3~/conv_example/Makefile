LIBS=`pkg-config --libs opencv`
OBJS = conv.o pool.o activation.o

lenet: conv.o pool.o activation.o main.o
	g++ -o lenet conv.o pool.o activation.o main.o $(LIBS)

main.o: main.cpp
	g++ -c main.cpp $(LIBS)

conv.o: conv.cpp
	g++ -c conv.cpp $(LIBS)

pool.o: pool.cpp
	g++ -c pool.cpp $(LIBS)

activation.o: activation.cpp
	g++ -c activation.cpp $(LIBS)


clean:
	rm -rf lenet
	rm -rf *.o
