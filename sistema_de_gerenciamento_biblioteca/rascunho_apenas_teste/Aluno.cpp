#include "Aluno.hpp"
#include <stdexcept>

Aluno::Aluno(const std::string& nome, int id) : nome(nome), id(id) {}

std::string Aluno::getNome() const {
    return nome;
}

void Aluno::setNome(const std::string& nome) {
    if (nome.empty()) {
        throw std::invalid_argument("O nome não pode estar vazio");
    }
    this->nome = nome;
}

int Aluno::getId() const {
    return id;
}

void Aluno::setId(int id) {
    if (id < 0) {
        throw std::invalid_argument("O ID não pode ser negativo");
    }
    this->id = id;
}

void Aluno::emprestarLivro(int idLivro) {
    idsLivrosEmprestados.push_back(idLivro);
}

void Aluno::devolverLivro(int idLivro) {
    idsLivrosEmprestados.erase(std::remove(idsLivrosEmprestados.begin(), idsLivrosEmprestados.end(), idLivro), idsLivrosEmprestados.end());
}

std::vector<int> Aluno::getLivrosEmprestados() const {
    return idsLivrosEmprestados;
}