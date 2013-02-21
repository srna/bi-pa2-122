/* citac.h */

class Citac {
   int	hodn;
   int	pocHodn;
public:
   Citac(int ph=0)  {pocHodn = ph; nastavit();}
   void zvetsit()   {hodn++;}
   void zmensit()   {hodn--;}
   void nastavit()  {hodn = pocHodn;}
   int  hodnota()   {return hodn;}
};
