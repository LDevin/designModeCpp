#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include <windows.h>

static DWORD WINAPI thread_1(LPVOID p);
static DWORD WINAPI thread_2(LPVOID p);

void startEventThread();


#endif // EVENT_H
