#ifndef WSEMAPHORE_H
#define WSEMAPHORE_H
#include <iostream>
#include <windows.h>

static DWORD WINAPI thread_1(LPVOID p);
static DWORD WINAPI thread_2(LPVOID p);

void startSemaphoreThread();

#endif // WSEMAPHORE_H
