#pragma once
#include "Obstaculo.h"

namespace CASTELOpp {
    namespace Entidade {
        namespace Obstaculo {
            class Lama :
                public Obstaculo
            {
            private:

            public:
                Lama(sf::Vector2f Pos);
                ~Lama();
                bool GerirAtk(Entidade* pEntidade);
                void Atacar(Entidade* EntidadeAtacada);
                float getVida() const { return 10.0f; }
                void TomaDano(float quantidade) {};
                bool Aparecer() const { return true; };
            };
        }
    }
}