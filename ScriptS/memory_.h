#include <Windows.h>
#include "plugin.h"

void ListMemMapSection();

struct MemSectionInfo
{
	duint SectionBaseAddr;
	duint SectionSize;
};