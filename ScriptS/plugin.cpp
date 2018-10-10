#include "plugin.h"
#include "MyForm.h"


extern "C" __declspec(dllexport) void CBBREAKPOINT(CBTYPE cbType, PLUG_CB_BREAKPOINT* info)
{
    dprintf("hit breakpoint on address %p\n", info->breakpoint->addr);
	ScriptS::MyForm myform;
	myform.ShowDialog();
}

//Initialize your plugin data here.
bool pluginInit(PLUG_INITSTRUCT* initStruct)
{
    return true; //Return false to cancel loading the plugin.
}

//Deinitialize your plugin data here.
void pluginStop()
{
}

//Do GUI/Menu related things here.
void pluginSetup()
{
}
