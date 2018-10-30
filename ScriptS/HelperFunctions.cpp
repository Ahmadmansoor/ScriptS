#include "HelperFunctions.h"
#include <msclr/marshal.h>

	String^ reMoveSpaces(String^ input_) {
		String^ temp;
		for (int i = 0; i < input_->Length; ++i) {
			if (input_->Substring(i, 1) != " ") {
				temp = temp + input_->Substring(i, 1);
			}
		}
		return temp;
	}



	const char* Str2ConstChar(System::String^ string_) {
		IntPtr p = Marshal::StringToHGlobalAnsi(string_);
		const char* linkStr = static_cast<char*>(p.ToPointer());
		return linkStr;
	}



	String^ CharArr2Str(char input_[]) {
		return gcnew String(input_);
	}


	String^ ClearSlash_etc(String^ input) {
		String^ temp;
		for (int i = 0; i < input->Length - 1; ++i) {
			//if (input->Substring(i, 1) != "\\" || input->Substring(i, 1) != ":") {
			if (Char::IsDigit(input, i)  || Char::IsLetter(input,i) || input->Substring(i, 1) == ".") {
				temp = temp + input->Substring(i, 1);
			}
		}
		return temp;
	}

	String^ charPTR2String(char* input) {
		
			//String^ temp = gcnew String(input);
			//const char* t = static_cast<const char*>(input);
		std::string temp2(input);
		std::wstring temp(temp2.begin(), temp2.end());
		String^ temp1 = gcnew String(temp.c_str());		
		return temp1;
		
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
