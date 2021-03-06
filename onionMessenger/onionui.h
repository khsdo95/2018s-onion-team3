#ifndef ONIONUI_H
#define ONIONUI_H

#include "common.h"
#include "message.h"

using namespace newmsg;

namespace oniui{
    class OnionUI{
    public:
        OnionUI();
        virtual ~OnionUI();
        static void MainUI();

        static void PrintChat(WINDOW*, string, unsigned int ,unsigned int);
        static void UISendThread(WINDOW*, string,unsigned int ,unsigned int);
        static void UIRecvThread(WINDOW*, string,unsigned int ,unsigned int);

        void Init();
        void ShowLogo();
        void ShowMenu();
    private:
        Message *msg;
    };
}

#endif // ONIONUI_H
