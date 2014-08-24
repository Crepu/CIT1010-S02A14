#include <iostream>

using namespace std;

void ordena_arreglo(int *a, int l);

int main()
{
   int n=0;
   int cont = 0;
   int aa[1000];
   
   cout << "Ingrese un numero entero positivo (-1 para terminar)" << endl;
   cin >> n;
   
   while (n!=-1)
   {
       aa[cont++] = n;
       cout << "Ingrese un numero entero positivo (-1 para terminar)" << endl;
       cin >> n;
   }
   
   //Imprime original
   for(int i=0; i<cont; i++)
   cout << aa[i] << endl;
      
   cout << endl;
   
   //ordena
   ordena_arreglo(aa,cont);
   
   //imprime ordenado
   for(int i=0; i<cont; i++)
   cout << aa[i] << endl;
   
   return 0;
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

