#include <iostream>

using namespace std;

void ordena_arreglo(int *a, int l);
void imprime_arreglo(int *a, int l);
void aso(int *a, int l, int x, float f); // amplifica seleccion en arreglo ordenado

int main()
{
   int n=0;
   int cont = 0;
   int aa[1000];
   int busc;
   float fact;
   
   cout << "Ingrese un conjunto de numeros enteros positivo (-1 para terminar)" << endl;
   cin >> n;
   
   while (n!=-1)
   {
       aa[cont++] = n;
       //cout << "Ingrese un numero entero positivo (-1 para terminar)" << endl;
       cin >> n;
   }
   
   cin >> busc;
   cin >> fact;
   
   //Imprime original
   cout << "ingresado: ";
   cout<<"lala"<<endl;
   imprime_arreglo(aa,cont);
   
   cout << "buscar: " << busc << endl;
   cout << "factor: " << fact << endl << endl;
   
   //ordena
   ordena_arreglo(aa,cont);
      
   //imprime ordenado
   cout << "ordenado:" << endl;
   imprime_arreglo(aa,cont);
   
   aso(aa, cont, busc, fact);
   
   return 0;
}

void aso(int *a, int l, int x, float f)
{
    //BUSCO
    int pos = -1;
    for(int i=0; i<l; i++)
    {
        if (a[i]==x)
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
    {
        //cout << "NO ESTA";
        return;
    }
        
    // AMPLIFICO
    a[pos] *= f;
    
    imprime_arreglo(a,l);
    
    //MANTENGO ORDEN
    int temp;
    while ( a[pos] > a[pos+1] && pos < l-1)
    {
        temp = a[pos];
        a[pos] = a[pos+1];
        a[pos+1] = temp;
        pos++;
        imprime_arreglo(a,l);
    }
    
    while ( a[pos] < a[pos-1] && pos > 0)
    {
        temp = a[pos];
        a[pos] = a[pos-1];
        a[pos-1] = temp;
        pos--;
        imprime_arreglo(a,l);
    }
    
}

void ordena_arreglo(int *a, int l)
{
    int aux = 0;

    for (int i=0; i<l; i++)
    {
        for (int j=0; j<l; j++)
        {
            if (a[i] < a[j])
            {
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
        }
    }
}

void imprime_arreglo(int *a, int l)
{
    for(int i=0; i<l; i++)
    cout << a[i] << " ";
    cout << endl;
}

