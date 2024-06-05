// devolver.hpp
#ifndef DEVOLVER_HPP
#define DEVOLVER_HPP

#include "Emprestimo.hpp"
#include "Livro.hpp"
#include "CadastroAluno.hpp"

class Devolver {
public:
    Devolver(Emprestimo& emprestimo);
    void realizarDevolucao();
private:
    Emprestimo& emprestimo;
};

#endif // DEVOLVER_HPP