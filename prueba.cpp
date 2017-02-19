#include "conjunto.h"
#include "crimen.h"
#include "fecha.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <time.h>
using namespace std;
	
	/** 
	@brief lee un fichero de delitos, linea a linea
	@param[in] s nombre del fichero
        @param[in,out] C conjunto sobre el que se lee
	@return true si la lectura ha sido correcta, false en caso contrario
	*/

	//Convierte un string a crimen y devuelve un crimen (metodo auxiliar)

crimen StringToCrime(string & cad)
{
	crimen cr;
	stringstream ss;
	ss << cad;
	long int id;
	string cadena;
	
	getline(ss, cadena, ',');
	id=atol(cadena.c_str());
	cr.setID(id);

	getline(ss, cadena, ',');
	cr.setCaseNumber(cadena);
	
	getline(ss, cadena, ',');
	fecha date(cadena);
	cr.setDate(date);

	getline(ss, cadena, ',');	

	getline(ss, cadena, ',');
	cr.setIUCR(cadena);

	getline(ss, cadena, ',');
	cr.setPrimaryType(cadena);

	getline(ss, cadena, ',');
	cr.setDescription(cadena);

	getline(ss, cadena, ',');
	cr.setLocationDescription(cadena);

	getline(ss, cadena, ',');
	if(cadena=="true")
		cr.setArrest(true);
	else
		cr.setArrest(false);

	getline(ss, cadena, ',');
	if(cadena=="true")
		cr.setDomestic(true);
	else
		cr.setDomestic(false);

	for(int i=0;i<9;i++)
		getline(ss, cadena, ',');

	
	getline(ss, cadena, ',');
	double valor=atof(cadena.c_str());
	cr.setLatitude(valor);

	getline(ss, cadena, ',');
	valor=atof(cadena.c_str());
	cr.setLongitude(valor);

	
	return cr;

}

bool load(conjunto &  C, const string & s) {
 ifstream fe;
 string cadena;
 double contador=0;
 //clock_t start,end;
 cout << "Abrimos "<< s << endl;
 fe.open(s.c_str(), ifstream::in);
 if (fe.fail())    
 {
   cerr << "Error al abrir el fichero " << s << endl;
 } else {
   getline(fe,cadena,'\n'); //leo la cabecera del fichero
   cout << cadena << endl;
    while ( !fe.eof() )
      { getline(fe,cadena,'\n');
       	if (!fe.eof()) {
	   	cout << "leo:: "<< cadena << endl <<endl;
		cout << "___________________________________________________"<< endl;
	   	// Convertir cadena a crimen
			
            	crimen aux = StringToCrime(cadena);

	//EFICIENCIA EMPÍRICA INSERCION

           	// Insertar cadena en el conjunto
		//start = clock();
            	C.insert(aux);
		//end= clock(); 
		//contador++;
 		//double dif = end-start;
 		//cout << contador << " " << dif/CLOCKS_PER_SEC <<  endl;
 				
         }
     }
    fe.close();
    return true;
    } // else
  fe.close();
  return false;
 }

int main()
{
	double contador=0;
	double aleatorio=0;
    //clock_t start,end;
    conjunto ChicagoDB;
    crimen d;
    fecha f;
    
    load(ChicagoDB, "crimenes.csv");
    
	// IMPRESION DEL CONJUNTO CHICAGODB
/*
    cout<<ChicagoDB<< endl << endl;
*/

	// PRUEBA DEL FIND POR ID
/*
	pair<conjunto::entrada,bool> aux;
	aux= ChicagoDB.find(10231069);
    cout << aux.first;
    cout << aux.second;
*/
	
	// PRUEBA DE FIND DADO UN IUCR 
/*
    conjunto nuevo= ChicagoDB.findIUCR("0337");
	cout <<nuevo;
*/
		
	// PRUEBA DE FIND DADA UNA DESCRIPCION
/*
    conjunto nuevo2= ChicagoDB.findDESCR("$500 AND UNDER");    
	cout << endl << nuevo2 << endl;
*/
	
	// PRUEBA ERASE CON UN CRIMEN
/*
	string crimen1=("10230957,HY418714,09/10/2015 11:30:00 PM,056XX S KARLOV AVE,0820,THEFT,$500 AND UNDER,RESIDENTIAL YARD (FRONT/BACK),false,false,0813,008,13,62,06,1149996,1866916,2015,09/17/2015 11:37:18 AM,41.790723284,-87.725541949,(41.790723284, -87.725541949)");
 
    d=StringToCrime(crimen1);
    nuevo2.erase(d);
    cout << endl << nuevo2 << endl;
*/
	
    // PRUEBA ERASE CON UN ID
/*
    if(nuevo2.erase(10230953))
    cout << endl << "HA SIDO BORRADO NUEVO 2" << endl;
    cout << endl << nuevo2<< endl;
*/
   
	

	// EFICIENCIA EMPÍRICA BUSQUEDA
	
/*
	for ( int i =0; i <1000; i ++){
		aleatorio = rand()%10500000;
		
		start= clock();
		ChicagoDB.find(aleatorio);
		
		end = clock();

		contador++;
 		double dif = end-start;
 		cout << contador << " " << dif/CLOCKS_PER_SEC <<  endl;


	}
*/

	

   return 0;
}
