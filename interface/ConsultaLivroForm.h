#pragma once

namespace Testebiblioteca {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Sumário para ConsultaLivroForm
	/// </summary>
	public ref class ConsultaLivroForm : public System::Windows::Forms::Form
	{
	public:
		ConsultaLivroForm(void)
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
		~ConsultaLivroForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ buttonBuscar; // Declaração do botão buttonBuscar

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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(247, 257);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(226, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Digite o titulo do livro que voce quer consultar:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(250, 284);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(223, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &ConsultaLivroForm::textBox1_TextChanged);
			// 
			// ConsultaLivroForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(735, 601);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Name = L"ConsultaLivroForm";
			this->Text = L"Consulta de Livro";
			this->Load += gcnew System::EventHandler(this, &ConsultaLivroForm::ConsultaLivroForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();
			this->buttonBuscar = (gcnew System::Windows::Forms::Button());
			this->buttonBuscar->Location = System::Drawing::Point(250, 310); // Ajuste conforme necessário
			this->buttonBuscar->Name = L"buttonBuscar";
			this->buttonBuscar->Size = System::Drawing::Size(75, 23);
			this->buttonBuscar->TabIndex = 3;
			this->buttonBuscar->Text = L"Buscar";
			this->buttonBuscar->UseVisualStyleBackColor = true;
			this->buttonBuscar->Click += gcnew System::EventHandler(this, &ConsultaLivroForm::buttonBuscar_Click);
			this->Controls->Add(this->buttonBuscar);

		}
#pragma endregion
	private: System::Void ConsultaLivroForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void buttonBuscar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ tituloProcurado = textBox1->Text->ToLower();
		array<String^>^ linhas = System::IO::File::ReadAllLines("livros.txt");
		bool livroEncontrado = false;

		for (int i = 1; i < linhas->Length; i += 4) { // Assume que cada livro tem 4 linhas e começa a busca pelo título
			if (linhas[i]->ToLower()->Contains(tituloProcurado)) {
				livroEncontrado = true;
				String^ resultado = "ID: " + linhas[i - 1] + "\nTítulo: " + linhas[i] + "\nAutor: " + linhas[i + 1] + "\nAno: " + linhas[i + 2];
				MessageBox::Show(resultado, "Livro Encontrado");
				break; // Remove este break se quiser buscar por múltiplos livros com títulos similares
			}
		}

		if (!livroEncontrado) {
			MessageBox::Show("Livro não encontrado.");
		}
	}

	};
}
