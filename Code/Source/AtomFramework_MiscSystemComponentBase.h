
#pragma once

#include <AzCore/Component/Component.h>
#include <AtomFramework_MiscBus.h>
#include <AzCore/Component/TickBus.h>
#include <AtomFramework_MiscConfiguration.h>

namespace AtomFramework
{
    class ATOMFRAMEWORK_MISC_API AtomFramework_MiscSystemComponentBase
        : public AZ::Component
        , protected AtomFramework_MiscRequestBus::Handler
        , public AZ::TickBus::Handler
    {
    public:
        AZ_COMPONENT_DECL_API(ATOMFRAMEWORK_MISC_API, AtomFramework_MiscSystemComponentBase);

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        AtomFramework_MiscSystemComponentBase();
        ~AtomFramework_MiscSystemComponentBase();

    protected:
        //! AtomFramework_MiscRequestBus::Handler overrides.
        //! @{
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        //! @}

        //! AZ::TickBus::Handler overrides.
        //! @{
        void OnTick(float deltaTime, AZ::ScriptTimePoint time) override;
        //! @}
    };
}
