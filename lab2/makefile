key := -std=c++17 -Wall -Werror

%.o: %.cpp *.h *.hpp
	g++ $(key) -c $<

main.out: main.o
	g++ $(key) -o $@ $^

clean:
	rm *.o *.out
