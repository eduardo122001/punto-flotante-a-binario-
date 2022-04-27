#include <iostream>
#include <bitset>
#include <math.h>
using namespace std;


void print_float(bitset<32> a){
    for(int i=31;i>-1;i--){
        cout<<a.test(i);
        if(i==31||i==23){
            cout<<" ";
        }
    }
    cout<<endl;
}

void print_doble(bitset<64> a){
    for(int i=63;i>-1;i--){
        cout<<a.test(i);
        if(i==63||i==52){
            cout<<" ";
        }
    }
    cout<<endl;
}

int main()
{



    float flot=32.72;double dobl=32.72;int entero=32;int entero_d=32;float decimal=0.72;float decimal_d=0.72;
    //float flot=36.46;double dobl=36.46;int entero=36;int entero_d=36;float decimal=0.46;float decimal_d=0.46;
    //float flot=25.86;double dobl=25.86;int entero=25;int entero_d=25;float decimal=0.86;float decimal_d=0.86;
    bitset<1>sign;
    bitset<8>exp_f;
    bitset<23>signif_f;
    bitset<32>flotante;

    if(entero<0){
        sign.set();
        flotante.set(31);
    }else{
        sign.reset();
        flotante.reset(31);
    }
//revision del decimal
    float dec=decimal;
    for(int i=22;i>-1;i--){
        dec=dec*2;
        if(dec>=1){
            signif_f.set(i);
            dec=dec-1;
        }else{
            signif_f.reset(i);
        }
    }
//revision del entero
    if(entero<0){entero=entero*(-1);}
    exp_f=entero;
    int j=7;
    for(int i=30;i>23;i--){
        if(exp_f.test(j)){
            flotante.set(i);
        }
        j--;
    }

    int n=0;
    for(int i=23;i<31;i++){
        if(flotante.test(i)){
            break;
        }
        n++;
        signif_f=signif_f>>1;
    }
    for(int i=22;i>-1;i--){
        if(signif_f.test(i)){
            flotante.set(i);
        }
    }

    int biased=n+(pow(2,(8-1))-1);
    exp_f=biased;
    j=7;
    for(int i=30;i>23;i--){
        if(exp_f.test(j)){
            flotante.set(i);
        }else{
            flotante.reset(i);
        }
        j--;
    }
    cout<<"Binario flotante(por el programa) de"<<flot<<endl;print_float(flotante);
    //float f=32.72;
    cout<<"binario flotante(por c++)"<<endl;
    print_float(bitset<sizeof flot*8>(*(long unsigned int*)(&flot)));
///////////////////////////////////////////////////

    bitset<1>sign_d;
    bitset<11>exp_d;
    bitset<52>signif_d;
    bitset<64>doble;


//revision de el simbolo
    if(entero_d<0){
        sign.set();
        doble.set(63);
    }else{
        sign.reset();
        doble.reset(63);
    }
//revision del decimal
    float dec_d=decimal_d;
    for(int i=51;i>-1;i--){
        dec_d=dec_d*2;
        if(dec_d>=1){
            signif_d.set(i);
            dec_d=dec_d-1;
        }else{
            signif_d.reset(i);
        }
    }
//revision del entero
    if(entero_d<0){entero_d=entero_d*(-1);}
    exp_d=entero_d;
    int jd=10;
    for(int i=62;i>52;i--){
        if(exp_d.test(jd)){
            doble.set(i);
        }
        jd--;
    }
//revision biased
    int nd=0;
    for(int i=52;i<63;i++){
        if(doble.test(i)){
            break;
        }
        nd++;
        signif_d=signif_d>>1;
    }

    for(int i=51;i>-1;i--){
        if(signif_d.test(i)){
            doble.set(i);
        }
    }

    int biasedd=nd+(pow(2,(8-1))-1);
    exp_d=biasedd;

    jd=10;
    for(int i=62;i>51;i--){
        if(exp_d.test(jd)){
            doble.set(i);
        }else{
            doble.reset(i);
        }
        jd--;
    }
    cout<<"Binario doble de "<<dobl<<endl;
    print_doble(doble);
    double d=32.72;
    cout<<"binario flotante(por c++)"<<endl;
    bitset<64>d1=d;
    //print_float(bitset<sizeof d1*8>(*(long unsigned int*)(&d1)));
//////////converison de flotante a doble/////////////////////////
    bitset<64>convertido;
    if(flotante.test(31)){
        convertido.set(63);
    }
    //agregamos los enteros
    int j_c=52;
    for(int i=23;i<31;i++){
        if(flotante.test(i)){
            convertido.set(j_c);
        }
        j_c++;
    }
    //agregamos los flotantes
    j_c=51;
    for(int i=22;i>-1;i--){
        if(flotante.test(i)){
            convertido.set(j_c);
        }
        j_c--;
    }
    cout<<"CAMBIO DE FLOTANTE A DOBLE"<<endl;
    cout<<"   ";print_float(flotante);
    print_doble(convertido);


}
