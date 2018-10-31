#pragma once

#include "pluginmain.h"

//plugin data
#define PLUGIN_NAME "BreakpointTest"
#define PLUGIN_VERSION 1

//functions
bool pluginInit(PLUG_INITSTRUCT* initStruct);
void pluginStop();
void pluginSetup();
//PLUG_CB_CREATEPROCESS* process_Info;
