#ifdef DLL1_EXPORTS
#define DLL1_API __declspec(dllexport)
#else
#define DLL1_API __declspec(dllimport)
#endif


#pragma once

class IHelloC
{
public:
	virtual ~IHelloC() =default;
	virtual int hello1() = 0;
};

class HelloC : public IHelloC
{
public:
	int hello1() { return 5646544; }
	static int hello3() { return 3436436; }
};



extern "C" DLL1_API IHelloC * createHelloC()
{
	return new HelloC();
}

extern "C" DLL1_API int hello3() { return 12435346; }