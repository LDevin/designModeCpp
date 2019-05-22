#ifndef WCRITICAL_H
#define WCRITICAL_H
#include <windows.h>
#include <iostream>

class RAII_CrtcSec
{
private:
    CRITICAL_SECTION crtc_sec;
public:
    RAII_CrtcSec() { ::InitializeCriticalSection(&crtc_sec); }
    ~RAII_CrtcSec() { ::DeleteCriticalSection(&crtc_sec); }
    RAII_CrtcSec(const RAII_CrtcSec &) = delete;
    RAII_CrtcSec & operator=(const RAII_CrtcSec &) = delete;
    //
    void Lock() { ::EnterCriticalSection(&crtc_sec); }
    void Unlock() { ::LeaveCriticalSection(&crtc_sec); }
};


static DWORD WINAPI thread_1(LPVOID p);
static DWORD WINAPI thread_2(LPVOID p);

void startCriticalThread();

#endif // WCRITICAL_H
