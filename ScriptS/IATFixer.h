#pragma once
#include"pluginsdk\_scriptapi.h"
namespace ScriptS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Microsoft::VisualBasic;

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
			this->SuspendLayout();
			// 
			// GetALLAPIEmulatedCall_Bu
			// 
			this->GetALLAPIEmulatedCall_Bu->Location = System::Drawing::Point(78, 536);
			this->GetALLAPIEmulatedCall_Bu->Name = L"GetALLAPIEmulatedCall_Bu";
			this->GetALLAPIEmulatedCall_Bu->Size = System::Drawing::Size(156, 41);
			this->GetALLAPIEmulatedCall_Bu->TabIndex = 0;
			this->GetALLAPIEmulatedCall_Bu->Text = L"Get ALL API Emulated Call";
			this->GetALLAPIEmulatedCall_Bu->UseVisualStyleBackColor = true;
			this->GetALLAPIEmulatedCall_Bu->Click += gcnew System::EventHandler(this, &IATFixer::GetALLAPIEmulatedCall_Bu_Click);
			// 
			// API_Emulated_Call_LB
			// 
			this->API_Emulated_Call_LB->FormattingEnabled = true;
			this->API_Emulated_Call_LB->Location = System::Drawing::Point(12, 32);
			this->API_Emulated_Call_LB->Name = L"API_Emulated_Call_LB";
			this->API_Emulated_Call_LB->Size = System::Drawing::Size(300, 498);
			this->API_Emulated_Call_LB->TabIndex = 1;
			// 
			// IATFixer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(983, 724);
			this->Controls->Add(this->API_Emulated_Call_LB);
			this->Controls->Add(this->GetALLAPIEmulatedCall_Bu);
			this->Name = L"IATFixer";
			this->Text = L"IATFixer";
			this->ResumeLayout(false);

		}


	private: System::Void GetALLAPIEmulatedCall_Bu_Click(System::Object^  sender, System::EventArgs^  e) {
		for (int i = 0; i < 10; ++i) {
			Script::Pattern::FindMem()

		}
	}
	};
}
