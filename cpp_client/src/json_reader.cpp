#include "../include/json_reader.h"

#include <iostream>
#include <fstream>
#include <cstdlib>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

std::vector<Matrix> readCaptures(const std::string& filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "ERROR: No se pudo abrir el archivo: "
                  << filename << std::endl;
        exit(1);
    }

    json data;

    try
    {
        file >> data;
    }
    catch (const std::exception& e)
    {
        std::cerr << "ERROR al leer JSON: "
                  << e.what()
                  << std::endl;

        exit(1);
    }

    if (!data.contains("captures"))
    {
        std::cerr << "ERROR: El JSON no contiene la clave 'captures'"
                  << std::endl;

        exit(1);
    }

    std::vector<Matrix> captures;

    for (const auto& capture : data["captures"])
    {
        Matrix matrix;

        for (const auto& row : capture["matrix"])
        {
            matrix.push_back(
                row.get<std::vector<double>>()
            );
        }

        captures.push_back(matrix);
    }

    return captures;
}
