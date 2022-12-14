#include "epic_search.h"

int main()
{

    // TODO read cli args
    
    // load files 
    auto item_data = nlohmann::json::parse(std::ifstream("res/Dados_Itens.json"));
    auto personages = nlohmann::json::parse(std::ifstream("res/Dados.json"));
    
    // gaming
    while(true)
    {
        neto::input item(item_data);
        auto results = neto::search(item, personages); 
        for(auto it = results.begin(); it != results.end(); ++it)
        {
            std::cout << *it << std::endl;
        }
        std::cout << "continue?" << std::endl;
        if(io::input<std::string, char>() != "yes")
        {
            break;
        }
        system("clear");
    }
}