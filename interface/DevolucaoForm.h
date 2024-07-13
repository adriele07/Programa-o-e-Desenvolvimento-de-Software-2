#pragma once

namespace Testebiblioteca {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Collections::Generic;
	/// <summary>
	/// Sumário para DevolucaoForm
	/// </summary>
	public ref class DevolucaoForm : public System::Windows::Forms::Form
	{
	public:
		DevolucaoForm(void)
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
		~DevolucaoForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label5;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			this->button1->Click += gcnew System::EventHandler(this, &DevolucaoForm::button1_Click);

			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(225, 279);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(186, 13);
			this->label1->TabIndex = 39;
			this->label1->Text = L"Insira o Titulo do Livro a ser devolvido";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(223, 311);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(282, 20);
			this->textBox1->TabIndex = 38;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(230, 210);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(224, 13);
			this->label5->TabIndex = 37;
			this->label5->Text = L"Insira o nome do Aluno a realizar a Devolução";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(228, 242);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(282, 20);
			this->textBox4->TabIndex = 36;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &DevolucaoForm::textBox4_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(318, 160);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(105, 13);
			this->label4->TabIndex = 35;
			this->label4->Text = L"Devolução de Livros";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(223, 351);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(282, 23);
			this->button1->TabIndex = 34;
			this->button1->Text = L"Realizar Devolução";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// DevolucaoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(733, 535);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Name = L"DevolucaoForm";
			this->Text = L"DevolucaoForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
		   private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			   String^ nomeAluno = textBox4->Text;
			   String^ tituloLivro = textBox1->Text;
			   String^ emprestimoParaDevolucao = nomeAluno + " emprestou o livro " + tituloLivro;

			   // Corrigido para usar System::Collections::Generic::List<T>
			   List<String^>^ linhasAtualizadas = gcnew List<String^>();
			   bool emprestimoEncontrado = false;

			   array<String^>^ linhasEmprestimos = System::IO::File::ReadAllLines("emprestimos.txt");
			   for each (String ^ linha in linhasEmprestimos) {
				   if (linha->Equals(emprestimoParaDevolucao)) {
					   emprestimoEncontrado = true;
				   }
				   else {
					   linhasAtualizadas->Add(linha); // Corrigido para usar Add em vez de push_back
				   }
			   }

			   if (emprestimoEncontrado) {
				   // Corrigido para converter List<T> para array antes de chamar WriteAllLines
				   array<String^>^ linhasParaSalvar = linhasAtualizadas->ToArray();
				   System::IO::File::WriteAllLines("emprestimos.txt", linhasParaSalvar);
				   System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter("devolucao.txt", true);
				   sw->WriteLine(nomeAluno + " devolveu o livro " + tituloLivro);
				   sw->Close();
				   MessageBox::Show("Devolução realizada com sucesso!");
			   }
			   else {
				   MessageBox::Show("Empréstimo não encontrado.");
			   }
		   }
};
}
