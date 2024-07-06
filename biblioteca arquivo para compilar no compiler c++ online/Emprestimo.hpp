//Emprestimo.hpp

#ifndef EMPRESTIMO_HPP
#define EMPRESTIMO_HPP

#include "Livro.hpp"
#include "CadastroAluno.hpp"
#include <string>

class Emprestimo {
public:
    Emprestimo(Livro& livro, Aluno& aluno, const std::string& dataEmprestimo);
    bool isLivroEmprestado();
    void realizarEmprestimo();
    Livro& getLivro();
    Aluno& getAluno(); // Adicione esta linha

private:
    Livro& livro;
    Aluno& aluno;
    std::string dataEmprestimo;
};

#endif

