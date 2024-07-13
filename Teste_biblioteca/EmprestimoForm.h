#pragma once

namespace Testebiblioteca {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Sumário para EmprestimoForm
	/// </summary>
	public ref class EmprestimoForm : public System::Windows::Forms::Form
	{
	public:
		EmprestimoForm(void)
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
		~EmprestimoForm()
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
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			this->button1->Click += gcnew System::EventHandler(this, &EmprestimoForm::button1_Click);

			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(234, 189);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(225, 13);
			this->label5->TabIndex = 31;
			this->label5->Text = L"Insira o nome do Aluno a realizar o emprestimo";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(232, 221);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(282, 20);
			this->textBox4->TabIndex = 30;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(322, 139);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(107, 13);
			this->label4->TabIndex = 29;
			this->label4->Text = L"Emprestimo de Livros";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(227, 330);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(282, 23);
			this->button1->TabIndex = 28;
			this->button1->Text = L"Realizar Emprestimo";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &EmprestimoForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(229, 258);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(200, 13);
			this->label1->TabIndex = 33;
			this->label1->Text = L"Insira o Titulo do Livro para o emprestimo";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(227, 290);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(282, 20);
			this->textBox1->TabIndex = 32;
			// 
			// EmprestimoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(732, 536);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Name = L"EmprestimoForm";
			this->Text = L"EmprestimoForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ nomeAluno = textBox4->Text;
		String^ tituloLivro = textBox1->Text;

		// Verificar se o aluno está cadastrado
		bool alunoCadastrado = false;
		array<String^>^ linhasAlunos = System::IO::File::ReadAllLines("alunos.txt");
		for each (String ^ linha in linhasAlunos) {
			if (linha->Contains(nomeAluno)) {
				alunoCadastrado = true;
				break;
			}
		}

		// Verificar se o livro já foi emprestado (independentemente do aluno)
		bool livroJaEmprestado = false;
		array<String^>^ linhasEmprestimos = System::IO::File::ReadAllLines("emprestimos.txt");
		for each (String ^ linha in linhasEmprestimos) {
			if (linha->Contains(tituloLivro)) {
				livroJaEmprestado = true;
				break;
			}
		}

		// Verificar se o livro existe
		bool livroExiste = false;
		array<String^>^ linhasLivros = System::IO::File::ReadAllLines("livros.txt");
		for (int i = 1; i < linhasLivros->Length; i += 4) { // Assume que cada livro tem 4 linhas e começa do título
			if (linhasLivros[i]->Equals(tituloLivro)) {
				livroExiste = true;
				break;
			}
		}

		// Realizar o empréstimo se o aluno estiver cadastrado, o livro existir e não tiver sido emprestado
		if (alunoCadastrado && livroExiste && !livroJaEmprestado) {
			String^ emprestimo = nomeAluno + " emprestou o livro " + tituloLivro;
			System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter("emprestimos.txt", true);
			sw->WriteLine(emprestimo);
			sw->Close();
			MessageBox::Show("Empréstimo realizado com sucesso!");
		}
		else {
			if (!alunoCadastrado) {
				MessageBox::Show("Aluno não cadastrado.");
			}
			else if (!livroExiste) {
				MessageBox::Show("Livro não existe.");
			}
			else if (livroJaEmprestado) {
				MessageBox::Show("Livro já foi emprestado.");
			}
		}
	}


};
}
