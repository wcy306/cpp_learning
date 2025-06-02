#include <iostream>
using namespace std;

class Base
{
public:
    int pub = 1;

protected:
    int prot = 2;

private:
    int priv = 3;

public:
    void show()
    {
        cout << "pub=" << pub << ", prot=" << prot << ", priv=" << priv << endl;
    }
};

// 公有继承
class PublicDerived : public Base
{
public:
    void access()
    {
        cout << "[PublicDerived] pub=" << pub << endl;   // 可以访问
        cout << "[PublicDerived] prot=" << prot << endl; // 可以访问
        // cout << priv << endl; // 错误，不能访问
    }
};

// 保护继承
class ProtectedDerived : protected Base
{
public:
    void access()
    {
        cout << "[ProtectedDerived] pub=" << pub << endl;   // 可以访问
        cout << "[ProtectedDerived] prot=" << prot << endl; // 可以访问
        // cout << priv << endl; // 错误，不能访问
    }
};

// 私有继承
class PrivateDerived : private Base
{
public:
    void access()
    {
        cout << "[PrivateDerived] pub=" << pub << endl;   // 可以访问
        cout << "[PrivateDerived] prot=" << prot << endl; // 可以访问
        // cout << priv << endl; // 错误，不能访问
    }
};

int main()
{
    PublicDerived pubObj;
    pubObj.access();
    cout << "main() 访问 PublicDerived.pub: " << pubObj.pub << endl; // 可以访问
    // cout << pubObj.prot << endl; // 错误，不能访问

    ProtectedDerived protObj;
    protObj.access();
    // cout << protObj.pub << endl; // 错误，不能访问

    PrivateDerived privObj;
    privObj.access();
    // cout << privObj.pub << endl; // 错误，不能访问

    return 0;
}