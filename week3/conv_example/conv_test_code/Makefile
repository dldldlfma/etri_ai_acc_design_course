LIBS=`pkg-config --cflags --libs opencv4`

OBJS = conv_test_code.o conv.o

conv_test: $(OBJS)
	g++ -o conv_test $(OBJS) $(LIBS)

conv_test_code.o: conv_test_code.cpp
	g++ -c conv_test_code.cpp $(LIBS)

conv.o: ../conv.cpp
	g++ -c ../conv.cpp $(LIBS)

