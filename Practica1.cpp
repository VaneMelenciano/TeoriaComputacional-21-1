#include <iostream>

using namespace std;

void encabezado();
class Cadena{
    private:
        string palabra;
        int longitud_palabra;
    public:
        void pedir_palabra(string);
        string Prefijos();
        string Sufijos();
        string SubCadenas();
        Cadena();
        ~Cadena();
};

Cadena::Cadena(){
    longitud_palabra=0;
    palabra=' ';
}
Cadena::~Cadena(){
    longitud_palabra=0;
    palabra=' ';
}

void Cadena::pedir_palabra(string pa){
    palabra=pa;
    longitud_palabra=palabra.length();
}
string Cadena::Prefijos(){
    int k=0;
    while(k<(longitud_palabra-1)){
    k++;
        for(int i=0; i<k; i++){
           cout << palabra[i];
        }
        cout << endl;
    }
}
string Cadena::Sufijos(){
    int o=(longitud_palabra-1);
    while(o>=1){
        for(int j=o; j<=longitud_palabra-1; j++){
            cout << palabra[j];
        }
        cout << endl;
        o--;
    }
}
string Cadena::SubCadenas(){
    if(longitud_palabra>2){
            int cont=0;
            int g=longitud_palabra-2;
            if(g==2){
                cout << palabra[1] << endl << palabra[2] << endl;
                for(int y=1; y<longitud_palabra-1; y++){
                    cout << palabra[y];
                }cout << endl << endl << "La palabra no tiene mas subcadenas" << endl << endl;

            }
            else{
                int x=1, l=2;
                while((longitud_palabra-l)>=2){
                    cout << palabra.substr(x, (longitud_palabra-l)) << endl;
                    l++;
                    cont++;
                }
                    while(cont<6){
                        int b=2, p=3;
                        while((longitud_palabra-p)>=2 && cont < 6){
                        cout << palabra.substr(b, (longitud_palabra-p)) << endl;
                        p++;
                        b++;
                        cont++;
                        }
                    }
                }
    }
    else{
        cout << "La palabra no tiene subcadenas" << endl;
    }
}



int main()
{
    string pal;
    Cadena objeto;
    int opcion;
    system("color 0F");
    encabezado();

    do {
    cout << endl << "\t\t\t***MENU***" << endl;
    cout << "\t\t-----------------------" << endl;
    cout << "\t\t1] Ingresar palabra" << endl;
    cout << "\t\t2] Salir" << endl;
    cout << "\t\t-----------------------" << endl;
    cout << endl << "\t  Introduzca la accion que desea realizar: ";
    cin >> opcion;
    cout << endl;
    switch(opcion)
    {
        case 1:
            cout << endl << "Escriba la palabra: " << endl;
            cin >> pal;
            int lon = pal.length();
            if(lon==1){
                cout << "La palabra no tiene una longitud suficiente para generar prefijos, sufijos y subcadenas" << endl;
            }
            else{
            objeto.pedir_palabra(pal);
            cout << endl << "prefijos" << endl << endl;
            objeto.Prefijos();
            cout << endl << "sufrijos" << endl<< endl;
            objeto.Sufijos();
            cout << endl << "Subcadenas" << endl << endl;
            objeto.SubCadenas();
            cout << endl;
            }
            break;
    }
    system("pause");
            system("cls");

}
while ( opcion != 2);
system("cls"); //LIMPLIAR PANTALLA
cout << endl << "FIN!" << endl;

    return 0;
}

void encabezado(){
 cout << "\t\t    INSTITUTO POLITECNICO NACIONAL " << endl << "UNIDAD PROFESIONAL INTERDISCIPLINARIA DE INGENIERIA CAPUS ZACATECAS" << endl <<  "\t\tINGENIERIA EN SISTEMAS COMPUTACIONALES" << endl << endl << "\t\t\tTeoria computacional" << endl << "\t \t \t \t2CM2" << endl << "\t\t     Vanessa Melenciano Llamas" << endl << "\t\t\t      2020670081" << endl << "\t \t       8 de octubre de 2020" << endl;
}

