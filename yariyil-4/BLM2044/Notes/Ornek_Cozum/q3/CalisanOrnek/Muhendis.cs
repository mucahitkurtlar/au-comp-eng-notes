using System;

namespace CalisanOrnek
{
    public class Muhendis : Calisan
    {
        public string unvan;
        public override void getInfo()
        {
            Console.WriteLine("ad: {0}\nunvan: {1}", ad, unvan);
        }
    }
}