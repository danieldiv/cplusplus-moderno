#ifndef URL_HPP___
#define URL_HPP___

#include <string>
#include <regex>

using namespace std;

class Url {
private:
    string url_;
    string esquema_;
    string dominio_;
    int porta_;
    string caminho_;

    bool valido_;
public:
    Url(string url): url_(url), porta_(0), valido_(true) { construirObjeto(); }
    Url(string esquema, string dominio, int porta, string caminho);

    void setEsquema(string esquema) { esquema_ = esquema; }
    void setDominio(string dominio) { dominio_ = dominio; }
    void setPorta(int porta) { porta_ = porta; }
    void setCaminho(string caminho) { caminho_ = caminho; }

    string reconstruirUrl();

    string getUrl() { return url_; }
    string getEsquema() const { return esquema_; }
    string getDominio() const { return dominio_; }
    int getPorta() const { return porta_; }
    string getCaminho() const { return caminho_; }

    void construirObjeto();
};

Url operator"" _url(const char *url, std::size_t tam) {
    return Url(url);
}

Url::Url(string esquema, string dominio, int porta, string caminho) {
    setEsquema(esquema);
    setDominio(dominio);
    setPorta(porta);
    setCaminho(caminho);
}

void Url::construirObjeto() {
    cout << getUrl() << endl;

    std::string str = getUrl();
    std::smatch matches;

    std::regex reg_completo(R"(([a-z]{5})://([a-z.-]*):(\d{2,4})/([\w.-]*)/(.*))");

    if (std::regex_search(str, matches, reg_completo)) {
        setEsquema(matches[1]);
        setDominio(matches[2]);
        setPorta(stoi(matches[3]));

        string caminho = matches[4];
        setCaminho(caminho.append("/").append(matches[5]));

        return;
    }

    std::regex reg_sem_porta(R"(([a-z]{5})://([a-z.-]*)/([\w.-]*)/(.*))");

    if (std::regex_search(str, matches, reg_sem_porta)) {
        setEsquema(matches[1]);
        setDominio(matches[2]);

        string caminho = matches[3];
        setCaminho(caminho.append("/").append(matches[4]));

        return;
    }

    std::regex reg_sem_caminho(R"(([a-z]{5})://([a-z.-]*):(\d{2,4})/)");

    if (std::regex_search(str, matches, reg_sem_caminho)) {
        setEsquema(matches[1]);
        setDominio(matches[2]);
        setPorta(stoi(matches[3]));

        return;
    }

    std::regex reg_sem_caminho_sem_porta(R"(([a-z]{5})://([a-z.-]*)/)");

    if (std::regex_search(str, matches, reg_sem_caminho_sem_porta)) {
        setEsquema(matches[1]);
        setDominio(matches[2]);

        return;
    }
    valido_ = false;
}

string Url::reconstruirUrl() {
    if (!valido_) return "Nenhuma correspondecia encontrada";

    string url;

    url.append(getEsquema()).append("://").append(getDominio());
    if (getPorta() != 0) url.append(":").append(to_string(getPorta()));
    url.append("/");
    if (getCaminho().size() > 0) url.append(getCaminho());

    return url;
}

#endif