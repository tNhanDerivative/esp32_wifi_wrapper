//
// Created by trongnhan on 9/10/23.
//


#include <iostream>
#include "../include/iNetwork.h"
#include "../include/Config.h"

typedef void(*callback)();

void test_callback(){
    std::cout << " test fake callback" << "\n";
}

void net_test(iNetwork& test_network, callback test_func){
    test_network.subscribe_wifi_event(NETWORK_CONNECTED,test_func);
    test_network.subscribe_wifi_event(NETWORK_DISCONNECTED,test_func);
    test_network.init_wifi();
}

int main(){
    Config config;
    iNetwork& test_network =config.get_network();
    net_test(test_network,test_callback);

    return 0;
}
