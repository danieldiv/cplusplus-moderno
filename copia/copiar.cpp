#include <iostream>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

bool checkInteiro(vector<string> vec) {
    for (auto v : vec) {
        if (v.compare("-i") == 0) return true;
    }
    return false;
}

int checkCasasDecimais(vector<string>vec) {
    vector<string>::iterator it;

    for (it = vec.begin(); it != vec.end(); ++it) {
        if ((*it).compare("-p") == 0) {
            ++it;
            return stoi(*it);
        }
    }
    return 4;
}

int checkSemente(vector<string>vec) {
    vector<string>::iterator it;

    for (it = vec.begin(); it != vec.end(); ++it) {
        if ((*it).compare("-s") == 0) {
            ++it;
            return stoi(*it);
        }
    }
    return -1;
}

pair<int, int> checkIntervalo(vector<string>vec) {
    vector<string>::iterator it;

    for (it = vec.begin(); it != vec.end(); ++it) {
        if ((*it).compare("-r") == 0) {
            int aux = stoi(*(++it));
            ++it;
            return make_pair(aux, stoi(*(it)));
        }
    }
    return make_pair(0, 1);
}

int checkQuantidade(vector<string> vec) {
    vector<string>::iterator it;

    for (it = vec.begin(); it != vec.end(); ++it) {
        if ((*it).compare("-n") == 0)
            return  stoi(*(++it));
    }
    return 1;
}

int main(int argc, char **argv) {
    vector<string> vec;
    vector<string>::iterator it;

    bool inteiro;
    int x, S, X, seed;
    double val;

    for (int i = 1; i < argc; i++)
        vec.push_back(argv[i]);

    inteiro = checkInteiro(vec);
    seed = checkSemente(vec);
    X = checkCasasDecimais(vec);
    x = checkQuantidade(vec);

    pair<int, int>intervalo = checkIntervalo(vec);
    int LI = intervalo.first;
    int LS = intervalo.second;

    if (seed >= 0)
        srand(seed);
    else
        srand(time(NULL));

    for (int i = 0; i < x; i++) {
        val = (inteiro) ? (LI + rand() % (LS - LI)) : ((LI + (double)rand() * (LS - LI)) / (double)RAND_MAX);
        cout << fixed << setprecision(X) << val << " ";
    }
    cout << endl;

    return 0;
}