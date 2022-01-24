namespace uni
{
    public class Departments
    {

        public Departments(string n)
        {
            name = n;
        }
        public string name;
        public Student student;
        public void addStudent(Student st) {
            student = st;
        }
    }
}