#include <iostream>
#include "event.h"
#include "wmutex.h"
#include "wcritical.h"
#include "wsemaphore.h"


using namespace std;

unsigned int counter = 0;

int main()
{
    cout << "Hello World!" << endl;
    //startEventThread();
    //startMutexThread();
    //startCriticalThread();
    startSemaphoreThread();

    system("pause");
    return 0;
}
