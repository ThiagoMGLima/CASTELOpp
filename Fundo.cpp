#include "Fundo.h"

CASTELOpp::Parallax::Fundo::Fundo(const ID ID) :
    Ente(ID), posAnteriorCamera(pGerGrafico->getCamera().getCenter()),
    camadas()
{


}

CASTELOpp::Parallax::Fundo::~Fundo() {
    for (int i = 0; i < camadas.size(); i++) {
        Camada* camada = camadas.at(i);
        if (camada) {
            delete(camada);
            camada = nullptr;
        }
    }
    camadas.clear();
}

void CASTELOpp::Parallax::Fundo::Atualizar(double t) {
    sf::Vector2f posCamera = pGerGrafico->getCamera().getCenter();
    sf::Vector2f ds = posCamera - posAnteriorCamera;
    posAnteriorCamera = posCamera;
    if (ds.x != 0.0f) {
        ds.x *= 0.5f;
        for (int i = 0; i < camadas.size(); i++) {
            camadas.at(i)->atualizar(ds, posCamera);
        }
    }
    desenhar();
}

void CASTELOpp::Parallax::Fundo::desenhar() {
    for (int i = 0; i < camadas.size(); i++) {
        Camada* camada = camadas.at(i);
        camada->desenharCamada(pGerGrafico->getWindow());
    }
}

void CASTELOpp::Parallax::Fundo::addCamada(const char* caminhoTextura, const float vel) {
    Camada* camada = new Camada((sf::Vector2f)pGerGrafico->getWindow()->getSize(), pGerGrafico->CarregarTextura(caminhoTextura), vel);
    if (camada == nullptr) {
        std::cout << "ERRO::CASTELOpp::Parallax::Fundo::nao foi possivel criar uma camada" << std::endl;
        exit(1);
    }
    camadas.push_back(camada);
}