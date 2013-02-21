/* zasobnik.h */

typedef char TypPrvku;

class Zasobnik {
  public: 
    Zasobnik(int = 100);
    ~Zasobnik();
    void vloz(TypPrvku p);
    TypPrvku odeber();
    bool jePrazdny();
  private:
    TypPrvku *prvky;
    int vrch;
    int maxVrch;
};

void chyba(const char *str);
