#include <bits/stdc++.h>

using namespace std;

void encabezado();

struct DProduccion{
		string Dato;
		DProduccion *Ant;
		DProduccion *Sig;
};
class Producciones{
    private:
        DProduccion *Lista;
        DProduccion *ListaFNC;
        int num; //De FNC
        int numPro; //de lista original
        char posA; //numero en que va A
        int numPaso2; //cuantas produciones en paso 2
        int nuevaPosA; //posicion de A, en entero
    public:
        void ingresar(string);
        bool Vacia();
        void mostrarLista();
        void paso1();
        void paso2();
        void paso3(vector<char>);
        void paso4();
        void paso5();
        void borrarDato(int);
        void ingresarPrincipio(string);
        void ingresarFinal(string);
        void vaciar();
        void mostrarFNC();
        Producciones();
        ~Producciones();
};


void Producciones::ingresarPrincipio(string dat){ //ingrresar en FNC
    DProduccion *Temp;
	Temp = new DProduccion;
	if(Temp==NULL)
	{
		cout << "No se genero la direccion de memoria" << endl;
	}
	else{
		if(num==0)
		{
			Temp -> Ant = NULL;
			Temp -> Sig = NULL;
			Temp -> Dato = dat;
			ListaFNC = Temp;
		}
		else{
			while(ListaFNC->Ant!=NULL)
			{
				ListaFNC=ListaFNC->Ant;
			}
			Temp->Dato=dat;
			Temp->Sig=ListaFNC;
			Temp->Ant=NULL;
			ListaFNC->Ant=Temp;
		}
	num++;
	}
}
void Producciones::ingresarFinal(string dat){ //ingrresar en FNC
    DProduccion *Temp;
	Temp = new DProduccion;
	if(Temp==NULL)
	{
		cout << "No se genero la direccion de memoria" << endl;
	}
	else{
		if(num==0)
		{
			Temp -> Ant = NULL;
			Temp -> Sig = NULL;
			Temp -> Dato = dat;
			ListaFNC = Temp;
		}
		else{
			while(ListaFNC->Sig!=NULL)
			{
				ListaFNC=ListaFNC->Sig;
			}
			Temp->Dato=dat;
			Temp->Sig=NULL;
			Temp->Ant=ListaFNC;
			ListaFNC->Sig=Temp;
		}
	num++;
	}
}

void Producciones::mostrarFNC(){
    DProduccion *Temp;
	if(num==0){
        cout << "\t\t\tNo hay expresion" << endl;
	}
	else
	{
	while (ListaFNC->Ant!=NULL){
		ListaFNC=ListaFNC->Ant;
	}
	Temp=ListaFNC;
	while (Temp!=NULL)
	{
		cout << Temp->Dato << endl;
		Temp=Temp->Sig;
		}
	}
}

Producciones::Producciones(){
    numPro=0;
    num = 0;
    Lista = new DProduccion;
    ListaFNC = new DProduccion;
    numPaso2=0;
    nuevaPosA=0;
}
bool Producciones::Vacia(){
    if(numPro==0){
        return true;
    }
    else{
        return false;
    }
}
Producciones::~Producciones(){
    if(Vacia()==false){
        DProduccion *Temp;
        Temp= new DProduccion;
        if(numPro==1){
            Temp=Lista;
            delete Temp;
        }
        else{
            while(Lista->Sig!=NULL && Lista->Ant!=NULL){
                while(Lista->Ant!=NULL){
                    Lista=Lista->Ant;
                }
                Temp=Lista;
                Lista=Temp->Sig;
                Lista->Ant=NULL;
                delete Temp;
            }
            Temp=Lista;
            delete Temp;
        }

        DProduccion *Temp1;
        Temp1= new DProduccion;
        if(ListaFNC==NULL){
            Temp1=ListaFNC;
            delete Temp1;
        }
        else{
            while(ListaFNC->Sig!=NULL && Lista->Ant!=NULL){
                while(ListaFNC->Ant!=NULL){
                    ListaFNC=ListaFNC->Ant;
                }
                Temp1=ListaFNC;
                ListaFNC=Temp1->Sig;
                ListaFNC->Ant=NULL;
                delete Temp1;
            }
            Temp1=ListaFNC;
            delete Temp1;
        }
    }
}
void Producciones::ingresar(string dat){
    DProduccion *Temp;
	Temp = new DProduccion;

	if (Temp==NULL)
		cout << "No se genero la direccion de memoria" << endl;
	else{
		if(Vacia()==true){
			Temp->Ant=NULL;
			Temp->Sig=NULL;
			Temp->Dato=dat;
			Lista = Temp;
		}
		else{
			while (Lista->Sig!=NULL)
					Lista=Lista->Sig;

				Temp -> Dato=dat;
				Temp -> Sig = NULL;
				Temp -> Ant = Lista;
				Lista -> Sig = Temp;
		}
	numPro++;
	}
}
void Producciones::mostrarLista(){
    DProduccion*Temp;
	if(numPro==0){
        cout << "\t\t\tLista vacia" << endl;
	}
	else
	{
	while (Lista->Ant!=NULL){
		Lista=Lista->Ant;
	}
	Temp=Lista;
	while (Temp!=NULL)
	{
		cout << "\t\t\t" << Temp->Dato << endl;
		Temp=Temp->Sig;
		}
	}
}
void Producciones::borrarDato(int posicion){ //2
    DProduccion *Temp;
    while(Lista->Ant!=NULL)
    {
        Lista=Lista->Ant;
    }
    Lista = Lista->Sig;
    Temp = Lista;
    while(posicion-2){
        Temp=Temp->Sig;
        posicion--;
    }
    if(Temp->Ant!=NULL && Temp->Sig != NULL){
        Temp->Ant->Sig=Temp->Sig;
        Temp->Sig->Ant=Temp->Ant;
        delete Temp;
        numPro-=1;
    } else if(Temp->Ant!=NULL){//ultimo
        Temp->Ant->Sig=NULL;
        delete Temp;
        numPro-=1;
    } else if(Temp->Sig!=NULL){ //primero
        Temp->Sig->Ant=NULL;
        delete Temp;
        numPro-=1;
    }
}
void Producciones::paso1(){
    DProduccion *Temp;
    while(Lista->Ant!=NULL)
    {
        Lista=Lista->Ant;
    }
    Lista = Lista->Sig;
    Temp = Lista;
	int n=2;
	int ma = numPro;
	while(n<=ma){ //recorre la lista
	    string d = Temp->Dato;
	    int lon = d.length();
	    if(lon<8){
            if((d[lon-1] > 96) &&(d[lon-1] <123)){
                ingresarFinal(d);
                borrarDato(n);
                n--; ma--;
            }
	    }
        if(Temp->Sig!=NULL){
            Temp = Temp ->Sig;
        }
      n++;
	}
	string dato = Temp->Dato;
	posA = dato[1];
	paso2();
}
void Producciones::paso2(){
    DProduccion *Temp;
    while(Lista->Ant!=NULL)
    {
        Lista=Lista->Ant;
    }
    Lista = Lista->Sig;
    Temp = Lista;
    int n=2;
    int numMinus=0;
    vector<char> abc; //minusculas
    int ma = numPro;
	while(n<=ma){ //metemos al vector todas las minusculas que haya
	    string d = Temp->Dato;
        int lon = d.length();
	    for(int i=0; i<lon;i++){
            if((d[i] > 96) &&(d[i] <123)){ //si es minuscula
                abc.push_back(d[i]); //guarda todas las minusculas que haya
            }
	    }
        if(Temp->Sig!=NULL){
        Temp = Temp ->Sig;}
      n++;
	}
	//borrar repeticiones
	for(int i=0; i<abc.size(); i++){ //tomando
        for(int j=i+1; j<abc.size(); ){ //nuevo
            if(abc[i]==abc[j]){
                abc.erase(abc.begin()+j);
            }
            else{j++;}
        }
	}
	//ordenar alfabericamnete
    sort( abc.begin( ), abc.end( ) );
	int pA = (int)posA - 48; // convertir a entero //3
	numPaso2=abc.size()+pA; //ingresa vector en FNC
	for(int i=pA+1, j=0; i<=numPaso2, j<abc.size(); i++, j++){
        string dato = "A" + to_string(i) + " -> " + abc[j];
        ingresarFinal(dato);
	}

	paso3(abc);
}
void Producciones::paso3(vector<char> abc){
    DProduccion *Temp;
    while(Lista->Ant!=NULL)
    {
        Lista=Lista->Ant;
    }
    Lista = Lista->Sig;
    Temp = Lista; //lista en inicio

    DProduccion *Temp1;
    while(ListaFNC->Ant!=NULL)
    {
        ListaFNC=ListaFNC->Ant;
    }
    Temp1 = ListaFNC;

    int n=2;
	int ma = numPro;
	int pA = (int)posA - 48 +1; // convertir a entero
	while(n<=ma){ //recorre la lista
	    string d = Temp->Dato;
	    for(int i=0; i<d.length(); i++){
            if((d[i] > 96) && (d[i] <123)){ //si es minuscula
                vector<char> buscar;
                buscar.push_back(d[i]);
                auto it = search(abc.begin(), abc.end(), buscar.begin(), buscar.end());
                int pos = it - abc.begin();
                int nueA = pos+pA;
                string nuevo = "A" + to_string(nueA);
                d.replace(i, 1, nuevo);
            }
	    }
    Temp->Dato = d;
    if(Temp->Sig!=NULL){
      Temp = Temp ->Sig;}
    n++;
	}
	pA+=abc.size()-1;
	nuevaPosA = pA;

    paso4();
}
void Producciones::paso4(){
    DProduccion *Temp;
    while(Lista->Sig!=NULL)
    {
        Lista=Lista->Sig;
    }
    Temp = Lista; //lista en inicio
    int n=2;
	int ma = numPro; //numero de productos
	while(ma>=2){ //recorre la lista
	    string d = Temp->Dato;
	    int lon = d.length();
	    if(lon <=11){
	        ingresarPrincipio(d);
	        if(Temp->Ant!=NULL){
                Temp = Temp ->Ant;
            }
            borrarDato(ma);
            ma--;
	    }
        else{
            if(Temp->Ant!=NULL){
                Temp = Temp ->Ant;
            }
                ma--;
        }
	}
	paso5();
}
void Producciones::paso5(){
    vector<string> paso5;
    DProduccion *Temp;
    while(Lista->Ant!=NULL)
    {
        Lista=Lista->Ant;
    }
    Lista = Lista->Sig;
    Temp = Lista; //lista en inicio
    int n=2;
	int ma = numPro;
	int pA = (int)posA - 48 +1; // convertir a entero
	while(n<=ma){ //recorre la lista
	    string d = Temp->Dato;
                for(int i=5; i<d.length(); ){
                    if(d[i-2]==62){
                            i++;
                            while(d[i] > 48 && d[i] < 58){
                                i++;
                            }

                        string dato1 = d.substr (0, i);
                        nuevaPosA++;
                        dato1 += " A" + to_string(nuevaPosA);
                        paso5.push_back(dato1);
                        string nuevoD = d.substr (i+1);
                        d=nuevoD;
                        break;
                    }
                    else{
                        i++;
                    }
                }
                    while(d.length()>=8){
                        string dato = "A" + to_string(nuevaPosA) + " -> " + d[0];
                        int i=1;
                        while(d[i] > 48 && d[i] < 58){ //miestras sea nuemero
                            dato+=d[i];
                            i++;
                        }
                        nuevaPosA++;
                        dato+=" A" +to_string(nuevaPosA);
                        paso5.push_back(dato);
                        string nuevoD = d.substr (i+1);
                        d = nuevoD;
                    }
                        string dato = "A" + to_string(nuevaPosA) + " -> " + d.substr (0);
                        paso5.push_back(dato);
    if(Temp->Sig!=NULL){
      Temp = Temp ->Sig;}
    n++;
	}
	for(int i=paso5.size()-1; i>=0; i--){
        ingresarPrincipio(paso5[i]);
	}
}
void Producciones::vaciar(){
    //lista
    if(Vacia()==false){
        DProduccion *Temp;
        Temp= new DProduccion;
        if(numPro==1){
            Temp=Lista;
            delete Temp;
        }
        else{
            while(Lista->Sig!=NULL && Lista->Ant!=NULL){
                while(Lista->Ant!=NULL){
                    Lista=Lista->Ant;
                }
                Temp=Lista;
                Lista=Temp->Sig;
                Lista->Ant=NULL;
                delete Temp;
            }
            Temp=Lista;
            delete Temp;
        }
    }
    //FNC
    if(num==0){
        DProduccion *Temp1;
        Temp1= new DProduccion;
        if(num==1){
            Temp1=ListaFNC;
            delete Temp1;
        }
        else{
            while(ListaFNC->Sig!=NULL && ListaFNC->Ant!=NULL){
                while(ListaFNC->Ant!=NULL){
                    ListaFNC=ListaFNC->Ant;
                }
                Temp1=ListaFNC;
                ListaFNC=Temp1->Sig;
                ListaFNC->Ant=NULL;
                delete Temp1;
            }
            Temp1=ListaFNC;
            delete Temp1;
        }
    }
    numPro=0;
    num = 0;
    Lista = new DProduccion;
    ListaFNC = new DProduccion;
    numPaso2=0;
    nuevaPosA=0;
}
int main()
{
    Producciones pro;
    char opcion;
    encabezado();

    do {
    system("color 0E");
    cout << endl << "\t\t\t\t***MENU***" << endl;
    cout << "\t\t\t--------------------------" << endl;
    cout << "\t\t\tA] Introducir productos " << endl;
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
            system("color 0D");
            cout << "Favor de escribir los productos como los siguinetes ejemplos: " << endl << "\tS -> a b A1 d e A2" << "\n\tA2 -> c A2 A3";
            cout << endl << "Numero de productos: "<<endl;
            int numP = 0;
            cin >> numP;
            cout << endl << "Productos: " << endl;
            while(numP+1){
                string produccion;
                getline(cin, produccion, '\n');
                pro.ingresar(produccion);
                numP--;
            }
            pro.paso1();
            cout << "------------------------------------------"<<endl;
            cout << endl << "FNC: " << endl;
            pro.mostrarFNC();
            system("pause");
            system("cls");
            pro.vaciar();
            break;
    }

}
while ( opcion != 'B' && opcion != 'b' );
system("cls"); //LIMPLIAR PANTALLA
system("color 0F");
cout << endl << "FIN!" << endl;

return 0;
    /*Producciones pro;
    int numP ;
    cin >> numP;
    while(numP+1){
        string produccion;
        getline(cin, produccion, '\n');
        pro.ingresar(produccion);
        numP--;
    }
    pro.paso1();


    cout << endl << "FNC: " << endl;
    pro.mostrarFNC();*/

}
void encabezado(){
 cout << "\t\t    INSTITUTO POLITECNICO NACIONAL " << endl << "UNIDAD PROFESIONAL INTERDISCIPLINARIA DE INGENIERIA CAPUS ZACATECAS" << endl <<  "\t\tINGENIERIA EN SISTEMAS COMPUTACIONALES" << endl << endl << "\t\t\tTeoria computacional" << endl << "\t \t \t \t2CM2" << endl << "\t\t     Vanessa Melenciano Llamas" << endl << "\t\t\t      2020670081" << endl << "\t \t       20 de enero de 2021" << endl << "\t\t   Forma Normal de Chomsky" << endl;
}
