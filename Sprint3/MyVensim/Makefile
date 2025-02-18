all: functional unit run_functional run_unit

functional:
	@g++ -o bin/functional test/functional/main.cpp test/functional/functional_tests.cpp src/model.cpp src/system.cpp src/flow.cpp

unit:
	@g++ -o bin/unit test/unit/main.cpp test/unit/unit_tests.cpp test/unit/unit_flow.cpp test/unit/unit_model.cpp test/unit/unit_system.cpp src/model.cpp src/system.cpp src/flow.cpp

run_functional: 
	./bin/functional

run_unit:
	./bin/unit

