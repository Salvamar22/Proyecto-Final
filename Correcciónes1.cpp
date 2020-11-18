#include <iostream>
#include <queue>
#include <list>
#include <string>
using namespace std;
//Estructura clientes
struct Clientes{
    string nombre;
    int dui;
    int edad;
};
//Aqui empieza parte de alejandro madriz
typedef Clientes cliente;
struct cajero{
    //otros datos
    int credencial;
    cliente c_actual;
};
cliente void_client = {"", -1, -1};
//Fuera del main
list <cajero> cajas;
queue<Clientes>normalqueue,vipqueue;



void show_till(cajero caja);
void dispatch();
cajero request_till();
cliente prioritize_client();

void mostrarCajeros();

//Aqui termina

//Mostrar cola
void showQueue (queue<Clientes> normal){
queue<Clientes> clone=normal;
    while (!clone.empty()){
        cout<<"Usuario."<<endl;
        cout<<"Nombre: ";
        cout << clone.front().nombre<< endl;
        cout<<"Dui: ";
        cout<<clone.front().dui<< endl;
        cout<<"Edad: ";
        cout<<clone.front().edad<< endl;
      clone.pop();
  }
}
//Menu para acceder a las colas
void menu(queue <Clientes> &normalQueue,queue <Clientes>&vipQueue){
    int option;
    bool status = true;
    while(status){
        cout<< "\n"<<"Bienvenidos"<<endl;
        cout << "1. Agregar cliente Normal: "<<endl;
        cout << "2. Mostrar cola de clientes normales:"<<endl;
        cout << "3. Agregar cliente VIP: "<<endl;
        cout << "4. Mostrar cola de clientes VIP:"<<endl;
        cout << "5. Despachar cliente"<<endl;
        cout << "6. Mostrar los cajeros"<<endl;
        cout << "7  Salir"<<endl;
        cout << "\n"<< "Ingrese la opcion que desea ejecutar: "<<endl;
        cin >> option;
        switch (option)
        {
    //Agregar cliente normal
    case 1:
        {
          cin.ignore();
          Clientes normal;
          cout<<"Nombre: ";
          getline(cin, normal.nombre);
          cout<<"Dui: ";
          cin>> normal.dui;
         
        //  do{
               cout<<"Edad: ";
                 cin>> normal.edad;
          //}while (normal.edad>=18&&normal.edad<=70);
    
          
          normalQueue.push(normal);
    break;
        }
    //Mostrar cola de clientes normales
    case 2: showQueue(normalQueue); 
    break;
    //Agregar cliente Vip
    case 3: 
        {
          cin.ignore();
          Clientes vip;
          cout<<"Nombre: ";
          getline(cin, vip.nombre);
          cout<<"Dui: ";
          cin>> vip.dui;
        //  do{
               cout<<"Edad: ";
                 cin>> vip.edad;
         // }while (vip.edad>=70&&vip.edad<=130);
          vipQueue.push(vip);  
        } 
    break;
    //Mostrar lista de clientes Vip
    case 4: showQueue(vipQueue); 
    break;
    case 5: dispatch();
    break;
    case 6:mostrarCajeros();
    break;
    case 7:
          cout << "Fin del programa" <<endl;
          status = false;
    break;
    default:
          cout<<"opcion invalida"<<endl;
    break;
        }
    }
}
//Consola
int main(){
    cajas.push_back({50, void_client});
    cajas.push_back({51, void_client});
    cajas.push_back({52, void_client});
    cajas.push_back({53, void_client});
    
    menu(normalqueue,vipqueue);
    return 0;
}

void show_till(cajero caja){
    //cout << "\nN cliente: "  << caja.c_actual.n_llegada;
    cout << "\nCredencial: "  << caja.credencial;
    if( void_client.dui == caja.c_actual.dui){
        cout << "\nSin cliente";
    }
    else{
        cout << "\nCliente: " << caja.c_actual.nombre;
    }
}

void show_all_tills(){
    int i=0;
    for(list<cajero>::iterator list_iter = cajas.begin(); list_iter != cajas.end(); list_iter++){
        cout << "\n\nCaja Numero: " << ++i;
        show_till(*list_iter);
    }
}

void dispatch(){
    int i = 0, c = 0;
    system("CLS");
    show_all_tills();
    cout << "\n\nSeleccione la caja a despachar: ";
    cin >> c;
    for(list<cajero>::iterator list_iter = cajas.begin(); list_iter != cajas.end(); list_iter++){
        if(++i == c){
            if( void_client.dui == (*list_iter).c_actual.dui ){
                cout << "\n\nEn esta caja no hay clientes!!";
            }
            else{
                (*list_iter).c_actual = void_client;
                cout << "\n\nCliente despachado exitosamente!!";
            }

            (*list_iter).c_actual = prioritize_client();

            return;
        }
    }
    cout << "\nNo se ha encontrado la caja seleccionada";
}

cajero request_till(){
    cajero t;
    cout << "Ingrese credencial: ";
    cin >> t.credencial;
    t.c_actual = prioritize_client();
}

cliente prioritize_client(){
    cliente new_client = void_client;
    if(vipqueue.empty())
    {
        if (!normalqueue.empty())
        {
            new_client = normalqueue.front();
            normalqueue.pop();
        }
    }
    else{
        new_client = vipqueue.front();
        vipqueue.pop();
    }
    return new_client;
}



void actCajas(cajero p){
	cliente cl;
    cout << "\nCredencial: "  << p.credencial;
    if( void_client.dui == p.c_actual.dui){
        cout << "\nSin cliente";
    }
    else{
        cout << "\nCliente: " <<p.c_actual.nombre;
        cout << "\nDui: "   <<p.c_actual.dui;
        cout << "\nEdad: "   << p.c_actual.edad;
      //  cout << "\nCredencial: "  << p.credencial;
    
    }
}

void mostrarCajeros(){
     int i=0;
    for(list<cajero>::iterator list_iter = cajas.begin(); list_iter != cajas.end(); list_iter++){
        cout << "\n\nCaja Numero: " << ++i;
        actCajas(*list_iter);
    }
}
