using System;

namespace LogOrnek
{
    public class FileLog : LogSinif
    {
        public override void logmesaji() {
            Console.WriteLine("file log");
        }
    }
}