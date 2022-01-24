using System;

namespace CalisanOrnek
{
    public class Memur : Calisan
    {
        public int derece;
        public override void getInfo()
        {
            Console.WriteLine("ad: " + ad + "\nderece: " + derece);
        }
    }
}