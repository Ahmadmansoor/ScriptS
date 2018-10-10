#include "plugin.h"
#include "MyForm.h"

#define plugin_name "testplugin"
#define plugin_version 1

//int pluginHandle;
//HWND hwndDlg;
//int hMenu;
//int hMenuDisasm;
//int hMenuDump;
//int hMenuStack;


extern "C" __declspec(dllexport) void CBBREAKPOINT(CBTYPE cbType, PLUG_CB_BREAKPOINT* info)
{
    dprintf("hit breakpoint on address %p\n", info->breakpoint->addr);
	//ScriptS::MyForm myform;
	//myform.ShowDialog();
}

//Initialize your plugin data here.
bool pluginInit(PLUG_INITSTRUCT* initStruct)
{
	initStruct->sdkVersion = plugin_version;
	initStruct->sdkVersion = PLUG_SDKVERSION;
	strcpy(initStruct->pluginName, plugin_name);
	pluginHandle = initStruct->pluginHandle;
	//testInit(initStruct);
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
