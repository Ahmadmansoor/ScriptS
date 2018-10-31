#include "plugin.h"
#include "IATFixer.h"

#define plugin_name "testplugin"
#define plugin_version 1

//int pluginHandle;
//HWND hwndDlg;
//int hMenu;
//int hMenuDisasm;
//int hMenuDump;
//int hMenuStack;


PROCESS_INFORMATION* fdProcessInfo_x;

extern "C" __declspec(dllexport) void CBBREAKPOINT(CBTYPE cbType, PLUG_CB_BREAKPOINT* info)
{
    //dprintf("hit breakpoint on address %p\n", info->breakpoint->addr);	
	//ScriptS::IATFixer IATFixer;
	//IATFixer.ShowDialog();
}

extern "C" __declspec(dllexport) void CBCREATEPROCESS(CBTYPE cbType,PLUG_CB_CREATEPROCESS* info)
{
	//here I could't recive the PLUG_CB_CREATEPROCESS I don't know why but could recive part of the strcture
	fdProcessInfo_x = new (PROCESS_INFORMATION);	
	fdProcessInfo_x = info->fdProcessInfo;
	
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
