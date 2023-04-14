#include <iostream>
#include <vector>

#include "url.hpp"

int main() {
    vector<string> enderecos = {
    "https://cefetplusplus.gith:ub.io/",
     "https://cefetplusplus.github.io/",
     "https://www.cefetmg.br/",
     "https://www.cefetmg.br:443/",
     "https://pt.wikipedia.org/wiki/URL",
     "https://pt.wikipedia.org/wiki/rec?URL#cite_note-4",
     "https://pt.wikipedia.org:56/wiki/rec?URL#cite_note-4"
    };

    cout << "UTILIZANDO CONSTRUTOR PADRAO" << endl << endl;
    for (auto end : enderecos) {
        Url url(end);
        cout << url.reconstruirUrl() << endl << endl;
    }

    cout << "UTILIZANDO LITERAL _url" << endl << endl;

    Url url1 = "https://cefetplusplus.gith:ub.io/"_url;
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


    return EXIT_SUCCESS;
}