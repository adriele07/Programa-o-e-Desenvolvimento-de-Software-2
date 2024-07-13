#pragma once
#include "CadastroAlunoForm.h"
#include "CadastroLivroForm.h"
#include "DevolucaoForm.h"
#include "EditarAlunoForm.h"
#include "EditarLivroForm.h"
#include "ExcluirAlunoForm.h"
#include "ExcluirLivroForm.h"
#include "EmprestimoForm.h"

namespace Testebiblioteca {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Sumário para MenuAdmForm
	/// </summary>
	public ref class MenuAdmForm : public System::Windows::Forms::Form
	{
	public:
		MenuAdmForm(void)
		{
			InitializeComponent();
			//
			//TODO: Adicione o código do construtor aqui
			//
		}

	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~MenuAdmForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;

	private:
		/// <summary>
		/// Variável de designer necessária.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necessário para suporte ao Designer - não modifique 
		/// o conteúdo deste método com o editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(265, 123);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(172, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Cadastrar Aluno";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MenuAdmForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(265, 210);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(172, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Cadastrar Livro";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MenuAdmForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(265, 333);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(172, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Devolução do  Livro";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MenuAdmForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(265, 152);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(172, 23);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Editar Aluno";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MenuAdmForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(265, 239);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(172, 23);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Editar Livro";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MenuAdmForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(265, 181);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(172, 23);
			this->button6->TabIndex = 5;
			this->button6->Text = L"Excluir Aluno";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MenuAdmForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(265, 275);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(172, 23);
			this->button7->TabIndex = 6;
			this->button7->Text = L"Excluir Livro";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MenuAdmForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(265, 304);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(172, 23);
			this->button8->TabIndex = 7;
			this->button8->Text = L"Emprestimo de livro";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MenuAdmForm::button8_Click);
			// 
			// MenuAdmForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(736, 600);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MenuAdmForm";
			this->Text = L"Administrador (Menu)";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		CadastroAlunoForm^ cadastroAlunoForm = gcnew CadastroAlunoForm();
		cadastroAlunoForm->ShowDialog();
	}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	CadastroLivroForm^ cadastroLivroForm = gcnew CadastroLivroForm();
	cadastroLivroForm->ShowDialog();
}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	DevolucaoForm^ devolucaoForm = gcnew DevolucaoForm();
	devolucaoForm->ShowDialog();
}

private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	EditarAlunoForm^ editarAlunoForm = gcnew EditarAlunoForm();
	editarAlunoForm->ShowDialog();
}

private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	EditarLivroForm^ editarLivroForm = gcnew EditarLivroForm();
	editarLivroForm->ShowDialog();
}

private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	ExcluirAlunoForm^ excluirAlunoForm = gcnew ExcluirAlunoForm();
	excluirAlunoForm->ShowDialog();
}

private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	ExcluirLivroForm^ excluirLivroForm = gcnew ExcluirLivroForm();
	excluirLivroForm->ShowDialog();
}

private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	EmprestimoForm^ emprestimoForm = gcnew EmprestimoForm();
	emprestimoForm->ShowDialog();
}
};
}
