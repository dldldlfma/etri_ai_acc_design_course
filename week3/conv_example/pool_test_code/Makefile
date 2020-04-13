
LIBS=`pkg-config --cflags --libs opencv4`

OBJS = pool_test_code.o pool.o

pool_test: $(OBJS)
	g++ -o pool_test $(OBJS) $(LIBS)

pool_test_code.o: pool_test_code.cpp
	g++ -c pool_test_code.cpp $(LIBS)

pool.o: ../pool.cpp
	g++ -c ../pool.cpp $(LIBS)

