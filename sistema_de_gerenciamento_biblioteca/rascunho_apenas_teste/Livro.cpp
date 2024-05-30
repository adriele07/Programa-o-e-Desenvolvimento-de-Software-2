#include "Livro.hpp"
#include <stdexcept>

Livro::Livro(int id, const std::string& titulo, const std::string& autor) 
    : id(id), titulo(titulo), autor(autor), emprestado(false), dataEmprestimo(std::chrono::system_clock::now()) {}

int Livro::getId() const {
    return id;
}

std::string Livro::getTitulo() const {
    return titulo;
}

void Livro::setTitulo(const std::string& titulo) {
    this->titulo = titulo;
}

std::string Livro::getAutor() const {
    return autor;
}

void Livro::setAutor(const std::string& autor) {
    this->autor = autor;
}

bool Livro::estaEmprestado() const {
    return emprestado;
}

void Livro::emprestar() {
    if (!emprestado) {
        emprestado = true;
        dataEmprestimo = std::chrono::system_clock::now();
    } else {
        throw std::runtime_error("Livro já está emprestado");
    }
}

void Livro::devolver() {
    if (emprestado) {
        emprestado = false;
    } else {
        throw std::runtime_error("Livro não foi emprestado");
    }
}

std::chrono::system_clock::time_point Livro::getDataEmprestimo() const {
    return dataEmprestimo;
}
