/* 
 * meteorito.h
 * 
 * Copyright  (C) Juan F. Huete
*/
#ifndef __fecha_H
#define __fecha_H

#include <string>
#include <iostream> 
#include <stdlib.h>
using namespace std;


//! Clase fecha, asociada a la 
/**! fecha::fecha,  .....
 * Descripción contiene toda la información asociada a una fecha con el formato  mm/dd/aaaa hh:mm:ss AM/PM
 @todo Escribe la documentación de la clase
 @todo Implementar esta clase

*/

class fecha {

public:
 	/** 
	@brief constructor por defecto que crea un objeto de la clase
	a la que pertenece con los valores minimos dados por el IR
	@return una fecha
 	*/ 
	fecha (); 



	/** 
	@brief constructor copia
 	*/ 
 	fecha (const fecha & f);


 	/** 
	@brief constructor por parámetros
	@param s const string que contiene la fecha a construir	(con el formato adecuado)	
 	*/ 
 	fecha (const string & s); 


 	/** 
	@brief operador de asignación
	@param f fecha a asignar
	@return referencia a una fecha con el formato mm/dd/aaaa  hh:mm:ss AM/PM
	@post no se modifica la fecha recibida como argumento
 	*/ 
 	fecha & operator=(const fecha & f);


 	/** 
	@brief operador de asignación
	@param s string a asignar
	@return referencia a una fecha con el formato mm/dd/aaaa  hh:mm:ss AM/PM
	@post no se modifica la fecha recibida como argumento
 	*/ 
 	fecha & operator=(const string & s); 


 	/** 
	@brief convierte la fecha a un string
	@return una fecha con el formato mm/dd/aaaa  hh:mm:ss AM/PM (en string)
	@post no se modifica la fecha
 	*/ 
 	string toString( ) const; 


 	/** 
	@brief operador comparación de igualdad
	@param f fecha a comparar
	@return true (si son iguales los objetos a comparar) o false(si no lo son)
	@post no se modifica la fecha con la que se hace la llamada a la función
	y ni la que se pasa como argumento
 	*/ 
 	bool operator==(const fecha & f) const;

 	/** 
	@brief operador comparación menor
	@param f fecha a comparar
	@return true(si es menor el objeto implicito que el que se le pasa como argumento) o false(si no lo es)
	@post no se modifica la fecha con la que se hace la llamada a la función
	 y ni la que se pasa como argumento
 	*/ 
 	bool operator<(const fecha & f)const;

 	/** 
	@brief operador comparación mayor
	@param f fecha a comparar
	@return true (si es mayor el objeto implicito que el que se le pasa como argumento) o false(si no lo es)
	@post no se modifica la fecha con la que se hace la llamada a la función
	 y ni la que se pasa como argumento
 	*/ 
 	bool operator>(const fecha & f) const;

 	/** 
	@brief operador comparación menor o igual
	@param f fecha a comparar
	@return true (si es menor o igual el objeto implicito que el que se le pasa como argumento) o false(si no lo es)
	@post no se modifica la fecha con la que se hace la llamada a la función
	 y ni la que se pasa como argumento
 	*/ 
 	bool operator<=(const fecha & f)const;

 	/** 
	@brief operador comparación menor o igual
	@param f fecha a comparar
	@return true (si es mayor o igual el objeto implicito que el que se le pasa como argumento) o false(si no lo es)
	@post no se modifica la fecha con la que se hace la llamada a la función
	 y ni la que se pasa como argumento
 	*/ 
 	bool operator>=(const fecha & f) const;

 	/** 
	@brief operador comparación distinto
	@param f fecha a comparar
	@return true (si ambos objetos son distintos o false(si no lo son)
	@post no se modifica la fecha con la que se hace la llamada a la función
	 y ni la que se pasa como argumento
 	*/  
 	bool operator!=(const fecha & f)const;


	/** 
	@brief Obtiene los segundos de la fecha	
	@return segundos de la fecha 
	
 	*/ 

 	int getSec();

	/** 
	@brief Obtiene los minutos de la fecha	
	@return minutos de la fecha 
	
 	*/ 

 	int getMin();

	/** 
	@brief Obtiene la hora de la fecha	
	@return hora de la fecha 
	
 	*/ 

 	int getHour();

	/** 
	@brief Obtiene el dia del mes de la fecha	
	@return dia del mes de la fecha 
	
 	*/ 

 	int getMDay();

	/** 
	@brief Obtiene el mes de la fecha	
	@return mes de la fecha 
	
 	*/ 

 	int getMon();

	/** 
	@brief Obtiene el año de la fecha	
	@return el año de la fecha 
	
 	*/ 

 	int getYear();


private:

	/**
	@brief sec segundos entre 0 y 59
	*/
  	int  sec; 

	/**
	@brief min minutos entre 0 y 59
	*/  
  	int  min; 

	/**
	@brief hour horas entre 0 y 23
	*/  
  	int  hour;

	/**
	@brief mday dia del mes entre 1 y 31
	*/  
  	int  mday; 

	/**
	@brief mon mes del año entre 0 y 11
	*/ 
  	int  mon; 

	/**
	@brief year año a partir del 2000
	*/   
  	int  year;  

 	/** 
	@brief flujo de salida << (friend) 
	@param os nombre de flujo
	@param f fecha
	@return referencia a flujo de salida
	@post no se modifica la fecha que se recibe como argumento
 	*/  
	friend  ostream& operator<< ( ostream& os, const fecha & f); 

	/** 
	@brief Chequea el invariante de la representacion	
	@return true si cumple el IR, false en caso contrario	
 	*/ 

	/** \invariant
	 
	 IR: rep ==> bool
	 
	\li Para cualquier sec, 0 <= sec < 60
	\li Para cualquier min, 0 <= min < 60
	\li Para cualquier hour, 0 <= hour < 23
	\li Para cualquier mday, 1 <= mday <= 31
	\li Para cualquier mon, 0 <= mon < 12
	\li Para cualquier year, 2000 <= year
	*/

	bool chequeaIRFecha();

};

 	/** 
	@brief flujo de salida <<
	@param os nombre de flujo
	@param f fecha
	@return referencia a flujo de salida
	@post no se modifica la fecha que se recibe como argumento
 	*/  
 	ostream& operator<< ( ostream& os, const fecha & f); 



 


#include "fecha.hxx" // Incluimos la implementacion.


#endif
