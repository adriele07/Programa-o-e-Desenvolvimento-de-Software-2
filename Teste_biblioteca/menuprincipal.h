#pragma once
#include "LoginAlunoForm.h"
#include "LoginAdmForm.h" // Inclua isso aqui

namespace Testebiblioteca {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnsoualuno;
	private: System::Windows::Forms::Button^ btnsouadministrador;

	private:
		System::ComponentModel::Container^ components;

		void InitializeComponent(void)
		{
			this->btnsoualuno = (gcnew System::Windows::Forms::Button());
			this->btnsouadministrador = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnsoualuno
			// 
			this->btnsoualuno->Location = System::Drawing::Point(256, 193);
			this->btnsoualuno->Name = L"btnsoualuno";
			this->btnsoualuno->Size = System::Drawing::Size(238, 77);
			this->btnsoualuno->TabIndex = 0;
			this->btnsoualuno->Text = L"Sou Aluno";
			this->btnsoualuno->UseVisualStyleBackColor = true;
			this->btnsoualuno->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// btnsouadministrador
			// 
			this->btnsouadministrador->Location = System::Drawing::Point(256, 304);
			this->btnsouadministrador->Name = L"btnsouadministrador";
			this->btnsouadministrador->Size = System::Drawing::Size(238, 78);
			this->btnsouadministrador->TabIndex = 1;
			this->btnsouadministrador->Text = L"Sou Administrador";
			this->btnsouadministrador->UseVisualStyleBackColor = true;
			this->btnsouadministrador->Click += gcnew System::EventHandler(this, &MyForm::btnsouadministrador_Click); // Adicione o manipulador de eventos aqui
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(732, 623);
			this->Controls->Add(this->btnsouadministrador);
			this->Controls->Add(this->btnsoualuno);
			this->Name = L"MyForm";
			this->Text = L"Gerenciamento de Biblioteca PDS2";
			this->ResumeLayout(false);

		}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		LoginAlunoForm^ loginForm = gcnew LoginAlunoForm();
		loginForm->ShowDialog(); // Use ShowDialog para abrir como uma janela modal
	}
	private: System::Void btnsouadministrador_Click(System::Object^ sender, System::EventArgs^ e) {
		LoginAdmForm^ loginAdmForm = gcnew LoginAdmForm();
		loginAdmForm->ShowDialog(); // Use ShowDialog para abrir como uma janela modal
	}
	};
}
