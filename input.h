#pragma once
#include <iostream>
#include <vector>
#include "json.hpp"
#include "io.h"
#include <filesystem>
#include "clear.h"

namespace neto
{

class input
{
public: // data
    std::string set;
    std::string type;
    std::string main;
    std::string sub1;
    std::string sub2;
    std::string sub3;
private: // members
    auto user_input(const std::vector<std::string> &compare)
    {
        std::string input;
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
            for (auto it = compare.begin(); it != compare.end() - 1; ++it)
            {
                std::cout << "\"" << *it << "\", ";
            }
            std::cout << *(compare.end() - 1) << std::endl;
            input.clear();
        }
    }

public: // constructors
    constexpr input(
        std::string _set,
        std::string _type,
        std::string _main,
        std::string _sub1,
        std::string _sub2,
        std::string _sub3)
        : set(_set), type(_type), main(_main), sub1(_sub1), sub2(_sub2), sub3(_sub3) {}

    constexpr input()
        : set(std::string()), type(std::string()), main(std::string()), sub1(std::string()), sub2(std::string()), sub3(std::string()) {}

    input(const nlohmann::json &itens)
    {
        // lazy
        std::cout << "type:" << std::endl;
        type = *user_input({"Arma", "Capacete", "Armadura", "Colar", "Anel", "Bota"});
        clear();
        std::cout << "Set:" << std::endl;
        set = *user_input(itens["Sets"].get<std::vector<std::string>>());
        clear();
        std::cout << "main status:" << std::endl;
        main = *user_input(itens[type]["main_stat"].get<std::vector<std::string>>());
        clear();
        std::cout << "sub status 1:" << std::endl;
        sub1 = *user_input(itens[type]["sub_stat"].get<std::vector<std::string>>());
        clear();
        std::cout << "sub status 2:" << std::endl;        
        sub2 = *user_input(itens[type]["sub_stat"].get<std::vector<std::string>>());        
        clear();
        std::cout << "sub status 3:" << std::endl;
        sub3 = *user_input(itens[type]["sub_stat"].get<std::vector<std::string>>());
        clear();
    }
};

} // neto namespace