using System;
using System.Runtime.InteropServices;
//old
class DLLImportExample {
    [DllImport("kernel32.dll")]
    public static extern uint GetCurrentProcessId();
    [DllImport("user32.dll", CharSet = CharSet.Unicode, SetLastError = true)]
    public static extern int MessageBoxW( 
        nint hWhd, string tpText, 
        string lpCaption, 
        uint uTupe
        );
}
//new
partial class LibraryImportExample {
    [LibraryImport("kernel32.dll")]
    [return: MarshalAs(UnmanagedType.U4)]
    public static partial uint GetCurrentProcessId();
}
class Program {
    public static void ShowGreate(string Name)
    {
        
        int rez = DLLImportExample.MessageBoxW(
            nint.Zero,
                $"Привет {Name} добро пожаловать на курс системного программирования ",
            "Hello", 0X40 | 0x04
            );
        Console.WriteLine( rez );
        

    }
    static void Main() {
        string Name = " ";
        ShowGreate(Name);
        //int rez = DLLImportExample.MessageBoxW( 
        //    nint.Zero, 
        //    DLLImportExample.GetCurrentProcessId().ToString(), 
        //    "Process",0X40 | 0x04
        //    );
        //Console.WriteLine($"MsgBox: {rez}" );
        //Console.WriteLine("Dll Import: " + LibraryImportExample.GetCurrentProcessId());        
       
    } 
}