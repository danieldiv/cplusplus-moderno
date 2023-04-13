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

    for (auto end : enderecos) {
        Url url(end);
        cout << url.reconstruirUrl() << endl << endl;
    }
    return EXIT_SUCCESS;
}