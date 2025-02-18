all: functional unit run_functional run_unit

functional:
	@g++ -o bin/functional test/functional/main.cpp test/functional/functional_tests.cpp src/model.cpp src/system.cpp src/flow.cpp

unit:

run_functional: 
	./bin/functional

run_unit:
	./bin/unit

