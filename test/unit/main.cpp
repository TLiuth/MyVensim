#include "unit_flow.h"
#include "unit_model.h"
#include "unit_system.h"

int main()
{
    unit_flow test_unit_flow;
    unit_model test_unit_model;
    unit_system test_unit_system;

    test_unit_model.run_unit_test_model();
    test_unit_system.run_unit_test_system();
    test_unit_flow.run_unit_test_flow();

    cout << "All tests passed!" << endl;
}