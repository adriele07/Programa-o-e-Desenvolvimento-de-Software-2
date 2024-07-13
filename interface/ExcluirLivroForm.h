#pragma once

namespace Testebiblioteca {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Sumário para ExcluirLivroForm
	/// </summary>
	public ref class ExcluirLivroForm : public System::Windows::Forms::Form
	{
	public:
		ExcluirLivroForm(void)
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
		~ExcluirLivroForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label5;
	protected:
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button1;

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
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			this->button1->Click += gcnew System::EventHandler(this, &ExcluirLivroForm::button1_Click);

			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(231, 221);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(179, 13);
			this->label5->TabIndex = 27;
			this->label5->Text = L"Insira o nome do Livro a ser excluido";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(229, 253);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(282, 20);
			this->textBox4->TabIndex = 26;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &ExcluirLivroForm::textBox4_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(332, 176);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(64, 13);
			this->label4->TabIndex = 23;
			this->label4->Text = L"Excluir Livro";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(229, 299);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(282, 23);
			this->button1->TabIndex = 19;
			this->button1->Text = L"Excluir Livro";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// ExcluirLivroForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(736, 559);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Name = L"ExcluirLivroForm";
			this->Text = L"Exclusão de Livros";
			this->Load += gcnew System::EventHandler(this, &ExcluirLivroForm::ExcluirLivroForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ExcluirLivroForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
		   private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			   String^ nomeLivroParaExcluir = textBox4->Text;
			   if (System::IO::File::Exists("livros.txt")) {
				   array<String^>^ linhas = System::IO::File::ReadAllLines("livros.txt");
				   System::Collections::Generic::List<String^>^ novasLinhas = gcnew System::Collections::Generic::List<String^>();
				   bool livroEncontrado = false;

				   for (int i = 0; i < linhas->Length; i += 4) {
					   bool excluirLivroAtual = false;
					   if (String::Compare(linhas[i + 1]->Trim()->ToLower(), nomeLivroParaExcluir->Trim()->ToLower(), true) == 0) {
						   livroEncontrado = true;
						   excluirLivroAtual = true;
					   }
					   if (!excluirLivroAtual) {
						   // Adiciona as linhas do livro atual à lista de novas linhas
						   for (int j = 0; j < 4 && i + j < linhas->Length; j++) {
							   novasLinhas->Add(linhas[i + j]);
						   }
					   }
				   }





				   if (livroEncontrado) {
					   System::IO::File::WriteAllLines("livros.txt", novasLinhas->ToArray());
					   MessageBox::Show("Livro excluído com sucesso!");
				   }
				   else {
					   MessageBox::Show("Livro não encontrado.");
				   }
			   }
			   else {
				   MessageBox::Show("Arquivo de livros não existe.");
			   }
		   }


};
}
