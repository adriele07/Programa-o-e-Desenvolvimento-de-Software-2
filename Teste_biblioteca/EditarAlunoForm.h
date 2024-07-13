#pragma once

namespace Testebiblioteca {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Sumário para EditarAlunoForm
	/// </summary>
	public ref class EditarAlunoForm : public System::Windows::Forms::Form
	{
	public:
		EditarAlunoForm(void)
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
		~EditarAlunoForm()
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
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label5;

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
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			this->button1->Click += gcnew System::EventHandler(this, &EditarAlunoForm::button1_Click);

			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(220, 401);
			this->textBox3->Name = L"textBox3";
			this->textBox3->PasswordChar = '*';
			this->textBox3->Size = System::Drawing::Size(282, 20);
			this->textBox3->TabIndex = 15;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(220, 325);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(282, 20);
			this->textBox2->TabIndex = 14;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(323, 115);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(64, 13);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Editar Aluno";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(217, 375);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(112, 13);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Nova Senha do Aluno";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(217, 294);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(124, 13);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Nova Matricula do Aluno";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(220, 253);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(282, 20);
			this->textBox1->TabIndex = 10;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(220, 449);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(282, 23);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Editar  Aluno";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(217, 226);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(107, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Novo nome do Aluno";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(220, 192);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(282, 20);
			this->textBox4->TabIndex = 16;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &EditarAlunoForm::textBox4_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(222, 160);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(180, 13);
			this->label5->TabIndex = 17;
			this->label5->Text = L"Insira o nome do Aluno a ser Editado";
			this->label5->Click += gcnew System::EventHandler(this, &EditarAlunoForm::label5_Click);
			// 
			// EditarAlunoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(737, 582);
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
			this->Name = L"EditarAlunoForm";
			this->Text = L"Edição de Alunos";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
	   private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		   String^ nomeAlunoEditar = textBox4->Text->Trim();
		   String^ novoNome = textBox1->Text->Trim();
		   String^ novaMatricula = textBox2->Text->Trim();
		   String^ novaSenha = textBox3->Text->Trim();

		   // Caminho do arquivo onde os dados dos alunos estão salvos
		   String^ caminhoArquivo = "alunos.txt";

		   // Verifica se o arquivo existe
		   if (!System::IO::File::Exists(caminhoArquivo)) {
			   MessageBox::Show("O arquivo de alunos não existe.");
			   return;
		   }

		   // Lê todas as linhas do arquivo
		   array<String^>^ linhas = System::IO::File::ReadAllLines(caminhoArquivo);
		   bool alunoEncontrado = false;

		   for (int i = 0; i < linhas->Length; i++) {
			   array<String^>^ partes = linhas[i]->Split(' ');
			   if (partes->Length >= 3 && partes[0]->Trim() == nomeAlunoEditar) {
				   alunoEncontrado = true;
				   // Atualiza as informações do aluno
				   linhas[i] = String::Format("{0} {1} {2}", (novoNome != "" ? novoNome : partes[0]), (novaSenha != "" ? novaSenha : partes[1]), (novaMatricula != "" ? novaMatricula : partes[2]));
				   break;
			   }
		   }

		   if (alunoEncontrado) {
			   // Escreve todas as linhas de volta para o arquivo, incluindo as alterações
			   System::IO::File::WriteAllLines(caminhoArquivo, linhas);
			   MessageBox::Show("Informações do aluno atualizadas com sucesso!");
		   }
		   else {
			   MessageBox::Show("Aluno não encontrado.");
		   }
	   }

};
}
