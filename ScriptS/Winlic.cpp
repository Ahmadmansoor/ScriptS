#include "Winlic.h"
//#include "pluginmain.h"
#include <Windows.h>
#include "pluginsdk\TitanEngine\TitanEngine.h"
#include <windows.h>
#include <stdio.h>
#include <psapi.h>
#include "pluginsdk\_scriptapi_module.h"
#include "IATFixer.h"


void Winlic_int(PLUG_INITSTRUCT* initStruct)
{
	_plugin_logprintf("[WinLic] pluginHandle: %d\n", pluginHandle);
	if (!_plugin_registercommand(pluginHandle, "IATFixerForm", cbIATFixer_LoadForm, false))
		_plugin_logputs("[TEST] error registering the \"plugin1\" command!");

	if (!_plugin_registercommand(pluginHandle, "test_", test_, false))
		_plugin_logputs("[TEST] error registering the \"plugin1\" command!");
}

static bool test_(int argc, char* argv[])
{
	SELECTIONDATA sel;
	GuiSelectionGet(GUI_DISASSEMBLY, &sel);
	duint pagesize = DbgMemGetPageSize(sel.start);
	duint sctionbase = DbgMemFindBaseAddr(sel.start, &pagesize);

	duint Findaddr = Script::Pattern::FindMem(sctionbase, pagesize, "488974240848897C241041544881ECB0000000");
	
	//Findaddr = Script::Pattern::FindMem(sctionbase, pagesize, "488974240848897C241041544881ECB0000000");
	return true;
}

static void ShowDialog_IATFixer()
{
	ScriptS::IATFixer IATFixer;
	IATFixer.ShowDialog();
}

static bool cbIATFixer_LoadForm(int argc, char* argv[])
{
	_plugin_logputs("[IATFixer] Loading Form!");	
	//ScriptS::IATFixer IATFixer;
	//IATFixer.ShowDialog();	
	
	System::Threading::Thread^ thread_ = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(&ShowDialog_IATFixer));
	thread_->Start();
	
	return true;
}


