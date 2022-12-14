#pragma once
#include "input.h"

namespace neto
{

class search_result
{
public: // data
    std::string personage_name;
    std::string build_name;
    const nlohmann::json* personages;
public: // constructor
    constexpr search_result() : personage_name(), build_name() {}
    constexpr search_result(std::string& _personage_name,std::string& _build_name) 
        : personage_name(_personage_name), build_name(_build_name) {}
public: // operators
    template<typename char_type> 
    friend inline std::basic_ostream<char_type>& operator<<(std::basic_ostream<char_type>& Left, const search_result& Right);
};

// search_result operators
template<typename char_type>
inline std::basic_ostream<char_type>& operator<<(std::basic_ostream<char_type>& Left, const search_result& Right)
{
    // Builds
    auto a = (*Right.personages)[Right.personage_name][Right.build_name];
    
    Left << Right.personage_name << Right.build_name;
    return Left;
}

/*
auto json_serch_container(json a, std::string b, std::string c)
{
    auto result = a.end();
    for(auto it2 = a.begin(); it2 != a.end(); ++it2)
    {
        if(a[b] == c)
        {
            result = it2;
            break;
        }
    }

    return result;
}
*/

std::vector<search_result> search(const input& item, const nlohmann::json& personages)
{
    std::vector<search_result> results;
    
    // personagem >> builds >> sets >> itens main stat >> item sub stat 
    for(auto it = personages.begin(); it != personages.end(); ++it)
    {

        // HERE
        // item.set;

    }   
    return results;
}

}   // neto namespace