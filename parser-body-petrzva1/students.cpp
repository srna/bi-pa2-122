#include <iostream>
#include <fstream>
#include <string>
#include <iostream>


#include "students.h"

using namespace std;


    Students::Students( )
    {
    	countStud = 0;
    }

    bool Students::AddStudent ( string Username,int Score)
    {
    	if (countStud >= STUDENTSMAX) return false;

    	for (int  i = 0 ; i < countStud ; i++)
    		if(m_Students[i].m_Username == Username)
    		{
    			m_Students[i].m_Score = m_Students[i].m_Score + Score;
    			return true;
    		}   

    	m_Students[countStud].m_Score = Score;
    	m_Students[countStud].m_Username = Username; 
    	countStud++;
    	return true;

    }

    
 
    void Students::PrintAll( void ) const
    {
    	int i;
   
   			cout << "Username pocet_bodu" << endl;
  			for ( i = 0; i < countStud; i ++ )
   			cout<<m_Students[i].m_Username << " " << m_Students[i].m_Score<< "b" << endl;
    }

    void Students::PrintToFile( char *soubor) const
    {
    	ofstream ofs;
    	ofs.open(soubor);
		ofs << "Username pocet_bodu" << endl;
		ofs << "-------------------" << endl;
    	for (int  i = 0; i < countStud; i ++ )
   			ofs<<m_Students[i].m_Username << " " << m_Students[i].m_Score<< "b" << endl;
    	cout<<"Import dat do souboru probehlo uspesne."<<endl;

    }

     bool Students::ParseData (string radek)
     {
		string jmeno="";
		char znak=' ';
		int hodnota=0;
		int mezery = 0;
		
		for(int j = 0 ; j < 8 + mezery ; j++)
		{
			znak = radek[j];
			if(znak == ' ' && jmeno =="")  //preskoci uvodni mezery
			{
				mezery ++;
			}
			else if(znak == ' ' && jmeno !="")
			{
				cout<<"Na radku se vyskytlo username ve kterem je mezera."<<endl;
				return false;
			}
			else
			jmeno = jmeno+znak;
		}
		
		for(unsigned int k = 8 +mezery; k < radek.length(); k++)
		{
			znak = radek[k];
			if(znak == ' ' ) 
			{
				continue;
			}
			else if(znak == '+')
			{
				
				if( radek[k+1] == '1' ||radek[k+1] == '2' ||radek[k+1] == '3' ||radek[k+1] == '4' ||
					radek[k+1] == '5' ||radek[k+1] == '6' ||radek[k+1] == '6' ||radek[k+1] == '7' ||
					radek[k+1] == '8' ||radek[k+1] == '9' ||radek[k+1] == '0' )
				{
					hodnota= hodnota+(int)radek[k+1]-48;
					k++;
			    }
			}
			else if(znak == '-')
			{
				if( radek[k+1] == '1' ||radek[k+1] == '2' ||radek[k+1] == '3' ||radek[k+1] == '4' ||
					radek[k+1] == '5' ||radek[k+1] == '6' ||radek[k+1] == '6' ||radek[k+1] == '7' ||
					radek[k+1] == '8' ||radek[k+1] == '9' ||radek[k+1] == '0' )
				{
					hodnota= hodnota-((int)radek[k+1]-48);
					k++;
			    }
			}
			else if(znak == '1' ||znak == '2' ||znak == '3' ||znak == '4' ||
				znak == '5' ||znak == '6' ||znak == '6' ||znak == '7' ||
				znak == '8' ||znak == '9' ||znak == '0' )
			{
				
				hodnota= hodnota+(int)radek[k]-48;
			  				
			}
			else
			{
				cout<<"Na radku se vyskytlo username delsi nez 8 znaku"<<endl;
				return false;
			}
				
		}
		AddStudent(jmeno,hodnota);
		//cout<< "student s username : " <<jmeno<< " ziskal celkem : "<<hodnota<<"b"<<endl;
		return true;
}

void Students::SortByScore ( void )
{
 	int i, j, minIdx;
   	TStudent tmp;

   for ( i = 0; i < countStud-1; i ++ )
    {
      minIdx = i;

      for ( j = i + 1; j < countStud; j ++ )
       if ( m_Students[j] . m_Score > m_Students[minIdx] . m_Score )
        minIdx = j;

      tmp = m_Students[ minIdx ];
      m_Students[minIdx] = m_Students[i];
      m_Students[i] = tmp;
    }
}