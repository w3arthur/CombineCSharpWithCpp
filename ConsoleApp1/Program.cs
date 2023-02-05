// See https://aka.ms/new-console-template for more information
using ClassLibrary1;
using System.Net.Security;
using System.Runtime.InteropServices;

/*public class HelloC
{
    public static  int hello3();
}
*/
public interface IHelloC
{
    public int hello1();
    public int hello3();
}


//view the guides:
// https://www.youtube.com/watch?v=o-ass4mkdiA&ab_channel=Kettlesimulator
// https://www.youtube.com/watch?v=8IWFeUkZ4bo&ab_channel=KingTut
// https://www.youtube.com/watch?v=UsnRGo4y5FQ&ab_channel=KennyGunderman
internal class Program
{
    public const string CppDll = @"Dll1.dll";
    [DllImport(CppDll, CallingConvention = CallingConvention.Cdecl)]
    public static extern int hello2();
    [DllImport(CppDll, CallingConvention = CallingConvention.Cdecl)]
    public static extern int hello3();

    [DllImport(CppDll, CallingConvention = CallingConvention.Cdecl)]
    public static extern IHelloC createHelloC();



    private static void Main(string[] args)
    {
        Console.WriteLine("Hello, World!");

        //string aaa = Hello.hello(); // C#

        int aaa = hello2(); //c++
        int bbb = hello3(); //c++


        Console.WriteLine(bbb);


        /// Use Unsafe mode 
        IHelloC helloC = createHelloC();

        Console.WriteLine("dll class value");
        Console.WriteLine(helloC.hello3());
    }
}