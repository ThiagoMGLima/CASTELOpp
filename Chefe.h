#pragma once
#include "Inimigo.h"

namespace CASTELOpp {
    namespace Entidade {
        namespace Personagens {
            namespace Inimigo {
                class Chefe :
                    public Inimigo
                {
                private:
                    void Inicializa();
                public:
                    Chefe(const sf::Vector2f Pos, const sf::Vector2f Tam, vector<Entidade*> Jogador);
                    ~Chefe();
                    float getVida() const;
                    bool Aparecer() const;
                    void Atacar(Entidade* entidadeAtacada);
                };
            }
        }
    }
}