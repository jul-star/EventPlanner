#pragma  once
#include  <string>
#include <map>

#include <Model/Constants.h>
#include <Model/Communication/Log.h>

using namespace std;

namespace EP {
namespace MD {

/*!
*  \brief Template Class Method
*/
template<typename T>
class TemplateMethodMap
{
public:
   typedef typename map<unsigned, T>::iterator iterator;
    // Inline
    TemplateMethodMap(){}
    virtual ~TemplateMethodMap(){}
    void AddItem(const T& inVal) { vMap.insert(make_pair(++vID,inVal));  ItemSet(vID); }
    T* Item() { return pItem; }
    const T* Item() const { return pItem; }
    unsigned Index() { return vIndex; }
    unsigned Index() const { return vIndex; }



    // Not Inline
    T* GetByID(unsigned inID);
    const T* GetByID(unsigned inID) const;

    T* ItemSet(unsigned inID);
    size_t Size() { return vMap.size(); }

     iterator begin() { return vMap.begin(); }
     iterator end() { return vMap.end(); }

protected:

    virtual void Setup(Log* inLog) = 0;


    static unsigned vID;
    map<unsigned, T> vMap;
    unsigned vIndex{0};
    T* pItem{nullptr};

private:

};

template<typename T>
unsigned TemplateMethodMap<T>::vID;

template<typename T>
T* TemplateMethodMap<T>::GetByID(unsigned inID)
{
    if( vMap.find(inID) != vMap.end())
    {
        return &vMap.at(inID);
    }
    else
    {
        return nullptr;
    }
}
template<typename T>
const T* TemplateMethodMap<T>::GetByID(unsigned inID) const
{
    if( vMap.find(inID) != vMap.end())
    {
        return &vMap.at(inID);
    }
    else
    {
        return nullptr;
    }
}

template<typename T>
T* TemplateMethodMap<T>::ItemSet(unsigned inID)
{
    if( vMap.find(inID) != vMap.end())
    {
        pItem = &vMap.at(inID);
        vIndex = inID;
        return pItem;
    }
    else
    {
        return nullptr;
    }
}

}}
