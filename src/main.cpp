#include "CH_HEAD.h"
#include "TestExecutionTime.h"

#include <iostream>
using namespace std;

int main()
{
    TestExecutionTime::start();
    BASE *ch = new S_51_ReversePairs();
    ch->main();
    TestExecutionTime::end();

    cout << "\n程序停止...\n";

    return 0;
}