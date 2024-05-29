#include <iostream>
#include <memory>
#include "Livro.hpp"
#include "Aluno.hpp"
#include "Biblioteca.hpp"

int main() {
    // Cria uma instância da biblioteca
    Biblioteca biblioteca;

    // Adiciona livros à biblioteca
    biblioteca.adicionarLivro(std::unique_ptr<Livro>(new Livro(1, "O Grande Gatsby", "F. Scott Fitzgerald")));
    biblioteca.adicionarLivro(std::unique_ptr<Livro>(new Livro(2, "1984", "George Orwell")));
    biblioteca.adicionarLivro(std::unique_ptr<Livro>(new Livro(3, "O Sol é para Todos", "Harper Lee")));

    // Adiciona alunos à biblioteca
    biblioteca.adicionarAluno(std::unique_ptr<Aluno>(new Aluno("Alice", 1)));
    biblioteca.adicionarAluno(std::unique_ptr<Aluno>(new Aluno("Bob", 2)));

    // Lista os livros na biblioteca
    std::cout << "Livros na biblioteca:\n";
    for (const auto& titulo : biblioteca.listarLivros()) {
        std::cout << " - " << titulo << "\n";
    }

    // Lista os alunos na biblioteca
    std::cout << "Alunos na biblioteca:\n";
    for (const auto& nome : biblioteca.listarAlunos()) {
        std::cout << " - " << nome << "\n";
    }

    // Empresta um livro
    try {
        biblioteca.emprestarLivro(1, "1984");
        std::cout << "Alice emprestou '1984'\n";
    } catch (const std::runtime_error& e) {
        std::cerr << "Erro: " << e.what() << "\n";
    }

    // Verifica a disponibilidade do livro
    std::cout << "'1984' está " << (biblioteca.livroDisponivel("1984") ? "disponível" : "indisponível") << "\n";

    // Devolve um livro
    try {
        biblioteca.devolverLivro(1, "1984");
        std::cout << "Alice devolveu '1984'\n";
    } catch (const std::runtime_error& e) {
        std::cerr << "Erro: " << e.what() << "\n";
    }

    // Verifica a disponibilidade do livro novamente
    std::cout << "'1984' está " << (biblioteca.livroDisponivel("1984") ? "disponível" : "indisponível") << "\n";

    return 0;
}