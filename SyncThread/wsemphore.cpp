#include "wsemaphore.h"

static HANDLE h_sem = NULL;

DWORD WINAPI thread_1(LPVOID p)
{
    extern int counter;

    while (true) {
        if (WAIT_OBJECT_0 == WaitForSingleObject(h_sem, INFINITE)) {

            if (counter < 1000) {
                ++counter;
                std::cout << "Thread 1 counting " << counter << "...\n"<<std::endl;
                ReleaseSemaphore(h_sem, 1, NULL);
            } else {
                ReleaseSemaphore(h_sem, 1, NULL);
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

        if (WAIT_OBJECT_0 == WaitForSingleObject(h_sem, INFINITE)) {

            if (counter < 1000) {
                ++counter;
                std::cout << "Thread 2 counting " << counter << "...\n"<<std::endl;
                ReleaseSemaphore(h_sem, 1, NULL);
            } else {
                ReleaseSemaphore(h_sem, 1, NULL);
                break;
            }
        }

    }

    return 0;
}

void startSemaphoreThread()
{
    std::cout << "start semaphore thread\n"<<std::endl;

    h_sem = CreateSemaphore(NULL, 1, 1, NULL);

    if (h_sem == INVALID_HANDLE_VALUE) {
        std::cout << "create semaphore failed\n"<<std::endl;
    }

    HANDLE h1 = ::CreateThread(NULL, 0, thread_1, NULL, 0, NULL);
    HANDLE h2 = ::CreateThread(NULL, 0, thread_2, NULL, 0, NULL);

    CloseHandle(h1);
    CloseHandle(h2);
}
