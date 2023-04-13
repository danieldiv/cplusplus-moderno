#include <iostream>

#include "url.hpp"

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

    return EXIT_SUCCESS;
}