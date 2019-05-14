#pragma once

#define RELEASE(X) {if(X != NULL) {delete X; X = NULL;}}
#define RELEASE_HANDLE(X) {if (X != NULL && X != INVALID_HANDLE_VALUE) {CloseHandle(X); X = NULL;}}