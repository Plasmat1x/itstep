#include "TemperatureModel.h"
#include "Observer.h"
#include "Controller.h"
#include "ConsoleView.h"

int main(int argc, char* argv[])
{
    TemperatureModel model(0);
    ConsoleView view(&model);
    Controller controller(&model);
    
    controller.start();

    return 0;
}