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
public: // metods
    friend std::vector<search_result> search(const input& item, const nlohmann::json& personages);
public: // constructor
    constexpr search_result() : personage_name(), build_name() {}
    constexpr search_result(std::string _personage_name, std::string _build_name) 
        : personage_name(_personage_name), build_name(_build_name) {}
public: // operators
    template<typename char_type> 
    friend inline std::basic_ostream<char_type>& operator<<(std::basic_ostream<char_type>& Left, const search_result& Right);
};

// search_result operators
template<typename char_type>
inline std::basic_ostream<char_type>& operator<<(std::basic_ostream<char_type>& Left, const search_result& Right)
{
    // auto a = (*Right.personages)[Right.personage_name][Right.build_name];
    Left << Right.personage_name << " " << Right.build_name;
    return Left;
}

std::vector<search_result> search(const input& item, const nlohmann::json& personages)
{
    std::vector<search_result> results;
    
        // cringe warnning

    // personagem >> builds >> sets >> itens main stat >> item sub stat 
    for(auto per_it = (personages["Personagens"]).begin(); per_it != (personages["Personagens"]).end(); ++per_it)
    {
        // personage_name = (*per_it)["Nome"];
        for(auto bui_it = (*per_it)["Builds"].begin(); bui_it != (*per_it)["Builds"].end(); ++bui_it)
        {
            // build_name = (*bui_it)["Nome"]
            for(auto set_it = (*bui_it)["Sets"].begin(); set_it != (*bui_it)["Sets"].end(); ++set_it)
            {
                if(item.set == *set_it)
                {
                    for(auto mai_it = (*bui_it)[item.type]["main_stat"].begin(); mai_it != (*bui_it)[item.type]["main_stat"].end(); ++mai_it)
                    {
                        if(item.main == *mai_it)
                        {
                            for(auto sub_it = (*bui_it)[item.type]["sub_stat"].begin(); sub_it != (*bui_it)[item.type]["sub_stat"].end(); ++sub_it)
                            {
                                if(item.sub == *sub_it)
                                {
                                    results.emplace_back((*bui_it)["Nome"], (*per_it)["Nome"]);
                                    break;
                                }
                            }
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }   
    return results;
}

}   // neto namespace