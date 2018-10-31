#include "memory_.h"
#include <vector>
#include "pluginsdk\bridgemain.h"

#define PAGE_SHIFT              (12)
//#define PAGE_SIZE               (4096)
#define PAGE_ALIGN(Va)          ((ULONG_PTR)((ULONG_PTR)(Va) & ~(PAGE_SIZE - 1)))
#define BYTES_TO_PAGES(Size)    (((Size) >> PAGE_SHIFT) + (((Size) & (PAGE_SIZE - 1)) != 0))
#define ROUND_TO_PAGES(Size)    (((ULONG_PTR)(Size) + PAGE_SIZE - 1) & ~(PAGE_SIZE - 1))
static PROCESS_INFORMATION g_pi = { 0, 0, 0, 0 };
PROCESS_INFORMATION* fdProcessInfo = &g_pi;


extern PROCESS_INFORMATION* fdProcessInfo_x;
std::vector<MemSectionInfo> MemSectionInfo_;

void ListMemMapSection()
{

	// First gather all possible pages in the memory range
	std::vector<MEMPAGE> pageVector;
	pageVector.reserve(200); //TODO: provide a better estimate
	{
		SIZE_T numBytes = 0;
		duint pageStart = 0;
		duint allocationBase = 0;		
		do
		{
			
			// Query memory attributes
			MEMORY_BASIC_INFORMATION mbi;
			memset(&mbi, 0, sizeof(mbi));

			numBytes = VirtualQueryEx(fdProcessInfo_x->hProcess, (LPVOID)pageStart, &mbi, sizeof(mbi));

			// Only allow pages that are committed/reserved (exclude free memory)
			if (mbi.State != MEM_FREE)
			{
				//auto bReserved = mbi.State == MEM_RESERVE; //check if the current page is reserved.
				//auto bPrevReserved = pageVector.size() ? pageVector.back().mbi.State == MEM_RESERVE : false; //back if the previous page was reserved (meaning this one won't be so it has to be added to the map)
				//																							 // Only list allocation bases, unless if forced to list all
				//if (bListAllPages || bReserved || bPrevReserved || allocationBase != duint(mbi.AllocationBase))
				//{
				//	// Set the new allocation base page
				//	allocationBase = duint(mbi.AllocationBase);

				//	MEMPAGE curPage;
				//	memset(&curPage, 0, sizeof(MEMPAGE));
				//	memcpy(&curPage.mbi, &mbi, sizeof(mbi));

				//	if (bReserved)
				//	{
				//		if (duint(curPage.mbi.BaseAddress) != allocationBase)
				//			sprintf_s(curPage.info, GuiTranslateText(QT_TRANSLATE_NOOP("DBG", "Reserved (%p)")), allocationBase);
				//		else
				//			strcpy_s(curPage.info, GuiTranslateText(QT_TRANSLATE_NOOP("DBG", "Reserved")));
				//	}
				//	else if (!ModNameFromAddr(pageStart, curPage.info, true))
				//	{
				//		// Module lookup failed; check if it's a file mapping
				//		wchar_t szMappedName[sizeof(curPage.info)] = L"";
				//		if ((mbi.Type == MEM_MAPPED) &&
				//			(GetMappedFileNameW(fdProcessInfo->hProcess, mbi.AllocationBase, szMappedName, MAX_MODULE_SIZE) != 0))
				//		{
				//			auto bFileNameOnly = false; //TODO: setting for this
				//			auto fileStart = wcsrchr(szMappedName, L'\\');
				//			if (bFileNameOnly && fileStart)
				//				strcpy_s(curPage.info, StringUtils::Utf16ToUtf8(fileStart + 1).c_str());
				//			else
				//				strcpy_s(curPage.info, StringUtils::Utf16ToUtf8(szMappedName).c_str());
				//		}
				//	}

				//	pageVector.push_back(curPage);
				//}
				//else
				//{
				//	// Otherwise append the page to the last created entry
				//	if (pageVector.size()) //make sure to not dereference an invalid pointer
				//		pageVector.back().mbi.RegionSize += mbi.RegionSize;
				//}

				MemSectionInfo temp = { (duint)mbi.BaseAddress, mbi.RegionSize };
				MemSectionInfo_.push_back(temp);
			}
						// Calculate the next page start
			
			
			duint newAddress = duint(mbi.BaseAddress) + mbi.RegionSize;

			if (newAddress <= pageStart)
				break;

			pageStart = newAddress;
		} while (numBytes);
	}
//
//	// Process file sections
//	int pagecount = (int)pageVector.size();
//	char curMod[MAX_MODULE_SIZE] = "";
//	for (int i = pagecount - 1; i > -1; i--)
//	{
//		auto & currentPage = pageVector.at(i);
//		if (!currentPage.info[0] || (scmp(curMod, currentPage.info) && !bListAllPages)) //there is a module
//			continue; //skip non-modules
//		strcpy(curMod, pageVector.at(i).info);
//		if (!ModBaseFromName(currentPage.info))
//			continue;
//		auto base = duint(currentPage.mbi.AllocationBase);
//		std::vector<MODSECTIONINFO> sections;
//		if (!ModSectionsFromAddr(base, &sections))
//			continue;
//		int SectionNumber = (int)sections.size();
//		if (!SectionNumber) //no sections = skip
//			continue;
//		if (!bListAllPages) //normal view
//		{
//			MEMPAGE newPage;
//			//remove the current module page (page = size of module at this point) and insert the module sections
//			pageVector.erase(pageVector.begin() + i); //remove the SizeOfImage page
//			for (int j = SectionNumber - 1; j > -1; j--)
//			{
//				const auto & currentSection = sections.at(j);
//				memset(&newPage, 0, sizeof(MEMPAGE));
//				VirtualQueryEx(fdProcessInfo->hProcess, (LPCVOID)currentSection.addr, &newPage.mbi, sizeof(MEMORY_BASIC_INFORMATION));
//				duint SectionSize = currentSection.size;
//				if (SectionSize % PAGE_SIZE) //unaligned page size
//					SectionSize += PAGE_SIZE - (SectionSize % PAGE_SIZE); //fix this
//				if (SectionSize)
//					newPage.mbi.RegionSize = SectionSize;
//				sprintf_s(newPage.info, " \"%s\"", currentSection.name);
//				pageVector.insert(pageVector.begin() + i, newPage);
//			}
//			//insert the module itself (the module header)
//			memset(&newPage, 0, sizeof(MEMPAGE));
//			VirtualQueryEx(fdProcessInfo->hProcess, (LPCVOID)base, &newPage.mbi, sizeof(MEMORY_BASIC_INFORMATION));
//			strcpy_s(newPage.info, curMod);
//			pageVector.insert(pageVector.begin() + i, newPage);
//		}
//		else //list all pages
//		{
//			duint start = (duint)currentPage.mbi.BaseAddress;
//			duint end = start + currentPage.mbi.RegionSize;
//			for (int j = 0, k = 0; j < SectionNumber; j++)
//			{
//				const auto & currentSection = sections.at(j);
//				duint secStart = currentSection.addr;
//				duint SectionSize = currentSection.size;
//				if (SectionSize % PAGE_SIZE) //unaligned page size
//					SectionSize += PAGE_SIZE - (SectionSize % PAGE_SIZE); //fix this
//				duint secEnd = secStart + SectionSize;
//				if (secStart >= start && secEnd <= end) //section is inside the memory page
//				{
//					if (k)
//						k += sprintf_s(currentPage.info + k, MAX_MODULE_SIZE - k, ",");
//					k += sprintf_s(currentPage.info + k, MAX_MODULE_SIZE - k, " \"%s\"", currentSection.name);
//				}
//				else if (start >= secStart && end <= secEnd) //memory page is inside the section
//				{
//					if (k)
//						k += sprintf_s(currentPage.info + k, MAX_MODULE_SIZE - k, ",");
//					k += sprintf_s(currentPage.info + k, MAX_MODULE_SIZE - k, " \"%s\"", currentSection.name);
//				}
//			}
//		}
//	}
//
//	// Get a list of threads for information about Kernel/PEB/TEB/Stack ranges
//	THREADLIST threadList;
//	ThreadGetList(&threadList);
//
//	for (auto & page : pageVector)
//	{
//		const duint pageBase = (duint)page.mbi.BaseAddress;
//		const duint pageSize = (duint)page.mbi.RegionSize;
//
//		// Check for windows specific data
//		if (pageBase == 0x7FFE0000)
//		{
//			strcpy_s(page.info, "KUSER_SHARED_DATA");
//			continue;
//		}
//
//		// Check in threads
//		for (int i = 0; i < threadList.count; i++)
//		{
//			DWORD threadId = threadList.list[i].BasicInfo.ThreadId;
//
//			// Mark TEB
//			//
//			// TebBase:      Points to 32/64 TEB
//			// TebBaseWow64: Points to 64 TEB in a 32bit process
//			duint tebBase = threadList.list[i].BasicInfo.ThreadLocalBase;
//			duint tebBaseWow64 = tebBase - (2 * PAGE_SIZE);
//
//			if (pageBase == tebBase)
//			{
//				sprintf_s(page.info, GuiTranslateText(QT_TRANSLATE_NOOP("DBG", "Thread %X TEB")), threadId);
//				break;
//			}
//			else if (pageBase == tebBaseWow64)
//			{
//#ifndef _WIN64
//				if (pageSize == (3 * PAGE_SIZE))
//				{
//					sprintf_s(page.info, GuiTranslateText(QT_TRANSLATE_NOOP("DBG", "Thread %X WoW64 TEB")), threadId);
//					break;
//				}
//#endif // ndef _WIN64
//			}
//
//			// Mark stack
//			//
//			// Read TEB::Tib to get stack information
//			NT_TIB tib;
//			if (!ThreadGetTib(tebBase, &tib))
//				continue;
//
//			// The stack will be a specific range only, not always the base address
//			duint stackAddr = (duint)tib.StackLimit;
//
//			if (stackAddr >= pageBase && stackAddr < (pageBase + pageSize))
//				sprintf_s(page.info, GuiTranslateText(QT_TRANSLATE_NOOP("DBG", "Thread %X Stack")), threadId);
//		}
//	}
//
//	// Only free thread data if it was allocated
//	if (threadList.list)
//		BridgeFree(threadList.list);
//
//	// Convert the vector to a map
//	EXCLUSIVE_ACQUIRE(LockMemoryPages);
//	memoryPages.clear();
//
//	for (auto & page : pageVector)
//	{
//		duint start = (duint)page.mbi.BaseAddress;
//		duint size = (duint)page.mbi.RegionSize;
//		memoryPages.insert(std::make_pair(std::make_pair(start, start + size - 1), page));
//	}
}