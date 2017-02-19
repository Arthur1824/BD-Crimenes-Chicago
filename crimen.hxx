
//! Clase crimen, asociada a la definición de un crimen 
/*! crimen::crimen,  .....
 * Descripción contiene toda la información asociada a un crimen.
 
 @todo Implementa esta clase, junto con su documentación asociada

*/
 


  
  crimen::crimen()
  {
  	  fecha x;
      ID=0;
      caseNumber="";
      date=x;
      IUCR="";
      primaryType="";
      description="";
      locationDesc="";
      arrest=false;
      domestic=false;
      latitude=0.0;
      longitude=0.0;
      
  }
  
  crimen::crimen(const crimen& x)
  {
      ID=x.ID;
      caseNumber=x.caseNumber;
      date=x.date;
      IUCR=x.IUCR;
      primaryType=x.primaryType;
      description=x.description;
      locationDesc=x.locationDesc;
      arrest=x.arrest;
      domestic=x.domestic;
      latitude=x.latitude;
      longitude=x.longitude;
      
      
  }   
	
	
  void crimen::setID(long int & id)
  {
      ID=id;
  }
	
  void crimen::setCaseNumber(const string &  s)
  {
      caseNumber=s;
  }
  
 
  void crimen::setIUCR(const string &  iucr)
  {
      IUCR=iucr;
  }
	

  void crimen::setDate(const fecha & d)
  {
      date=d;
  }
  
  
  void crimen::setPrimaryType(const string &  pt)
  {
      primaryType=pt;
      
  }
  
  void crimen::setDescription(const string &  desc)
  {
      description=desc;
      
  }
  
  
  void crimen::setLocationDescription(const string &  locDesc)
  {
      locationDesc=locDesc;
      
  }
  
  void crimen::setLatitude(const double &  lat)
  {
      latitude=lat;
      
  }
  
   
  void crimen::setLongitude(const double &  longitud)
  {
      longitude=longitud;
      
  }
      
  
  void crimen::setArrest(bool a)
  {
      arrest=a;
      
  }
	
  void crimen::setDomestic(bool d)
  {
      domestic=d;
      
  }
  
 
  long int crimen::getID( ) const
  {
      return ID;
      
  }
  
  
  string crimen::getCaseNumber( ) const
  {
      return caseNumber;
  }
  
  
  fecha crimen::getDate( ) const
  {
      return date;
  }
  
  
  string crimen::getIUCR( ) const
  {
      return IUCR;
  }
  
  
  string crimen::getPrimaryType( ) const
  {
      return primaryType;
  }
  
  
  string crimen::getDescription( ) const
  {
      return description;
  }
  
  
  
  string crimen::getLocationDesc( ) const
  {
      return locationDesc;
  }
  

  double crimen::getLatitude( ) const
  {
      return latitude;
  }
  
  
  double crimen::getLongitude( ) const
  {
      return latitude;
  }
  bool crimen::getArrest() const
  {
  	return arrest;
  }

  bool crimen::getDomestic() const
  {
  	return domestic;
  }
  
 
   crimen & crimen::operator=(const crimen & x)
   {
       if(this != &x){
           
            ID=x.ID;
            caseNumber=x.caseNumber;
            date=x.date;
            IUCR=x.IUCR;
            primaryType=x.primaryType;
            description=x.description;
            locationDesc=x.locationDesc;
            arrest=x.arrest;
            domestic=x.domestic;
            latitude=x.latitude;
            longitude=x.longitude;
       }
       
       return *this;
   }
         
   bool crimen::operator==(const crimen & x) const
   {
       bool iguales=false;
       
       if (ID==x.ID)
           iguales=true;
       
       return iguales;
       
   }
           
	 
   bool crimen::operator<(const crimen & x) const
   {
       bool menor=false;
       
       if(ID<x.ID)
           menor=true;
       
       return menor;
       
   }

   ostream& operator<< ( ostream& os, const crimen& c)
   {
       
       os <<c.ID <<",  " <<c.caseNumber <<",  " <<c.date <<",  " <<c.IUCR <<",  " <<c.primaryType <<",  " <<c.description;
       os <<",  \n" <<c.locationDesc <<",  ";
       if(c.arrest)
       {
       		cout << "true, ";
       }
       else
       {
       		cout << "false, ";
       }

       if(c.domestic)
       {
       		cout << "true, ";
       }
       else
       {
       		cout << "false, ";
       }

        cout << c.latitude <<",  " <<c.longitude;
       
       return os;
       
   }
