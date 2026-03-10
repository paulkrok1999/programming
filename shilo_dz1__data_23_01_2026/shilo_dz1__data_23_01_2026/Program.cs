using System.Runtime.InteropServices;
public class ProcessApiHelper
{
    // Структура PROCESSENTRY32
    [StructLayout(LayoutKind.Sequential)]
    public struct PROCESSENTRY32
    {
        public uint dwSize;
        public uint cntUsage;
        public uint th32ProcessID;
        public IntPtr th32DefaultHeapID;
        public uint th32ModuleID;
        public uint cntThreads;
        public uint th32ParentProcessID;
        public int pcPriClassBase;
        public uint dwFlags;
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 260)]
        public string szExeFile;
    }

    [DllImport("kernel32.dll", SetLastError = true)]
    public static extern IntPtr CreateToolhelp32Snapshot(uint dwFlags, uint th32ProcessID);

    [DllImport("kernel32.dll", SetLastError = true)]
    public static extern bool Process32First(IntPtr hSnapshot, ref PROCESSENTRY32 lppe);

    [DllImport("kernel32.dll", SetLastError = true)]
    public static extern bool Process32Next(IntPtr hSnapshot, ref PROCESSENTRY32 lppe);

    [DllImport("kernel32.dll", SetLastError = true)]
    public static extern bool CloseHandle(IntPtr hObject);

    public const uint TH32CS_SNAPPROCESS = 0x00000002;

    // Пример использования
    public static void ListAllProcesses()
    {
        IntPtr hSnapshot = IntPtr.Zero;
        PROCESSENTRY32 procEntry = new PROCESSENTRY32();
        procEntry.dwSize = (uint)Marshal.SizeOf(typeof(PROCESSENTRY32));
        try
        {
            // Создаем снимок процессов
            hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

            if (hSnapshot == IntPtr.Zero)
            {
                Console.WriteLine($"Ошибка CreateToolhelp32Snapshot: {Marshal.GetLastWin32Error()}");
                return;
            }

            // Получаем первый процесс
            if (!Process32First(hSnapshot, ref procEntry))
            {
                Console.WriteLine($"Ошибка Process32First: {Marshal.GetLastWin32Error()}");
                return;
            }
            Console.WriteLine("Список процессов:");
            Console.WriteLine("PID\tИмя процесса");
            Console.WriteLine("---\t------------");

            do
            {
                Console.WriteLine($"{procEntry.th32ProcessID}\t{procEntry.szExeFile}");
            }
            while (Process32Next(hSnapshot, ref procEntry));
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Ошибка: {ex.Message}");
        }
        finally { if (hSnapshot != IntPtr.Zero) CloseHandle(hSnapshot); }
    }
}
class Program { static void Main() { ProcessApiHelper.ListAllProcesses(); } }