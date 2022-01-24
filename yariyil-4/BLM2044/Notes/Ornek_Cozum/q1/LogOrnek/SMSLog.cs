using System;

namespace LogOrnek
{
    public class SMSLog : LogSinif
    {
        public override void logmesaji() {
            Console.WriteLine("sms log");
        }
    }
}