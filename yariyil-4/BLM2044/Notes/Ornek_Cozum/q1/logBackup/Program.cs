using System;

namespace LogOrnek
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            FileLog myFileog = new FileLog();
            myFileog.uyari();
        }
    }
}
