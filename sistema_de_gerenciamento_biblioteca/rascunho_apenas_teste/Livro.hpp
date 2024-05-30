#pragma once
#include <string>
#include <chrono>
#include <ctime>

class Livro {
private:
    int id;
    std::string titulo;
    std::string autor;
    bool emprestado;
    std::chrono::system_clock::time_point dataEmprestimo;

public:
    Livro(int id, const std::string& titulo, const std::string& autor);

    int getId() const;
    std::string getTitulo() const;
    void setTitulo(const std::string& titulo);

    std::string getAutor() const;
    void setAutor(const std::string& autor);

    bool estaEmprestado() const;
    void emprestar();
    void devolver();

    std::chrono::system_clock::time_point getDataEmprestimo() const;
};
