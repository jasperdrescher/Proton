#pragma once

#include <string>

namespace Proton
{
    typedef enum
    {
        RESOURCE_NULL = 0,
        RESOURCE_MESH = 1,
        RESOURCE_MATERIAL = 2,
        RESOURCE_TEXTURE = 3,
        RESOURCE_AUDIO = 4,
    }RESOURCE_TYPE;

    class Resource
    {
    public:
        Resource() : m_ID(0), m_Scope(0), m_Type(RESOURCE_NULL) {}
        virtual ~Resource() {}
        virtual void Load() = 0;
        virtual void Unload() = 0;

        void SetResourceID(unsigned int ID) { m_ID = ID; }
        unsigned int GetResourceID() const { return m_ID; }

        void SetFilename(std::string filename) { m_Filename = filename; }
        std::string GetFilename() const { return m_Filename; }

        void SetResourceType(RESOURCE_TYPE type) { m_Type = type; }
        RESOURCE_TYPE GetResourceType() const { return m_Type; }

        void SetResourceScope(unsigned int scope) { m_Scope = scope; }
        unsigned int GetResourceScope() const { return m_Scope; }

        bool IsLoaded() const { return m_IsLoaded; }
        void SetLoaded(bool value) { m_IsLoaded = value; }

    protected:
        unsigned int m_ID;
        unsigned int m_Scope;
        std::string m_Filename;
        RESOURCE_TYPE m_Type;
        bool m_IsLoaded;

    private:

    };
}
