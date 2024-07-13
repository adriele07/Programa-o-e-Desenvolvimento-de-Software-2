#pragma once

namespace Testebiblioteca {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Sumário para ExcluirAlunoForm
	/// </summary>
	public ref class ExcluirAlunoForm : public System::Windows::Forms::Form
	{
	public:
		ExcluirAlunoForm(void)
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
		~ExcluirAlunoForm()
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
			this->button1->Click += gcnew System::EventHandler(this, &ExcluirAlunoForm::button1_Click);

			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(228, 251);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(183, 13);
			this->label5->TabIndex = 31;
			this->label5->Text = L"Insira o nome do Aluno a ser excluido";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(226, 283);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(282, 20);
			this->textBox4->TabIndex = 30;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(329, 206);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(68, 13);
			this->label4->TabIndex = 29;
			this->label4->Text = L"Excluir Aluno";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(226, 329);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(282, 23);
			this->button1->TabIndex = 28;
			this->button1->Text = L"Excluir Aluno";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ExcluirAlunoForm::button1_Click);
			// 
			// ExcluirAlunoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(735, 558);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Name = L"ExcluirAlunoForm";
			this->Text = L"ExcluirAlunoForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ nomeAlunoParaExcluir = textBox4->Text;
		String^ caminhoArquivo = "alunos.txt";
		array<String^>^ linhas = System::IO::File::ReadAllLines(caminhoArquivo);
		System::Collections::Generic::List<String^>^ novasLinhas = gcnew System::Collections::Generic::List<String^>();

		bool alunoEncontrado = false; // Variável para rastrear se o aluno foi encontrado

		for each (String ^ linha in linhas) {
			array<String^>^ partes = linha->Split(' ');
			if (partes[0] == nomeAlunoParaExcluir) {
				alunoEncontrado = true; // Aluno encontrado
			}
			else {
				novasLinhas->Add(linha); // Adiciona linha ao novo array se não for o aluno a ser excluído
			}
		}

		if (alunoEncontrado) {
			System::IO::File::WriteAllLines(caminhoArquivo, novasLinhas->ToArray());
			MessageBox::Show("Aluno excluído com sucesso!");
		}
		else {
			MessageBox::Show("Aluno não encontrado!");
		}
	}


	};
}
