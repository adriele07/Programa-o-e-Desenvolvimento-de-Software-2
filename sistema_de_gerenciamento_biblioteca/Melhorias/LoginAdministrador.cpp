//LoginAdministrador.cpp
#include "LoginAdministrador.hpp"
#include <algorithm> // Include this header for std::find_if

LoginAdministrador::LoginAdministrador(const std::vector<Administrador>& administradores) : administradores(administradores) {}

bool LoginAdministrador::autenticar(const std::string& nomeDeUsuario, const std::string& senha) {
    auto it = std::find_if(administradores.begin(), administradores.end(), [&](const Administrador& admin) {
        return admin.nomeDeUsuario == nomeDeUsuario && admin.senha == senha;
    });

    return it != administradores.end();
}
