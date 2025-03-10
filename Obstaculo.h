#pragma once
#include "Entidade.h"

namespace CASTELOpp {
    namespace Entidade {
        namespace Obstaculo {
            
            class Obstaculo :
                public Entidade
            {
            protected:
                sf::Texture Textura;
            public:
                Obstaculo(const sf::Vector2f pos, const sf::Vector2f tam, ID Id);
                ~Obstaculo();
                void Atualizar(double t);
                void colisao(Entidade* entidade,sf::Vector2f desl);
                virtual bool GerirAtk(Entidade* pEntidade);
                virtual void Atacar(Entidade* EntidadeAtacada);
                void setTextura(sf::Texture textura);
                virtual float getVida() const { return 0.0f; }
                virtual void TomaDano(float quantidade){}
                virtual bool Aparecer() const { return true; };
            };
        }
    }
}



