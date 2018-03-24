
#include "common.h"
#include "message.h"

namespace newmsg{

    Message::Message(){}

    // KEY
    Message::Message(int id, int loginStatus, string ip, string githubID, string pubkey){
        this->jason["id"] = id;
        this->jason["bullian"] = loginStatus;
        this->jason["ip"] = ip;
        this->jason["githubID"] = githubID;
        this->jason["pubkey"] = pubkey;
    }

    Message::~Message(){}

    void Message::setIP(string ip) {
        this->jason["ip"] = ip;
    }

    string Message::getIP(){
        return this->jason.at("ip").get<std::string>();
    }

    void Message::setBullian(int bullian) {
        this->jason["bullian"] = bullian;
    }

    void Message::setJason(json) {
        this->jason["id"] = jason["id"];
        this->jason["bullian"] = jason["bullian"];
        this->jason["ip"] = jason["ip"];
        this->jason["content"] = jason["content"];
    }

    void Message::SendMessage(){
        s_mutex.lock();
        qSendMsg.push(this->jason.dump());
        s_mutex.unlock();
    }

    void Message::SendKey(){
        s_mutex.lock();
        qSendMsg.push(this->jason.dump());
        s_mutex.unlock();
    }

    void Message::CheckMessage(){
        cout << this->jason.dump();
    }

    void Message::RecvMessage(){
        r_mutex.lock();
        string str(qRecvMsg.front());
        qRecvMsg.pop();
        r_mutex.unlock();
//        this->jason = json::parse(str);
//        this->id = this->jason["id"];
//        this->bullian = this->jason["bullian"];
//        this->ip = this->jason["ip"];
//        this->content = this->jason["content"];
    }

}
