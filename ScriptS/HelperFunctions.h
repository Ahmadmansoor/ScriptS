#pragma once
#include "Winlic.h"

using namespace System;
using namespace Microsoft::VisualBasic;
using namespace Runtime::InteropServices;

///////////////////////////////////////////////////////////////////Helper Functions
String^ reMoveSpaces(String^ input_);
const char* str2Char(System::String^ string_);
String^ CharArr2Str(char input_[]);
duint Hex2duint(String^ input_);
String^ duint2Hex(duint input_);

