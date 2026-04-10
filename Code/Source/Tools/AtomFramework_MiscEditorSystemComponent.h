
#pragma once

#include <Source/AtomFramework_MiscSystemComponentBase.h>
#include <AzToolsFramework/API/ToolsApplicationAPI.h>

namespace AtomFramework
{
    class AtomFramework_MiscEditorSystemComponent
        : public AtomFramework_MiscSystemComponentBase
        , protected AzToolsFramework::EditorEvents::Bus::Handler
    {
        using BaseSystemComponent = AtomFramework_MiscSystemComponentBase;
    public:
        AZ_COMPONENT_DECL(AtomFramework_MiscEditorSystemComponent);

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        AtomFramework_MiscEditorSystemComponent();
        ~AtomFramework_MiscEditorSystemComponent();

    protected:

        void Activate() override;
        void Deactivate() override;
    };
}
