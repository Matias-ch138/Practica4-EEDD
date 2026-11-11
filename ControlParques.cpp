#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include "ControlParques.h"
#include "LectorCSV.h"
using namespace std;
static bool leerCampoCSV(const string& linea, size_t& posicion, string& campo, char separador = ',') {
    campo.clear();
    bool entreComillas = posicion < linea.size() && linea[posicion] == '"';
    if (entreComillas) {
        ++posicion;
    }

    while (posicion < linea.size()) {
        char caracter = linea[posicion];
        if (entreComillas && caracter == '"') {
            if (posicion + 1 < linea.size() && linea[posicion + 1] == '"') {
                campo += '"';
                posicion += 2;
            } else {
                entreComillas = false;
                ++posicion;
            }
        } else if (!entreComillas && caracter == separador) {
            ++posicion;
            return true;
        } else {
            campo += caracter;
            ++posicion;
        }
    }

    return !entreComillas;
}

static bool leerRegistroArbol(const string& linea, string campos[], size_t numeroCampos) {
    size_t posicion = 0;
    for (size_t i = 0; i < numeroCampos; ++i) {
        if (!leerCampoCSV(linea, posicion, campos[i], ';')) {
            return false;
        }
        if (i + 2 < numeroCampos && posicion == linea.size()) {
            return false;
        }
    }
    return posicion == linea.size();
}

static float leerMedidaCSV(const string& campo) {
    if (campo.empty()) {
        return 0.0f;
    }
    string normalizado = campo;
    replace(normalizado.begin(), normalizado.end(), ',', '.');
    return stof(normalizado);
}

static Especie* buscarEspecie(vector<Especie>& especies, const string& codigo) {
    int inicio = 0;
    int fin = static_cast<int>(especies.size()) - 1;
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        const string& codigoMedio = especies[medio].get_codigo_especie();
        if (codigoMedio == codigo) {
            return &especies[medio];
        }
        if (codigoMedio < codigo) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }
    return nullptr;
}

static Parque* buscarParquePorCodigo(list<Parque>& parques, int codigo) {
    list<Parque>::iterator it=parques.begin();
    while(it!=parques.end()){
        if(it->get_cod_parque()==codigo) return &*it;
        it++;
    }
    return nullptr;
}
ControlParques::ControlParques(){
    
}
ControlParques::ControlParques(const string& rutaEspecies, const string& rutaParques, const string& rutaArboles){
    LectorCSV lector;
    lector.cargar(varieties, rutaEspecies);
    sort(varieties.begin(), varieties.end()); 

    // 1. Cargar Parques
    ifstream fichero(rutaParques);
    if (fichero.is_open()) {
        string linea;
        while (getline(fichero, linea)) {
            if (linea.empty()) continue;
            
            string cod_str, nombre_parque;
            size_t posicion = 0;

            if (leerCampoCSV(linea, posicion, cod_str) &&
                leerCampoCSV(linea, posicion, nombre_parque)) {
                try {
                    int cod = stoi(cod_str);
                    Parque p(cod, nombre_parque);
                    parks.push_back(p);
                } catch (const invalid_argument& e) {
                    continue;
                }
            }
        }
        fichero.close();
    } else {
        cerr << "Error: No se pudo abrir el archivo de parques: " << rutaParques << endl;
    }

    // 2. Cargar Árboles
    ifstream ficheroArboles(rutaArboles);
    if (!ficheroArboles.is_open()) {
        cerr << "Error: No se pudo abrir el archivo de arboles: " << rutaArboles << endl;
        return;
    }

    string lineaArbol;
    getline(ficheroArboles, lineaArbol);
    while (getline(ficheroArboles, lineaArbol)) {
        if (!lineaArbol.empty() && lineaArbol.back() == '\r') {
            lineaArbol.pop_back();
        }
        if (lineaArbol.empty()) continue;

        string campos[12];
        if (!leerRegistroArbol(lineaArbol, campos, 12) || campos[0].empty()) {
            continue;
        }

        try {
            string x = campos[6];
            string y = campos[7];
            replace(x.begin(), x.end(), ',', '.');
            replace(y.begin(), y.end(), ',', '.');
            
            Arbol arbol(campos[0], stoi(campos[1]), stoi(campos[2]), campos[3],
                        stoi(campos[4]), campos[5], stod(x), stod(y),
                        leerMedidaCSV(campos[10]), leerMedidaCSV(campos[11]));
            
            Especie* especieEncontrada = buscarEspecie(varieties, campos[8]);
            arbol.setEspecie(especieEncontrada);

            // Insertar en mapa principal de árboles (con tipo explicito std::pair)
            pair<map<string, Arbol>::iterator, bool> resultado = trees.insert({arbol.get_assetnum(), arbol});
            if (!resultado.second) {
                continue; 
            }

            // Obtener puntero al árbol insertado en el mapa
            Arbol* arbolAlmacenado = &(resultado.first->second);
            
            // Relación con Parque (bidireccional)
            Parque* parque = buscarParquePorCodigo(parks, arbolAlmacenado->get_num_parque());
            if (parque != nullptr) {
                parque->insertarArbol(arbolAlmacenado); 
                arbolAlmacenado->setParque(parque);
            }
            
            // Insertar en multimap de nombres comunes
            if (especieEncontrada != nullptr) {
                treeName.insert({especieEncontrada->get_nombre_comun(), arbolAlmacenado});
            }
            
        } catch (const exception&) {
            continue;
        }
    }
}


int ControlParques::contarEspecieParque(string ncomun){
    int contador = 0;
    list<Parque>::iterator it=parks.begin();
    while(it!=parks.end()){
        if(it->existeNbreCom(ncomun)){
            contador++;
        }
        it++;
    }
    return contador;
}

vector<Especie> ControlParques::listadoEspecieSubNbre(string cadena){
    vector<Especie> resultados;
    for(int i=0; i<varieties.size(); i++){
        if(varieties[i].getnombre_cientifico().find(cadena) != string::npos){
            resultados.push_back(varieties[i]);
        }
    }
    return resultados;
}

Parque* ControlParques::buscarParque(const string& nbre_parque){
    list<Parque>::iterator it=parks.begin();
    while(it!=parks.end()){
        if(it->get_nbre_parque() == nbre_parque){
            return &*it;
        }
      it++;  
    }
    return nullptr;
}


vector<Especie>& ControlParques::get_varieties(){
    return varieties;
}

const vector<Especie>& ControlParques::get_varieties() const{
    return varieties;
}

list<Parque>& ControlParques::get_parks(){
    return parks;
}

const list<Parque>& ControlParques::get_parks() const{
    return parks;  
}

list<Parque>& ControlParques::get_nbre_parque(){
    return parks;
}

const list<Parque>& ControlParques::get_nbre_parque() const{
    return parks;
}

Arbol* ControlParques::buscarArbol(string asNum){
    if (trees.count(asNum) > 0) {    
        return &trees.at(asNum);     
    }
    return nullptr;
}
vector<Arbol*> ControlParques::listaArbParque(string nbre_parque){
    Parque* parque = buscarParque(nbre_parque);
    if (parque != nullptr) {
        return parque->get_contains();
    }
    return vector<Arbol*>();
}
Arbol* ControlParques::arbolMasAlto(){
    Arbol* arbolMasAlto=nullptr;
    list<Parque>::iterator it=parks.begin();
    while(it!=parks.end()){
        Arbol* mayorParque=it->arbolMasAlto();
        if(mayorParque != nullptr){
            if(arbolMasAlto==nullptr || mayorParque->get_altura()>arbolMasAlto->get_altura()){
                arbolMasAlto=mayorParque;
            }
        }
        it++;
    }
    return arbolMasAlto;
}
int ControlParques::contarEspecies(string nbre_parque){
    Parque* parque =buscarParque(nbre_parque);
    if(parque!=nullptr){
        return parque->contarEspecies();
    }
    return 0;
}
int ControlParques::contarTipos(){
    list<Parque>::iterator it=parks.begin();
    set<string> tiposUnicos;
    while(it!=parks.end()){
        const vector<Arbol*> &arboles= it->get_contains();
        for (int i = 0; i < arboles.size(); i++){
            string tipo = arboles[i]->getTipoEspecie();
            if (!tipo.empty()) {
                tiposUnicos.insert(tipo);
            }
        }
        it++;
    }
    return tiposUnicos.size();
}

unsigned int ControlParques::numArboles() const {
    return trees.size();
}

vector<Parque*> ControlParques::listarParquesArbol(const string& ncomun){
    set<Parque*> parquesUnicos;
    multimap<string, Arbol*>::iterator it = treeName.lower_bound(ncomun);
    multimap<string, Arbol*>::iterator fin = treeName.upper_bound(ncomun);
    while(it!=fin){
        Parque* paux=it->second->getParque();
        if(paux!=nullptr){
            parquesUnicos.insert(paux);
        } 
        
        it++;
    }
    return vector<Parque*>(parquesUnicos.begin(), parquesUnicos.end());
}

vector<Arbol*> ControlParques::buscarArbolNcomun(const string& ncomun){
    vector<Arbol*> resultados;
    multimap<string,Arbol*>::iterator it = treeName.lower_bound(ncomun);
    while(it != treeName.end()&&it->first==ncomun){
        resultados.push_back(it->second);
        it++;
    }
    return resultados;
}

vector<Arbol*> ControlParques::buscarArbolNcomunComienzo(const string& ncomun){
    pair<multimap<string,Arbol*>::iterator,multimap<string,Arbol*>::iterator> pareja = treeName.equal_range(ncomun);
    vector<Arbol*> resultados;
    while(pareja.first!=pareja.second){
        resultados.push_back(pareja.first->second);
        pareja.first++;
    }
}

