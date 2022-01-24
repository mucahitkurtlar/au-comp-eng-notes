using System;
using System.Collections.Generic;

namespace CalisanOrnek
{
    class Program
    {
        static void Main(string[] args)
        {
            //q3
            Memur myMemur = new Memur();
            myMemur.ad = "Jamiryo";
            myMemur.derece = 42;
            myMemur.getInfo();

            Console.WriteLine();

            Muhendis myMuhendis = new Muhendis();
            myMuhendis.ad = "Antonyo";
            myMuhendis.unvan = "Cok iyi muhendis";
            myMuhendis.getInfo();


            //q4 2 1 3

            /*
            List<List<string>> myList = new List<List<string>>();
            myList.Add(new List<string> { "a", "b" });
            myList.Add(new List<string> { "c", "d", "e" });
            myList.Add(new List<string> { "qwerty", "asdf", "zxcv" });
            myList.Add(new List<string> { "a", "b" });
            */
            List<List<Calisan>> calisans = new List<List<Calisan>>();
            Calisan c_1 = new Calisan();
            //c1.ad = "c1";
            Calisan c2 = new Calisan();
            //c2.ad = "c2";
            Calisan c3 = new Calisan();
            //c3.ad = "c3";
            Calisan c4 = new Calisan();
            //c4.ad = "c4";
            Calisan c5 = new Calisan();
            //c5.ad = "c5";
            Calisan c6 = new Calisan();
            //c6.ad = "c6";
            calisans.Add(new List<Calisan> {c_1, c2});
            calisans.Add(new List<Calisan> {c3});
            calisans.Add(new List<Calisan> {c4, c5, c6});

            foreach (List<Calisan> subList in calisans)
            {
                foreach (var calisan in subList)
                {
                    Console.Write(calisan);
                }
                Console.WriteLine();
            }
 
        }
    }
}
