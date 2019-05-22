#ifndef WMUTEX_H
#define WMUTEX_H
#include <iostream>
#include <windows.h>

static DWORD WINAPI thread_1(LPVOID p);
static DWORD WINAPI thread_2(LPVOID p);

void startMutexThread();

#endif // WMUTEX_H
