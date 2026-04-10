
#pragma once

namespace AtomFramework
{
    // System Component TypeIds
    inline constexpr const char* AtomFramework_MiscSystemComponentBaseTypeId = "{3F9BC9ED-FB11-4754-9BA0-BD4CE32D9D6A}";
    inline constexpr const char* AtomFramework_MiscSystemComponentTypeId = "{C3DD024E-66EF-4557-9F10-20CC6A6FE5E5}";
    inline constexpr const char* AtomFramework_MiscEditorSystemComponentTypeId = "{E9BD184F-1CDC-44CC-8862-14DC72247AF0}";

    // Module derived classes TypeIds
    inline constexpr const char* AtomFramework_MiscModuleInterfaceTypeId = "{3F7C695C-C06C-427B-A312-103503AECA70}";
    inline constexpr const char* AtomFramework_MiscModuleTypeId = "{941535F2-A3E1-4B59-9923-086A1D8D962C}";
    // The Editor Module by default is mutually exclusive with the Client Module
    // so they use the Same TypeId
    inline constexpr const char* AtomFramework_MiscEditorModuleTypeId = AtomFramework_MiscModuleTypeId;

    // Interface TypeIds
    inline constexpr const char* AtomFramework_MiscRequestsTypeId = "{B74C9EAB-21CB-4999-A133-BBD7C7C15894}";
}
