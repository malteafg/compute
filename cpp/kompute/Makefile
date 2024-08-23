.PHONY: basic

basic: build
	make build
	./build/basic

build:
	cmake -B build/ -S .
	cmake --build build/

clean:
	@rm -rf build/
