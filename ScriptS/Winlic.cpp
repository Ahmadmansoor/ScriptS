#include "Winlic.h"
#include "pluginmain.h"
#include <Windows.h>
#include "pluginsdk\TitanEngine\TitanEngine.h"
#include <windows.h>
#include <stdio.h>
#include <psapi.h>
#include "pluginsdk\_scriptapi_module.h"
#include "MyForm.h"


void Winlic_int(PLUG_INITSTRUCT* initStruct)
{
	_plugin_logprintf("[WinLic] pluginHandle: %d\n", pluginHandle);
	if (!_plugin_registercommand(pluginHandle, "IATFixerForm", cbIATFixer_LoadForm, false))
		_plugin_logputs("[TEST] error registering the \"plugin1\" command!");
}

static bool cbIATFixer_LoadForm(int argc, char* argv[])
{
	_plugin_logputs("[IATFixer] Loading Form!");
	//char line[GUI_MAX_LINE_SIZE] = "";
	
	
	return true;
}