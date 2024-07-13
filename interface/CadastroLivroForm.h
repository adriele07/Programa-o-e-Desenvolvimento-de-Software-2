#pragma once
using namespace System::IO;

namespace Testebiblioteca {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Sumário para CadastroLivroForm
	/// </summary>
	public ref class CadastroLivroForm : public System::Windows::Forms::Form
	{
	public:
		CadastroLivroForm(void)
		{
			InitializeComponent();
			//
			//TODO: Adicione o código do construtor aqui
			//
			InicializarProximoId();
		}

	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~CadastroLivroForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ textBox3;
	protected:
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;

		   // Adicione esta variável membro na declaração da classe CadastroLivroForm
	private: int livroId;

	private:
		/// <summary>
		/// Variável de designer necessária.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necessário para suporte ao Designer - não modifique 
		/// o conteúdo deste método com o editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1->Click += gcnew System::EventHandler(this, &CadastroLivroForm::button1_Click);

			this->SuspendLayout();
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(229, 375);
			this->textBox3->Name = L"textBox3";
			this->textBox3->PasswordChar = '*';
			this->textBox3->Size = System::Drawing::Size(282, 20);
			this->textBox3->TabIndex = 15;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(229, 299);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(282, 20);
			this->textBox2->TabIndex = 14;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(331, 135);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(96, 13);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Cadastro de LIvros";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(226, 349);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(67, 13);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Ano do Livro";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(226, 268);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 13);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Autor do Livro";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(229, 227);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(282, 20);
			this->textBox1->TabIndex = 10;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &CadastroLivroForm::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(229, 423);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(282, 23);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Cadastrar Livro";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(226, 200);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Titulo do Livro";
			// 
			// CadastroLivroForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(737, 580);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"CadastroLivroForm";
			this->Text = L"CadastroLivroForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
		   // Adicione esta variável membro na declaração da classe CadastroLivroForm
		  
	void InicializarProximoId()
	{
		// Tenta abrir o arquivo livros.txt para leitura
		if (File::Exists("livros.txt"))
		{
			array<String^>^ linhas = File::ReadAllLines("livros.txt");
			int maiorId = 0;
			for (int i = 0; i < linhas->Length; i += 4) // Assume que cada livro tem 4 linhas
			{
				int idAtual = Int32::Parse(linhas[i]);
				if (idAtual > maiorId)
				{
					maiorId = idAtual;
				}
			}
			livroId = maiorId + 1; // Configura o próximo ID disponível
		}
		else
		{
			livroId = 1; // Se o arquivo não existir, começa do ID 1
		}
	}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	// Abre o arquivo livros.txt em modo de adição (append)
	System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter("livros.txt", true);

	// Lê os valores dos campos de texto
	String^ titulo = textBox1->Text;
	String^ autor = textBox2->Text;
	String^ ano = textBox3->Text;

	// Escreve as informações no arquivo, seguindo o formato especificado
	sw->WriteLine(livroId.ToString());
	sw->WriteLine(titulo);
	sw->WriteLine(autor);
	sw->WriteLine(ano);

	// Incrementa o ID do livro para o próximo uso
	livroId++;

	// Fecha o arquivo
	sw->Close();

	// Opcional: Limpa os campos de texto após salvar
	textBox1->Clear();
	textBox2->Clear();
	textBox3->Clear();

	// Opcional: Mostra uma mensagem indicando sucesso
	MessageBox::Show("Livro cadastrado com sucesso!");
}

};
}
