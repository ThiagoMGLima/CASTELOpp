#pragma once
#include "Inimigo.h"

namespace CASTELOpp {
    namespace Entidade {
        namespace Personagens {
            namespace Inimigo {
                
                class Fantasma :
                    public Inimigo
                {
                private:
                    float fantasmagorico;
                    void Inicializa();

                public:
                    Fantasma(const sf::Vector2f Pos, const sf::Vector2f Tam, vector<Entidade*> jogador);
                    ~Fantasma();
                    float getVida() const;
                    bool Aparecer() const;
                    void Atacar(Entidade* entidadeAtacada);
                };
            }
        }
    }
}
