#pragma once

namespace Testebiblioteca {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Windows::Forms;

	/// <summary>
	/// Sumário para CadastroAlunoForm
	/// </summary>
	public ref class CadastroAlunoForm : public System::Windows::Forms::Form
	{
	public:
		CadastroAlunoForm(void)
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
		~CadastroAlunoForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(217, 185);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(80, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nome do Aluno";
			this->label1->Click += gcnew System::EventHandler(this, &CadastroAlunoForm::label1_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(220, 408);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(282, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Cadastrar Aluno";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &CadastroAlunoForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(220, 212);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(282, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &CadastroAlunoForm::textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(217, 253);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(95, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Matricula do Aluno";
			this->label2->Click += gcnew System::EventHandler(this, &CadastroAlunoForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(217, 334);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Senha do Aluno";
			this->label3->Click += gcnew System::EventHandler(this, &CadastroAlunoForm::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(322, 120);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(94, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Cadastro de Aluno";
			this->label4->Click += gcnew System::EventHandler(this, &CadastroAlunoForm::label4_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(220, 284);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(282, 20);
			this->textBox2->TabIndex = 6;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &CadastroAlunoForm::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(220, 360);
			this->textBox3->Name = L"textBox3";
			this->textBox3->PasswordChar = '*';
			this->textBox3->Size = System::Drawing::Size(282, 20);
			this->textBox3->TabIndex = 7;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &CadastroAlunoForm::textBox3_TextChanged);
			// 
			// CadastroAlunoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(733, 579);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"CadastroAlunoForm";
			this->Text = L"Cadastro de Alunos";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
	  private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		  // Obter os valores dos campos de texto
		  String^ nomeAluno = textBox1->Text;
		  String^ matriculaAluno = textBox2->Text;
		  String^ senhaAluno = textBox3->Text;

		  // Caminho do arquivo onde os dados serão salvos
		  String^ caminhoArquivo = "alunos.txt";

		  // Criar um StreamWriter para adicionar informações ao arquivo
		  // O segundo parâmetro é true para anexar dados ao arquivo existente
		  // Se o arquivo não existir, ele será criado
		  try
		  {
			  StreamWriter^ sw = gcnew StreamWriter(caminhoArquivo, true);
			  // Adiciona uma quebra de linha ao final de cada registro de aluno
			  sw->WriteLine(nomeAluno + " " + senhaAluno + " " + matriculaAluno);
			  sw->Close();
			  MessageBox::Show("Aluno cadastrado com sucesso!");
		  }
		  catch (Exception^ e)
		  {
			  MessageBox::Show("Erro ao salvar o arquivo: " + e->Message);
		  }
	  }



};
}
