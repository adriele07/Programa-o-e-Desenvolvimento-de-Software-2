//CadastroAdministrador.cpp
#include "CadastroAdministrador.hpp"
#include <fstream>

bool isAdministradorRegistrado(const std::vector<Administrador>& administradores, const std::string& nomeDeUsuario) {
    for (const auto& admin : administradores) {
        if (admin.nomeDeUsuario == nomeDeUsuario) {
            return true;
        }
    }
    return false;
}

void salvarAdministradoresEmArquivo(const std::vector<Administrador>& administradores) {
    std::ofstream arquivo("administradores.txt");

    for (const auto& admin : administradores) {
        arquivo << admin.nomeDeUsuario << "\n" << admin.senha << "\n";
    }
}