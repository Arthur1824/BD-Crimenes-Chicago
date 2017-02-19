/* 
 * conjunto.h
 * 
 * Copyright  (C) Juan F. Huete
*/

#ifndef __CONJUTO_H
#define __CONJUTO_H
#include <string>
#include <vector>
#include <iostream> 
#include <functional>
#include "crimen.h"

using namespace std;


//! Clase conjunto
/**! Métodos--> conjunto:: conjunto(), insert(), find(),  findIUCR(), findDESCR(), erase(), size(), empty()

 * Tipos--> conjunto::entrada, conjunto::size_type

 * Descripción

* Un conjunto es un contenedor que permite almacenar en orden creciente un conjunto de elementos no repetidos.  En nuestro caso el conjunto va a tener un subconjunto restringido de métodos (inserción de elementos, consulta de un elemento, etc). Este conjunto "simulará" un conjunto de la stl, con algunas claras diferencias pues, entre otros,  no estará dotado de la capacidad de iterar (recorrer) a través de sus elementos.

* Asociado al conjunto, tendremos el tipo  \code conjunto::entrada \endcode que permite hacer referencia al elemento  almacenados en cada una de las posiciones del conjunto, en nuestro caso delitos (crimenes). Para esta entrada el requisito es que tenga definidos el operador< y operator=

* Además encontraremos el tipo \code conjunto::size_type \endcode que permite hacer referencia al número de elementos en el conjunto.

* El número de elementos en el conjunto puede variar dinámicamente; la gestión de la memoria es automática. 
 
 Ejemplo de su uso:
\code
...
conjunto DatosChicago, agresion;
crimen cr;

conjunto.insert(cr);
...
agresion = conjunto.findDESCR("BATTERY");

if (!agresion.empty()){
 cout <<"Tenemos "<< agresion.size() << " agresiones" << endl;
 cout << agresion << endl;
} else "No hay agresiones en el conjunto" << endl;
...
\endcode
 @todo Implementa esta clase, junto con su documentación asociada
 */




template<class CMP>
class conjunto
{  
public:

    /**
	@brief entrada permite hacer referencia al elemento  almacenados en cada una de las posiciones del conjunto
    */
	typedef crimen entrada;


	/** 
	@brief size_type numero de elementos en el conjunto
    */
	typedef unsigned int size_type;


	/** 
	@brief constructor primitivo. 
	
	*/
	conjunto( );

	/**
	@brief Constructor de conjunto que contiene los elementos contenidos en el rango [ini,fin) 
	*/
	conjunto( typename conjunto<CMP>::iterator & ini, typename conjunto<CMP>::iterator &fin);



	/** 
	@brief constructor de copia
	@param[in] d conjunto a copiar
	*/
	conjunto (const conjunto<CMP> & d);

	/**
	@brief consultor del tamaño del conjunto
	@return el tamaño del conjunto
	*/
	
	size_type size()const ;/////////////////////////////////////////////////////////////////////////////////
	
	/**
	@brief class iterator. Iterador sobre los delitos
	*/
	class iterator;  
	/**
	@brief class const_iterator. Iterador sobre los delitos, ahora constante.
	*/
   	class const_iterator;


	/** 
	@brief busca un crimen en el conjunto
	@param id identificador del crimen  buscar
	@return Si existe una entrada en el conjunto devuelve un par con una copia de la entrada en el conjunto y con el segundo valor a true. 		Si  no se encuentra devuelve la entrada con la definicion por defecto y false 
	@post no modifica el conjunto.
	\verbatim Uso
       

	if (C.find(12345).second ==true) cout << "Esta" ;
	else cout << "No esta";
	\endverbatim
	*/


	//pair<conjunto::entrada,bool>  find( const long int & id) const;


	/**
	@brief busqueda binaria de un crimen en un conjunto
	@param d crimen a buscar
	@return bool está/no está
	*/
	bool busquedaBinaria (const crimen &d );

	/**
	@brief busqueda binaria del id de un crimen en un conjunto
	@param	d crimen a buscar
	@return int posición donde se encuentra ese crimen
	*/
	int busquedaBinaria(const crimen &d ) const;


	/** @brief busca un crimen en el conjunto
	@param c crimen
	@return Si existe una entrada en el conjunto devuelve un iterador a la posicion donde está el elemento. Si  no se encuentra devuelve end()

	@post no modifica el conjunto.
	\code Ejemplo
	*/
	conjunto<CMP>::iterator find(const crimen & c);

	/** @brief busca un crimen en el conjunto CONSTANTE
	@param c crimen.
	@return Si existe una entrada en el conjunto devuelve un iterador CONSTANTE a la posicion donde está el elemento. Si  no se encuentra devuelve end()
	@post no modifica el conjunto.
	\code Ejemplo
	*/
	conjunto<CMP>::const_iterator find(const crimen & c)const;


	/** @brief busca un crimen en el conjunto
	@param id identificador del crimen  buscar
	@return Si existe una entrada en el conjunto devuelve un iterador a lo posicion donde está el elemento. Si  no se encuentra devuelve end()
	@post no modifica el conjunto.
	\code Ejemplo
	*/
	conjunto<CMP>::iterator find( const long int & id);


	/** @brief busca un crimen en el conjunto
	@param id identificador del crimen  buscar
	@return Si existe una entrada en el conjunto devuelve un iterador a lo posicion donde está el elemento. Si  no se encuentra devuelve end()
	@post no modifica el conjunto.
	\code Ejemplo
       

	if (C.find(12345)!=C.end() ) cout << "Esta" ;
	else cout << "No esta";
	\endcode
	*/

	
	conjunto<CMP>::const_iterator find( const long int & id) const;


	/** @brief Devuelven un iterador al primer elemento en el contenedor que no precede a x en el conjunto, esto es, es equivalente a x o 		le sigue según la relacion de orden definida por CMP. Esta función utiliza el functor interno devolviendo un iterador al primer 	elemento, e, para el que se satisface que comp(e,x) es falso. 
	@param x crimen de entrada
	@return iterador de clase conjunto<CMP>
	*/

	conjunto<CMP>::iterator lower_bound (const entrada & x);



	/** @brief Devuelven un iterador constante al primer elemento en el contenedor que no precede a x en el conjunto, esto es, es 		equivalente a x o 		le sigue según la relacion de orden definida por CMP. Esta función utiliza el functor interno 		devolviendo un iterador al primer 	elemento, e, para el que se satisface que comp(e,x) es falso. 
	@param x crimen de entrada
	@return iterador constante de clase conjunto<CMP>
	*/

	conjunto<CMP>::const_iterator lower_bound (const entrada & x) const;



	/** @brief Devuelven un iterador al primer elemento en el contenedor que precede a x en el conjunto según la relacion de orden 		definida por CMP. Esta función utiliza el functor interno devolviendo un iterador al primer 	elemento, e, para el que se satisface 		que comp(e,x) es verdadero. 
	@param x crimen de entrada
	@return iterador de clase conjunto<CMP>
	*/
	conjunto<CMP>::iterator upper_bound (const entrada & x);



	/** @brief Devuelven un iterador constante al primer elemento en el contenedor que precede a x en el conjunto según la relacion de 		orden definida por CMP. Esta función utiliza el functor interno devolviendo un iterador al primer 	elemento, e, para el 		que se satisface que comp(e,x) es verdadero. 
	@param x crimen de entrada
	@return iterador de clase conjunto<CMP>
	*/
	conjunto<CMP>::const_iterator upper_bound (const entrada & x) const;


	/** 
	@brief busca los crimenes con el mismo codigo IUCR
	@param iucr identificador del crimen  buscar
	@return Devuelve un  conjunto con todos los crimenes con el codigo IUCR. Si no existe ninguno devuelve el conjunto vacio.
	@post no modifica el conjunto.
	\verbatim Uso
        vector<crimen> C, A;
        ....
        A = C.findIUCR("0460");
	\endverbatim
	*/
	conjunto<CMP> findIUCR( const string & iucr) const;


	/** 
	@brief busca los crimenes que contienen una determinada descripcion 
	@param descr string que representa la descripcion del delito buscar
	@return Devuelve un  conjunto con todos los crimenes  que contengan descr en su descripcionR. Si no existe ninguno devuelve el 		conjunto vacio.
	@post no modifica el conjunto.
	\verbatim Uso
        vector<crimen> C, A;
        ....
        A = C.findDESCR("BATTERY");
	\endverbatim
	*/
	conjunto<CMP>findDESCR( const string & descr) const;


	/** 
	@brief Inserta una entrada en el conjunto
	@param s entrada a insertar
	@return true si la entrada se ha podido insertar con éxito. False en caso contrario
	@post 	 Si e no esta en el conjunto, el size() sera incrementado en 1.
	*/
	void insert( const crimen & s);


	/** 
	@brief Borra el delito dado un identificacador.
	Busca la entrada con id en el conjunto  y si la encuentra la borra
	@param[in] id a borrar
	@return true si la entrada se ha podido borrar con éxito. False en caso contrario
	@post Si esta en el conjunto su tamaño se decrementa en 1.
	*/
	bool erase(const long int & id);
	

	
	/** 
	@brief Borra una crimen con identificador dado por e.getID() en el conjunto.
	Busca la entrada con id en el conjunto (o e.getID() en el segundo caso) y si la encuentra la borra
	@param[in] e con e.getID() que queremos borrar, el resto de los valores no son tenidos en cuenta
	@return true si la entrada se ha podido borrar con éxito. False en caso contrario
	@post Si esta en el conjunto su tamaño se decrementa en 1.
	*/
	bool erase(const  conjunto::entrada & e);
	
	
	/** 
	@brief operador de asignación
	@param[in] org conjunto  a copiar.
	 Crea un conjunto duplicado exacto de org.
	*/
	conjunto & operator=( const conjunto & org);


	
	/** 
	@brief Chequea si el conjunto esta vacio
	@return true si size()==0, false en caso contrario.
	*/
	bool empty() const;

	// ================================= ITERADORES ========================================/

    /**
    @brief devuelve iterador al inicio del conjunto
    */
    iterator begin() ;

    /**
    @brief devuelve iterador al final (posición siguiente al último del conjunto
    */
    iterator end() ;


	/** @brief class iterator
	 * forward iterador sobre el conjunto, LECTURA
	 *  iterator() ,operator*(), operator++, operator++(int) operator=, operator==, operator!=
	 * */


    class iterator {       

       	public:
       		
		/** 
		@brief Constructor por defecto del iterador sobre el conjunto
		*/
       	iterator();


	    /**
	    @brief Constructor del iterador que recibe un parametro para indicar su posicion
		@param[in] it Recibe un iterador it que se le asigna al this.itsv.
		*/
       	iterator (const iterator & it);


	    /**
	    @brief Sobrecarga del operador asterisco para el iterador sobre el conjunto.
		@return Devuelve el contenido de la posición al que apunta el iterador.
		@post La función no modifica itsv.
		*/
       	const conjunto::entrada & operator*() const;


	    /**
	    @brief Sobrecarga del operador ++i para el iterador sobre el conjunto.

		@return Devuelve la siguiente posición (siguiente crimen).
		*/  
       	iterator operator++( int );


	    /**
	    @brief Sobrecarga del operador i++ para el iterador sobre el conjunto.
		@return Devuelve la siguiente posición (siguiente crimen).
		*/  
       	iterator & operator++();


	    /**
	    @brief Sobrecarga del operador --i para el iterador sobre el conjunto.
	    @return Devuelve la siguiente posición (siguiente crimen).
		*/     
       	iterator operator--(int);


	    /**
	    @brief Sobrecarga del operador i-- para el iterador sobre el conjunto.
		@return Devuelve la siguiente posición (siguiente crimen).
		*/  
       	iterator & operator--();


	    /**
	    @brief Sobrecarga del operador == para el iterador sobre el conjunto.
	    @param[in] it Recibe un iterador it.;
		@return Devuelve  true si son iguales y false en caso contrario.
		*/      
       	bool operator==(const iterator & it);


	    /**
	    @brief Sobrecarga del operador != para el iterador sobre el conjunto.
	    @param[in] it Recibe un iterador it.;
		@return Devuelve  true si son diferentes y false en caso contrario.
		*/    
       	bool operator!=(const iterator & it);


       	private:

	   	/**
	   	@brief conjunto como clase amiga para poder acceder a sus datos miembros
	   	desde la clase iterator
	   	*/
	   	friend class conjunto;

	   	/**
	   	@brief itsv iterador sobre un vector de entrada que me permitirá
	   	trabajar sobre un conjunto.
	   	*/

       		vector<entrada>::iterator itsv; 
	};
/**
 	@brief  
    @return Devuelve el const_iterator a la primera posición del conjunto.
	@post no modifica el conjunto
    */
    
	const_iterator cbegin() const;


	/**
	@brief iterador al final
    @return Devuelve el iterador constante a la  posición final del conjunto.
	@post no modifica el conjunto
    */
	const_iterator cend() const;



	/**
	
	@brief class const_iterator
	 * forward iterador constante sobre el diccionario, Lectura 
	 *  const_iterator ,operator*, operator++, operator++(int) operator=, operator==, operator!=
	 * */

	class const_iterator {
		public:
		/**
		@brief Constructor por defecto del iterador constante sobre el conjunto
		*/
		const_iterator();


		 /**
		@brief Constructor del iterador constante que recibe un parametro para indicar su posicion
		@param[in] it Recibe un iterador it que se le asigna al this.c_itv.
		*/
		const_iterator(const const_iterator & it);


	    /** 
	    @brief Convierte iterator en const_iterator
	    */
		const_iterator(const iterator & it);


		/**
		@brief Sobrecarga del operador asterisco para el iterador constante sobre el conjunto.
		@return Devuelve el contenido de la posición al que apunta el iterador.
		@post La función no modifica c_itv.
		*/
		const conjunto::entrada & operator*() const;


		/**
		@brief Sobrecarga del operador ++i para el iterador constante sobre el conjunto.	    
		@return Devuelve la siguiente posición (siguiente crimen).
		*/  
		const_iterator operator++( int );


		/**
		@brief Sobrecarga del operador i++ para el iterador constante sobre el conjunto.
		@return Devuelve la siguiente posición (siguiente crimen).
		*/  
		const_iterator & operator++();


		/**
		@brief Sobrecarga del operador --i para el iterador constante sobre el conjunto.
		@return Devuelve la siguiente posición (siguiente crimen).
		*/	 	
	 	const_iterator operator--(int);


	 	 /**
	 	@brief Sobrecarga del operador i-- para el iterador constante sobre el conjunto.
		@return Devuelve la siguiente posición (siguiente crimen).
		*/   
	    const_iterator & operator--();


	    /**
	    @brief Sobrecarga del operador == para el iterador constante sobre el conjunto.
	    @param[in] it Recibe un iterador it.;
		@return Devuelve  true si son iguales y false en caso contrario.
		*/            
		bool operator==(const const_iterator & it);


		/**
		@brief Sobrecarga del operador != para el iterador sobre el conjunto.
	    @param[in] it Recibe un iterador it.;
		@return Devuelve  true si son diferentes y false en caso contrario.
		*/    
		bool operator!=(const const_iterator & it);


		private:

			/**
	   	@brief conjunto como clase amiga para poder acceder a sus datos miembros
	   	desde la clase iterator
	   	*/
	   	friend class conjunto;

	   	/**
	   	@brief c_itv iterador constante sobre un vector de entrada que me permitirá
	   	trabajar sobre un conjunto.
	   	*/
		vector<entrada>::const_iterator c_itv;// Para poder acceder a los datos privados de conjunto
		  	
		  
	};



	private:
 	vector<crimen> vc; // vector ORDENADO por crimen.id que almacena los elementos del conjunto
 	CMP cmp;


	/** \invariant
	 
	 IR: rep ==> bool
	 
	\li Para todo i, 0 <= i < vc.size() se cumple
		vc[i].ID > 0;
	\li Para todo i, 0 <= i <= D.dic.size()-1 se cumple
		vc[i].ID< vc[i+1].ID

	EL METODO INSERT DE LA CLASE

	*/

	/**
  	@brief iterator como clase amiga de la clase conjunto
  	para poder acceder a sus datos miembros
  	*/
	friend class iterator;

	/**
  	@brief iterator como clase amiga de la clase conjunto
  	para poder acceder a sus datos miembros
  	*/
  	friend class const_iterator;
 

	/**
	@brief Declaracion del operator<< como metodo amigo
	@param sal flujo de salida pasado por referencia
	@param D conjunto constante a imprimir por pantalla
	@return el flujo de salida 
	*/
	template < class X >
  	friend ostream &  operator << ( ostream & sal, const conjunto<X> & D);

	
	/** 
	@brief Chequea el Invariante de la representacion 
	@return true si el invariante es correcto, falso en caso contrario
	*/
  	bool cheq_rep( ) const;	


 

};
	template < class CMP >
	ostream &  operator << ( ostream & sal, const conjunto<CMP> & D);


	

#include "conjunto.hxx"

#endif
