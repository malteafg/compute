.PHONY: basic info build

basic:
	@make build
	./build/basic

info:
	@make build
	./build/info

build:
	cmake -B build/ -S .
	cmake --build build/

clean:
	@rm -rf build/
