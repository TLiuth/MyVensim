#ifndef MAIN_FUNCIONAL_TESTS
#define MAIN_FUNCIONAL_TESTS
#include "functional_tests.h"
#include <iostream>

using namespace std;

int main()
{
    exponentialFuncionalTest();
    logisticalFuncionalTest();
    complexFuncionalTest();
    cout << "Todos os testes foram bem sucedidos!" << endl;
    return 0;
}

#endif // MAIN_FUNCIONAL_TESTS