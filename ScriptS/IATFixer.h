#pragma once

#include "Winlic.h"
#include <msclr/marshal.h>
#include "HelperFunctions.h"
#include "memory_.h"
//#include "plugin.h"
//#include "pluginsdk\_scriptapi_register.h"
//#include "pluginsdk\\_scriptapi_debug.h"

extern std::vector<MemSectionInfo> MemSectionInfo_;

namespace ScriptS {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Microsoft::VisualBasic;
	using namespace Runtime::InteropServices;



	//////////////////////////////////////////////////////////////////////

		/*class IAT_table
		{
		public:
			IAT_table(duint addr_, duint value__);
			~IAT_table();

		private:
			duint addr;
			duint value_;
		};

		IAT_table::IAT_table(duint addr_, duint value__)
		{
			addr = addr_; value_ = value__;

		}

		IAT_table::~IAT_table()
		{
		}*/


		//////////////////////////////////////////////////////////////////////

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

	private:
		ref class IAT_table
		{
		public:
			duint iat_addr;
			duint API_addr;
			String^ APIName;
		public:
			IAT_table(duint iat_addr_, duint API_addr_, String^ APIName__) {
				iat_addr = iat_addr_;
				API_addr = API_addr_;
				APIName = APIName__;
			};
		};


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
	private: System::Windows::Forms::CheckBox^  CB_LimitBySction;



	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  TB_IATTableAddress;


	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  TB_IATTableSize;
	private: System::Windows::Forms::Button^  Bu_FixEmulatedAPIinIATtable;

	private: System::Windows::Forms::Button^  Bu_FixEmulatedAPIinIATtable0;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  TB_OEP;
	private: System::Windows::Forms::ListBox^  LB_CmdBreak;
	private: System::Windows::Forms::Label^  La_count;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ListBox^  Fix_API_Emulated_Call_LB;
	private: System::Windows::Forms::ListBox^  Fixed_IAT_Table;





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
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->Fixed_IAT_Table = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Bu_FixEmulatedAPIinIATtable0 = (gcnew System::Windows::Forms::Button());
			this->Bu_FixEmulatedAPIinIATtable = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->TB_IATTableAddress = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->TB_IATTableSize = (gcnew System::Windows::Forms::TextBox());
			this->Fix_API_Emulated_Call_LB = (gcnew System::Windows::Forms::ListBox());
			this->La_count = (gcnew System::Windows::Forms::Label());
			this->LB_CmdBreak = (gcnew System::Windows::Forms::ListBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->TB_OEP = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->TB_SectionLimitaion = (gcnew System::Windows::Forms::TextBox());
			this->CB_LimitBySction = (gcnew System::Windows::Forms::CheckBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->TB_PatternSearch = (gcnew System::Windows::Forms::TextBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->SuspendLayout();
			// 
			// GetALLAPIEmulatedCall_Bu
			// 
			this->GetALLAPIEmulatedCall_Bu->Location = System::Drawing::Point(300, 142);
			this->GetALLAPIEmulatedCall_Bu->Margin = System::Windows::Forms::Padding(4);
			this->GetALLAPIEmulatedCall_Bu->Name = L"GetALLAPIEmulatedCall_Bu";
			this->GetALLAPIEmulatedCall_Bu->Size = System::Drawing::Size(179, 54);
			this->GetALLAPIEmulatedCall_Bu->TabIndex = 1;
			this->GetALLAPIEmulatedCall_Bu->Text = L"Get ALL API Emulated Call";
			this->GetALLAPIEmulatedCall_Bu->UseVisualStyleBackColor = true;
			this->GetALLAPIEmulatedCall_Bu->Click += gcnew System::EventHandler(this, &IATFixer::GetALLAPIEmulatedCall_Bu_Click);
			// 
			// API_Emulated_Call_LB
			// 
			this->API_Emulated_Call_LB->FormattingEnabled = true;
			this->API_Emulated_Call_LB->ItemHeight = 16;
			this->API_Emulated_Call_LB->Location = System::Drawing::Point(13, 204);
			this->API_Emulated_Call_LB->Margin = System::Windows::Forms::Padding(4);
			this->API_Emulated_Call_LB->Name = L"API_Emulated_Call_LB";
			this->API_Emulated_Call_LB->Size = System::Drawing::Size(198, 180);
			this->API_Emulated_Call_LB->TabIndex = 5;
			this->API_Emulated_Call_LB->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &IATFixer::API_Emulated_Call_LB_MouseDoubleClick);
			// 
			// TB_SectionBase
			// 
			this->TB_SectionBase->CharacterCasing = System::Windows::Forms::CharacterCasing::Upper;
			this->TB_SectionBase->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Bold));
			this->TB_SectionBase->Location = System::Drawing::Point(152, 110);
			this->TB_SectionBase->Margin = System::Windows::Forms::Padding(4);
			this->TB_SectionBase->MaxLength = 16;
			this->TB_SectionBase->Name = L"TB_SectionBase";
			this->TB_SectionBase->Size = System::Drawing::Size(138, 22);
			this->TB_SectionBase->TabIndex = 2;
			this->TB_SectionBase->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->TB_SectionBase->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &IATFixer::TB_SectionBase_MouseDoubleClick);
			// 
			// TB_SectionSize
			// 
			this->TB_SectionSize->CharacterCasing = System::Windows::Forms::CharacterCasing::Upper;
			this->TB_SectionSize->Location = System::Drawing::Point(152, 140);
			this->TB_SectionSize->Margin = System::Windows::Forms::Padding(4);
			this->TB_SectionSize->MaxLength = 16;
			this->TB_SectionSize->Name = L"TB_SectionSize";
			this->TB_SectionSize->Size = System::Drawing::Size(138, 22);
			this->TB_SectionSize->TabIndex = 3;
			this->TB_SectionSize->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Courier New", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(10, 114);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(134, 16);
			this->label1->TabIndex = 6;
			this->label1->Text = L"text Section Base:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Courier New", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(6, 140);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(141, 16);
			this->label2->TabIndex = 7;
			this->label2->Text = L"text  Section Size:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->groupBox2);
			this->groupBox1->Controls->Add(this->Fix_API_Emulated_Call_LB);
			this->groupBox1->Controls->Add(this->La_count);
			this->groupBox1->Controls->Add(this->LB_CmdBreak);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->TB_OEP);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->TB_SectionLimitaion);
			this->groupBox1->Controls->Add(this->CB_LimitBySction);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->TB_PatternSearch);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->GetALLAPIEmulatedCall_Bu);
			this->groupBox1->Controls->Add(this->API_Emulated_Call_LB);
			this->groupBox1->Controls->Add(this->TB_SectionSize);
			this->groupBox1->Controls->Add(this->TB_SectionBase);
			this->groupBox1->Location = System::Drawing::Point(5, 4);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			this->groupBox1->Size = System::Drawing::Size(485, 646);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->Fixed_IAT_Table);
			this->groupBox2->Controls->Add(this->button1);
			this->groupBox2->Controls->Add(this->Bu_FixEmulatedAPIinIATtable0);
			this->groupBox2->Controls->Add(this->Bu_FixEmulatedAPIinIATtable);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->TB_IATTableAddress);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->TB_IATTableSize);
			this->groupBox2->Location = System::Drawing::Point(13, 391);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(466, 240);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"IAT Table & Fix Options";
			// 
			// Fixed_IAT_Table
			// 
			this->Fixed_IAT_Table->FormattingEnabled = true;
			this->Fixed_IAT_Table->ItemHeight = 16;
			this->Fixed_IAT_Table->Location = System::Drawing::Point(198, 81);
			this->Fixed_IAT_Table->Margin = System::Windows::Forms::Padding(4);
			this->Fixed_IAT_Table->Name = L"Fixed_IAT_Table";
			this->Fixed_IAT_Table->Size = System::Drawing::Size(261, 148);
			this->Fixed_IAT_Table->TabIndex = 17;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(11, 185);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(185, 46);
			this->button1->TabIndex = 19;
			this->button1->Text = L"Fix emulated API in IAT Table / Method2";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &IATFixer::button1_Click);
			// 
			// Bu_FixEmulatedAPIinIATtable0
			// 
			this->Bu_FixEmulatedAPIinIATtable0->Location = System::Drawing::Point(11, 81);
			this->Bu_FixEmulatedAPIinIATtable0->Name = L"Bu_FixEmulatedAPIinIATtable0";
			this->Bu_FixEmulatedAPIinIATtable0->Size = System::Drawing::Size(187, 46);
			this->Bu_FixEmulatedAPIinIATtable0->TabIndex = 18;
			this->Bu_FixEmulatedAPIinIATtable0->Text = L"Fix emulated API in IAT Table / Method1";
			this->Bu_FixEmulatedAPIinIATtable0->UseVisualStyleBackColor = true;
			this->Bu_FixEmulatedAPIinIATtable0->Click += gcnew System::EventHandler(this, &IATFixer::Bu_FixEmulatedAPIinIATtable0_Click);
			// 
			// Bu_FixEmulatedAPIinIATtable
			// 
			this->Bu_FixEmulatedAPIinIATtable->Enabled = false;
			this->Bu_FixEmulatedAPIinIATtable->Location = System::Drawing::Point(11, 133);
			this->Bu_FixEmulatedAPIinIATtable->Name = L"Bu_FixEmulatedAPIinIATtable";
			this->Bu_FixEmulatedAPIinIATtable->Size = System::Drawing::Size(185, 46);
			this->Bu_FixEmulatedAPIinIATtable->TabIndex = 16;
			this->Bu_FixEmulatedAPIinIATtable->Text = L"Fix emulated API in IAT Table / Method2";
			this->Bu_FixEmulatedAPIinIATtable->UseVisualStyleBackColor = true;
			this->Bu_FixEmulatedAPIinIATtable->Click += gcnew System::EventHandler(this, &IATFixer::Bu_FixEmulatedAPIinIATtable_Click);
			this->Bu_FixEmulatedAPIinIATtable->MouseHover += gcnew System::EventHandler(this, &IATFixer::Bu_FixEmulatedAPIinIATtable_MouseHover);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(10, 25);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(160, 16);
			this->label5->TabIndex = 14;
			this->label5->Text = L"IAT Table Address :";
			// 
			// TB_IATTableAddress
			// 
			this->TB_IATTableAddress->CharacterCasing = System::Windows::Forms::CharacterCasing::Upper;
			this->TB_IATTableAddress->Font = (gcnew System::Drawing::Font(L"Courier New", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TB_IATTableAddress->Location = System::Drawing::Point(178, 22);
			this->TB_IATTableAddress->Margin = System::Windows::Forms::Padding(4);
			this->TB_IATTableAddress->MaxLength = 16;
			this->TB_IATTableAddress->Name = L"TB_IATTableAddress";
			this->TB_IATTableAddress->Size = System::Drawing::Size(190, 21);
			this->TB_IATTableAddress->TabIndex = 12;
			this->TB_IATTableAddress->Text = L"14175B000";
			this->TB_IATTableAddress->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->TB_IATTableAddress->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &IATFixer::TB_IATTableAddress_MouseDoubleClick);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(34, 54);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(136, 16);
			this->label6->TabIndex = 15;
			this->label6->Text = L"IAT Table Size :";
			// 
			// TB_IATTableSize
			// 
			this->TB_IATTableSize->CharacterCasing = System::Windows::Forms::CharacterCasing::Upper;
			this->TB_IATTableSize->Location = System::Drawing::Point(178, 51);
			this->TB_IATTableSize->Margin = System::Windows::Forms::Padding(4);
			this->TB_IATTableSize->MaxLength = 16;
			this->TB_IATTableSize->Name = L"TB_IATTableSize";
			this->TB_IATTableSize->Size = System::Drawing::Size(190, 22);
			this->TB_IATTableSize->TabIndex = 13;
			this->TB_IATTableSize->Text = L"5AE8";
			this->TB_IATTableSize->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// Fix_API_Emulated_Call_LB
			// 
			this->Fix_API_Emulated_Call_LB->FormattingEnabled = true;
			this->Fix_API_Emulated_Call_LB->ItemHeight = 16;
			this->Fix_API_Emulated_Call_LB->Location = System::Drawing::Point(219, 204);
			this->Fix_API_Emulated_Call_LB->Margin = System::Windows::Forms::Padding(4);
			this->Fix_API_Emulated_Call_LB->Name = L"Fix_API_Emulated_Call_LB";
			this->Fix_API_Emulated_Call_LB->Size = System::Drawing::Size(261, 180);
			this->Fix_API_Emulated_Call_LB->TabIndex = 16;
			// 
			// La_count
			// 
			this->La_count->AutoSize = true;
			this->La_count->Location = System::Drawing::Point(298, 122);
			this->La_count->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->La_count->Name = L"La_count";
			this->La_count->Size = System::Drawing::Size(56, 16);
			this->La_count->TabIndex = 15;
			this->La_count->Text = L"Count:";
			// 
			// LB_CmdBreak
			// 
			this->LB_CmdBreak->FormattingEnabled = true;
			this->LB_CmdBreak->ItemHeight = 16;
			this->LB_CmdBreak->Location = System::Drawing::Point(298, 18);
			this->LB_CmdBreak->Margin = System::Windows::Forms::Padding(4);
			this->LB_CmdBreak->Name = L"LB_CmdBreak";
			this->LB_CmdBreak->Size = System::Drawing::Size(182, 100);
			this->LB_CmdBreak->TabIndex = 14;
			this->LB_CmdBreak->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &IATFixer::LB_CmdBreak_MouseDoubleClick);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(10, 86);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(32, 16);
			this->label7->TabIndex = 13;
			this->label7->Text = L"OEP";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// TB_OEP
			// 
			this->TB_OEP->CharacterCasing = System::Windows::Forms::CharacterCasing::Upper;
			this->TB_OEP->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Bold));
			this->TB_OEP->Location = System::Drawing::Point(152, 80);
			this->TB_OEP->Margin = System::Windows::Forms::Padding(4);
			this->TB_OEP->MaxLength = 16;
			this->TB_OEP->Name = L"TB_OEP";
			this->TB_OEP->Size = System::Drawing::Size(138, 22);
			this->TB_OEP->TabIndex = 12;
			this->TB_OEP->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->TB_OEP->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &IATFixer::TB_OEP_MouseDoubleClick);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(155, 44);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(136, 32);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Call xx xx xx xx\r\n nop";
			// 
			// TB_SectionLimitaion
			// 
			this->TB_SectionLimitaion->CharacterCasing = System::Windows::Forms::CharacterCasing::Upper;
			this->TB_SectionLimitaion->Font = (gcnew System::Drawing::Font(L"Courier New", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TB_SectionLimitaion->Location = System::Drawing::Point(152, 175);
			this->TB_SectionLimitaion->Margin = System::Windows::Forms::Padding(4);
			this->TB_SectionLimitaion->MaxLength = 16;
			this->TB_SectionLimitaion->Name = L"TB_SectionLimitaion";
			this->TB_SectionLimitaion->ReadOnly = true;
			this->TB_SectionLimitaion->Size = System::Drawing::Size(138, 21);
			this->TB_SectionLimitaion->TabIndex = 4;
			this->TB_SectionLimitaion->Text = L"143769000";
			this->TB_SectionLimitaion->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->TB_SectionLimitaion->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &IATFixer::TB_SectionLimitaion_MouseDoubleClick);
			this->TB_SectionLimitaion->MouseHover += gcnew System::EventHandler(this, &IATFixer::TB_SectionLimitaion_MouseHover);
			// 
			// CB_LimitBySction
			// 
			this->CB_LimitBySction->AutoSize = true;
			this->CB_LimitBySction->Checked = true;
			this->CB_LimitBySction->CheckState = System::Windows::Forms::CheckState::Checked;
			this->CB_LimitBySction->Font = (gcnew System::Drawing::Font(L"Courier New", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CB_LimitBySction->Location = System::Drawing::Point(12, 169);
			this->CB_LimitBySction->Name = L"CB_LimitBySction";
			this->CB_LimitBySction->Size = System::Drawing::Size(97, 36);
			this->CB_LimitBySction->TabIndex = 9;
			this->CB_LimitBySction->Text = L"Limite To \r\nSection :";
			this->CB_LimitBySction->UseVisualStyleBackColor = true;
			this->CB_LimitBySction->CheckedChanged += gcnew System::EventHandler(this, &IATFixer::CB_LimitBySction_CheckedChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(10, 21);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(128, 16);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Pattern Search:";
			// 
			// TB_PatternSearch
			// 
			this->TB_PatternSearch->CharacterCasing = System::Windows::Forms::CharacterCasing::Upper;
			this->TB_PatternSearch->Location = System::Drawing::Point(158, 18);
			this->TB_PatternSearch->Margin = System::Windows::Forms::Padding(4);
			this->TB_PatternSearch->Name = L"TB_PatternSearch";
			this->TB_PatternSearch->Size = System::Drawing::Size(132, 22);
			this->TB_PatternSearch->TabIndex = 0;
			this->TB_PatternSearch->Text = L"E8\?\?\?\?\?\?\?\?90";
			this->TB_PatternSearch->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(505, 683);
			this->tabControl1->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(497, 654);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Trace Method";
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(497, 654);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Method 2";
			// 
			// IATFixer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(512, 688);
			this->Controls->Add(this->tabControl1);
			this->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->Name = L"IATFixer";
			this->Text = L"IATFixer";
			this->Deactivate += gcnew System::EventHandler(this, &IATFixer::IATFixer_Deactivate);
			this->Load += gcnew System::EventHandler(this, &IATFixer::IATFixer_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->ResumeLayout(false);

		}

	private: System::Void GetALLAPIEmulatedCall_Bu_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ PatternSearch = TB_PatternSearch->Text;  //# E8????????90 #
		if (TB_SectionBase->Text == "" || TB_SectionSize->Text == "" || TB_PatternSearch->Text == "" || TB_IATTableAddress->Text == "" || TB_IATTableSize->Text == "") {
			Interaction::MsgBox("Please Fill the Missing Data", MsgBoxStyle::DefaultButton1, "Error");
			return;
		}
		bool LimitationEnabled = CB_LimitBySction->Checked;
		if (LimitationEnabled && TB_SectionLimitaion->Text == "") {
			Interaction::MsgBox("Please Fill Section to limit ", MsgBoxStyle::DefaultButton1, "Error");
			return;
		}
		LB_CmdBreak->Items->Clear();
		Fix_API_Emulated_Call_LB->Items->Clear();
		API_Emulated_Call_LB->Items->Clear();
		duint OEP = Hex2duint(TB_OEP->Text);
		duint Textsctionbase = Hex2duint(TB_SectionBase->Text);
		duint Textpagesize = Hex2duint(TB_SectionSize->Text);
		if (Textsctionbase == -1 || Textpagesize == -1)
		{
			Interaction::MsgBox("Something wrong with Text sctionbase or pagesize", MsgBoxStyle::DefaultButton1, "Error");
			return;
		}

		GuiUpdateDisable(); // we need to use this because sometimes search will take more time and x64dbg could be hang 
		//duint API_Emulated_Section_Addr = Hex2duint(TB_SectionLimitaion->Text);

		// -1- save IAT table for later compare and fix the missig API in the table
		duint IAT_Table_Address = Hex2duint(TB_IATTableAddress->Text);
		duint IAT_TableSize = Hex2duint(TB_IATTableSize->Text);
		System::Collections::Generic::List<IAT_table^>^  iat_table_ = gcnew System::Collections::Generic::List<IAT_table^>;
		duint temp = IAT_Table_Address;
		while (temp <= IAT_Table_Address + IAT_TableSize)
		{
			duint API_Addr;
			char* ModuleName = new char[MAX_STRING_SIZE]();
			DbgMemRead(temp, &API_Addr, 8);
			//DbgGetModuleAt(DataValue_, ModuleName);
			IAT_table^ r = gcnew IAT_table(temp, API_Addr, GetAPIName_LableWay(API_Addr));
			temp = temp + 8;
			iat_table_->Add(r);
		}
		// -1-
		//return;
		duint API_Emulated_Section_Addr = Hex2duint(TB_SectionLimitaion->Text);
		duint API_Emulated_Section_Base_Addr = DbgMemFindBaseAddr(API_Emulated_Section_Addr, 0);
		duint API_Emulated_Section_Size = DbgMemGetPageSize(API_Emulated_Section_Base_Addr);

		// now search for all commands #or rax, qword ptr ss:[rsp]# , All Call xxxxx will pass through this command and it hold API in RAX
		// pattern is #48 0B 04 24#
		duint or_CmdFindAddr = API_Emulated_Section_Base_Addr;
		//const char* cmdSearch = "or rax, qword ptr ss:[rsp]";
		const char* or_cmdSearch = "48 0B 04 24";
		LB_CmdBreak->Items->Clear();
		int lbCount = 0;
		while (or_CmdFindAddr <= API_Emulated_Section_Base_Addr + API_Emulated_Section_Size)
		{
			duint delta = or_CmdFindAddr - API_Emulated_Section_Base_Addr;
			or_CmdFindAddr = Script::Pattern::FindMem(or_CmdFindAddr, API_Emulated_Section_Size - delta, or_cmdSearch);
			if (or_CmdFindAddr == 0xffffffffffffffff || or_CmdFindAddr == 0) break;
			Script::Debug::SetBreakpoint(or_CmdFindAddr);
			LB_CmdBreak->Items->Add(duint2Hex(or_CmdFindAddr));
			or_CmdFindAddr = or_CmdFindAddr + 0x4;
			lbCount += 1;
			IATFixer::Refresh();
			Application::DoEvents();
		}
		La_count->Text = Microsoft::VisualBasic::Conversion::Str(lbCount);
		//GuiUpdateEnable(true);
		//return;
		duint Findaddr = Textsctionbase;
		while (Findaddr <= Textsctionbase + Textpagesize) {
			duint delta = Findaddr - Textsctionbase;
			Findaddr = Script::Pattern::FindMem(Findaddr, Textpagesize - delta, Str2ConstChar(PatternSearch)); //E8????????90
			if (Findaddr == 0xffffffffffffffff || Findaddr == 0) break;
			else
			{
				DISASM_INSTR* instr = new DISASM_INSTR;
				DbgDisasmAt(Findaddr, instr);
				if (LimitationEnabled) {
					/*duint base_emulatedAPi_Section;
					try
					{
						base_emulatedAPi_Section = Hex2duint(reMoveSpaces(TB_SectionLimitaion->Text->Trim()));
					}
					catch (const std::exception&)
					{
						Interaction::MsgBox("Base emulated address is wrong pls fix it", MsgBoxStyle::DefaultButton1, "Error");
						return;
					}*/

					//if (checkLimitation(instr, base_emulatedAPi_Section)) {
					if (checkLimitation(instr, API_Emulated_Section_Base_Addr)) {
						Script::Register::Set(Script::Register::RIP, Findaddr);
						//Script::Debug::SetBreakpoint(Findaddr + 0x5); we already put BP at all commands of "or rax, qword ptr ss:[rsp]"
						Script::Debug::Run();
						Script::Debug::Wait();
						Application::DoEvents();
						DISASM_INSTR* instr1 = new DISASM_INSTR;
						DbgDisasmAt(Script::Register::Get(Script::Register::RIP), instr1);
						if (checkCmdAtBP(instr1)) {
							duint API_Addr = Script::Register::Get(Script::Register::RAX);
							duint Call_Addr = Findaddr;
							// here we fix the call by search through the IAT Table iat_table_ and replace emulated Call
							// with call qword ptr ds:[API_Addr]
							duint iat_addr = FindAPIAddr(iat_table_, API_Addr);
							if (iat_addr == 0) {
								Interaction::MsgBox("Something wrong with finding API in the Iat Table, API Address: " + duint2Hex(API_Addr) , MsgBoxStyle::DefaultButton1, "Error");
								return;
							}
							else
							{
								String^ AssNewCallCmd = "call qword ptr ds:[" + duint2Hex(iat_addr) + "]";
								DbgAssembleAt(Findaddr, Str2ConstChar(AssNewCallCmd));
								//GuiUpdateEnable(true);
								//return;
							}
							API_Emulated_Call_LB->Items->Add("Call_Addr:  " + duint2Hex(Call_Addr) + " >> "  "API: " + duint2Hex(API_Addr));
							IATFixer::Refresh();
							Application::DoEvents();
						}
						else {
							Interaction::MsgBox("Something Go wrong and we not reach the next BP", MsgBoxStyle::DefaultButton1, "Error");
							return;
						}

						//API_Emulated_Call_LB->Items->Add(duint2Hex(Findaddr) + ": " + CharArr2Str(instr->instruction) + " ");
						//IATFixer::Refresh();
						//Application::DoEvents();
					}
				}
				/*else {
					API_Emulated_Call_LB->Items->Add(duint2Hex(Findaddr) + "  " + CharArr2Str(instr->instruction));
					IATFixer::Refresh();
					Application::DoEvents();
				}*/
				Findaddr = Findaddr + 0x2; // (PatternSearch->Length / 2) - 2;
			}
		} ////////////////////////////////
		Script::Register::Set(Script::Register::RIP, OEP);
		GuiUpdateEnable(true);
	}

	private: duint FindAPIAddr(System::Collections::Generic::List<IAT_table^>^  iat_table_, duint API_Addr) {
		for each (IAT_table^ x in iat_table_)
		{
			if (x->API_addr == API_Addr) {
				return x->iat_addr;
			}
		}
		return 0;
	}

	private: System::Void IATFixer_Load(System::Object^  sender, System::EventArgs^  e) {
		SELECTIONDATA sel;
		GuiSelectionGet(GUI_DISASSEMBLY, &sel);
		duint pagesize = DbgMemGetPageSize(sel.start);
		duint sctionbase = DbgMemFindBaseAddr(sel.start, &pagesize);
		TB_OEP->Text = duint2Hex(sel.start);
		TB_SectionBase->Text = duint2Hex(sctionbase); // Conversion::Hex(sctionbase);
		TB_SectionSize->Text = duint2Hex(pagesize); //Conversion::Hex(pagesize);
		TB_PatternSearch->SelectAll();
	}

	private: System::Void IATFixer_Deactivate(System::Object^  sender, System::EventArgs^  e) {
		Application::DoEvents();
	}
	private: System::Void API_Emulated_Call_LB_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		String^ Line_ = API_Emulated_Call_LB->GetItemText(API_Emulated_Call_LB->SelectedItem);
		Line_ = Line_->Trim()->Substring(0, Line_->IndexOf(" "));
		//duint addr = Hex2duint(Line_);
		DbgCmdExec(Str2ConstChar("disasm " + Line_));
	}

	private: System::Void CB_LimitBySction_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (CB_LimitBySction->Checked) {
			TB_SectionLimitaion->ReadOnly = false; Bu_FixEmulatedAPIinIATtable->Enabled = true;
		}
		else {
			TB_SectionLimitaion->ReadOnly = true; Bu_FixEmulatedAPIinIATtable->Enabled = false;
		}

	}


	private: bool checkLimitation(DISASM_INSTR* instr, duint base_emulatedAPi_Section) {
		String^ command_ = CharArr2Str(instr->instruction);
		duint pagesize = DbgMemGetPageSize(base_emulatedAPi_Section);
		if (command_->ToLower()->StartsWith("call")) {
			duint CallAddr = Hex2duint(command_->Substring(command_->IndexOf(" ") + 3, command_->Length - command_->IndexOf(" ") - 3)->Trim()); // we add 3 -after find space- which is " 0x" like in command "call 0xff512f4c"
			if (CallAddr >= base_emulatedAPi_Section && CallAddr <= base_emulatedAPi_Section + pagesize) {
				return true;
			}
			else { return false; };
		}
		return false;
	}

	private: bool FixSimilarCall(System::Collections::Generic::List<IAT_table^>^  iat_table_, duint Call_Addr, DISASM_INSTR* instr_, duint sctionbase, duint sectionSize, duint API_Addr) {
		duint find_Addr = sctionbase;
		duint temp;
		DbgMemRead(Call_Addr, &temp, 5);
		String^ cmdSearch_ = CharArr2Str(instr_->instruction);  //"E8" + 
		//cmdSearch_= cmdSearch_->
		//const char* cmdSearch;
		while (find_Addr <= sctionbase + sectionSize)

		{
			duint delta = find_Addr - sctionbase;
			//find_Addr = Script::Pattern::FindMem(find_Addr, sctionbase - delta, cmdSearch);
			if (find_Addr == 0xffffffffffffffff || find_Addr == 0) break;
		}
		return 0;
	}

	private: bool checkCmdAtBP(DISASM_INSTR* instr) {
		String^ command_ = CharArr2Str(instr->instruction);
		//command_ = command_->ToLower;
		String^ x = "or rax, qword ptr ss:[rsp]";
		if (command_ == x) {
			return true;
		}
		return false;
	}

	private: System::Void TB_SectionLimitaion_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		SELECTIONDATA sel;
		GuiSelectionGet(GUI_DISASSEMBLY, &sel);
		duint pagesize = DbgMemGetPageSize(sel.start);
		duint sctionbase = DbgMemFindBaseAddr(sel.start, &pagesize);
		TB_SectionLimitaion->Text = duint2Hex(sctionbase);
	}
	private: System::Void TB_SectionLimitaion_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		ToolTip^ tTip = gcnew ToolTip;
		tTip->Show("Go to any emulated Call and" + Environment::NewLine + " then press enter then double click here to " + Environment::NewLine + " get base of emulated section", this->TB_SectionLimitaion, 8000);
	}
	private: System::Void Bu_FixEmulatedAPIinIATtable_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		ToolTip^ tTip = gcnew ToolTip;

		tTip->Show("To Enable this Option" + Environment::NewLine + ",you should enable -Limit To Section- option", this->Bu_FixEmulatedAPIinIATtable, 8000);
		tTip->ShowAlways = true;
	}

	private: System::Void TB_SectionBase_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void TB_SectionBase_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		SELECTIONDATA sel;
		GuiSelectionGet(GUI_DISASSEMBLY, &sel);
		duint pagesize = DbgMemGetPageSize(sel.start);
		TB_SectionSize->Text = duint2Hex(pagesize);
		TB_SectionBase->Text = duint2Hex(DbgMemFindBaseAddr(sel.start, &pagesize));

	}
	private: System::Void Bu_FixEmulatedAPIinIATtable_Click(System::Object^  sender, System::EventArgs^  e) {

		//DbgGetModuleAt()

		if (TB_SectionLimitaion->Text == "get mouse here see tooltips for it work" || TB_SectionLimitaion->Text == "" || TB_IATTableAddress->Text == "" || TB_IATTableSize->Text == "") {
			Interaction::MsgBox("Text Box Section Limitaion has wrong value", MsgBoxStyle::DefaultButton1, "Error"); return;
		}
		else {
			try
			{
				duint IAT_Table_Address = Hex2duint(TB_IATTableAddress->Text);
				duint IAT_TableSize = Hex2duint(TB_IATTableSize->Text);
				System::Collections::Generic::List<IAT_table^>^  iat_table_ = gcnew System::Collections::Generic::List<IAT_table^>;

				// save IAT table for later compare and fix the missig API in the table
				duint temp = IAT_Table_Address;
				while (temp <= IAT_Table_Address + IAT_TableSize)
				{
					duint DataValue_;
					DbgMemRead(temp, &DataValue_, 8);
					IAT_table^ r = gcnew IAT_table(temp, DataValue_, "");  /// dont' forget to fix here
					temp = temp + 8;
					iat_table_->Add(r);
				}
				duint API_Emulated_Section_Addr = Hex2duint(TB_SectionLimitaion->Text);
				duint API_Emulated_Section_Base_Addr = DbgMemFindBaseAddr(API_Emulated_Section_Addr, 0);
				duint API_Emulated_Section_Size = DbgMemGetPageSize(API_Emulated_Section_Base_Addr);

				// now search for all commands #or rax, qword ptr ss:[rsp]# , All Call xxxxx will pass through this command and it hold API in RAX
				/*duint CmdFindAddr = API_Emulated_Section_Base_Addr; duint temp_ = API_Emulated_Section_Base_Addr;
				const char* cmdSearch = "or rax, qword ptr ss:[rsp]";
				while (temp_ <= API_Emulated_Section_Base_Addr + API_Emulated_Section_Size)
				{
					duint delta = CmdFindAddr - API_Emulated_Section_Base_Addr;
					CmdFindAddr = DbgAssembleAt(temp_, cmdSearch);


				}*/
				//////////////////////////////////////
				// we will add some missing API so we have to search for this #55 48 89 E5 48 83 EC 30 E8 00 00 00 00# 
				// or #55 48 89 E5 48 83 EC 30 E8 00 00 00 00 41 5A#
				//////////////////////////////////////

				duint Findaddr = API_Emulated_Section_Base_Addr;
				String^ PatternSearch = "6A 00 48 8D 85 ?? ?? ?? ?? 50 48 8D 85";
				String^ PatternSearch1 = "55 48 89 E5 48 83 EC 30 E8 00 00 00 00"; // define 
				duint tempx = API_Emulated_Section_Base_Addr;
				//should eb found one time so we will search for it 1 time 

				while (tempx <= API_Emulated_Section_Base_Addr + API_Emulated_Section_Size)
				{

					duint delta = Findaddr - API_Emulated_Section_Base_Addr;
					Findaddr = Script::Pattern::FindMem(tempx, API_Emulated_Section_Size - delta, Str2ConstChar(PatternSearch));
					if ((Findaddr == 0xffffffffffffffff || Findaddr == 0) && (tempx == API_Emulated_Section_Base_Addr)) {
						Interaction::MsgBox("I think techinic not work on this Target, sorry pls connect me with your target", MsgBoxStyle::DefaultButton2, "Error");
						return;
					}
					if (Findaddr == 0xffffffffffffffff || Findaddr == 0) {
						Interaction::MsgBox("Done", MsgBoxStyle::DefaultButton2, "Done");
						return;
						return;
					}
					else {
						tempx = Findaddr + 4; // PatternSearch->Length - 4;
						Script::Register::Set(Script::Register::RIP, Findaddr);
						Script::Debug::SetBreakpoint(Findaddr + 0x1F);
						//Interaction::MsgBox(duint2Hex(Script::Register::Get(Script::Register::RIP)), MsgBoxStyle::DefaultButton2, "RIP");
						Script::Debug::Run();
						Script::Debug::Wait();
						Application::DoEvents();
						if (Script::Register::Get(Script::Register::RIP) != Findaddr + 0x1F) {
							Interaction::MsgBox("Something Go wrong and we not reach the next BP", MsgBoxStyle::DefaultButton1, "Error");
							return;
						}
						else {
							Script::Debug::DeleteBreakpoint(Findaddr + 0x1F);
							duint APi_name_addr;  String^ APi_name_Str; duint moduleName_addr;  String^ moduleName_Str;
							duint API_Addr; /// the will be the address of the API so we can replace it in the 
											//IAT table with emualted API
							duint emulatedAPI_addr = Script::Register::Get(Script::Register::RSP) - 0x10;
							APi_name_addr = Script::Register::Get(Script::Register::RSP) - 0x18;
							moduleName_addr = Script::Register::Get(Script::Register::RSP) - 0x20;;
							DbgMemRead(emulatedAPI_addr, &emulatedAPI_addr, 8);
							DbgMemRead(APi_name_addr, &APi_name_addr, 8);
							DbgMemRead(moduleName_addr, &moduleName_addr, 8);
							for each (IAT_table^ j in iat_table_) {
								try
								{
									if (j->API_addr == emulatedAPI_addr) {
										char* APi_name = new char[MAX_STRING_SIZE]();
										char* moduleName = new char[MAX_STRING_SIZE]();
										//Interaction::MsgBox("here", MsgBoxStyle::DefaultButton1, "here");
										bool s1 = DbgGetStringAt(APi_name_addr, APi_name);
										if (!s1) { Interaction::MsgBox("S1", MsgBoxStyle::DefaultButton1, "Error"); }
										//String^ d = charPTR2String(APi_name);
										APi_name_Str = ClearSlash_etc(charPTR2String(APi_name));
										//APi_name_Str = ClearSlash_etc(d);


										bool s2 = DbgGetStringAt(moduleName_addr, moduleName);
										if (!s2) { Interaction::MsgBox("S2", MsgBoxStyle::DefaultButton1, "Error"); }
										//String^ d1 = charPTR2String(moduleName);
										//moduleName_Str = ClearSlash_etc(d1);
										moduleName_Str = ClearSlash_etc(charPTR2String(moduleName));

										String^ temp = moduleName_Str + ":" + APi_name_Str;
										const char* d2 = Str2ConstChar(temp);
										API_Addr = DbgValFromString(d2);
										//API_Addr = DbgValFromString(Str2ConstChar(temp));
										if (!DbgMemWrite(j->iat_addr, &API_Addr, 8)) {
											Interaction::MsgBox("Can't write to mem at :" + duint2Hex(API_Addr), MsgBoxStyle::DefaultButton1, "Error");
											return;
										}
									}/////////////////////
								}
								catch (const std::exception& s)
								{

									Interaction::MsgBox(duint2Hex(emulatedAPI_addr), MsgBoxStyle::DefaultButton1, "Error");
								}

							}
						}

					}
				} ////////////////////////////////////////////////////

			}
			catch (const std::exception& s)
			{
				Interaction::MsgBox("Something Go wrong :( ", MsgBoxStyle::DefaultButton1, "Error");
			}



		}
	}
	private: System::Void TB_IATTableAddress_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		SELECTIONDATA sel;
		GuiSelectionGet(GUI_DUMP, &sel);
		TB_IATTableAddress->Text = duint2Hex(sel.start);

	}
	private: System::Void Bu_FixEmulatedAPIinIATtable0_Click(System::Object^  sender, System::EventArgs^  e) {

		//ListMemMapSection();

		//Interaction::MsgBox("you should be at OEP of the target or near :)", MsgBoxStyle::DefaultButton1, "Info");
		duint sectionBaseddr = 0x0000000000010000, sectionSize = DbgMemGetPageSize(sectionBaseddr);
		duint finishSectionAddrSearchBase = DbgMemFindBaseAddr(Hex2duint(TB_OEP->Text), 0);
		duint findaddr;
		while (sectionBaseddr != finishSectionAddrSearchBase)
		{
			findaddr = Script::Pattern::FindMem(sectionBaseddr, sectionSize, "D0 76 D3 78 00 00 00 00 40 92 D7 78 00 00 00 00");
			if (findaddr != 0xffffffffffffffff && findaddr != 0x0) {
				break;
			}
			else
			{
				sectionBaseddr = sectionBaseddr + sectionSize + 0x1000;
				MEMMAP* MEMMAP_ = new (MEMMAP);
				DbgMemMap(MEMMAP_);
				int x = Script::Memory::GetProtect(sectionBaseddr, true);
				if (x == 0) {
					duint x1 = Script::Memory::GetSize(sectionBaseddr, true);
					int ll = 5;
					ll = 10;
				}

				duint temp = DbgMemFindBaseAddr(sectionBaseddr, 0);
				if (temp != 0) {
					sectionBaseddr = temp;
					sectionSize = DbgMemGetPageSize(sectionBaseddr);
					//break;
				}
				else
				{
					sectionBaseddr = sectionBaseddr + sectionSize + 1000;
				}

				//for (int s = 0; s < 20; ++s) {					
					//duint temp = DbgMemFindBaseAddr(sectionBaseddr, 0);
					//if (temp != 0) {
					//	sectionBaseddr = temp;
					//	sectionSize = DbgMemGetPageSize(sectionBaseddr);
					//	//break;
					//}
					//else
					//{
					//	sectionBaseddr = sectionBaseddr + sectionSize + 1000;
					//}
				//}

			}
		}

	}
	private: System::Void TB_OEP_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		SELECTIONDATA sel;
		GuiSelectionGet(GUI_DISASSEMBLY, &sel);
		TB_OEP->Text = duint2Hex(sel.start);

	}
	private: System::Void LB_CmdBreak_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		String^ Line_ = LB_CmdBreak->GetItemText(LB_CmdBreak->SelectedItem);
		//duint addr = Hex2duint(Line_);
		//const char* x = ;
		DbgCmdExec(Str2ConstChar("disasm " + Line_));
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		// this way to get the API name from the address by get the lable of this address as x64dbg is write the name of the API in the lable
		SEGMENTREG segment;
		char* text = new char[MAX_STRING_SIZE];
		DbgGetLabelAt(0x0000000078D34EF0, segment, text);
	}
	};

}
