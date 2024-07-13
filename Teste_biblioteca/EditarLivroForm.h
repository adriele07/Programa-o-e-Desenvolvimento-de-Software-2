#pragma once

namespace Testebiblioteca {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	/// <summary>
	/// Sumário para EditarLivroForm
	/// </summary>
	public ref class EditarLivroForm : public System::Windows::Forms::Form
	{
	public:
		EditarLivroForm(void)
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
		~EditarLivroForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label5;
	protected:
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;

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
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(229, 147);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(157, 13);
			this->label5->TabIndex = 27;
			this->label5->Text = L"Insira o ID do livro a ser Editado";
			this->label5->Click += gcnew System::EventHandler(this, &EditarLivroForm::label5_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(227, 179);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(282, 20);
			this->textBox4->TabIndex = 26;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &EditarLivroForm::textBox4_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(227, 388);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(282, 20);
			this->textBox3->TabIndex = 25;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(227, 312);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(282, 20);
			this->textBox2->TabIndex = 24;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(330, 102);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(60, 13);
			this->label4->TabIndex = 23;
			this->label4->Text = L"Editar Livro";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(224, 362);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(92, 13);
			this->label3->TabIndex = 22;
			this->label3->Text = L"Novo Ano do livro";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(224, 281);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(102, 13);
			this->label2->TabIndex = 21;
			this->label2->Text = L"Novo Autor do Livro";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(227, 240);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(282, 20);
			this->textBox1->TabIndex = 20;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(227, 436);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(282, 23);
			this->button1->TabIndex = 19;
			this->button1->Text = L"Editar  Livro";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &EditarLivroForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(224, 213);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(103, 13);
			this->label1->TabIndex = 18;
			this->label1->Text = L"Novo Titulo do Livro";
			// 
			// EditarLivroForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(733, 560);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"EditarLivroForm";
			this->Text = L"EditarLivroForm";
			this->Load += gcnew System::EventHandler(this, &EditarLivroForm::EditarLivroForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void EditarLivroForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
	  private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		  String^ idLivroEditar = textBox4->Text->Trim();

		  if (!File::Exists("livros.txt")) {
			  MessageBox::Show("O arquivo de livros não existe.");
			  return;
		  }

		  array<String^>^ linhas = File::ReadAllLines("livros.txt");
		  bool livroEncontrado = false;
		  for (int i = 0; i < linhas->Length; i += 5) { // Assume que cada livro tem 5 linhas (ID, Título, Autor, Ano, Espaço em branco)
			  if (linhas[i]->Trim() == idLivroEditar) {
				  livroEncontrado = true;
				  linhas[i + 1] = textBox1->Text; // Atualiza o título
				  linhas[i + 2] = textBox2->Text; // Atualiza o autor
				  linhas[i + 3] = textBox3->Text; // Atualiza o ano

				  File::WriteAllLines("livros.txt", linhas);
				  MessageBox::Show("Livro editado com sucesso!");
				  break;
			  }
		  }

		  if (!livroEncontrado) {
			  MessageBox::Show("Livro não encontrado.");
		  }
	  }


private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
