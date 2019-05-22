#include "event.h"

static HANDLE h_event = NULL;

DWORD WINAPI thread_1(LPVOID p)
{
    (void)p;
    extern int counter;

    while (true) {
        WaitForSingleObject(h_event, INFINITE);
        ResetEvent(h_event);

        if (counter < 1000) {
            ++counter;
            std::cout << "Thread 1 counting " << counter << "...\n"<<std::endl;
            SetEvent(h_event);
        } else {
            SetEvent(h_event);
            break;
        }

    }

    return 0;
}

DWORD WINAPI thread_2(LPVOID p)
{
    (void)p;
    extern int counter;

    while (true) {

        WaitForSingleObject(h_event, INFINITE);
        ResetEvent(h_event);

        if (counter < 1000) {
            ++counter;
            std::cout << "Thread 2 counting " << counter << "...\n"<<std::endl;
            SetEvent(h_event);
        } else {
            SetEvent(h_event);
            break;
        }

    }

    return 0;
}

void startEventThread()
{
    std::cout << "start event thread\n"<<std::endl;

    h_event = CreateEvent(NULL, TRUE, FALSE, NULL);
    SetEvent(h_event);
    HANDLE h1 = ::CreateThread(NULL, 0, thread_1, NULL, 0, NULL);
    HANDLE h2 = ::CreateThread(NULL, 0, thread_2, NULL, 0, NULL);

    CloseHandle(h1);
    CloseHandle(h2);
}
