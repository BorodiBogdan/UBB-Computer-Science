#include "tests/test.h"

int main()
{
    // testAll(CreateUi());

    Ui *ui = CreateUi();

    startUi(ui);
    deleteUi(ui);
    return 0;
}