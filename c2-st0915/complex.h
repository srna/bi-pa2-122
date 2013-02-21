class Complex{
int re,im;
public:
Complex(int r=0, int i=0){re=r;im=i;}
int getRe() const {return re;}
int getIm() const {return im;}
void setRe(int r){re=r;}
void setIm(int i){im=i;}
float abs(){return sqrt(re*re+im*im);}
void print(){cout << "(" << re << "+" << im << "i)";}
Complex add(const Complex& y) const {
int real, imag;
real=re+y.re;
imag=im+y.im;
Complex z(real,imag);
return z;

     }
Complex diff(const Complex& y) const {
int real, imag;
real=re-y.re;
imag=im-y.im;
Complex z(real,imag);
return z;

     }
};




Complex add(const Complex& x, const Complex& y){
int re=x.getRe()+y.getRe();
int im=x.getIm()+y.getIm();

Complex z(re,im);
return z;
}

Complex diff(Complex x, Complex y){
int re=x.getRe()-y.getRe();
int im=x.getIm()-y.getIm();

Complex z(re,im);
return z;
}