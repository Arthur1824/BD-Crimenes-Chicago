// conjunto.hxx	

	template<class CMP>
	conjunto<CMP> :: conjunto( ){   
		
    	}


	template<class CMP>
	conjunto<CMP> :: conjunto(typename conjunto<CMP>::iterator & ini, typename conjunto<CMP>::iterator& fin){

		while(ini != fin)
		{
			this.insert(*ini);
			++ini;
		}
			
	}
	
    	template<class CMP>
	conjunto<CMP> :: conjunto (const conjunto<CMP> & d){

        	vc =d.vc;

    }

    	template<class CMP>
    	unsigned int conjunto<CMP> :: size() const {
		conjunto :: size_type util;
		util = vc.size();
		return util;
	}


	template<class CMP>
   	bool conjunto<CMP>::busquedaBinaria (const crimen &d ){

    		int sup=vc.size()-1;
    		int inf = 0;
		int medio = 0;

    		while (sup > inf) {
      			medio = (inf+sup)/2;
      			if (!cmp(vc[medio],d) && !cmp(d,vc[medio]) ) return true;  // comparamos igualdad entre crimen
      			else if (cmp(vc[medio],d)) inf = medio+1; // comparamos menor entre crimen
      			else sup = medio-1;
    		}

    	return false;


	}


	template<class CMP>
	int conjunto<CMP>::busquedaBinaria(const crimen &d ) const {

   	  
	   	int sup=vc.size()-1;
    		int inf = 0;
		int medio = 0;
		bool encontrado=false;

		while (sup > inf && !encontrado) {

      			medio = (inf+sup)/2;

      			if (!cmp(vc[medio],d) && !cmp(d,vc[medio]) ) 
				encontrado=true;
  
      			else if (cmp(vc[medio],d))
				inf = medio+1;
 
      			else 
				sup = medio-1;
    		}

    		return medio;
	}
	

	template<class CMP>
	typename conjunto<CMP>::iterator conjunto<CMP>::find(const crimen & c)
	{

		conjunto<CMP>::iterator salida;
		salida.itsv=vc.begin() + busquedaBinaria(c);
		return salida;
		
	}

	template<class CMP>
	typename conjunto<CMP>::const_iterator conjunto<CMP>::find(const crimen & c)const
	{

		conjunto<CMP>::const_iterator salida;
		salida.itsv=vc.cbegin() + busquedaBinaria(c);
		return salida;
		
	}

	template<class CMP>
	typename conjunto<CMP>::iterator conjunto<CMP>::find( const long int & id){

		conjunto<CMP>::iterator ini;
		ini.itsv=vc.begin();		
		bool encontrado = false;

		while(ini != vc.end() && !encontrado)
		{
			if(id == *ini.getID())
			{
				encontrado = true;
			}
			else
				++ini;
		}
		
		return ini;


	}
	

	template<class CMP>
	typename conjunto<CMP>::const_iterator conjunto<CMP>::find( const long int & id) const{

		conjunto<CMP>::iterator ini;
		ini.itsv=vc.begin();
		typename conjunto<CMP>::const_iterator sal;
		bool encontrado = false;

		while(ini != vc.end() && !encontrado)
		{
			if(id == *ini.getID())
			{
				encontrado = true;
			}
			else
				++ini;
		}
		sal = ini;
		return sal;
		
	}

	template <class CMP>
  	typename conjunto<CMP>::iterator conjunto<CMP>::lower_bound (const entrada & x)
	{
	 	typename conjunto<CMP>::iterator ini;
		ini.itsv = vc.begin();
		bool encontrado = false;		
			
		while (ini < vc.end() && !encontrado){
				if (cmp(x, *ini)|| x == *ini) 
					encontrado = true;
				else 
					ini++;
			
		}


		return ini;
	}


	template <class CMP>
  	typename conjunto<CMP>::const_iterator conjunto<CMP>::lower_bound (const entrada & x) const
	{
	 	typename conjunto<CMP>::iterator ini;
		ini.itsv = vc.begin();
		bool encontrado = false;
		
		while ( ini < vc.end() && !encontrado){
			if ( cmp(x, *ini) || x==*ini ) 
				encontrado = true;
			else 
				ini++;
		}
		typename conjunto<CMP>::const_iterator sal = ini;
		return sal;
	}
	

	template <class CMP>
  	typename conjunto<CMP>::iterator conjunto<CMP>::upper_bound (const entrada & x)
	{
	 	typename conjunto<CMP>::iterator ini;
		ini.itsv = vc.begin();
		bool encontrado = false;		
		while ( ini < vc.end() && !encontrado){
			if ( cmp(*ini,x) ) 
				encontrado = true;
			else 
				ini++;
		}
		return ini;
	}


	template <class CMP>
  	typename conjunto<CMP>::const_iterator conjunto<CMP>::upper_bound (const entrada & x) const
	{
	 	typename conjunto<CMP>::iterator ini;
		ini.itsv = vc.begin();
		bool encontrado = false;
		
		while ( ini < vc.end() && !encontrado){
			if ( cmp(*ini, x) ) 
				encontrado = true;
			else 
				ini++;
		}
		typename conjunto<CMP>::const_iterator sal = ini;
		return sal;
	}

	
	template<class CMP>
	conjunto<CMP> conjunto<CMP> ::  findIUCR( const string & iucr) const{
        
		conjunto<CMP> salida;
		    
		for (int i = 0; i < vc.size(); i++){
		    if ( vc[i].getIUCR() == iucr )
		        salida.insert(vc[i]);
		}
        
    	return salida;
	}


	template<class CMP>
	conjunto<CMP> conjunto<CMP> :: findDESCR( const string & descr) const{
	
		conjunto<CMP> salida;
	
		for (int i = 0; i < vc.size(); i++){
			if (vc[i].getDescription()== descr)
				salida.insert(vc[i]);
		}

		return salida;

	}


	template<class CMP>
	void conjunto<CMP>::insert( const crimen & s){
	
        bool insertado = false;
        for (int i =0; !insertado && i < vc.size(); )
            if (cmp(vc[i],s) ) i++;
            else {
              vc.insert(vc.begin()+i,s);
              insertado = true;
            }
        if (!insertado) vc.push_back(s);
     }




	template<class CMP>
	conjunto<CMP> & conjunto<CMP> :: operator=( const conjunto & org){

		if(this != &org){
			for (int i= 0; i<vc.size(); i++)
				vc[i]=org.vc[i];
			
		}
		
		return *this;
			
	}


	template<class CMP>
	bool conjunto<CMP> :: empty() const{
		bool vacio = false;
	
		if (vc.size() == 0)
			vacio = true;
	
		return vacio;

	}


	template<class CMP>
	typename conjunto<CMP>::iterator conjunto<CMP>::begin(){

	typename conjunto<CMP>::iterator sal;
	sal.itsv = vc.begin();
        return sal;

	}

	
	template<class CMP>
	typename conjunto<CMP>::iterator conjunto<CMP>::end(){

	typename conjunto<CMP>::iterator sal;
	sal.itsv = vc.end();
        return sal;

	}
	
	
	template<class CMP>
	conjunto<CMP>::iterator::iterator(){

	}


	template<class CMP>
	conjunto<CMP>::iterator:: iterator(const conjunto::iterator & i){

  	itsv = i.itsv;

	}


	template<class CMP>
	const typename conjunto<CMP>::entrada & conjunto<CMP>::iterator:: operator*() const{

		return *itsv;
	}


	template<class CMP>
	typename conjunto<CMP>::iterator conjunto<CMP>::iterator:: operator ++ (int i){
		
		typename conjunto<CMP>::iterator sal(*this);
		itsv++;
		return sal;
		
	}


	template<class CMP>
	typename conjunto<CMP>::iterator& conjunto<CMP>::iterator:: operator ++ (){
		
		itsv++;
		return *this;
		
	}


	template<class CMP>
	typename conjunto<CMP>::iterator conjunto<CMP>::iterator:: operator -- (int i){
		
		typename conjunto<CMP>::iterator sal(*this);
		itsv--;
		return sal;
		
	}


	template<class CMP>
	typename conjunto<CMP>::iterator& conjunto<CMP>::iterator:: operator -- (){
		
		
		itsv--;
		return *this;
		
	}


	template<class CMP>
	bool conjunto<CMP>::iterator:: operator ==(const iterator & it){

		return (itsv==(it.itsv));
	}


	template<class CMP>	
	bool conjunto<CMP>::iterator:: operator !=(const iterator & it){

		return !((this)==&(it));
	}
//Empezamos con todo const_iterator


	template<class CMP>
	typename conjunto<CMP>::const_iterator conjunto<CMP>::cbegin() const{

	typename conjunto<CMP>::const_iterator sal;
	sal.c_itv = vc.cbegin();
    	return sal;

	}

	
	template<class CMP>
	typename conjunto<CMP>::const_iterator conjunto<CMP>::cend() const{

	typename conjunto<CMP>::const_iterator sal;
	sal.c_itv = vc.cend();
        return sal;

	}


	template<class CMP>
	conjunto<CMP>::const_iterator::const_iterator(){
	}


	template<class CMP>
	conjunto<CMP>::const_iterator::const_iterator(const const_iterator & it){

		c_itv = it.c_itv;
	
	}

	
	template<class CMP>
	conjunto<CMP>::const_iterator::const_iterator (const iterator & it){

		c_itv = it.itsv;
	}


	template<class CMP>
	const typename conjunto<CMP>::entrada & conjunto<CMP>::const_iterator::operator*() const{

		return *c_itv;

	}


	template<class CMP>
	typename conjunto<CMP>::const_iterator conjunto<CMP>::const_iterator:: operator++ (int i){

	typename conjunto<CMP>::const_iterator sal(*this);
		c_itv++;
		return sal;

	}


	template<class CMP>
	typename conjunto<CMP>::const_iterator& conjunto<CMP>::const_iterator:: operator++ (){

		c_itv++;
		return *this;

	}


	template<class CMP>
	typename conjunto<CMP>::const_iterator conjunto<CMP>::const_iterator:: operator-- (int i){
		typename conjunto<CMP>::const_iterator sal(*this);
		c_itv--;
		return sal;
	}


	template<class CMP>
	typename conjunto<CMP>::const_iterator& conjunto<CMP>::const_iterator:: operator-- (){

		c_itv--;
		return *this;

	}


	template<class CMP>
	bool conjunto<CMP>::const_iterator::operator==(const const_iterator & it){

		return (c_itv==(it.c_itv));

	}


	template<class CMP>
	bool conjunto<CMP>::const_iterator::operator!=(const const_iterator & it){

		return !(this==&it);

	}

	
	template<class CMP>
	ostream &  operator << ( ostream & sal, const conjunto<CMP> & D){

		for (int i = 0; i < D.size(); i ++){
			sal << D.vc[i]<< endl;
			sal << "__________________________________________"<<endl;
		}

		return sal;
	}





