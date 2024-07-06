#include "devolver.hpp"
#include <fstream>
#include <sstream>

// Constructor
Devolver::Devolver(Emprestimo& emprestimo) : emprestimo(emprestimo) {
    // No setup needed in this case
}

// realizarDevolucao method
void Devolver::realizarDevolucao() {
    std::ifstream arquivo("emprestimos.txt");
    std::ofstream temp("temp.txt");
    std::string linha;
    bool livroEncontrado = false;

    while (std::getline(arquivo, linha)) {
        std::stringstream ss(linha);
        std::string idLivro, titulo, autor, ano, nomeUsuario, numeroMatricula, dataEmprestimo;
        std::getline(ss, idLivro, ',');  // ID do livro
        std::getline(ss, titulo, ',');   // Título do livro (ignorado)
        std::getline(ss, autor, ',');    // Autor do livro (ignorado)
        std::getline(ss, ano, ',');      // Ano do livro (ignorado)
        std::getline(ss, nomeUsuario, ','); // Nome de usuário do aluno
        std::getline(ss, numeroMatricula, ','); // Número de matrícula (ignorado)
        std::getline(ss, dataEmprestimo); // Data de empréstimo (ignorada)

        // Verifica se a linha corresponde ao livro e ao aluno
        if (std::stoi(idLivro) == emprestimo.getLivro().getId() && nomeUsuario == emprestimo.getAluno().getNomeDeUsuario()) {
            livroEncontrado = true; // Livro emprestado pelo aluno encontrado
        }
        else {
            temp << linha << "\n"; // Copia a linha para o arquivo temporário se não for o livro a ser devolvido
        }
    }

    // Fechar os arquivos
    arquivo.close();
    temp.close();

    if (livroEncontrado) {
        // Deletar o arquivo original e renomear o arquivo temporário
        remove("emprestimos.txt");
        rename("temp.txt", "emprestimos.txt");
        std::cout << "Livro devolvido com sucesso." << std::endl;
    }
    else {
        std::cerr << "Erro: Livro não está emprestado por este aluno." << std::endl;
        // Deleta o arquivo temporário, pois a devolução não foi realizada
        remove("temp.txt");
    }
}