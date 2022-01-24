namespace uni
{
    public class University
    {
        public Departments departments;
        public string name;

        public void createDepartment(string n)
        {
            departments = new Departments(n);
        }
    }
}