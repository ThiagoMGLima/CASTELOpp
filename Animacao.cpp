#include "Animacao.h"

CASTELOpp::Animacao::Animacao::Animacao(sf::RectangleShape* corpo) :
    corpo(corpo), mapImagem(), imgAtual(""), clock()
{

}

CASTELOpp::Animacao::Animacao::~Animacao() {
    std::map<std::string, Imagem*>::iterator it = mapImagem.begin();
    while (it != mapImagem.end()) {
        if (it->second) {
            delete(it->second);
            it->second = nullptr;
        }
        it++;
    }
    mapImagem.clear();
}

void CASTELOpp::Animacao::Animacao::atualizar(const bool paraEsquerda, std::string imgAtual) {
   
    if (this->imgAtual != imgAtual) {
        if (this->imgAtual != "") {
            mapImagem[this->imgAtual]->resetar();
        }
        this->imgAtual = imgAtual;
    }
    float dt = clock.getElapsedTime().asSeconds();
    clock.restart();

    Imagem* img = mapImagem[this->imgAtual];
    sf::Vector2f tamCorpo = corpo->getSize();
    sf::Vector2f escala = img->getEscala();

    img->atualizar(paraEsquerda, dt);
    corpo->setTextureRect(img->getTamanho());
    corpo->setTexture(img->getTextura());
    corpo->setScale(escala.x, escala.y);
}

void CASTELOpp::Animacao::Animacao::setAnimacao(const char* caminhoTextura, std::string nomeAnimacao, const unsigned int qtdImagem, const float tempoTroda, const sf::Vector2f escala) {
    Imagem* img = new Imagem(caminhoTextura, qtdImagem, tempoTroda, escala);
    mapImagem.insert(std::pair<std::string, Imagem*>(nomeAnimacao, img));
}