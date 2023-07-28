.PHONY: dogs cats clean all

all: dogs cats

dogs:
	clang++ -O3 -Wall -shared -std=c++11 -fPIC $(shell python3 -m pybind11 --includes) dogs.cpp -o dogs$(shell python3-config --extension-suffix)

cats:
	clang++ -O3 -Wall -shared -std=c++11 -fPIC $(shell python3 -m pybind11 --includes) cats.cpp -o cats$(shell python3-config --extension-suffix)

clean:
	rm -f *.so
