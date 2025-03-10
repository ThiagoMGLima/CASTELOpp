#include "Camada.h"

CASTELOpp::Parallax::Camada::Camada(const sf::Vector2f tamJanela, sf::Texture textura, const float vel) :
    tamJanela(tamJanela), textura(textura), dimensao(0, 0, 0, 0), vel(vel)
{
    dimensao.width = -abs((float)textura.getSize().x);
    dimensao.height = textura.getSize().y;
    dimensao.left = textura.getSize().x;

    fundo.setSize(tamJanela);
    fundo.setTexture(&this->textura);
    fundo.setPosition(0.0f, 0.0f);

    fundoAuxiliar.setSize(tamJanela);
    fundoAuxiliar.setTexture(&this->textura);
    fundoAuxiliar.setPosition(tamJanela.x, 0.0f);
}

CASTELOpp::Parallax::Camada::~Camada() {

}

void CASTELOpp::Parallax::Camada::trocarTextura() {
    sf::RectangleShape trocar = fundo;
    fundo = fundoAuxiliar;
    fundoAuxiliar = trocar;
}

void CASTELOpp::Parallax::Camada::desenharCamada(sf::RenderWindow* window) {
    window->draw(fundo);
    if (vel != 0.0f) {
        window->draw(fundoAuxiliar);
    }
}

void CASTELOpp::Parallax::Camada::atualizar(const sf::Vector2f ds, const sf::Vector2f posCameraAtual) {
    const float posDireita = posCameraAtual.x + tamJanela.x / 2.0f;
    const float posEsquerda = posCameraAtual.x - tamJanela.x / 2.0f;

    if (vel != 0.0f) {
        const sf::Vector2f posFundo = fundo.getPosition();
        const sf::Vector2f posFundoAux = fundoAuxiliar.getPosition();

        //aplicando o movimento contrário para as camadas
        fundo.move(ds.x * -vel, 0.0f);
        fundoAuxiliar.move(ds.x * -vel, 0.0f);

        if (ds.x > 0.0f) { // camera movendo para a direita
            if (posFundo.x + tamJanela.x < posEsquerda) {
                trocarTextura();
                fundo.setPosition(posEsquerda, 0.0f);
                fundoAuxiliar.setPosition(posDireita, 0.0f);
            }

        }
        else { // camera movendo para a esquerda
            if (posFundo.x > posEsquerda) {
                trocarTextura();
                fundo.setPosition(posEsquerda - tamJanela.x, 0.0f);
                fundoAuxiliar.setPosition(posEsquerda, 0.0f);
            }
        }
    }
    else {
        fundo.setPosition(posEsquerda, 0.0f);
    }
}