#pragma once

#include <PrimeGenerator.h>
#include <vector>

namespace UI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for PrimeGeneratorGUI
	/// </summary>
	public ref class PrimeGeneratorGUI : public System::Windows::Forms::Form
	{
	private:
		PrimeGenerator* prime;
	public:
		PrimeGeneratorGUI(void)
		{
			InitializeComponent();
			
			prime = new PrimeGenerator();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PrimeGeneratorGUI()
		{
			if (components)
			{
				delete components;
				delete prime;
			}
		}
	private: System::Windows::Forms::Button^  generateButton;
	private: System::Windows::Forms::Label^  label1;

	protected:


	private: System::Windows::Forms::Label^  inputBox;
	private: System::Windows::Forms::TextBox^  outputBox;
	protected:



	private: System::Windows::Forms::TextBox^  textBox2;

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
			this->generateButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->inputBox = (gcnew System::Windows::Forms::Label());
			this->outputBox = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// generateButton
			// 
			this->generateButton->Location = System::Drawing::Point(197, 182);
			this->generateButton->Name = L"generateButton";
			this->generateButton->Size = System::Drawing::Size(75, 23);
			this->generateButton->TabIndex = 0;
			this->generateButton->Text = L"Generate";
			this->generateButton->UseVisualStyleBackColor = true;
			this->generateButton->Click += gcnew System::EventHandler(this, &PrimeGeneratorGUI::generateButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(21, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(184, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Prime numbers less than upper bound";
			// 
			// inputBox
			// 
			this->inputBox->AutoSize = true;
			this->inputBox->Location = System::Drawing::Point(21, 133);
			this->inputBox->Name = L"inputBox";
			this->inputBox->Size = System::Drawing::Size(142, 13);
			this->inputBox->TabIndex = 2;
			this->inputBox->Text = L"Enter your upper bound here";
			// 
			// outputBox
			// 
			this->outputBox->Location = System::Drawing::Point(24, 42);
			this->outputBox->Multiline = true;
			this->outputBox->Name = L"outputBox";
			this->outputBox->ReadOnly = true;
			this->outputBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->outputBox->Size = System::Drawing::Size(139, 88);
			this->outputBox->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(24, 164);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 4;
			// 
			// PrimeGeneratorGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(312, 261);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->outputBox);
			this->Controls->Add(this->inputBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->generateButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"PrimeGeneratorGUI";
			this->Text = L"PrimeGeneratorGUI";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void generateButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 int upperBound = int::Parse(inputBox->Text);
				 std::vector<int> primeList = prime->GetPrimeLessThan(upperBound);
				 int totalPrime = primeList.size();
				 String^ s = "";

				 for (int I = 0; I < totalPrime; I++){
					 s = s + primeList[I].ToString();

					 if (I != totalPrime - 1){
						 s = s + "";
					 }
				 }
				 outputBox->Text = s;
			 }
};
}
