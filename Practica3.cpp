#include <bits/stdc++.h>

using namespace std;
void encabezado();

struct DExpresiones{
		char Dato;
		DExpresiones *Ant;
		DExpresiones *Sig;
};

class Expresion{
	private:
		DExpresiones *ListaExpresion; //guarda la expresion
		string alfabeto;
		string salidasF;
		int PosicionActual=0;
		int num;
		char vacio = 'E';
	public:
		void Ingresar(char);
		bool Vacia();
		void Mostrar();
		void Formal();
		void Formal1(int);
		void Vaciar();
		bool BuscarAlfabeto(char, int);
		Expresion();
		~Expresion();
};

Expresion::Expresion(){
	ListaExpresion = NULL;
	num=0;
	PosicionActual = 0;
}

void Expresion::Ingresar(char dat){ //ingresar expresion
	DExpresiones *Temp;
	Temp = new DExpresiones;

	if (Temp==NULL)
		cout << "No se genero la direccion de memoria" << endl;
	else{
		if(Vacia()==true){
			Temp->Ant=NULL;
			Temp->Sig=NULL;
			Temp->Dato=dat;
			ListaExpresion = Temp;
		}
		else{
			while (ListaExpresion->Sig!=NULL)
					ListaExpresion=ListaExpresion->Sig;

				Temp -> Dato=dat;
				Temp -> Sig = NULL;
				Temp -> Ant = ListaExpresion;
				ListaExpresion -> Sig = Temp;
		}
	num++;
	}
}

bool Expresion::Vacia(){ //expresion
	if(num==0)
		return true;
	else
		return false;
}

void Expresion::Mostrar(){ //expresion
	DExpresiones *Temp;
	if(num==0){
        cout << "\t\t\tNo hay expresion" << endl;
	}
	else
	{
	while (ListaExpresion->Ant!=NULL){
		ListaExpresion=ListaExpresion->Ant;
	}
	Temp=ListaExpresion;
	while (Temp!=NULL)
	{
		cout << Temp->Dato;
		Temp=Temp->Sig;
		}
	}
}

Expresion::~Expresion(){
    if(Vacia()==false){
        DExpresiones *Temp;
        Temp= new DExpresiones;
        if(num==1){
            Temp=ListaExpresion;
            delete Temp;
        }
        else{
            while(ListaExpresion->Sig!=NULL && ListaExpresion->Ant!=NULL){
                while(ListaExpresion->Ant!=NULL){
                    ListaExpresion=ListaExpresion->Ant;
                }
                Temp=ListaExpresion;
                ListaExpresion=Temp->Sig;
                ListaExpresion->Ant=NULL;
                delete Temp;
            }
            Temp=ListaExpresion;
            delete Temp;
        }
    }
}

void Expresion::Formal(){
    int n = num;
    int contA=0;
    DExpresiones *Temp;
    Temp = ListaExpresion;
    while (Temp->Ant!=NULL){
        Temp=Temp->Ant;
    } //Temp está en el inicion de la lista
    while(n>0)
        {
            switch (Temp->Dato)
            {
            case '+':
                cout << "(q" << PosicionActual << ", " << Temp->Ant->Dato << ") -> q" << PosicionActual+1 << endl;
                PosicionActual++;
                cout << "(q" << PosicionActual << ", " << Temp->Ant->Dato << ") -> q" << PosicionActual << endl;
                //char dato = Temp->Ant->Dato;
                    if(BuscarAlfabeto(Temp->Ant->Dato, contA) == false){
                        /*continue;
                    }
                    else{*/
                            cout << "entro" << endl;
                        alfabeto[contA] = Temp->Ant->Dato;
                        contA++;
                    }
                break;
            case '*':
                cout << "(q" << PosicionActual << ", " << vacio << ") -> q" << PosicionActual+1 << endl;
                PosicionActual++;
                cout << "(q" << PosicionActual << ", " << Temp->Ant->Dato << ") -> q" << PosicionActual << endl;
                    alfabeto[contA] = Temp->Ant->Dato;
                    contA++;
                break;
            case '|':
				cout << "(q" << PosicionActual << ", " << Temp->Ant->Dato << ") -> q" << PosicionActual+1 << endl;
				cout << "(q" << PosicionActual << ", " << Temp->Sig->Dato << ") -> q" << PosicionActual+1 << endl;
				PosicionActual++;
                    alfabeto[contA] = Temp->Ant->Dato;
                    contA++;
                    alfabeto[contA] = Temp->Sig->Dato;
                    contA++;
                Temp=Temp->Sig;
				break;
			case '?':
				cout << "(q" << PosicionActual << ", " << Temp->Ant->Dato << ") -> q" << PosicionActual+1 << endl;
				cout << "(q" << PosicionActual << ", " << vacio << ") -> q" << PosicionActual+1 << endl;
                    alfabeto[contA] = Temp->Ant->Dato;
                    contA++;
                    PosicionActual++;
				break;
            default:
					if(Temp->Sig==NULL){
                        cout << "(q" << PosicionActual << ", " << Temp->Dato << ") -> q" << PosicionActual+1 << endl;
                        PosicionActual++;
                            alfabeto[contA] = Temp->Dato;
                            contA++;
					}
					else if ((Temp->Sig->Dato!='+')&&(Temp->Sig->Dato!='*')&&(Temp->Sig->Dato!='?')&&(Temp->Sig->Dato!='|'))
					{
						cout << "(q" << PosicionActual << ", " << Temp->Dato << ") -> q" << PosicionActual+1 << endl;
                        PosicionActual++;
                            alfabeto[contA] = Temp->Dato;
                            contA++;
					}
                break;
            } //switch
            if(Temp->Sig!=NULL){
            Temp = Temp->Sig;}
            else if(Temp->Sig==NULL){
                    break;
				}
            n--;
       }
       Formal1(contA);
       Vaciar();

}

bool Expresion::BuscarAlfabeto(char d, int contA){ //si lo encuetra true
    bool bandera = false;
    for(int i=0; i<contA; i++){
        if(alfabeto[i]==d){
            bandera = true; //si lo encuentra
        }
    }
    if(bandera == false){ //no esta
        return false;
    }
    else{
        return true;
    }
}

void Expresion::Formal1(int a){
    cout << endl << "M = ({";
    for(int i=0; i<a; i++){
        if(i<a-1) cout << alfabeto[i] << ", ";
        else cout << alfabeto[i];
    }
    cout <<"}, {";
    for(int j=0; j<=PosicionActual; j++){
        if(j<PosicionActual) cout << "q" << j << ", ";
        else cout << "q" << j;
    }
    cout <<"}, Trans , {q0}, {q" << PosicionActual << "})" << endl;
}

void Expresion::Vaciar(){
    if(Vacia()==false){
        DExpresiones *Temp;
        Temp= new DExpresiones;
        if(num==1){
            Temp=ListaExpresion;
            delete Temp;
        }
        else{
            while(ListaExpresion->Sig!=NULL && ListaExpresion->Ant!=NULL){
                while(ListaExpresion->Ant!=NULL){
                    ListaExpresion=ListaExpresion->Ant;
                }
                Temp=ListaExpresion;
                ListaExpresion=Temp->Sig;
                ListaExpresion->Ant=NULL;
                delete Temp;
            }
            Temp=ListaExpresion;
            delete Temp;
        }
    }
    ListaExpresion = NULL;
	num=0;
	PosicionActual = 0;
}

int main()
{
    Expresion exp;
    char opcion;
    encabezado();

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
            cout << endl << "Favor no poner nada por la concatenacion " << endl;
            cout << endl << "\t\t Escriba la expresion regular >>>> " << endl;
            string ex;
            cin >> ex;
            system("color 0F");
            for(int i=0; i<ex.length(); i++){
                exp.Ingresar(ex[i]);
            }
            system("pause");
            system("cls");
            cout << "-------------------------------------------"<< endl;
            cout << "Expresion regular:" << endl << endl << "\t\t";
            exp.Mostrar();
            cout << endl << endl << "-------------------------------------------"<< endl  <<endl;
            exp.Formal();
            cout << "-------------------------------------------"<< endl << endl;
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
 cout << "\t\t    INSTITUTO POLITECNICO NACIONAL " << endl << "UNIDAD PROFESIONAL INTERDISCIPLINARIA DE INGENIERIA CAPUS ZACATECAS" << endl <<  "\t\tINGENIERIA EN SISTEMAS COMPUTACIONALES" << endl << endl << "\t\t\tTeoria computacional" << endl << "\t \t \t \t2CM2" << endl << "\t\t     Vanessa Melenciano Llamas" << endl << "\t\t\t      2020670081" << endl << "\t \t       6 de noviembre de 2020" << endl;
}
