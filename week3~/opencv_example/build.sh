rm test
rm mat_test

g++ test.cpp -o test `pkg-config --libs opencv`
g++ mat_test.cpp -o mat_test `pkg-config --libs opencv`

