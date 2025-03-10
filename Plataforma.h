#pragma once
#include "Obstaculo.h"

namespace CASTELOpp {
    namespace Entidade {
        namespace Obstaculo {
            
            class Plataforma :
                public Obstaculo
            {
                int qualTextura;
            public:
                Plataforma(sf::Vector2f pos);
                Plataforma(sf::Vector2f pos,sf::Vector2f tam,bool invi);
                Plataforma(sf::Vector2f pos, sf::Vector2f tam, const char* caminhoTextura);
                ~Plataforma();
                bool GerirAtk(Entidade* pEntidade);
                void Atacar(Entidade* EntidadeAtacada);
                float getVida() const { return 0.0f; }
                void TomaDano(float quantidade) {};
                bool Aparecer() const  { return true; };
            };
        }
    }
}


