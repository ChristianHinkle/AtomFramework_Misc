
#pragma once

#include <AtomFramework_MiscTypeIds.h>

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace AtomFramework
{
    class AtomFramework_MiscRequests
    {
    public:
        AZ_RTTI(AtomFramework_MiscRequests, AtomFramework_MiscRequestsTypeId);
        virtual ~AtomFramework_MiscRequests() = default;
        // Put your public methods here
    };

    class AtomFramework_MiscBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using AtomFramework_MiscRequestBus = AZ::EBus<AtomFramework_MiscRequests, AtomFramework_MiscBusTraits>;
    using AtomFramework_MiscInterface = AZ::Interface<AtomFramework_MiscRequests>;

}
