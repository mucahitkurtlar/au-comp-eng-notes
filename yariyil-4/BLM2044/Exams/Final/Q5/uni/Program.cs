using System;

namespace uni
{
    class Program
    {
        static void Main(string[] args)
        {
            University myUni = new University();
            myUni.createDepartment("departmattt");
            Student st = new Student("studenttt");
            myUni.departments.addStudent(st);
            Console.WriteLine(myUni.departments.student.name);
        }
    }
}
