#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
//Estructura clientes
struct Clientes{
    string nombre;
    int dui;
    int edad;
};
//Mostrar cola
void showQueue (queue<Clientes> normal){
queue<Clientes> clone=normal;
    while (!clone.empty()){
        cout<<"Nombre: "<<endl;
        cout<<clone.front().nombre<<endl;
        cout<<"Dui: "<<endl;
        cout<<clone.front().dui<<endl;
        cout<<"Edad: "<<endl;
        cout<<clone.front().edad<<endl;
      clone.pop();
  }
}
//Menu para acceder a las colas
void menu(queue <Clientes> &normalQueue,queue <Clientes>&vipQueue){
    int option;
    bool status = true;
    while(status){
        cout<< "\n"<<"MENU DE COLAS"<<endl;
        cout << "1. Agregar cliente Normal: "<<endl;
        cout << "2. Mostrar cola de clientes normales:"<<endl;
        cout << "3. Agregar cliente VIP: "<<endl;
        cout << "4. Mostrar cola de clientes VIP:"<<endl;
        cout << "5. Salir"<<endl;
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
    case 5:
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
    queue<Clientes>normalqueue,vipqueue;
    menu(normalqueue,vipqueue);
     return 0;
}
