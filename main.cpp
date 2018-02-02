#include <iostream>
#include <fstream>
using namespace std;



unsigned int tam_nombre=0;
string nombre;
unsigned int tam_ciudad=0;
string ciudad;
unsigned int tam_estado=0;
string estado_civil;
unsigned int tam_registro=16+tam_estado+tam_ciudad+tam_nombre;

int cont =0;

void escribir(string nombre_archivo)
{
    ofstream out (nombre_archivo.c_str(),ios::in);
    if(!out.is_open())
    {
        out.open(nombre_archivo.c_str());
    }
    out.seekp(cont*tam_registro);
    out.write((char*)&tam_registro,4);
    out.write((char*)&tam_nombre,4);
    out.write(nombre.c_str(),tam_nombre);
    out.write((char*)&tam_ciudad, 4);
    out.write(ciudad.c_str(),tam_ciudad);
    out.write((char*)&tam_estado,4);
    out.write(estado_civil.c_str(),tam_estado);
    out.close();

    cont++;
}

/*
 * Constructor de la clase "Datos"  Datos(int tam_registro,int tam_nombre,
 * string nombre, int tam_ciudad, string ciudad, int tam_estado, string estado_civil)
 * */
void leer(string nombre_archivo, int posicion)
{


    char nom[tam_nombre];
    char ciud[tam_ciudad];
    char estadoCivil[tam_estado];


        ifstream in(nombre_archivo.c_str());
        in.seekg(posicion*tam_registro);

        in.read((char*)&tam_registro,4);
        cout<<"Register size: "<<tam_registro<<endl;
        in.read((char*)&tam_nombre,4);
        cout<<"Name Size: "<<tam_nombre<<endl;
        in.read(nom,tam_nombre);
        cout<<"Name: "<<nom<<endl;
        in.read((char*)&tam_ciudad,4);
        cout<<"City Size: "<<tam_ciudad<<endl;
        in.read(ciud,tam_ciudad);
        cout<<"City: "<<ciud<<endl;
        in.read((char*)&tam_estado,4);
         cout<<"Status Size: "<<tam_estado;
        in.read(estadoCivil,tam_estado);
        cout<<"Status: "<<estadoCivil<<endl;
        in.close();

}


int main() {
    int op=0;
    int pos=0;

    do{
        cout<<"\t\t\t\t###################Menu###################"<<endl;
        cout<<"1. Escribir en archivo"<<endl;
        cout<<"2. Leer archivo segun la posicion"<<endl;
        cout<<"Si desea salir del sistema ingrese 0"<<endl;
        cout<<"Opcion: ";
        cin>>op;


        switch(op){
            case 1:
                cout<<"Ingrese el nombre que desea escribrir en un archivo: ";
                cin>>nombre;
                cout<<tam_nombre<<endl;

                cout<<"Ingrese la ciudad de su procedencia: ";
                cin>>ciudad;
                cout<<tam_ciudad<<endl;

                cout<<"Ingrese su estado civil: ";
                cin>>estado_civil;
                cout<<tam_estado<<endl;

                tam_nombre=nombre.size();
                tam_ciudad=ciudad.size();
                tam_estado=estado_civil.size();

                escribir("archivo.dat");


                cout<<"Ingrese su opcion: ";
                cin>>op;
                break;

            case 2:
                cout<<"Ingrese la posicion que desea buscar: ";
                cin>>pos;
                leer("archivo.dat", pos);
                break;

        }
    }while(!op==0);


    return 0;
}