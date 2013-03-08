#ifndef __STUDENTS_H_
#define __STUDENTS_H_



using namespace std;

struct TStudent
 {
   string     m_Username;
   int        m_Score;
   
 };

class Students
 {
   public:
                             Students( );

    bool                     AddStudent( string Username,int Score);
    bool                     ParseData (string radek);
    void                     SortByScore( void );
    void                     PrintAll( void ) const;
    void                     PrintToFile(char *soubor)const;

   protected:
    int                      countStud;
    static const int         STUDENTSMAX=50; //udava maximalni pocet studentu, kteri mohou byt v tabulce
    TStudent                 m_Students [STUDENTSMAX];


};

 #endif /* __STUDENTS_H_ */