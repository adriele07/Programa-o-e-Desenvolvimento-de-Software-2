#include "Library.hpp"
#include <algorithm>
#include <stdexcept>

void Library::adicionarLivro(std::unique_ptr<Book> livro) {
    if (!livro) {
        throw std::invalid_argument("Livro não pode ser nulo");
    }
    livros.push_back(std::move(livro));
}

void Library::adicionarAluno(std::unique_ptr<Student> aluno) {
    if (!aluno) {
        throw std::invalid_argument("Aluno não pode ser nulo");
    }
    alunos.push_back(std::move(aluno));
}

Book* Library::encontrarLivro(const std::string& titulo) const {
    for (const auto& livro : livros) {
        if (livro->getTitulo() == titulo) {
            return livro.get();
        }
    }
    return nullptr;
}

Student* Library::encontrarAluno(int id) const {
    for (const auto& aluno : alunos) {
        if (aluno->getId() == id) {
            return aluno.get();
        }
    }
    return nullptr;
}

void Library::emprestarLivro(int idAluno, const std::string& tituloLivro) {
    Book* livro = encontrarLivro(tituloLivro);
    Student* aluno = encontrarAluno(idAluno);

    if (livro && aluno && !livro->estaEmprestado()) {
        livro->emprestar();
        aluno->emprestarLivro(livro->getId());
        historicoEmprestimos[idAluno].push_back(livro->getId());
    } else {
        throw std::runtime_error("Erro ao emprestar livro: livro pode não existir, aluno pode não existir ou livro já pode estar emprestado");
    }
}

void Library::devolverLivro(int idAluno, const std::string& tituloLivro) {
    Book* livro = encontrarLivro(tituloLivro);
    Student* aluno = encontrarAluno(idAluno);

    if (livro && aluno && livro->estaEmprestado()) {
        livro->devolver();
        aluno->devolverLivro(livro->getId());
    } else {
        throw std::runtime_error("Erro ao devolver livro: livro pode não existir, aluno pode não existir ou livro pode não estar emprestado");
    }
}

std::vector<std::string> Library::listarLivros() const {
    std::vector<std::string> titulosLivros;
    for (const auto& livro : livros) {
        titulosLivros.push_back(livro->getTitulo());
    }
    return titulosLivros;
}

std::vector<std::string> Library::listarAlunos() const {
    std::vector<std::string> nomesAlunos;
    for (const auto& aluno : alunos) {
        nomesAlunos.push_back(aluno->getNome());
    }
    return nomesAlunos;
}

bool Library::livroEstaDisponivel(const std::string& titulo) const {
    Book* livro = encontrarLivro(titulo);
    return livro && !livro->estaEmprestado();
}

bool Library::alunoEstaCadastrado(int id) const {
    return encontrarAluno(id) != nullptr;
}

std::vector<int> Library::getHistoricoEmprestimosAluno(int idAluno) const {
    auto it = historicoEmprestimos.find(idAluno);
    if (it != historicoEmprestimos.end()) {
        return it->second;
    }
    return {};
}

std::vector<int> Library::getLivrosEmprestadosAluno(int idAluno) const {
    Student* aluno = encontrarAluno(idAluno);
    if (aluno) {
        return aluno->getLivrosEmprestados();
    }
    return {};
}

std::vector<int> Library::getAlunosQuePegaramLivro(const std::string& tituloLivro) const {
    std::vector<int> alunosQuePegaram;
    for (const auto& [idAluno, idsLivros] : historicoEmprestimos) {
        if (std::find(idsLivros.begin(), idsLivros.end(), encontrarLivro(tituloLivro)->getId()) != idsLivros.end()) {
            alunosQuePegaram.push_back(idAluno);
        }
    }
    return alunosQuePegaram;
}
