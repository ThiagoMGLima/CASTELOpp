#pragma once
#include "Estado.h"
#include "Floresta.h"
#include "Castelo.h"


namespace CASTELOpp {
    namespace Estado {
        class EstadoJogar :
            public Estado
        {
        private:
            Fase::Fase* fase;
            
        public:
            EstadoJogar(const ID Id,Fase::Fase* fase);
            ~EstadoJogar();
            Fase::Fase* getFase() const;
            void Atualizar(double t);
            vector<Entidade::Entidade*> getJgdr();
        };
    }
}
