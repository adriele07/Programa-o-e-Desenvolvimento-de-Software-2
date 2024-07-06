//CadastroAdministrador.cpp
#include "CadastroAdministrador.hpp"
#include <fstream>

bool isAdministradorRegistrado(const std::vector<Administrador>& administradores, const std::string& nomeDeUsuario) {
    return std::find_if(administradores.begin(), administradores.end(), [&nomeDeUsuario](const Administrador& admin) {
        return admin.nomeDeUsuario == nomeDeUsuario;
        }) != administradores.end();
}



void salvarAdministradoresEmArquivo(const std::vector<Administrador>& administradores) {
    std::ofstream arquivo("administradores.txt");

    for (const auto& admin : administradores) {
        arquivo << admin.nomeDeUsuario << "\n" << admin.senha << "\n";
    }
}