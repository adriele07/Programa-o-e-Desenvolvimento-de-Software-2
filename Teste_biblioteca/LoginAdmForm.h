#pragma once
#include "MenuAdmForm.h" // Inclua isso aqui
// Inclua o namespace necessário para StreamReader e File
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO; // Incluído para corrigir o erro com StreamReader e File

namespace Testebiblioteca {

	public ref class LoginAdmForm : public System::Windows::Forms::Form
	{
	public:
		LoginAdmForm(void)
		{
			InitializeComponent();
			// Adicione o manipulador de eventos aqui, dentro do construtor
			this->btnloginadministrador->Click += gcnew System::EventHandler(this, &LoginAdmForm::btnloginadministrador_Click);
		}

	protected:
		~LoginAdmForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnloginadministrador;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;

		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necessário para suporte ao Designer - não modifique 
		/// o conteúdo deste método com o editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnloginadministrador = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// btnloginadministrador
			// 
			this->btnloginadministrador->Location = System::Drawing::Point(311, 361);
			this->btnloginadministrador->Name = L"btnloginadministrador";
			this->btnloginadministrador->Size = System::Drawing::Size(112, 50);
			this->btnloginadministrador->TabIndex = 9;
			this->btnloginadministrador->Text = L"Login Administrador";
			this->btnloginadministrador->UseVisualStyleBackColor = true;
			this->btnloginadministrador->Click += gcnew System::EventHandler(this, &LoginAdmForm::btnloginadministrador_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(250, 271);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(38, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Senha";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(250, 189);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(43, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Usuario";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(253, 303);
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(230, 20);
			this->textBox2->TabIndex = 6;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(253, 217);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(230, 20);
			this->textBox1->TabIndex = 5;
			// 
			// LoginAdmForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(733, 600);
			this->Controls->Add(this->btnloginadministrador);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"LoginAdmForm";
			this->Text = L"LoginAdmForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	
#pragma endregion
	private: System::Void btnloginadministrador_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ usuario = textBox1->Text;
		String^ senha = textBox2->Text;
		bool autenticado = false;

		// Lendo o arquivo de administradores
		StreamReader^ sr = File::OpenText("administradores.txt");
		String^ linha;
		while ((linha = sr->ReadLine()) != nullptr) {
			array<String^>^ partes = linha->Split(' ');
			if (partes->Length == 2) {
				String^ usuarioArquivo = partes[0];
				String^ senhaArquivo = partes[1];
				if (usuarioArquivo->Equals(usuario) && senhaArquivo->Equals(senha)) {
					autenticado = true;
					break;
				}
			}
		}
		sr->Close();

		if (autenticado) {
			MessageBox::Show("Autenticação bem-sucedida!", "Sucesso", MessageBoxButtons::OK, MessageBoxIcon::Information);

			// Cria uma instância do MenuAdmForm
			Testebiblioteca::MenuAdmForm^ menuForm = gcnew Testebiblioteca::MenuAdmForm();
			this->Hide(); // Esconde o formulário de login
			menuForm->ShowDialog(); // Exibe o MenuAdmForm como uma caixa de diálogo
			this->Show(); // Opcional: Mostra novamente o formulário de login após fechar o MenuAdmForm
		}
		else {
			MessageBox::Show("Usuário ou senha incorretos!", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

	}

};
}
