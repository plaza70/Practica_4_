#include <iostream>

#include "../include/json_reader.h"
#include "../include/validator.h"
#include "../include/interpolator.h"
#include "../include/http_client.h"

int main()
{
    auto captures =
        readCaptures("../tactile_captures_50.json");

    std::cout
        << "Numero de capturas: "
        << captures.size()
        << std::endl;

    bool allValid = true;

    for(size_t i = 0; i < captures.size(); i++)
    {
        if(!validateMatrix(captures[i]))
        {
            std::cout
                << "Error en captura "
                << i
                << std::endl;

            allValid = false;
        }
    }

    if(allValid)
    {
        std::cout
            << "Todas las matrices son 16x16"
            << std::endl;
    }

    for(size_t i = 0; i < captures.size(); i++)
    {
        Matrix enlarged =
            bilinearInterpolation(
                captures[i],
                128,
                128
            );

        if(i == 0)
        {
            std::cout
                << "Filas interpoladas: "
                << enlarged.size()
                << std::endl;

            std::cout
                << "Columnas interpoladas: "
                << enlarged[0].size()
                << std::endl;
        }

        sendMatrix(enlarged);

        std::cout
            << "Matriz "
            << i + 1
            << " enviada"
            << std::endl;
    }

    std::cout
        << "Proceso completado"
        << std::endl;

    return 0;
}
