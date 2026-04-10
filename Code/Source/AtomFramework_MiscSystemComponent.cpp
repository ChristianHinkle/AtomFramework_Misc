
#include <Source/AtomFramework_MiscSystemComponent.h>

#include <AtomFramework_MiscTypeIds.h>
#include <AzCore/Serialization/SerializeContext.h>

namespace AtomFramework
{
    AZ_COMPONENT_IMPL(AtomFramework_MiscSystemComponent, "AtomFramework_MiscSystemComponent",
        AtomFramework_MiscSystemComponentTypeId, BaseSystemComponent);

    void AtomFramework_MiscSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<AtomFramework_MiscSystemComponent, BaseSystemComponent>()
                ->Version(0)
                ;
        }
    }

    void AtomFramework_MiscSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        BaseSystemComponent::GetProvidedServices(provided);
        provided.push_back(AZ_CRC_CE("AtomFramework_MiscService"));
    }

    void AtomFramework_MiscSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        BaseSystemComponent::GetIncompatibleServices(incompatible);
        incompatible.push_back(AZ_CRC_CE("AtomFramework_MiscService"));
    }

    void AtomFramework_MiscSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        BaseSystemComponent::GetRequiredServices(required);
    }

    void AtomFramework_MiscSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        BaseSystemComponent::GetDependentServices(dependent);
    }

    AtomFramework_MiscSystemComponent::AtomFramework_MiscSystemComponent() = default;
    AtomFramework_MiscSystemComponent::~AtomFramework_MiscSystemComponent() = default;

    void AtomFramework_MiscSystemComponent::Activate()
    {
        BaseSystemComponent::Activate();
    }

    void AtomFramework_MiscSystemComponent::Deactivate()
    {
        BaseSystemComponent::Deactivate();
    }
}
