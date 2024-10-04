#include <iostream>
#include <string>
#include <memory>

using namespace std;

//Interfaz

class IMessageSender
{
    public:
        virtual void sendMessage(const string& message) = 0;
        virtual ~IMessageSender()= default;
};

//Implementaciones

class TextMessageSender: public IMessageSender
{
    public:
        void sendMessage(const string& message)override{
            cout<<"Enviando SMS: "<<message<<endl;
        }
};

/*class EmailMessageSender
{
    public:
        void sendMessage(const string& message)override{
            cout<<"Enviando Email: "<<message<<endl;
        }
};

class InstantMessageSender
{
    public:
        void sendMessage(const string& message)override{
            cout<<"Enviando Mensaje Instantaneo: "<<message<<endl;
        }
};
*/
class MessagingApp
{
    private:
        unique_ptr<IMessageSender>sender;

    public:
        MessagingApp(unique_ptr<IMessageSender>s) : sender(move(s)){}

        void sendMessage(const string& message)
        {
            sender->sendMessage(message);
        }
};



int main()
{
    unique_ptr<IMessageSender> textSender = make_unique<TextMessageSender>();
    MessagingApp app1(move(textSender));
    app1.sendMessage("Hola, este es un mensaje de texto.");

    // Enviar un correo electrónico
    /* unique_ptr<IMessageSender> emailSender = make_unique<EmailMessageSender>();
    MessagingApp app2(move(emailSender));
    app2.sendMessage("Hola, este es un correo electrónico.");

    // Enviar un mensaje instantáneo
    unique_ptr<IMessageSender> instantMessageSender = make_unique<InstantMessageSender>();
    MessagingApp app3(move(instantMessageSender));
    app3.sendMessage("Hola, este es un mensaje instantáneo.");*/
    return 0;
}