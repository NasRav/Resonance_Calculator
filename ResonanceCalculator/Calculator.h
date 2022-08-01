#pragma once

#include <cmath>

namespace ResonanceCalculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Calculator
	/// </summary>
	public ref class Calculator : public System::Windows::Forms::Form
	{
	public:
		Calculator(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	const double	ro0 = 0.00114;
	const double	R_gas = 0.2968e+7;
	const double	gamma = 1.4;
	const double	PI = acos(-1);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Calculator()
		{
			if (components)
			{
				delete components;
			}
		}
	protected:
	private: System::Windows::Forms::Label^ L;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ T;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ f;
	private: System::Windows::Forms::Button^ button1;

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
			this->L = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->T = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->f = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// L
			// 
			this->L->AutoSize = true;
			this->L->Location = System::Drawing::Point(10, 9);
			this->L->Name = L"L";
			this->L->Size = System::Drawing::Size(75, 13);
			this->L->TabIndex = 0;
			this->L->Text = L"L (Length, cm)";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(10, 30);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = this->L->Size;
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"100";
			// 
			// T
			// 
			this->T->AutoSize = true;
			this->T->Location = System::Drawing::Point(91, 9);
			this->T->Name = L"T";
			this->T->Size = System::Drawing::Size(96, 13);
			this->T->TabIndex = 2;
			this->T->Text = L"T (Temperature, K)";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(91, 30);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = this->T->Size;
			this->textBox2->TabIndex = 3;
			this->textBox2->Text = L"293.15";
			// 
			// f
			// 
			this->f->AutoSize = true;
			this->f->Location = System::Drawing::Point(194, 30);
			this->f->Name = L"f";
			this->f->Size = System::Drawing::Size(0, 13);
			this->f->TabIndex = 4;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(197, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Calculate";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Calculator::button1_Click);
			// 
			// Calculator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(391, 79);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->f);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->T);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->L);
			this->Name = L"Calculator";
			this->Text = L"Calculator";
			this->Load += gcnew System::EventHandler(this, &Calculator::Calculator_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Calculator_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		double p0 = ro0 * R_gas * Convert::ToDouble(this->textBox2->Text);
		double c0 = sqrt(gamma * p0 / ro0);
		double f = c0 / (2 * Convert::ToDouble(this->textBox1->Text));
		this->f->Text = L"c = " + Convert::ToString(c0) + 
			" cm/s\nf = " + Convert::ToString(f) +
			" Hz\nomega = " + Convert::ToString(2 * PI * f) + " rad / s";
	}
};
}
