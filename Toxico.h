#pragma once
#include "Obstaculo.h"

namespace CASTELOpp {
    namespace Entidade {
        namespace Obstaculo {
            
            class Toxico :
                public Obstaculo{
            
            private:
                sf::Clock TempoTox;
                
            public:
                Toxico(sf::Vector2f pos);
                ~Toxico();
                
                bool GerirAtk(Entidade* pEntidade);
                void Atacar(Entidade* EntidadeAtacada);
                float getVida() const { return 0.0f; }
                void TomaDano(float quantidade) {};
                bool Aparecer() const { return true; };
            };
        }
    }
}


