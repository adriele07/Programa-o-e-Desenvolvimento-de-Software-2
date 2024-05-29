#pragma once
#include <vector>
#include <memory>
#include <string>
#include <unordered_map>
#include "Livro.hpp"
#include "Aluno.hpp"

class Biblioteca {
private:
    std::vector<std::unique_ptr<Livro>> livros;
    std::vector<std::unique_ptr<Aluno>> Alunos;
    std::unordered_map<int, std::vector<int>> historicoEmprestimos;

public:
    void adicionarLivro(std::unique_ptr<Livro> livro);
    void adicionarAluno(std::unique_ptr<Aluno> Aluno);

    Livro* encontrarLivro(const std::string& titulo) const;
    Aluno* encontrarAluno(int id) const;

    void emprestarLivro(int idAluno, const std::string& tituloLivro);
    void devolverLivro(int idAluno, const std::string& tituloLivro);

    std::vector<std::string> listarLivros() const;
    std::vector<std::string> listarAlunos() const;

    bool livroDisponivel(const std::string& titulo) const;
    bool AlunoRegistrado(int id) const;
    std::vector<int> obterHistoricoEmprestimosAluno(int idAluno) const;
    std::vector<int> obterLivrosEmprestadosAluno(int idAluno) const;
    std::vector<int> obterEmprestadoresLivro(const std::string& tituloLivro) const;
};
