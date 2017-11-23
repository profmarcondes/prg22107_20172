#ifndef FUNCOES_H
#define FUNCOES_H

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Funcao {
protected:
    Funcao* _f;

public:
    Funcao(): _f(0) {}
    Funcao(Funcao* f): _f(f) {}
    virtual double operator()(double x) = 0;
    virtual ~Funcao() {}

    static double integrar(Funcao* f, double x0, double x1, double step){
        double res;
        if(x1 < x0){
            res = x0;
            x0 = x1;
            x1 = res;
        }
        res = 0;
        while(x0 < x1){
            res += step * (*f)(x0);
            x0 += step;
        }
        return res;
    }
};

class Constante: public Funcao {
    const double _value;
public:
    Constante(double val): _value(val) {}
    double operator()(double x){
        return _value;
    }
};

class Escalar: public Funcao {
    const double _value;
public:
    Escalar(double val, Funcao* f): Funcao(f), _value(val) {}
    Escalar(Funcao* f): Funcao(f), _value(1) {}
    Escalar(double val): _value(val) {}
    Escalar(): _value(1) {}

    double operator()(double x){
        if(_f)
            x = (*_f)(x);
        return _value*x;
    }
};

class Potencial: public Funcao {
    const double _value;
public:
    Potencial(double val, Funcao* f): Funcao(f), _value(val) {}
    Potencial(Funcao* f): Funcao(f), _value(1) {}
    Potencial(double val): _value(val) {}
    Potencial(): _value(1) {}

    double operator()(double x){
        if(_f)
            x = (*_f)(x);
        return pow(x,_value);
    }
};

class Exponencial: public Funcao {
    const double _value;
public:
    Exponencial(double val, Funcao* f): Funcao(f), _value(val) {}
    Exponencial(Funcao* f): Funcao(f), _value(1) {}
    Exponencial(double val): _value(val) {}
    Exponencial(): _value(1) {}

    double operator()(double x){
        if(_f)
            x = (*_f)(x);
        return pow(_value,x);
    }
};

class Seno: public Funcao {
public:
    Seno(Funcao* f = 0): Funcao(f) {}
    double operator()(double x){
        if(_f)
            x = (*_f)(x);
        return sin(x);
    }
};

class Coseno: public Funcao {
public:
    Coseno(Funcao* f = 0): Funcao(f) {}
    double operator()(double x){
        if(_f)
            x = (*_f)(x);
        return cos(x);
    }
};

class FuncaoAgregada: public Funcao {
    vector<Funcao*> _lista;
public:
    FuncaoAgregada() {}
    FuncaoAgregada(Funcao * f1, Funcao * f2){
        _lista.push_back(f1);
        _lista.push_back(f2);
    }
    FuncaoAgregada(Funcao * f1, Funcao * f2, Funcao * f3){
        _lista.push_back(f1);
        _lista.push_back(f2);
        _lista.push_back(f3);
    }
    void agrega(Funcao * f){
        _lista.push_back(f);
    }
    double operator()(double x){
        double result = 0;
        for(vector<Funcao *>::iterator vi=_lista.begin(); vi!=_lista.end(); vi++){
            result += (**vi)(x);
        }
        return result;
    }
};

#endif // FUNCOES_H
