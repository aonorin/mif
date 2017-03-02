//-------------------------------------------------------------------
//  MetaInfo Framework (MIF)
//  https://github.com/tdv/mif
//  Created:     09.2016
//  Copyright (C) 2016-2017 tdv
//-------------------------------------------------------------------

// STD
#include <iostream>

// MIF
#include <mif/net/http/server.h>
#include <mif/net/http/servlet.h>

// COMMON
//#include "common/client.h"
//#include "common/ps/ihello_world.h"

// THIS
//#include "common/id/service.h"

// TODO:
// {
#include "mif/net/http/web_service.h"
// }

class MyWebService
    : public Mif::Service::Inherit<Mif::Net::Http::WebService>
{
public:

    MyWebService()
    {
        AddHandler("/stat", this, &MyWebService::Stat);
    }

    std::string Stat(Prm<std::string, Name("format")> const &format)
    {
        std::cout << "OnStat" << std::endl;
        return format ? "Yes" : "No";
    }
};

int main(int argc, char const **argv)
{
    if (argc != 3)
    {
        std::cerr << "Bad params. Usage: helloworld_server <host> <port>" << std::endl;
        return -1;
    }
    try
    {
        /*auto factory = Mif::Service::Make<Mif::Service::Factory, Mif::Service::Factory>();
        factory->AddClass<Service::Id::HelloWorld>();*/

        std::cout << "Starting server on \"" << argv[1] << ":" << argv[2] << "\" ..." << std::endl;

        //std::chrono::microseconds const timeout{10 * 1000 * 1000};

        //auto clientFactory = Service::Ipc::MakeClientFactory(4, timeout, factory);

        Mif::Net::Http::Server server{argv[1], argv[2], 2, 24,
                {Mif::Net::Http::Method::Type::Get},
                {
                    //{"/", Mif::Net::Http::MakeServlet(clientFactory)}
                    {"/api", Mif::Net::Http::MakeWebService<MyWebService>()}
                }
            };
        (void)server;
        
        std::cout << "Started server. Press Enter for quit." << std::endl;
        
        std::cin.get();
        
        std::cout << "Server stopped." << std::endl;

    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}