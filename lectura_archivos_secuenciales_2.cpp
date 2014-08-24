#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main() {
    string elProducto;
    int elPrecio;
    float laCantidad;
    int laSuma=0;
    
    ifstream miArchivo;
    miArchivo.open("input.txt");
    
    if (miArchivo.is_open()) {
        
        cout<<"Su cuenta"<<endl<<endl;
        
        while (!miArchivo.eof()) {
            
            miArchivo>>elProducto>>elPrecio>>laCantidad;
            //Reajuste de precios
            elPrecio *= 1.30;
            
            //El impuesto IVA
            elPrecio *= 1.19;
            
            //Imprimimos
            cout<<elProducto<<": ("<<laCantidad<<"x"<<elPrecio<<") = $";
            cout<<(int)(laCantidad*elPrecio)<<".-"<<endl;
            
            //Sumamos
            laSuma+=(int)(laCantidad*elPrecio);
            
        }
        cout<<endl<<endl;
        cout<<"Total a pagar: $"<<laSuma<<".-";
    }
    miArchivo.close();
    return 0;
}
