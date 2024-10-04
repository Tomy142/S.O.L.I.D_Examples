#include <iostream>
#include <string>
#include <memory>

using namespace std;


//Clase Base TV
class TV
{
    protected:
        int volume = 0;
        int channels = 1;
        bool status = false;

    public:
        TV(int s_volume, int s_channel, bool s_status){
            this-> volume = s_volume;
            this-> channels = s_channel;
            this-> status = s_status;
        };

        ~TV(){};
//Metodos Virtuales
        virtual int setVolume(int s_volume){
            if(s_volume >= 0 && s_volume <= 100){
                volume =s_volume;
            }
            else{
                cout<<"Volumen invalido"<<endl;
            }
            return volume;
        };

        virtual int setChannels(int s_channel){
            if(s_channel > 0 && s_channel <= 500){
                channels=s_channel;
            }
            else{
                cout<<"Canal no disponible"<<endl;
            }
            return channels;
        };

        virtual bool setStatus(bool s_status){
            status = s_status;
            if(status){
                cout<<"Televisor Prendido"<<endl;
            }
            else{
                cout<<"Televisor Apagado"<<endl;
            }
            return status;
        }

};

class RemoteControl : public TV
{
    public:
        RemoteControl(int s_volume, int s_channel, bool s_status): TV( s_volume, s_channel, s_status){};

        ~RemoteControl(){};
//Sobreescritura de metodos
        int setVolume(int s_volume){
            if(s_volume >= 0 && s_volume <= 100){
                volume =s_volume;
            }
            else{
                cout<<"Volumen invalido"<<endl;
            }
            return volume;
        };

        int setChannels(int s_channel){
            if(s_channel > 0 && s_channel <= 500){
                channels=s_channel;
            }
            else{
                cout<<"Canal no disponible"<<endl;
            }
            return channels;
        };

        bool setStatus(bool s_status){
            status = s_status;
            if(status){
                cout<<"Televisor Prendido"<<endl;
            }
            else{
                cout<<"Televisor Apagado"<<endl;
            }
            return status;
        }
};

int main(){
    // Creación de una instancia de TV
    unique_ptr<TV> myTV = make_unique<TV>(10, 1, false);
    cout<<"Valores instanciados por la TV"<<endl;
    cout<<"Volumen: "<<myTV->setVolume(25)<<endl;
    cout<<"Canal: "<<myTV->setChannels(10)<<endl;
    cout<<"Estado del televisor: ";
    myTV->setStatus(true);
    cout<<endl;

    // Creación de una instancia de RemoteControl
    unique_ptr<RemoteControl> myRemote = make_unique<RemoteControl>(10, 1, false);
    cout<<"Modificamos los valores desde el control remoto respetando las condiciones"<<endl;
    cout<<"Volumen: "<<myRemote->setVolume(50)<<endl;
    cout<<"Canal: "<<myRemote->setChannels(20)<<endl;
    cout<<"Estado del televisor: ";
    myRemote->setStatus(true);

    return 0;
}

    