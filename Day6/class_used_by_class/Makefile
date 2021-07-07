#Rectangle.exe Makefile
app.out: Point.o Rectangle.o main.o
	g++ Point.o Rectangle.o main.o -o app.out
main.o: main.cpp Rectangle.hpp
	g++ -c main.cpp -o main.o
Rectangle.o: Rectangle.cpp Rectangle.hpp Point.hpp
	g++ -c Rectangle.cpp -o Rectangle.o
Point.o: Point.cpp Point.hpp
	g++ -c Point.cpp -o Point.o
clean:
	rm *.o app.out
