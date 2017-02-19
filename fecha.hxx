/* @brief fichero de implementacion de la clase fecha*/

	/** \invariant
	 
	 IR: rep ==> bool
	 
	\li Para cualquier sec, 0 <= sec < 60
	\li Para cualquier min, 0 <= min < 60
	\li Para cualquier hour, 0 <= hour < 23
	\li Para cualquier mday, 1 <= mday <= 31
	\li Para cualquier mon, 0 <= mon < 12
	\li Para cualquier year, 2000 <= year
	*/


	fecha :: fecha ()
	{
		sec=0;
		min=0;
		hour=0;
		mday=1;
		mon=0;
		year=2000;		
	}

	fecha::fecha(const fecha & x){

	
		*this = x;
		if(!((*this).chequeaIRFecha())) 
			cout << "La fecha no cumple el invariante de representación" <<endl;

	}

	fecha :: fecha (const string & s)
	{	
		
		string subcadena;
		
		subcadena=s.substr(0,2);
		mon= atoi(subcadena.c_str());
		
		
		subcadena=s.substr(3,2);
		mday= atoi(subcadena.c_str());
		
		
		subcadena=s.substr(6,4);
		year= atoi(subcadena.c_str());
		

		subcadena=s.substr(11,2);
		hour= atoi(subcadena.c_str());

		subcadena=s.substr(20,2);
		if(subcadena == "PM")
		
			hour = hour+12;
		
		if ( hour == 24 )
			hour = hour -24 ;
		
		

		subcadena=s.substr(14,2);
		min= atoi(subcadena.c_str());
		

		subcadena=s.substr(17,2);
		sec= atoi(subcadena.c_str());
		

		

		
	}


	fecha & fecha :: operator=(const fecha & f)
	{
		if(this != &f){
			sec= f.sec;
			min= f.min;
			hour= f.hour;
			mday= f.mday;
			mon= f.mon;
			year= f.year;
		}

		return *this;				

	}

	fecha & fecha :: operator=(const string & s)
	{
		fecha nueva(s);
		if(*this != nueva)
		{

			sec= nueva.sec;
			min= nueva.min;
			hour= nueva.hour;
			mday= nueva.mday;
			mon= nueva.mon;
			year= nueva.year;

		}	
		
		return *this;

	} // s es un string con el formato mm/dd/aaaa hh:mm:ss AM/PM


	bool fecha :: operator==(const fecha & f) const{
		
		bool iguales = false;
		if ((year == f.year) && (mon == f.mon) && (mday == f.mday) && (hour == f.hour) && (min == f.min) && (sec == f.sec))
			iguales = true;
		return iguales;
	}

	bool fecha :: operator!=(const fecha & f)const
	{
		return(!(*this == f));
	}

	bool fecha :: operator<(const fecha & f)const
	{	
		bool menor=false;

		if(year < f.year)
		{
			menor = true;
		}
		else if( year == f.year)
		{
			if(mon < f.mon)
			{
				menor = true;
			}
			else if(mon == f.mon)
			{
				if(mday < f.mday)
				{
					menor = true;
				}
				else if(mday == f.mday)
				{
					if(hour < f.hour)
					{
						menor = true;
					}
					else if(hour == f.hour)
					{
						if(min < f.min)
						{
							menor = true;
						}
						else if(min == f.min)
						{
							if(sec < f.sec)
							{
								menor = true;
							}
							else if (sec == f.sec)
							{
								menor = false;
							}
						}
					}
				}
			}
		}
		
		return menor;
	}
			
		
	
		
 	bool fecha :: operator>(const fecha & f) const
 	{
 		return ((*this != f) && !(*this < f));
 	}
 	bool fecha :: operator<=(const fecha & f)const
 	{
 		return !(*this>f);
 	}
 	bool fecha :: operator>=(const fecha & f) const
 	{
 		return !(*this<f);
 	}

	string ConvierteEntero(const int numero){

		string resultado;
		int numero1=numero;

		if (numero<10)
			resultado= "0" + to_string(numero1);

		else
			resultado= to_string(numero1);

	return resultado;

	}
			


	string fecha :: toString( ) const //convierte la fecha a un string
	{
		string cadena;		
		
		cadena= ConvierteEntero(mon)+ "/" + ConvierteEntero(mday)+ "/" + ConvierteEntero(year)+
		" " + ConvierteEntero(hour) +":" + ConvierteEntero(min)+ ":"+ConvierteEntero(sec);
		

		return cadena;
		
	}



	
	int fecha :: getSec()
	{
		return sec;
	}
	
	int fecha :: getMin()
	{
		return min;
	}
	
	int fecha :: getHour()
	{
		return hour;
	}

	int fecha :: getMDay()
	{
		return mday;
	}

	int fecha :: getMon()
	{
		return mon;
	}

	int fecha :: getYear()
	{
		return year;
	}

	bool fecha::chequeaIRFecha()

	{
		bool cumpleIR=false;

		if((sec>=0 && sec<60) && (min>=0 && min<60) && (hour>=0 && hour<23) && (mday>=1 && mday<=31) && (mon>=0 && mon<12) &&
			(year>=2000))
				cumpleIR=true;

		return cumpleIR; 
		

	}


	ostream& operator<< ( ostream& os, const fecha & f)
	{
		os << f.toString() ;
		return os; 
	}

	


