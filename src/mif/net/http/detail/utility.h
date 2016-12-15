//-------------------------------------------------------------------
//  MetaInfo Framework (MIF)
//  https://github.com/tdv/mif
//  Created:     12.2016
//  Copyright (C) 2016 tdv
//-------------------------------------------------------------------

#ifndef __MIF_NET_HTTP_DETAIL_UTILITY_H__
#define __MIF_NET_HTTP_DETAIL_UTILITY_H__

// STD
#include <memory>

// EVENT
#include <event2/event.h>

// MIF
#include "mif/net/http/ioutput_pack.h"
#include "mif/net/http/methods.h"

namespace Mif
{
    namespace Net
    {
        namespace Http
        {
            namespace Detail
            {
                namespace Utility
                {

                    int ConvertMethodType(Method::Type type);
                    int ConvertAllowedMethods(Methods const &allowedMethods);

                    char const* GetReasonString(IOutputPack::Code code);
                    int ConvertCode(IOutputPack::Code code);

                    using EventBasePtr = std::unique_ptr<event_base, decltype(&event_base_free)>;

                    EventBasePtr CreateEventBase();

                }   // namespace Utility

            }   // namespace Detail
        }   // namespace Http
    }   // namespace Net
}   // namespace Mif

#endif // !__MIF_NET_HTTP_DETAIL_UTILITY_H__