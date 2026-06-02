#include "../include/http_client.h"

#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <iostream>

using json = nlohmann::json;

void sendMatrix(const Matrix& matrix)
{
    CURL* curl = curl_easy_init();

    if(!curl)
    {
        std::cerr << "Error inicializando CURL"
                  << std::endl;
        return;
    }

    json j;
    j["matrix"] = matrix;

    std::string payload = j.dump();

    struct curl_slist* headers = nullptr;

    headers =
        curl_slist_append(
            headers,
            "Content-Type: application/json"
        );

    curl_easy_setopt(
        curl,
        CURLOPT_URL,
        "http://127.0.0.1:5000/upload"
    );

    curl_easy_setopt(
        curl,
        CURLOPT_HTTPHEADER,
        headers
    );

    curl_easy_setopt(
        curl,
        CURLOPT_POSTFIELDS,
        payload.c_str()
    );

    CURLcode result =
        curl_easy_perform(curl);

    if(result != CURLE_OK)
    {
        std::cerr
            << curl_easy_strerror(result)
            << std::endl;
    }

    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
}
