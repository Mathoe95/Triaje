#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

class Paciente{
	private:
		int codigo;
		string dni;
		string nombre;
		string primer_apellido;
		string segundo_apellido;
		int edad;
		char* sexo;
		string hora;
		int hora_minutos;
	public:
		Paciente(int,string,string,string,string,int,char*);
		void mostrar();
		void mostrar_lista_paciente();
		string getDni();
		int getCodigo();
		string getHora();
		string getNombre();
		int getHora_minutos();
		void setHora(string anno,string mes,string dia,string horaa,string minutos,string segundos);
		void setHora_minutos_hoy(int d,int h,int min);
		int comprobar_horas(int hora_inicial , int hora_final);
		
};
Paciente::Paciente(int cod,string dn,string nomb,string primer,string segundo,int ed,char* sex){
	codigo = cod;
	dni = dn;
	nombre = nomb;
	primer_apellido= primer;
	segundo_apellido = segundo;
	edad = ed;
	sexo = sex;
	hora;
	hora_minutos;
};

void Paciente::mostrar(){
	cout<<"Codigo:"<<codigo<<endl;
	cout<<"dni:"<<dni<<endl;
	cout<<"nombre:"<<nombre<<endl;
	cout<<"primer apellido:"<<primer_apellido<<endl;
	cout<<"segundo apellido:"<<segundo_apellido<<endl;
	cout<<"edad:"<<edad<<endl;
	cout<<"sexo:"<<sexo<<endl;
	cout<<"hora:"<<hora<<endl;
};
void Paciente::mostrar_lista_paciente(){
	cout<<"Codigo:"<<codigo<<endl;
	cout<<"dni:"<<dni<<endl;
	cout<<"hora:"<<hora<<endl;
};


string Paciente::getDni(){
	return dni;
};
int Paciente::getCodigo(){
	return codigo;
};
string Paciente::getHora(){
	return hora;
};

void Paciente::setHora(string anno,string mes,string dia,string horaa,string minutos,string segundos){
	hora=anno+"/"+mes+"/"+dia+"/"+horaa+"/"+minutos+"/"+segundos;
}
string Paciente::getNombre(){
	return nombre;
};

void Paciente::setHora_minutos_hoy(int d,int h,int min){
	hora_minutos= (d*1440)+ (h*60) + min;
}
int Paciente::getHora_minutos(){
	return hora_minutos;
};

int Paciente::comprobar_horas(int hora_inicial , int hora_final){
	if((hora_inicial-hora_final) > 0){
		int total = hora_inicial-hora_final;
		return total;
	}
	else{
		return 0;
	}
}





