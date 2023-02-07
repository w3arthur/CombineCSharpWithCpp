#ifdef DLL1_EXPORTS
#define DLL1_API __declspec(dllexport)
#else
#define DLL1_API __declspec(dllimport)
#endif


#include <string>

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

extern "C" DLL1_API int HelloC_hello1(IHelloC * helloC)
{
	return helloC->hello1();
}

extern "C" DLL1_API void EndHelloC(IHelloC* helloC)
{
	delete helloC;
}

extern "C" DLL1_API int HelloC_hello3()	//static
{
	return HelloC::hello3();
}


extern "C" DLL1_API const char* StringOutPut()	//static
{
	return "hello from c++ string";
}

extern "C" DLL1_API std::string StringOutPut2()	//static
{
	return "hello from c++ std::string2";
}



extern "C" DLL1_API int hello3() { return 12435346; }