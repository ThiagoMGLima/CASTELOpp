#pragma once
#include "Ente.h"
namespace CASTELOpp {
    namespace Estado {
        class Estado :
            public Ente
        {
        private:
            bool remover;
            std::vector<float*>* vtemposFase;
            std::vector<std::string*>* nomes;

        public:
            Estado(const ID Id);
            virtual ~Estado();
            virtual void Atualizar(double t) = 0;
            void setRemover(const bool remover = true);
            const bool getRemover() const;
            
            void addpontuacao(float t);
           
            
            std::vector<float*>* getvtempos() const;
        };
    }
}


