#include <iostream>

#include "url.hpp"

void printMatches(std::string str, std::regex reg) {
    std::smatch matches;

    if (std::regex_search(str, matches, reg)) {
        for (int i = 1; i < matches.size(); i++) {
            cout << matches[i] << endl;
        }
    } else {
        cout << "Nenhuma correspondecia encontrada" << endl;
    }
    cout << endl;
}

int main() {
    Url url1("https://cefetplusplus.gith:ub.io/");
    cout << url1.reconstruirUrl() << endl << endl;

    Url url2 = "https://cefetplusplus.github.io/"_url;
    cout << url2.reconstruirUrl() << endl << endl;

    Url url3 = "https://www.cefetmg.br/"_url;
    cout << url3.reconstruirUrl() << endl << endl;

    Url url4 = "https://www.cefetmg.br:443/"_url;
    cout << url4.reconstruirUrl() << endl << endl;

    Url url5 = "https://pt.wikipedia.org/wiki/URL"_url;
    cout << url5.reconstruirUrl() << endl << endl;

    Url url6 = "https://pt.wikipedia.org/wiki/rec?URL#cite_note-4"_url;
    cout << url6.reconstruirUrl() << endl << endl;

    Url url7 = "https://pt.wikipedia.org:56/wiki/rec?URL#cite_note-4"_url;
    cout << url7.reconstruirUrl() << endl << endl;

    // cout << endl;

    // std::string str11 = "123-867-5309-1223";
    // std::regex reg11("\\w{3}-\\w{3}-\\w{4}-\\w{4}");
    // printMatches(str11, reg11);
    //  std::regex reg14("[\\w._%+-]{1,20}@[\\w.-]{2,20}.[A-Za-z]{2,3}");

    // \d [0-9] pega apenas numeros
    // \w [a-zA-Z0-9] pega numeros e letras
    // \W [^a-zA-Z0-9] nao pega numeros nem letras

    // esquema://domínio:porta/caminho/recurso?query_string#fragmento
    // std::regex reg(R"([\w]{1,5}://[a-z.-]{1,26}:[\d]{2,4}/[\w]{1,52}/[\w]{1,26}?[\w]{1,26}#[\w_-]{1,26})");

    // std::string str = "https://cefetplusplus.github.io:4430/caminho/recurso?query_string#fragmento";

    // // completo
    // std::regex reg_completo(R"(([a-z]{5})://([a-z.-]*):(\d{2,4})/([\w.-]*)/(.*))");

    // // sem porta
    // std::regex reg_sem_porta(R"(([a-z]{5})://([a-z.-]*)/([\w.-]*)/(.*))");

    // // sem caminho
    // std::regex reg_sem_caminho(R"(([a-z]{5})://([a-z.-]*):(\d{2,4})/)");

    // // sem caminho, sem porta
    // std::regex reg_sem_caminho_sem_porta(R"(([a-z]{5})://([a-z.-]*)/)");

    // cout << endl;
    // printMatches(url1.getUrl(), reg_sem_caminho_sem_porta);
    // printMatches(url3.getUrl(), reg_sem_caminho_sem_porta);
    // printMatches(url4.getUrl(), reg_sem_caminho_sem_porta);
    // printMatches(url5.getUrl(), reg_sem_caminho_sem_porta);
    // printMatches(url6.getUrl(), reg_sem_caminho_sem_porta);

    return EXIT_SUCCESS;
}