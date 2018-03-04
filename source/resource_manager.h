#pragma once

#include <vector>
#include <string>

class Resource;

class ResourceManager
{
public:
    ResourceManager() : m_ResourceCount(0) {}
    virtual ~ResourceManager() {}
    static ResourceManager& GetInstance() { return *m_Instance; }

    Resource* GetResource(unsigned int ID);
    bool Load(std::string filename);
    void SetCurrentScope(unsigned int scope);
    const unsigned int GetResourceCount() const { return m_ResourceCount; }
protected:
    unsigned int m_ResourceCount;
    std::vector<Resource*> m_Resources;
private:
    static ResourceManager* m_Instance;
};
