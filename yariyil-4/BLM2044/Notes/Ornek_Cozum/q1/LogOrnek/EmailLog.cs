using System;

namespace LogOrnek
{
    public class EmailLog : LogSinif
    {
        public override void logmesaji() {
            Console.WriteLine("email log");
        }
    }
}