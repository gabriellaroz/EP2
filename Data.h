#ifndef DATA_H
#define DATA_H

class Data {
public:
    Data(int mes, int ano);
    Data(Data* base, int meses);

virtual ~Data();
int getMes(); 
int getAno(); 
static bool estaDentroDoPeriodo(Data* inicio, Data* fim, Data* d); 
static bool temInterseccao(Data* inicio1, Data* fim1, Data* inicio2, Data* fim2); 

private: 
 int mes;
 int ano; 
};

#endif