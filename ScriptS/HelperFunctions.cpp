#include "HelperFunctions.h"


	String^ reMoveSpaces(String^ input_) {
		String^ temp;
		for (int i = 0; i < input_->Length; ++i) {
			if (input_->Substring(i, 1) != " ") {
				temp = temp + input_->Substring(i, 1);
			}
		}
		return temp;
	}



	const char* str2Char(System::String^ string_) {
		IntPtr p = Marshal::StringToHGlobalAnsi(string_);
		const char* linkStr = static_cast<char*>(p.ToPointer());
		return linkStr;
	}



	String^ CharArr2Str(char input_[]) {
		return gcnew String(input_);
	}


	duint Hex2duint(String^ input_) {
		try
		{
			return __int64::Parse(reMoveSpaces(input_), System::Globalization::NumberStyles::HexNumber);
		}
		catch (const std::exception&)
		{
			return -1;
		}
	}
	

	String^ duint2Hex(duint input_) {
		try
		{
			return Conversion::Hex(input_);
		}
		catch (const std::exception&)
		{
			return "";
		}
	}