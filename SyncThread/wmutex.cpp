#include "wmutex.h"

static HANDLE h_mutex = NULL;

DWORD WINAPI thread_1(LPVOID p)
{
    extern int counter;

    while (true) {
        if (WAIT_OBJECT_0 == WaitForSingleObject(h_mutex, INFINITE)) {

            if (counter < 1000) {
                ++counter;
                std::cout << "Thread 1 counting " << counter << "...\n"<<std::endl;
                ReleaseMutex(h_mutex);
            } else {
                ReleaseMutex(h_mutex);
                break;
            }
        }

    }

    return 0;
}

DWORD WINAPI thread_2(LPVOID p)
{
    extern int counter;

    while (true) {

        if (WAIT_OBJECT_0 == WaitForSingleObject(h_mutex, INFINITE)) {

            if (counter < 1000) {
                ++counter;
                std::cout << "Thread 2 counting " << counter << "...\n"<<std::endl;
                ReleaseMutex(h_mutex);
            } else {
                ReleaseMutex(h_mutex);
                break;
            }
        }

    }

    return 0;
}

void startMutexThread()
{
    std::cout << "start mutex thread\n"<<std::endl;

    h_mutex = CreateMutex(NULL, FALSE, NULL);

    HANDLE h1 = ::CreateThread(NULL, 0, thread_1, NULL, 0, NULL);
    HANDLE h2 = ::CreateThread(NULL, 0, thread_2, NULL, 0, NULL);

    CloseHandle(h1);
    CloseHandle(h2);
}
