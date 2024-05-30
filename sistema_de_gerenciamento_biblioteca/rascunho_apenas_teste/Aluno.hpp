#pragma once
#include <string>
#include <vector>
#include <algorithm>

class Aluno {
private:
    int id;
    std::string nome;
    std::vector<int> idsLivrosEmprestados;

public:
    Aluno(const std::string& nome, int id);

    std::string getNome() const;
    void setNome(const std::string& nome);

    int getId() const;
    void setId(int id);

    void emprestarLivro(int idLivro);
    void devolverLivro(int idLivro);
    std::vector<int> getLivrosEmprestados() const;
};
