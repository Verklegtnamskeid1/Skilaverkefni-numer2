#include "main.h"
#include "sk1data.h"
#include "consoleui.h"
#include "cvs.cpp"
int main()
{
    /* Þetta opnar skjalið og hendir því inn */
    openCSVfile();

    /* Starta console */
    ConsoleUI ui = ConsoleUI();
    ui.start();


    /* Vista skjalið og hætta */
    saveCSVfile();
    return 0;
}

