#ifndef JSON_READER_H
#define JSON_READER_H

#include <vector>
#include <string>

using Matrix = std::vector<std::vector<double>>;

std::vector<Matrix> readCaptures(const std::string& filename);

#endif
