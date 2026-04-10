
#pragma once

#include <Source/AtomFramework_MiscSystemComponentBase.h>

namespace AtomFramework
{
    class AtomFramework_MiscSystemComponent
        : public AtomFramework_MiscSystemComponentBase
    {
        using BaseSystemComponent = AtomFramework_MiscSystemComponentBase;
    public:
        AZ_COMPONENT_DECL(AtomFramework_MiscSystemComponent);

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        AtomFramework_MiscSystemComponent();
        ~AtomFramework_MiscSystemComponent();

    protected:

        void Activate() override;
        void Deactivate() override;
    };
}
