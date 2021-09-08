#include <bits/stdc++.h>

using namespace std;

void encabezado();

class expresiones{
    private:
        string expresion;
        string cadena;
    public:
        void Pedir(string, string);
        bool comprobar();
        expresiones();
        ~expresiones();
        void NoValida();
};

expresiones::expresiones(){}

expresiones::~expresiones(){}

void expresiones::Pedir(string Ex, string Ca){
    expresion=Ex;
    cadena=Ca;
}
bool expresiones::comprobar(){
    int lonex=expresion.size();
    int lonca=cadena.size();
    int k=0;
    if(lonex==1){ // si la expresion solo tiene un caracter
        if(isalpha(expresion[k])){ // si ese caracter es una letra
            if(expresion[k]==cadena[k]){ // si esa letra es igual a la primera de la cadena
                if(lonca == 1){ //si la cadena solo tiene esa letra
                    return true;
                }
                else{
                    return false;
                }
            }
            else{return false;}

        }
    }
    int i=1, j=0;

    while(i < lonex){
            if(expresion[i]=='|'){
                        if(cadena[j]==expresion[i-1]){
                            i+=2;
                            if(i==lonex && j+1!= lonca){
                                return false;
                                break;
                            }
                            else if(i==lonex && j+1 == lonca){
                                return true;
                            }
                            else{
                                j++;
                                continue;
                            }
                        }
                        else if(cadena[j]==expresion[i+1]){
                            i+=2;
                            if(i==lonex && j+1!= lonca){
                                return false;
                                break;
                            }
                            else{
                                j++;
                                continue;
                            }
                        }
                        else{
                            return false;
                            break;
                        }
                }
            if(expresion[i]=='+'){
                        if(cadena[j]==expresion[i-1]){
                            while(cadena[j]==expresion[i-1]){
                                j++;
                            }
                            if(cadena[j]==expresion[i-1]){
                                i++;
                                continue;
                            }
                            else{
                                if(j==lonca && i+1 == lonex){
                                    return true;
                                }
                                else if(j!=lonca && i+1 == lonex){
                                    return false;
                                    break;
                                }
                                        i++;
                                    continue;
                            }
                        }
                        else{
                            return false;
                            break;
                        }
                }
            if(expresion[i]=='*'){
                        if(cadena[j]!=expresion[i-1]){
                            i++;
                            if(cadena[j]=='E'){
                                j++;
                                if(j==lonca){
                                    return true;
                                }
                                else{
                                    continue;
                                }
                            }
                            else if(i==lonex && j!= lonca){
                                return false;
                                break;
                            }
                            else if(i==lonex && j== lonca){
                                return true;
                            }
                            else{
                                continue;
                            }
                        }
                        else{
                            while(cadena[j]==expresion[i-1]){
                                j++;
                            }
                            if(cadena[j-1]==expresion[i-1]){
                                if(i+1 == lonex && j == lonca){
                                    return true;
                                }
                                else{
                                i++;
                                continue;
                                }
                            }
                            else{
                                if(j==lonca && i+1 == lonex){
                                    return true;
                                }
                                else if(j!=lonca && i+1 == lonex){
                                    return false;
                                    break;
                                }
                                else{
                                        i++;
                                    continue;
                                }
                            }
                        }
            }
            if(expresion[i]=='?'){
                        if(cadena[j]!=expresion[i-1]){
                            i++;
                            if(cadena[j]=='E'){
                                    if(j+1==lonca && i==lonex){
                                        return true;
                                    }
                                    else{
                                        return false;
                                    }
                            }
                            else if(i==lonex && j !=lonca){
                                    return false;
                                    break;
                            }
                            else if(i==lonex && j == lonca){
                                return true;
                            }
                            else{
                                continue;
                            }
                        }
                        else{ // si son iguales
                            i++;
                            if(i==lonex && isalpha(cadena[j+1])){
                                    return false;
                                    break;
                            }
                            else if(i==lonex && j+1==lonca){
                                return true;
                            }
                                    j++;
                        }
                }
            if(expresion[i]=='.'){
                if(isalpha(expresion[i-1]) && expresion[i-2]!='|'){
                        if(expresion[i-1]==cadena[j]){
                            j++;
                            i+=2;
                            if(i==lonex){
                                if(expresion[i-1]==cadena[j] && j+1 == lonca){ return true; }
                                else{return false;}
                            }
                            else{
                                if(isalpha(expresion[i-1])){
                                    if(expresion[i-1]==cadena[j]){continue;}
                                    else{return false;}
                                }
                                else{continue;}
                            }
                        }
                        else{
                                return false;
                        }
                }
                else if(isalpha(expresion[i+1]) && expresion[i+2]=='.'){
                    if(expresion[i+1]==cadena[j]){
                            i+=2;
                            if(i==lonex){
                                if(expresion[i-1]==cadena[j] && j+1 == lonca){ return true; }
                                else{return false;}
                            }
                            else{
                                if(isalpha(expresion[i-1])){
                                    if(expresion[i-1]==cadena[j]){continue;}
                                    else{return false;}
                                }
                                else{continue;}
                            }
                        }
                        else{
                                return false;
                        }
                }
                else if(isalpha(expresion[i+1]) && i+2 == lonex){
                    if(expresion[i+1]==cadena[j]){
                         if(j+1 == lonca){
                            return true;
                         }
                         else{
                            return false;
                         }
                    }
                    else{
                            return false;
                    }
                }
            i+=2;

            }

            if(isalpha(expresion[i])){
                if(expresion[i]==cadena[j]){
                        j++;
                        i++;
                        continue;
                }
                else{return false;}
            }
    }
if(i != lonex |  j != lonca){return false;}
else{return true;}
}


int main()
{
    char opcion;

    encabezado();
    expresiones obj;

    do {
    system("color 0E");
    cout << endl << "\t\t\t\t***MENU***" << endl;
    cout << "\t\t\t--------------------------" << endl;
    cout << "\t\t\tA] Introducir una expresion " << endl;
    cout << "\t\t\tB] Salir" << endl;
    cout << "\t\t\t--------------------------" << endl;
    cout << endl << "\t  Introduzca la accion que desea realizar: ";
    cin >> opcion;
    cout << endl;
		  opcion = toupper(opcion);

    switch(opcion)
    {
        case 'A':
            system("cls");
            system("color 08");
            cout << endl << "Favor de expresar el vacio con 'E' y la concatenacion con un punto '.' " << endl;
            cout << endl << "\t\t Escriba la expresion regular >>>> " << endl;
            string ex;
            cin >> ex;
            cout << endl << endl << "Si desea cambiar de expresion, ingrese un '1'" << endl << "\t\t";
            string ca;
            while(ca!="1"){
            system("color 0F");
                cout << endl << endl << "\t Escriba la cadena a evaluar >> ";

                cin >> ca;
                if(ca!="1"){
                cout << endl;
                obj.Pedir(ex, ca);
                if(obj.comprobar()==true){
                    cout << "Aceptada" << endl;
                }
                else{
                    cout << "No aceptada" << endl;
                }
                }
                else{
                    system("color 08");
                    cout << endl;
                }
            }

            system("pause");
            system("cls");
            break;
    }

}
while ( opcion != 'B' && opcion != 'b' );
system("cls"); //LIMPLIAR PANTALLA
system("color 0A");
cout << endl << "FIN!" << endl;


    return 0;
}

void encabezado(){
 cout << "\t\t    INSTITUTO POLITECNICO NACIONAL " << endl << "UNIDAD PROFESIONAL INTERDISCIPLINARIA DE INGENIERIA CAPUS ZACATECAS" << endl <<  "\t\tINGENIERIA EN SISTEMAS COMPUTACIONALES" << endl << endl << "\t\t\tTeoria computacional" << endl << "\t \t \t \t2CM2" << endl << "\t\t     Vanessa Melenciano Llamas" << endl << "\t\t\t      2020670081" << endl << "\t \t       17 de noviembre de 2020" << endl;
}
