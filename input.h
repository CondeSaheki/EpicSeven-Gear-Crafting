#pragma once
#include <iostream>
#include <vector>
#include "json.hpp"
#include "io.h"
#include <filesystem>

namespace neto
{

class input
{
public: // data
    std::string set;
    std::string type;
    std::string main;
    std::string sub;

private: // members
    auto user_input(const std::vector<std::string> &compare)
    {
        std::string input;
        bool found;
        while (true)
        {
            input = io::input_line<char>();
            input.erase(input.end() - 1);
            for (auto it = compare.begin(); it != compare.end(); ++it)
            {
                if (input == *it)
                {
                    return it;
                }
            }
            // help message
            std::cout << "try again options are:" << std::endl;
            for (auto it = compare.begin(); it != compare.end(); ++it)
            {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
            input.clear();
        }
    }

public: // constructors
    constexpr input(
        std::string _set,
        std::string _type,
        std::string _main,
        std::string _sub)
        : set(_set), type(_type), main(_main), sub(_sub) {}

    constexpr input()
        : set(std::string()), type(std::string()), main(std::string()), sub(std::string()) {}

    input(const nlohmann::json &itens)
        : set(std::string()), type(std::string()), main(std::string()), sub(std::string()){}
    {
        // lazy
        std::cout << "type:" << std::endl;
        type = *user_input({"Arma", "Capacete", "Armadura", "Colar", "Anel", "Bota"});
        std::cout << "Set:" << std::endl;
        set = *user_input(itens["Sets"].get<std::vector<std::string>>());
        std::cout << "main status:" << std::endl;
        main = *user_input(itens[type]["main_stat"].get<std::vector<std::string>>());
        std::cout << "sub status:" << std::endl;
        sub = *user_input(itens[type]["sub_stat"].get<std::vector<std::string>>());
    }
};

} // neto namespace