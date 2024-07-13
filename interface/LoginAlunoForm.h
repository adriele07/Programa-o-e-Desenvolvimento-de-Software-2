#pragma once
#include "MenuAlunoForm.h"
namespace Testebiblioteca {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Sumário para LoginAlunoForm
	/// </summary>
	public ref class LoginAlunoForm : public System::Windows::Forms::Form
	{
	public:
		LoginAlunoForm(void)
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
		~LoginAlunoForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnloginaluno;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnloginaluno = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(236, 231);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(230, 20);
			this->textBox1->TabIndex = 0;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(236, 317);
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(230, 20);
			this->textBox2->TabIndex = 1;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &LoginAlunoForm::textBox2_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(233, 203);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(43, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Usuario";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(233, 285);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(38, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Senha";
			// 
			// btnloginaluno
			// 
			this->btnloginaluno->Location = System::Drawing::Point(294, 375);
			this->btnloginaluno->Name = L"btnloginaluno";
			this->btnloginaluno->Size = System::Drawing::Size(112, 50);
			this->btnloginaluno->TabIndex = 4;
			this->btnloginaluno->Text = L"Login Aluno";
			this->btnloginaluno->UseVisualStyleBackColor = true;
			this->btnloginaluno->Click += gcnew System::EventHandler(this, &LoginAlunoForm::btnloginaluno_Click);
			// 
			// LoginAlunoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(737, 624);
			this->Controls->Add(this->btnloginaluno);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"LoginAlunoForm";
			this->Text = L"LoginAlunoForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnloginaluno_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ nomeAluno = textBox1->Text;
		String^ senha = textBox2->Text;
		bool autenticado = false;

		StreamReader^ sr = File::OpenText("alunos.txt");
		String^ linha;
		while ((linha = sr->ReadLine()) != nullptr) {
			array<String^>^ partes = linha->Split(' ');
			if (partes->Length == 3) {
				String^ nomeArquivo = partes[0];
				String^ senhaArquivo = partes[1];
				if (nomeArquivo->Equals(nomeAluno) && senhaArquivo->Equals(senha)) {
					autenticado = true;
					break;
				}
			}
		}
		sr->Close();

		if (autenticado) {
			MessageBox::Show("Autenticação bem-sucedida!", "Sucesso", MessageBoxButtons::OK, MessageBoxIcon::Information);

			// Cria uma nova instância de MenuAlunoForm e a exibe
			MenuAlunoForm^ menuForm = gcnew MenuAlunoForm();
			this->Hide(); // Esconde o formulário de login
			menuForm->ShowDialog(); // Mostra o MenuAlunoForm como uma caixa de diálogo modal
			this->Close(); // Fecha o formulário de login após retornar do MenuAlunoForm
		}
		else {
			MessageBox::Show("Nome do aluno ou senha incorretos!", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}



};
}
