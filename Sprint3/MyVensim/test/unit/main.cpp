#include "unit_flow.h"
#include "unit_model.h"
#include "unit_system.h"

int main()
{
    run_unit_test_model();
    run_unit_test_system();

    cout << "All tests passed!" << endl;
}