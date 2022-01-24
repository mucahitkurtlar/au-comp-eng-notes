using System;

namespace LogOrnek
{
    public class LogSinif : ILog
    {
        public virtual void logmesaji() {}
        public void uyari() {
            logmesaji();
        }
    }
}