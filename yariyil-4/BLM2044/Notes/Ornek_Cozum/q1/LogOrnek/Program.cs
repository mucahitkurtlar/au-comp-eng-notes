using System;
using System.Collections.Generic;

namespace LogOrnek
{
    class Program
    {
        static void Main(string[] args)
        {
            LogSinif myLog = new FileLog();
            myLog.uyari();

            LogSinif email = new EmailLog();
            LogSinif sms = new SMSLog();
            LogSinif file = new FileLog();

            var logs = new List<LogSinif>();
            logs.Add(email);
            logs.Add(sms);
            logs.Add(file);
            foreach (var log in logs)
            {
                Console.WriteLine(log);
            }

        }
    }
}
