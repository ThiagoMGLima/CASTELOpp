#pragma once

//perseguir o jogador
#include "Jogador.h"

//Para gerar numeros aleatorios
#include <time.h>

//Utilizar a funcao fabs
#include <math.h>

#define VELOCIDADE_INIMIGO 5.5f
#define RAIO_AGRO 250.0f
#define RAIO_ATK 150.0f


namespace CASTELOpp {
    namespace Entidade {
        namespace Personagens{

            namespace Inimigo {

                class Inimigo :
                    public Personagem
                {
                private:
                    //Entidade* pJogador;
                    vector<Entidade*> vJogadores;

                    int sorteado;
                    sf::Clock relogio;
                    virtual void Inicializa();
                protected:
                    bool atacando;
                    bool jaAtacou;
                    double TempoMorte;
                    bool temJgdrPerto;

                public:
                    Inimigo(const sf::Vector2f Pos, const sf::Vector2f Tam, vector<Entidade*> vjogador);
                    ~Inimigo();
                    void Persegue(sf::Vector2f posJogador, sf::Vector2f posInimigo);
                    void Atualizar(double t);
                    void atualizaDistancia(double t);
                    void moveAle();
                    void move();
                    //void colisao(Entidade* entidadeColidida, sf::Vector2f desl);
                    void AtualizaAnimacao();
                    sf::Vector2f getDistInimJog();
                    virtual void Atacar(Entidade* entidadeAtacada);
                    bool GerirAtk(Entidade* pEntidade);
                    float getVida() const;
                    virtual bool Aparecer() const;
                    Entidade* getJogPerto();
                };
            }
        }
    }
}


