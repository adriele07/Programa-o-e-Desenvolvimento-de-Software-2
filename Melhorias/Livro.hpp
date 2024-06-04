//Livro.hpp
#ifndef LIVRO_HPP
#define LIVRO_HPP

#include <string>

class Livro {
public:
    Livro(int id, const std::string& titulo, const std::string& autor, int ano)
        : id(id), titulo(titulo), autor(autor), ano(ano), emprestado(false) {}

    int getId() const { return id; }
    const std::string& getTitulo() const { return titulo; }
    const std::string& getAutor() const { return autor; }
    int getAno() const { return ano; }
    bool isEmprestado() const { return emprestado; }
    void emprestar() { emprestado = true; }
    void devolver() { emprestado = false; }

private:
    int id;
    std::string titulo;
    std::string autor;
    int ano;
    bool emprestado;
};

#endif // LIVRO_HPP