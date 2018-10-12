#pragma once

#include "Winlic.h"
#include <msclr/marshal.h>


namespace ScriptS {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Microsoft::VisualBasic;
	using namespace Runtime::InteropServices;
	/*using namespace AdR::Samples::NativeCallingCLR::ClrAssembly;*/

	/// <summary>
	/// Summary for IATFixer
	/// </summary>
	public ref class IATFixer : public System::Windows::Forms::Form
	{
	public:
		IATFixer(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~IATFixer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  GetALLAPIEmulatedCall_Bu;
	protected:

	private: System::Windows::Forms::ListBox^  API_Emulated_Call_LB;
	private: System::Windows::Forms::TextBox^  TB_SectionBase;
	private: System::Windows::Forms::TextBox^  TB_SectionSize;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  TB_PatternSearch;
	private: System::Windows::Forms::TextBox^  TB_SectionLimitaion;

	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Label^  Log_Lab;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->GetALLAPIEmulatedCall_Bu = (gcnew System::Windows::Forms::Button());
			this->API_Emulated_Call_LB = (gcnew System::Windows::Forms::ListBox());
			this->TB_SectionBase = (gcnew System::Windows::Forms::TextBox());
			this->TB_SectionSize = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->Log_Lab = (gcnew System::Windows::Forms::Label());
			this->TB_SectionLimitaion = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->TB_PatternSearch = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// GetALLAPIEmulatedCall_Bu
			// 
			this->GetALLAPIEmulatedCall_Bu->Location = System::Drawing::Point(345, 29);
			this->GetALLAPIEmulatedCall_Bu->Margin = System::Windows::Forms::Padding(4);
			this->GetALLAPIEmulatedCall_Bu->Name = L"GetALLAPIEmulatedCall_Bu";
			this->GetALLAPIEmulatedCall_Bu->Size = System::Drawing::Size(132, 63);
			this->GetALLAPIEmulatedCall_Bu->TabIndex = 0;
			this->GetALLAPIEmulatedCall_Bu->Text = L"Get ALL API Emulated Call";
			this->GetALLAPIEmulatedCall_Bu->UseVisualStyleBackColor = true;
			this->GetALLAPIEmulatedCall_Bu->Click += gcnew System::EventHandler(this, &IATFixer::GetALLAPIEmulatedCall_Bu_Click);
			// 
			// API_Emulated_Call_LB
			// 
			this->API_Emulated_Call_LB->FormattingEnabled = true;
			this->API_Emulated_Call_LB->ItemHeight = 16;
			this->API_Emulated_Call_LB->Location = System::Drawing::Point(11, 168);
			this->API_Emulated_Call_LB->Margin = System::Windows::Forms::Padding(4);
			this->API_Emulated_Call_LB->Name = L"API_Emulated_Call_LB";
			this->API_Emulated_Call_LB->Size = System::Drawing::Size(466, 388);
			this->API_Emulated_Call_LB->TabIndex = 1;
			this->API_Emulated_Call_LB->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &IATFixer::API_Emulated_Call_LB_MouseDoubleClick);
			// 
			// TB_SectionBase
			// 
			this->TB_SectionBase->Font = (gcnew System::Drawing::Font(L"Courier New", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TB_SectionBase->Location = System::Drawing::Point(142, 29);
			this->TB_SectionBase->Margin = System::Windows::Forms::Padding(4);
			this->TB_SectionBase->Name = L"TB_SectionBase";
			this->TB_SectionBase->Size = System::Drawing::Size(190, 21);
			this->TB_SectionBase->TabIndex = 2;
			this->TB_SectionBase->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// TB_SectionSize
			// 
			this->TB_SectionSize->Location = System::Drawing::Point(142, 65);
			this->TB_SectionSize->Margin = System::Windows::Forms::Padding(4);
			this->TB_SectionSize->Name = L"TB_SectionSize";
			this->TB_SectionSize->Size = System::Drawing::Size(190, 22);
			this->TB_SectionSize->TabIndex = 3;
			this->TB_SectionSize->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(8, 32);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(112, 16);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Section Base:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(8, 68);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(112, 16);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Section Size:";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->Log_Lab);
			this->groupBox1->Controls->Add(this->TB_SectionLimitaion);
			this->groupBox1->Controls->Add(this->checkBox1);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->TB_PatternSearch);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->GetALLAPIEmulatedCall_Bu);
			this->groupBox1->Controls->Add(this->API_Emulated_Call_LB);
			this->groupBox1->Controls->Add(this->TB_SectionSize);
			this->groupBox1->Controls->Add(this->TB_SectionBase);
			this->groupBox1->Location = System::Drawing::Point(8, 4);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			this->groupBox1->Size = System::Drawing::Size(488, 606);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"groupBox1";
			// 
			// Log_Lab
			// 
			this->Log_Lab->AutoSize = true;
			this->Log_Lab->Location = System::Drawing::Point(8, 570);
			this->Log_Lab->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Log_Lab->Name = L"Log_Lab";
			this->Log_Lab->Size = System::Drawing::Size(40, 16);
			this->Log_Lab->TabIndex = 10;
			this->Log_Lab->Text = L"Log:";
			// 
			// TB_SectionLimitaion
			// 
			this->TB_SectionLimitaion->Font = (gcnew System::Drawing::Font(L"Courier New", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TB_SectionLimitaion->Location = System::Drawing::Point(197, 138);
			this->TB_SectionLimitaion->Margin = System::Windows::Forms::Padding(4);
			this->TB_SectionLimitaion->Name = L"TB_SectionLimitaion";
			this->TB_SectionLimitaion->ReadOnly = true;
			this->TB_SectionLimitaion->Size = System::Drawing::Size(280, 21);
			this->TB_SectionLimitaion->TabIndex = 9;
			this->TB_SectionLimitaion->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(11, 138);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(179, 20);
			this->checkBox1->TabIndex = 8;
			this->checkBox1->Text = L"Limite To Section :";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(7, 106);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(128, 16);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Pattern Search:";
			// 
			// TB_PatternSearch
			// 
			this->TB_PatternSearch->CharacterCasing = System::Windows::Forms::CharacterCasing::Upper;
			this->TB_PatternSearch->Location = System::Drawing::Point(142, 103);
			this->TB_PatternSearch->Margin = System::Windows::Forms::Padding(4);
			this->TB_PatternSearch->Name = L"TB_PatternSearch";
			this->TB_PatternSearch->Size = System::Drawing::Size(335, 22);
			this->TB_PatternSearch->TabIndex = 6;
			this->TB_PatternSearch->Text = L"0000000000000000";
			this->TB_PatternSearch->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// IATFixer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1135, 625);
			this->Controls->Add(this->groupBox1);
			this->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"IATFixer";
			this->Text = L"IATFixer";
			this->Deactivate += gcnew System::EventHandler(this, &IATFixer::IATFixer_Deactivate);
			this->Load += gcnew System::EventHandler(this, &IATFixer::IATFixer_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}

	private: System::Void GetALLAPIEmulatedCall_Bu_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ PatternSearch = TB_PatternSearch->Text;
		if (TB_SectionBase->Text == "" || TB_SectionSize->Text == "" || TB_PatternSearch->Text == "") {
			Interaction::MsgBox("Please Fill the Missing Data", MsgBoxStyle::DefaultButton1, "Error");
			return;
		}
		/*if ( PatternSearch->Length %  2 == 0 ) {
			Interaction::MsgBox("Pattern Search not Mod 2 ", MsgBoxStyle::DefaultButton1, "Error");
			return;
		}*/
		API_Emulated_Call_LB->Items->Clear();
		duint sctionbase = Hex2duint(TB_SectionBase->Text);
		duint pagesize = Hex2duint(TB_SectionSize->Text);
		if (sctionbase == -1 || pagesize == -1)
		{
			Interaction::MsgBox("Something wrong with sctionbase or pagesize", MsgBoxStyle::DefaultButton1, "Error");
			return;
		}
		duint Findaddr = sctionbase;
		for (duint i = sctionbase; i <= sctionbase + pagesize; ++i) {
			duint delta = Findaddr - sctionbase;
			duint cc = pagesize - delta;
			Findaddr = Script::Pattern::FindMem(i, pagesize - delta, str2Char(PatternSearch));
			if (Findaddr == 0xffffffffffffffff || Findaddr == 0) return;
			else
			{
				DISASM_INSTR* instr = new DISASM_INSTR;
				i = Findaddr + (PatternSearch->Length / 2) - 1;
				DbgDisasmAt(Findaddr, instr);
				API_Emulated_Call_LB->Items->Add(duint2Hex(Findaddr) + "  " + CharArr2Str(instr->instruction));
				Log_Lab->Text = "Log: " + duint2Hex(Findaddr) + "  " + CharArr2Str(instr->instruction);
				IATFixer::Refresh();
				Application::DoEvents();
			}
		}
	}
	private: System::Void IATFixer_Load(System::Object^  sender, System::EventArgs^  e) {
		SELECTIONDATA sel;
		GuiSelectionGet(GUI_DISASSEMBLY, &sel);
		duint pagesize = DbgMemGetPageSize(sel.start);
		duint sctionbase = DbgMemFindBaseAddr(sel.start, &pagesize);
		TB_SectionBase->Text = Conversion::Hex(sctionbase);
		TB_SectionSize->Text = Conversion::Hex(pagesize);
	}

	private: System::Void IATFixer_Deactivate(System::Object^  sender, System::EventArgs^  e) {
		Application::DoEvents();
	}
	private: System::Void API_Emulated_Call_LB_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		String^ Line_ = API_Emulated_Call_LB->GetItemText(API_Emulated_Call_LB->SelectedItem);
		Line_ = Line_->Trim()->Substring(0, Line_->IndexOf(" "));
		duint addr = Hex2duint(Line_);
		DbgCmdExec( str2Char("disasm " + Line_));
	}


			 ///////////////////////////////////////////////////////////////////Helper Functions
	private:
		String^ reMoveSpaces(String^ input_) {
			String^ temp;
			for (int i = 0; i < input_->Length; ++i) {
				if (input_->Substring(i, 1) != " ") {
					temp = temp + input_->Substring(i, 1);
				}
			}
			return temp;
		}


	private:
		const char* str2Char(System::String^ string_) {
			IntPtr p = Marshal::StringToHGlobalAnsi(string_);
			const char* linkStr = static_cast<char*>(p.ToPointer());
			return linkStr;
		}


	private:
		String^ CharArr2Str(char input_[]) {
			return gcnew String(input_);
		}

	private:
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


	private:
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


	};

}
