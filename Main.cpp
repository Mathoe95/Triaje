#include <iostream>
#include <string>
#include<stdio.h>
#include<conio.h>
#include <ctime>
#include<vector>
#include <sstream>
#include <iomanip>

#include "Paciente.h"
#include "opciones.h"

using namespace std;


int main (){
	vector <Paciente> pilaPaciente;
	vector <Paciente> pilaPacienteTemp;
	vector <Paciente> listaR;
	vector <Paciente> listaN;
	vector <Paciente> listaA;
	vector <Paciente> listaV;
			
	Paciente p1 = Paciente(1,"99999991A","Silvia","Martos","Esteve",45,"H");
	Paciente p2 = Paciente(2,"99999992B","Mario","Ruiz","Sanchez",28,"V");
	Paciente p3 = Paciente(3,"99999993C","Maria","Setien","Buendia",60,"H");
	Paciente p4 = Paciente(4,"99999994D","Luis","Dominguez","Gracia",4,"V");
	Paciente p5 = Paciente(5,"99999995E","Eva","Navarro","Hueste",23,"H");
	Paciente p6 = Paciente(6,"99999996F","Jose","Marquez","Mendez",15,"V");
	Paciente p7 = Paciente(7,"99999997G","Lucia","Vindel","Higuera",80,"H");
	Paciente p8 = Paciente(8,"99999998H","Victor","Mendez","Gimeno",67,"V");
	Paciente p9 = Paciente(9,"99999999J","Elena","Espinosa","Moreno",2,"H");
	Paciente p10 = Paciente(10,"100000000K","Manuel","Garcia","Perez",87,"V");

	
	pilaPaciente.push_back(p1);
	pilaPaciente.push_back(p2);
	pilaPaciente.push_back(p3);
	pilaPaciente.push_back(p4);
	pilaPaciente.push_back(p5);
	pilaPaciente.push_back(p6);
	pilaPaciente.push_back(p7);
	pilaPaciente.push_back(p8);
	pilaPaciente.push_back(p9);
	pilaPaciente.push_back(p10);
	bool reinicio = true;	
	while (reinicio){
		//creamos una estructura de datos de tiempo en el que guardaremos la fecha en el formato año/mes/dia/hora/minutos/segundos para despues hacer un casting a string.
		time_t t = time(0);  
	    struct tm * punteroFecha = localtime(&t);  
	    int dia = punteroFecha->tm_mday;
	    int mes = punteroFecha->tm_mon + 1;
	    int anno = punteroFecha->tm_year + 1900;
		time_t tiempoactual;
	  	time( &tiempoactual );
	  	punteroFecha = localtime( &tiempoactual );
	  	int Hora   = punteroFecha->tm_hour;
	 	int Minuto   = punteroFecha->tm_min;
	  	int Segundo   = punteroFecha->tm_sec;
	  	
		stringstream ss;
		ss << anno;
		string a = ss.str();
		
		stringstream ss1;
		ss1 << dia;
		string d = ss1.str();
		
		stringstream ss2;
		ss2 << mes;
		string m = ss2.str();
		
		stringstream ss3;
		ss3 << Hora;
		string h = ss3.str();
		
		stringstream ss4;
		ss4 << Minuto;
		string mi = ss4.str();
		
		stringstream ss5;
		ss5 << Segundo;
		string s = ss5.str();
	  	
		int num;
		int op;
		int codigo_num;
		int codigo_buscado;
		int oplista;
		int diaa;
		int horass;
		int minutoss;
		bool encontrado = false;
		string tipo_emergencia;
		string tipo_emergencia_a_cambiar;
		string dni_buscar;
		string dni_buscado;
		//llamamos al menu de opciones
		menu();
		cin >> num ;
		
		switch (num){
			//El caso 0 es para dar de alta a los pacientes de la pila pacientes.
			case 0:
				// si esta vacia la pila pacientes no podemos seguir dando de alta.
				if (pilaPaciente.empty()){	
					cout<<"No hay pacientes para darles de alta"<<endl;
				} 
				else{
					//cada vez que vayamos a dar de alta a un paciente nos dara infomracion de el y a donde lo vamos a enviar.
					cout << "DATOS DEL PACIENTE"<<endl;
					pilaPaciente[pilaPaciente.size()-1].mostrar();
					
					cout << "MARQUE SEGUN LAS OPCIONES A DONDE DEBE IR"<<endl;
					cout << "1. Resucitacion(rojo)"<<endl;
					cout << "2. Emergencia(naranja)"<<endl;
					cout << "3. Urgencia(amarillo)"<<endl;
					cout << "4. Urgencia Menor(verde)"<<endl;
					
					cout << "Introduce una opcion:";
					cin >> op;
					
					switch (op){
						//En cada emergencia lo sacamos de la pila pacientes,lo eliminamos , lo pasamos a la lista,guardamos en el momento de darle de alta los minutos totales del dia y la fecha del dia.
						case 1:
							listaR.push_back(pilaPaciente[pilaPaciente.size()-1]);
							pilaPaciente.pop_back();
							listaR[listaR.size()-1].setHora(a,m,d,h,mi,s);
							listaR[listaR.size()-1].setHora_minutos_hoy(dia,Hora,Minuto);
							listaR[listaR.size()-1].mostrar_lista_paciente();
							break;
						case 2:
							listaN.push_back(pilaPaciente[pilaPaciente.size()-1]);
							pilaPaciente.pop_back();
							listaN[listaN.size()-1].setHora(a,m,d,h,mi,s);
							listaN[listaN.size()-1].setHora_minutos_hoy(dia,Hora,Minuto);
							listaN[listaN.size()-1].mostrar_lista_paciente();
							break;
						case 3:
							listaA.push_back(pilaPaciente[pilaPaciente.size()-1]);
							pilaPaciente.pop_back();
							listaA[listaA.size()-1].setHora(a,m,d,h,mi,s);
							listaA[listaA.size()-1].setHora_minutos_hoy(dia,Hora,Minuto);
							listaA[listaA.size()-1].mostrar_lista_paciente();
							break;
						case 4:
							listaV.push_back(pilaPaciente[pilaPaciente.size()-1]);
							pilaPaciente.pop_back();
							listaV[listaV.size()-1].setHora(a,m,d,h,mi,s);
							listaV[listaV.size()-1].setHora_minutos_hoy(dia,Hora,Minuto);
							listaV[listaV.size()-1].mostrar_lista_paciente();
							break;
						default:
							cout<<"Error"<<endl;
							break;
					
					}
				}
				break;
			// En el caso 1 le damos de baja al paciente mediante su dni.	
			case 1:
				cout <<"MENU DE BAJA DE PACIENTE"<<endl;
				cout<<"introduce el dni a buscar:";
				cin >> dni_buscar ;
				//Comprobamos primero si no esta vacia la emergencia,despues la recorremos y vamos comprobando si el dni del paciente de la emergencia coincide con el introducido por consola , entonces lo eliminamos.
				//Una vez encontrado dentro de la lista,damos un valor de cierto para que no se ejecute mas el caso 1.				
				if(!listaR.empty()){
					for(int i = listaR.size()-1; i>=0; i--){
						string dni_buscado = listaR[i].getDni();
						if(dni_buscar == dni_buscado){
							listaR.erase(listaR.begin()+i);
							encontrado = true;
							break;
							}
						}
					if(encontrado){
						break;
					}
				}
				if(!listaN.empty()){	
					for(int i = listaN.size()-1; i>=0; i--){
						string dni_buscado = listaN[i].getDni();
						if(dni_buscar == dni_buscado){
							listaN.erase(listaN.begin()+i);
							encontrado = true;
							break;
							}
						}
					if(encontrado){
						break;
					}
				}
				if(!listaA.empty()){
					for(int i = listaA.size()-1; i>=0; i--){
						string dni_buscado = listaA[i].getDni();
						if(dni_buscar == dni_buscado){
							listaA.erase(listaA.begin()+i);
							encontrado = true;
							break;
							}
						}
					if(encontrado){
						break;
					}
				}
				if(!listaV.empty()){
					for(int i = listaV.size()-1; i>=0; i--){
						string dni_buscado = listaV[i].getDni();
						if(dni_buscar == dni_buscado){
							listaV.erase(listaV.begin()+i);
							encontrado = true;
							break;
							}	
						}
					if(encontrado){
						break;
					}
				}
				//comprobamos que la pila no esta vacia,una vez comprobado si esta en una emergencia.Si esta vacia entonces vamos a salir del programa.
				if(pilaPaciente.empty()){
					cout<<"Vas a salir del programa"<<endl;
					exit(-1);
				}else{
					//Recorremos la pila en busca de que coincida el dni con el paciente de la pila,si es el primero de todos,entonces solamente lo eliminamos y no se realiza mas intruccciones.
					//Si no ha sido el primero y hemos recorrido la pila ,entonces esta ha metido en una pila auxiliar los que no coincidian.
					for( int i = pilaPaciente.size()-1; i>0; i--){
						string dni_buscado = pilaPaciente[i].getDni();
						if(dni_buscar == dni_buscado){
							pilaPaciente.pop_back();
							break;
							}
					
						else{
							pilaPacienteTemp.push_back(pilaPaciente[i]);
							pilaPaciente.pop_back();
							cout<<"MOSTRANDO LAS TRANSFERENCIAS DE LAS PILAS PACIENTE A PILA PACIENTE TEMP"<<endl;
							cout<<"Ultimo de la pila paciente"<<endl;
							pilaPaciente[pilaPaciente.size()-1].mostrar();
							cout<<"Ultimo de la pila pacienteTemp"<<endl;
							pilaPacienteTemp[pilaPacienteTemp.size()-1].mostrar();
						}				
					}
					//una vez metidos en la pila aux comprobamos que esta no esta vacia,por el caso primero que puede darse que comentamos anteriormente,si no lo esta entonces la recorremos y lo volvemos a meter en la pila paciente.
					if(!pilaPacienteTemp.empty()){
						for( int i = pilaPacienteTemp.size()-1; i>=0; i--){
							pilaPaciente.push_back(pilaPacienteTemp[i]);
							pilaPacienteTemp.pop_back();
							cout<<"MOSTRANDO LAS TRANSFERENCIAS DE LAS PILAS PACIENTETEMP A PILA PACIENTE"<<endl;
							cout<<"Ultimo de la pila paciente"<<endl;
							pilaPaciente[pilaPaciente.size()-1].mostrar();
							if(!pilaPacienteTemp.empty()){
								cout<<"Ultimo de la pila pacienteTemp"<<endl;
								pilaPacienteTemp[pilaPacienteTemp.size()-1].mostrar();
								}
						}
					}
				}
				break;
			//En el caso 2 introducimos el codigo de la persona que esta en una emergenica,despues decimos en cual esta y a donde queremos moverlo.
			case 2:
				cout << "2. Modifiacion-Reasigncion de paciente a tipo emergencia"<<endl;
				cout<<"introduce el codigo del paciente que vas a cambiar de emergencia:";
				cin >> codigo_num ;
				
				cout<<"introduce el tipo de emergencia en el que esta(r,n,a,v):";
				cin >> tipo_emergencia;
				
				cout<<"introduce el tipo de emergencia en el que vas a cambiarlo(r,n,a,v):";
				cin >> tipo_emergencia_a_cambiar;
				//si el codigo esta dentro de un rango y las leras coinciden a donde esta y queremos que vaya,entonces recorremos la lista y si coincide con el codigo,lo metemos en esa lista,lo eliminamos y modificamos la fecha a la actual.
				if(codigo_num >= 0 and codigo_num <= 10){
					if(tipo_emergencia == "r" or tipo_emergencia == "R"){
						if(!listaR.empty()){
							for(int i = listaR.size()-1; i>=0; i--){
								codigo_buscado = listaR[i].getCodigo();
								if(codigo_num == codigo_buscado){
									if(tipo_emergencia_a_cambiar == "n" or tipo_emergencia_a_cambiar == "N"){
										listaR[i].setHora(a,m,d,h,mi,s);
										listaN.push_back(listaR[i]);
										listaR.erase(listaR.begin()+i);
									}
									else if (tipo_emergencia_a_cambiar == "a" or tipo_emergencia_a_cambiar == "A"){
										listaR[i].setHora(a,m,d,h,mi,s);
										listaA.push_back(listaR[i]);
										listaR.erase(listaR.begin()+i);
									}
									else if (tipo_emergencia_a_cambiar == "v" or tipo_emergencia_a_cambiar == "V"){
										listaR[i].setHora(a,m,d,h,mi,s);
										listaV.push_back(listaR[i]);
										listaR.erase(listaR.begin()+i);
									}
									else{
										cout<<"Error de reasignacion"<<endl;
										}	
									}
								}
							}else{
								cout<<"Error de reasignacion"<<endl;	
							}
						}
					else if(tipo_emergencia == "n" or  tipo_emergencia == "N") {
						if(!listaN.empty()){
							for(int i = listaN.size()-1; i>=0; i--){
								codigo_buscado = listaN[i].getCodigo();
								if(codigo_num == codigo_buscado){
									if(tipo_emergencia_a_cambiar == "r" or tipo_emergencia_a_cambiar == "R"){
										listaN[i].setHora(a,m,d,h,mi,s);
										listaR.push_back(listaN[i]);
										listaN.erase(listaN.begin()+i);
									}
									else if (tipo_emergencia_a_cambiar == "a" or tipo_emergencia_a_cambiar == "A"){
										listaN[i].setHora(a,m,d,h,mi,s);
										listaA.push_back(listaN[i]);
										listaN.erase(listaN.begin()+i);
									}
									else if (tipo_emergencia_a_cambiar == "v" or tipo_emergencia_a_cambiar == "V"){
										listaN[i].setHora(a,m,d,h,mi,s);
										listaV.push_back(listaN[i]);
										listaN.erase(listaN.begin()+i);
										}
									else{
										cout<<"Error de reasignacion"<<endl;
										}	
									}
								}
						}else{
							cout<<"Error de reasignacion"<<endl;
						}
					}
					else if(tipo_emergencia == "a" or tipo_emergencia == "A") {
						if(!listaA.empty()){
							for(int i = listaA.size()-1; i>=0; i--){
								codigo_buscado = listaA[i].getCodigo();
								if(codigo_num == codigo_buscado){
									if(tipo_emergencia_a_cambiar == "r" or tipo_emergencia_a_cambiar == "R"){
										listaA[i].setHora(a,m,d,h,mi,s);
										listaR.push_back(listaA[i]);
										listaA.erase(listaA.begin()+i);
									}
									else if (tipo_emergencia_a_cambiar == "n" or tipo_emergencia_a_cambiar == "N"){
										listaA[i].setHora(a,m,d,h,mi,s);
										listaN.push_back(listaA[i]);
										listaA.erase(listaA.begin()+i);
									}
									else if (tipo_emergencia_a_cambiar == "v" or tipo_emergencia_a_cambiar == "V"){
										listaA[i].setHora(a,m,d,h,mi,s);
										listaV.push_back(listaA[i]);
										listaA.erase(listaA.begin()+i);
										}
									else{
										cout<<"Error de reasignacion"<<endl;
										}	
									}
								}
						}else{
							cout<<"Error de reasignacion"<<endl;
						}
					}
					else if(tipo_emergencia == "v" or tipo_emergencia == "V") {
						if(!listaV.empty()){
							for(int i = listaV.size()-1; i>=0; i--){
								codigo_buscado = listaV[i].getCodigo();
								if(codigo_num == codigo_buscado){
									if(tipo_emergencia_a_cambiar == "r" or tipo_emergencia_a_cambiar == "R"){
										listaV[i].setHora(a,m,d,h,mi,s);
										listaR.push_back(listaV[i]);
										listaV.erase(listaV.begin()+i);
									}
									else if (tipo_emergencia_a_cambiar == "n" or tipo_emergencia_a_cambiar == "N"){
										listaV[i].setHora(a,m,d,h,mi,s);
										listaN.push_back(listaV[i]);
										listaV.erase(listaV.begin()+i);
									}
									else if (tipo_emergencia_a_cambiar == "a" or tipo_emergencia_a_cambiar == "A"){
										listaV[i].setHora(a,m,d,h,mi,s);
										listaA.push_back(listaV[i]);
										listaV.erase(listaV.begin()+i);
										}
									else{
										cout<<"Error de reasignacion"<<endl;
										}	
									}
								}
						}	
						else{
							cout<<"Error de reasignacion"<<endl;
						}
					}else{
						cout<<"Error de reasignacion"<<endl;	
					}
				}else{
					cout<<"Error de reasignacion"<<endl;
				}
				break;
			//En el caso 3 vamos a consultar los pacientes y las emergencias.
			case 3:
				cout << "CONSULTA DE PACIENTES/EMERGENCIA"<<endl;
				cout << "1. Consulta de pacientes"<<endl;
				cout << "2. Consulta de emergencias"<<endl;
				cout << "3. Consulta de tiempos de emergencias superados"<<endl;
				cout << "Introduce una opcion:";
				cin >> op;
				switch (op){
					//En el caso 1 tenemos la opcion de consultar el paciente por sus dni o todos los pacientes.
					case 1:
						cout << "CONSULTA DE PACIENTES"<<endl;
						cout << "1. Consulta de paciente por dni"<<endl;
						cout << "2. Consulta de todos los pacientes"<<endl;
						cout << "Introduce una opcion:";
						cin >> op;
						switch (op){
							//introducimos el dni y vamos a recorrer la pila paciente en busca de que coincida con su dni.
							case 1:
								cout<<"introduce el dni a buscar:";
								cin >> dni_buscar;
								
								for( int i = pilaPaciente.size()-1; i>=0; i--){
									dni_buscado = pilaPaciente[i].getDni();
									if(dni_buscar == dni_buscado){
										pilaPaciente[i].mostrar();
										}
									}
								break;
							//Vamos a buscar todos los pacientes de la pila y mostrar sus datos.
							case 2:
								for (int i = pilaPaciente.size()-1 ; i>=0 ; i--){
								cout << "DATOS DEL PACIENTE"<<endl;
								pilaPaciente[i].mostrar();
								}
								break;
								
							default:
								cout<<"Error"<<endl;
								break;
							}
							break;	
					//En el caso 2 vamos a consultar las emergencias por codigo o de cada tipo de emergencia.
					case 2:
						cout << "CONSULTA DE EMERGENCIAS"<<endl;
						cout << "1. Consulta de la emergencia a la que esta asignado un paciente por su codigo"<<endl;
						cout << "2. Consulta de todos los pacientes en cada emergencia"<<endl;
						cout << "Introduce una opcion:";
						cin >> op;
						switch (op){
							//Recorremos las listas de las emergencias y comprobamos que el codigo coincide del paciente y el introducido.Si coincide,mostraremos los datos del paciente y en que emergencia esta.
							case 1:
								cout<<"introduce el codigo a buscar:";
								cin >> codigo_num;
									
								for(int i = listaR.size()-1; i>=0; i--){
									int codigo_buscado = listaR[i].getCodigo();
									if(codigo_num == codigo_buscado){
										cout<<"DNI:"<<listaR[i].getDni()<<endl;
										cout<<"Resucitacion(rojo)"<<endl;
									}
								}
								for(int i = listaN.size()-1; i>=0; i--){
									int codigo_buscado = listaN[i].getCodigo();
									if(codigo_num == codigo_buscado){
										cout<<"DNI:"<<listaN[i].getDni()<<endl;
										cout<<"Emergencia(naranja)"<<endl;
									}
									}
								for(int i = listaA.size()-1; i>=0; i--){
									int codigo_buscado = listaA[i].getCodigo();
									if(codigo_num == codigo_buscado){
										cout<<"DNI:"<<listaA[i].getDni()<<endl;
										cout<<"Urgencia(amarillo)"<<endl;
									}
									}
								for(int i = listaV.size()-1; i>=0; i--){
									int codigo_buscado = listaV[i].getCodigo();
									if(codigo_num == codigo_buscado){
										cout<<"DNI:"<<listaV[i].getDni()<<endl;
										cout<<"Urgencia Menor(verde)"<<endl;
									}
									}
								
								break;
							//Comprobamos por listas todos los pacientes de una lista recorriendola y mostando el codigo,dni y hora del paciente.	
							case 2:								
								cout << "MARQUE LA LISTA QUE DESEA CONSULTAR"<<endl;
								cout << "1. Resucitacion(rojo)"<<endl;
								cout << "2. Emergencia(naranja)"<<endl;
								cout << "3. Urgencia(amarillo)"<<endl;
								cout << "4. Urgencia Menor(verde)"<<endl;
								
								cout << "Introduce una opcion:";
								cin >> oplista;
									
								switch (oplista){
									case 1:
										if(!listaR.empty()){
											for(int i = listaR.size()-1; i>=0; i--){
												cout<<"Codigo:"<<listaR[i].getCodigo()<<endl;
												cout<<"Dni:"<<listaR[i].getDni()<<endl;
												cout<<"Hora:"<<listaR[i].getHora()<<endl;
												}
											}
										break;	
									case 2:
										if(!listaN.empty()){	
											for(int i = listaN.size()-1; i>=0; i--){
												cout<<"Codigo:"<<listaN[i].getCodigo()<<endl;
												cout<<"Dni:"<<listaN[i].getDni()<<endl;
												cout<<"Hora:"<<listaN[i].getHora()<<endl;
											}
											}
										break;
									case 3:
										if(!listaA.empty()){
											for(int i = listaA.size()-1; i>=0; i--){
												cout<<"Codigo:"<<listaA[i].getCodigo()<<endl;
												cout<<"Dni:"<<listaA[i].getDni()<<endl;
												cout<<"Hora:"<<listaA[i].getHora()<<endl;
												}
											}
										break;
									case 4:
										if(!listaA.empty()){
											for(int i = listaV.size()-1; i>=0; i--){
												cout<<"Codigo:"<<listaV[i].getCodigo()<<endl;
												cout<<"Dni:"<<listaV[i].getDni()<<endl;
												cout<<"Hora:"<<listaV[i].getHora()<<endl;
												}
											}
										break;
									}	
									break;		
							}
							break;
					//Consulta de tiempos excedidos de espera en cada emergencia.
					case 3:
						cout << "1. Resucitacion(rojo)"<<endl;
						cout << "2. Emergencia(naranja)"<<endl;
						cout << "3. Urgencia(amarillo)"<<endl;
						cout << "4. Urgencia Menor(verde)"<<endl;
					
						cout << "Introduce una opcion:";
						cin >> op;
							
						switch (op){
							//Introducimos el dia,hora y minutos que sea anterior a la que el sistema ha dado de alta al paciente , para compararlo y si este es menor a la del alta entonces calculamis el tiempo de espera que se ha exceddio.
							//En el caso de la lista roja es desde que hemos introducido la hora por consola hasta la que se dio de alta.
							case 1:
								for(int i = listaR.size()-1; i>=0; i--){
									cout << "Introduce la fecha del dia:";
									cin >> diaa;
									cout << "Introduce la fecha de la hora:";
									cin >> horass;
									cout << "Introduce la fecha de los minutos:";
									cin >> minutoss;
									int total = (diaa*1440)+(horass*60)+minutoss;
									
									cout<<"DATOS DE EL PACIENTE"<<endl;
									if(listaR[i].comprobar_horas(listaR[i].getHora_minutos(),total) > 0){	    
										cout<<"Tiempo de exceso en minutos:"<<listaR[i].comprobar_horas(listaR[i].getHora_minutos(),total)<<endl;
									}
									cout<<"Tipo de emergencia:Resucitacion"<<endl;
									cout<<"Codigo del paciente:"<<listaR[i].getCodigo()<<endl;
									cout<<"Hora dado de alta:"<<listaR[i].getHora()<<endl;
										
								}
								break;
							//En el caso de la lista naranja es desde que hemos introducido la hora por consola hasta la que se dio de alta y restarle 15 minutos.
							case 2:
								for(int i = listaN.size()-1; i>=0; i--){
									cout << "Introduce la fecha del dia:";
									cin >> diaa;
									cout << "Introduce la fecha de la hora:";
									cin >> horass;
									cout << "Introduce la fecha de los minutos:";
									cin >> minutoss;
									int total = (diaa*1440)+(horass*60)+minutoss;
									
									cout<<"DATOS DE EL PACIENTE"<<endl;		    
									if(listaN[i].comprobar_horas(listaN[i].getHora_minutos(),total) > 15){
									    cout<<"Tiempo de exceso en minutos:"<<listaN[i].comprobar_horas(listaN[i].getHora_minutos(),total)-15<<endl;	
									}
									cout<<"Tipo de emergencia:Emergencia"<<endl;
									cout<<"Codigo del paciente:"<<listaN[i].getCodigo()<<endl;
									cout<<"Hora dado de alta:"<<listaN[i].getHora()<<endl;
										
								}
								break;
							//En el caso de la lista naranja es desde que hemos introducido la hora por consola hasta la que se dio de alta y restarle 60 minutos.
							case 3:
								for(int i = listaA.size()-1; i>=0; i--){
									cout << "Introduce la fecha del dia:";
									cin >> diaa;
									cout << "Introduce la fecha de la hora:";
									cin >> horass;
									cout << "Introduce la fecha de los minutos:";
									cin >> minutoss;
									int total = (diaa*1440)+(horass*60)+minutoss;
									
								    cout<<"DATOS DE EL PACIENTE"<<endl;	
								    if(listaA[i].comprobar_horas(listaA[i].getHora_minutos(),total) >60 ){
								    	cout<<"Tiempo de exceso en minutos:"<<listaA[i].comprobar_horas(listaA[i].getHora_minutos(),total)-60<<endl;	
									}
									cout<<"Tipo de emergencia:Urgencia"<<endl;
									cout<<"Codigo del paciente:"<<listaA[i].getCodigo()<<endl;
									cout<<"Hora dado de alta:"<<listaA[i].getHora()<<endl;	
								}
								break;
							//En el caso de la lista naranja es desde que hemos introducido la hora por consola hasta la que se dio de alta y restarle 120 minutos.
							case 4:
								for(int i = listaV.size()-1; i>=0; i--){
									cout << "Introduce la fecha del dia:";
									cin >> diaa;
									cout << "Introduce la fecha de la hora:";
									cin >> horass;
									cout << "Introduce la fecha de los minutos:";
									cin >> minutoss;
									int total = (diaa*1440)+(horass*60)+minutoss;
									
									cout<<"DATOS DE EL PACIENTE"<<endl;		    
								   if(listaV[i].comprobar_horas(listaV[i].getHora_minutos(),total) >120 ){
										cout<<"Tiempo de exceso en minutos:"<<listaV[i].comprobar_horas(listaV[i].getHora_minutos(),total)-120<<endl;	
									}
									cout<<"Tipo de emergencia:Urgencia Menor"<<endl;
									cout<<"Codigo del paciente:"<<listaV[i].getCodigo()<<endl;
									cout<<"Hora dado de alta:"<<listaV[i].getHora()<<endl;
										
								}
								break;
							default:
								cout<<"Error"<<endl;
								break;
						}		
				}
				break;
			//En el caso 4 sirve para reinicial el programa,reseteando los datos.
			case 4:
				cout<<"SE VA A REINICIAR EL PROGRAMA"<<endl;
				reinicio = false;
				break;
			//En el caso 5 sirve para salir del programa.
			case 5:
				exit(-1);
				break;
			default:
				cout<<"Error"<<endl;
				break;
		
	}
}
	main();
	getchar();
	return 0;	
}

