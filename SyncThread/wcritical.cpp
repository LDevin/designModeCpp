#include "wcritical.h"

static RAII_CrtcSec cs;

DWORD WINAPI thread_1(LPVOID p)
{
    extern int counter;

    while (true) {

        cs.Lock();
        if (counter < 1000) {
            ++counter;
            std::cout << "Thread 1 counting " << counter << "...\n"<<std::endl;
            cs.Unlock();
        } else {
            cs.Unlock();
            break;
        }

    }

    return 0;
}

DWORD WINAPI thread_2(LPVOID p)
{
    extern int counter;

    while (true) {

        cs.Lock();
        if (counter < 1000) {
            ++counter;
            std::cout << "Thread 2 counting " << counter << "...\n"<<std::endl;
            cs.Unlock();
        } else {
            cs.Unlock();
            break;
        }

    }

    return 0;
}

void startCriticalThread()
{
    std::cout << "start critical thread\n"<<std::endl;

    HANDLE h1 = ::CreateThread(NULL, 0, thread_1, NULL, 0, NULL);
    HANDLE h2 = ::CreateThread(NULL, 0, thread_2, NULL, 0, NULL);

    CloseHandle(h1);
    CloseHandle(h2);
}
