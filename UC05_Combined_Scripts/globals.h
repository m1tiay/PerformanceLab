#ifndef _GLOBALS_H
#define _GLOBALS_H

//--------------------------------------------------------------------
// Include Files
#include "lrun.h"
#include "web_api.h"
#include "lrw_custom_body.h"

//--------------------------------------------------------------------
// Global Variables

int ThinkTime = 5;
int responseCode;
char * success;
int responseTime;
int before_sentBytes, after_sentBytes, submit_sentBytes;
int before_bytes, after_bytes, submit_bytes;
int timeStamp;
char resultParam[100];

#endif // _GLOBALS_H
