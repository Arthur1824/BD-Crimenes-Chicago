/* 
 * meteorito.h
 * 
 * Copyright  (C) Juan F. Huete
*/
#ifndef __CRIMEN_H
#define __CRIMEN_H

#include <string>
#include <iostream> 

#include "fecha.h"
//! Clase crimen, asociada a la definición de un crimen 
/**! crimen::crimen,  .....
 * Descripción contiene toda la información asociada a un crimen.
 
 @todo Implementa esta clase, junto con su documentación asociada

*/


class crimen {
 public: 

  
	/**@brief constructor por defecto
	crea un objeto de la clase
	a la que pertenece con los valores minimos dados por el IR
	 */ 
  	crimen();


	/** 
	@brief constructor copia
	*/
 
	crimen(const crimen& x);


	/**@brief método para asignar el ID
	@param id int a asignar
	 */
  	void setID(long int & id);


	/** 
     	@brief método para asignar el número de caso
	@param s string a asignar
     	*/
  	void setCaseNumber(const string &  s);

  
	/** 
	@brief método para asignar IUCR
	@param iucr string a asignar a IUCR
	 */
  	void setIUCR(const string &  iucr);


	/** 
     	@brief método para asignar la fecha
	@param d fecha a asignar
     	*/        

  	void setDate(const fecha & d);

  
  	/** 
     	@brief método para asignar el tipo de delito
	@param pt string a asignar
 	*/
  	void setPrimaryType(const string &  pt);


  
  	/** 
     	@brief método para asignar una descripcion detallada
	@param desc string a asignar
 	*/
  	void setDescription(const string &  desc);


  
  	/** 
     	@brief método para asignar descripcion del tipo de 		localizacion
	@param locDesc string a asignar
 	*/
  	void setLocationDescription(const string &  locDesc);

  
  	/** 
     	@brief método para asignar coordenada de latitud
	@param lat double a asignar
 	*/
  	void setLatitude(const double &  lat);


  
    	/** 
     	@brief método para asignar coordenada de longitud
	@param longitud double a asignar
 	*/
  	void setLongitude(const double &  longitud);


  
	/** 
	@brief método para describir si ha sido o no arrestado
	@param a bool
 	*/
  	void setArrest(bool a);


	/** 
	@brief método para saber si el crimen fue doméstico o no
	@param d bool
 	*/
  	void setDomestic(bool d); 
  
  
  	/**
	@brief método para conocer el ID
	@return long int ID
 	*/
  	long int getID( ) const;


  	/** 
	@brief método para conocer el número de caso
	@return string
 	*/	
  	string getCaseNumber( ) const;


	/**
	@brief método para conocer la fecha
	@return fecha
 	*/	
  	fecha getDate( ) const;


  
   	/**
	@brief método para conocer el IUCR
	@return string IUCR
 	*/
  	string getIUCR( ) const;


  
  	/** 
	@brief método para conocer el tipo de delito
	@return string primaryType
 	*/
  	string getPrimaryType( ) const;


  
  	/** 
	@brief método para obtener una descripcion detallada
	@return string descripcion
 	*/
  	string getDescription( ) const;


  
  	/**
	@brief método para conocer el tipo de localizacion
	@return string locatio
 	*/
  	string getLocationDesc( ) const;


  
  	/** 
	@brief método para conocer la coordenada de latitud
	@return double latitude
 	*/
  	double getLatitude( ) const;


  
    	/** 
	@brief método para conocer la coordenada de longitud
	@return double longitude
 	*/
  	double getLongitude( ) const;



	/** 
	@brief método para conocer si fue arrestado o no
	@return double longitude
	*/
	bool getArrest() const;



  	/**
	 @brief método para conocer si fue doméstico o no
     	@return double longitude
 	*/
  	bool getDomestic() const;

  
  
	/**
	@brief operador asignación
	@param c crimen a asignar
	@return referencia a crimen
	 */  
   	crimen & operator=(const crimen & c);


	/** @brief operador comparación igualdad
	@param x crimen a comparar
	@return bool
	@post no se modifica el crimen con la que se hace la llamada a la función
	ni la que se pasa como argumento
	 */  
   	bool operator==(const crimen & x) const;


	/** 
	@brief operador comparación menor
	@param x crimen a comparar
	@return bool
	@post no se modifica el crimen con la que se hace la llamada a la función
	ni la que se pasa como argumento
	 */
   	bool operator<(const crimen & x) const;


 private:
	 /**
	@brief flujo de salida << (friend) 
	@param os nombre de flujo
	@param c crimen
	@return referencia a flujo de salida
 	*/  
   	friend ostream& operator<< ( ostream& os, const crimen& c);


   	/**	
	@brief ID identificador del crimen
	*/
	long int ID;
	
	/**
	@brief caseNumber numero del caso
	*/
	string caseNumber;

	/**
	@brief date fecha en la que ocurrio el crimen
	*/
	
	fecha date;
	
	/**
	@brief IUCR codigo especial
	*/ 
	string IUCR;

	/**
	@brief primaryType tipo de crimen
	*/	
	string primaryType;

	/**
	@brief description descripcion del crimen
	*/
	string description;
		
	/**
	@brief locationDesc descripcion de donde tuvo lugar el 		
	crimen
	*/
	string locationDesc;

	/**
	@brief arrest si hubo arresto
	*/
	bool arrest;
	
	/**
	@brief domestic si fue un crimen domestico
	*/
	bool domestic;

	/**
	@brief latitude coordenada de latitud
	*/
	double latitude;

	/**
	@brief longitude coordenada de longitud
        */
	
	double longitude;
   
  
};

	/** 
	@brief flujo de salida <<
	@param os nombre de flujo
	@param  c crimen mostrar en el flujo
	@return referencia a flujo de salida
 	*/  
  	ostream& operator<< ( ostream& , const crimen& c );


	/** @brief class ComparacionPorFechaD {
	 * functor que permite hacer comparaciones por fecha
	 * en orden decreciente.
	 * operator()
	 * */
	class ComparacionPorFechaD {

	public:

		/**
    		@brief Sobrecarga del operador () que permitirá hacer las comparaciones
		@param a primer crimen
		@param b segundo crimen
		@return devuelve true si la fecha del primer crimen es posterior a la de b, false en caso contrario
    		*/		
    		bool operator()(const crimen &a, const crimen &b) {
     			return (a.getDate() > b.getDate()); 
 		}
	};

	
	/** @brief class ComparacionPorFechaC {
	 * functor que permite hacer comparaciones por fecha
	 * en orden creciente.
	 * operator()
	 * */
	
	class ComparacionPorFechaC {

	public:

		/**
    		@brief Sobrecarga del operador () que permitirá hacer las comparaciones
		@param a primer crimen
		@param b segundo crimen
		@return devuelve true si la fecha del primer crimen precede en el tiempo a la de b, false en caso contrario
    		*/	
		bool operator()(const crimen &a, const crimen &b){

     			return (a.getDate() < b.getDate()); 
 		}
	};


	
	/** @brief class ComparacionPorIUCR{
	 * functor que permite hacer comparaciones por IUCR
	 * (segun operador < definido para el tipo string).
	 * operator()
	 * */
	class ComparacionPorIUCR{
	
	public:

		/**
    		@brief Sobrecarga del operador () que permitirá hacer las comparaciones
		@param a primer crimen
		@param b segundo crimen
		@return devuelve true si el IUCR del primer crimen es menor (segun operador < de la clase string) a la del segundo crimen, false en caso contario
    		*/
		
		bool operator()(const crimen &a, const crimen &b) {
			return (a.getIUCR() < b.getIUCR());
		}

	};


#include "crimen.hxx"
#endif
