#pragma once

#include "EmprestimoForm.h"
#include "DevolucaoForm.h"
#include "ConsultaLivroForm.h"

namespace Testebiblioteca {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MenuAlunoForm : public System::Windows::Forms::Form
	{
	public:
		MenuAlunoForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MenuAlunoForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button1;
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->button8 = (gcnew System::Windows::Forms::Button());
			   this->button7 = (gcnew System::Windows::Forms::Button());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->SuspendLayout();
			   // 
			   // button8
			   // 
			   this->button8->Location = System::Drawing::Point(289, 275);
			   this->button8->Name = L"button8";
			   this->button8->Size = System::Drawing::Size(172, 31);
			   this->button8->TabIndex = 15;
			   this->button8->Text = L"Devolução de Livro";
			   this->button8->UseVisualStyleBackColor = true;
			   this->button8->Click += gcnew System::EventHandler(this, &MenuAlunoForm::button8_Click);
			   // 
			   // button7
			   // 
			   this->button7->Location = System::Drawing::Point(289, 237);
			   this->button7->Name = L"button7";
			   this->button7->Size = System::Drawing::Size(172, 31);
			   this->button7->TabIndex = 14;
			   this->button7->Text = L"Emprestimo de Livro";
			   this->button7->UseVisualStyleBackColor = true;
			   this->button7->Click += gcnew System::EventHandler(this, &MenuAlunoForm::button7_Click);
			   // 
			   // button1
			   // 
			   this->button1->Location = System::Drawing::Point(289, 312);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(172, 31);
			   this->button1->TabIndex = 16;
			   this->button1->Text = L"Consultar Livro";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &MenuAlunoForm::button1_Click);
			   // 
			   // MenuAlunoForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(735, 601);
			   this->Controls->Add(this->button1);
			   this->Controls->Add(this->button8);
			   this->Controls->Add(this->button7);
			   this->Name = L"MenuAlunoForm";
			   this->Text = L"Aluno (Menu)";
			   this->ResumeLayout(false);
		   }
#pragma endregion

	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		EmprestimoForm^ emprestimoForm = gcnew EmprestimoForm();
		emprestimoForm->Show();
	}

	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
		DevolucaoForm^ devolucaoForm = gcnew DevolucaoForm();
		devolucaoForm->Show();
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		ConsultaLivroForm^ consultaLivroForm = gcnew ConsultaLivroForm();
		consultaLivroForm->Show();
	}
	};
}
