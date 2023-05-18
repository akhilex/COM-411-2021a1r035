#include<iostream>
#include<vector>
using namespace std;
//student class is created
class student{
private://private data members are declared
    string name;
    int add;
    int rollno;
    int zip;
    int sub;
    int n;
    string email;
    char sub_name[3][20];
   float max_mark[50],min_mark[50],obt_mark[50];
   float  overallMarks = 0, minMarks = 0;
   float percentage = 0;
   float total_marks = 0;
   float check = 0;


public:

		// Function to check the character is an alphabet or not
		bool isChar(char c)
		{
			return ((c >= 'a' && c <= 'z')
					|| (c >= 'A' && c <= 'Z'));
		}

		// Function to check the character is an digit or not
		bool isDigit(const char c)
		{
			return (c >= '0' && c <= '9');
		}

		// Function to check email id is valid or not
		bool is_valid(string email)
			{
			// Check the first character is an alphabet or not
			if (!isChar(email[0])) {

				// If it's not an alphabet email id is not valid
				return 0;
			}
			// Variable to store position of At and Dot
			int At = -1, Dot = -1;

			// Traverse over the email id string to find position of Dot and At
			for (int i = 0;
				i < email.length(); i++) {

				// If the character is '@'
				if (email[i] == '@') {

					At = i;
				}

				// If character is '.'
				else if (email[i] == '.') {

					Dot = i;
				}
			}

			// If At or Dot is not present
			if (At == -1 || Dot == -1)
				return 0;

			// If Dot is present before At
			if (At > Dot)
				return 0;

			// If Dot is present at the end
			return !(Dot >= (email.length() - 1));
		}
    void addstudent(vector<student>& students)
    {
        cout<<"Enter the number of students to get added:";
        cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter student name:";
        cin>>name;
        cout<<"\nEnter address:";
        cin>>add;
        cout<<"\nEnter student rollno:";
        cin>>rollno;
        cout<<"\nEnter zip code:";
        cin>>zip;
        while(check==0)
			{
			cout<<"Enter E-mail Id: ";
            cin>>email;
			bool ans = is_valid(email);
			if (ans) {
				cout << email << " : "
					<< "valid" << endl;
				check = 1;
			}
			else {
				cout << email << " : "
					<< "invalid! Re enter again" << endl;
				check = 0;
			}
			}

            cout << "Enter the number of subjects to get added: ";
            cin >> sub;
           for (int j = 0; j < sub; j++) {
                cout << "Enter subject " << j + 1 << " name: ";
                cin >> sub_name[j];
                cout << "Enter maximum marks for subject " << j + 1 << ": ";
                cin >> max_mark[j];
                cout << "Enter minimum marks for subject " << j + 1 << ": ";
                cin >> min_mark[j];
                cout << "Enter obtained marks for subject " << j + 1 << ": ";
                cin >> obt_mark[j];

           }
        students.push_back(*this);

    }
    }

void updatestudent(vector<student>&students)//member function for data updating using rollno
{
    int updaterollno;
    cout<<"Enter roll number of the student to be updated:";
    cin>>updaterollno;
    for(int i=0;i<students.size();i++){
        if(students[i].rollno==updaterollno){
            cout<<"Enter updated student name:";
            cin>>students[i].name;
            cout<<"Enter updated address:";
            cin>>students[i].add;
            cout<<"Enter updated rollno:";
            cin>>students[i].rollno;
            cout<<"Enter updated zip code:";
            cin>>students[i].zip;
        }
    }
}
void deletestudent(vector<student>& students)//member function which deletes the data of a specific student
{
    int deleterollno;
    cout<<"Enter roll number of the student to be deleted:";
    cin>>deleterollno;
    for(int i=0;i<students.size();i++){
        if(students[i].rollno==deleterollno){
            students.erase(students.begin()+i);
        }
    }
}
void displaystudents(vector<student>& students)
{
    cout<<"Name\t Address\t Rollno\t Zip";
    for(int i=0;i<students.size();i++){
        cout<<students[i].name<<"\t"<<students[i].add<<"\t"<<students[i].rollno<<"\t"<<students[i].zip<<endl;

    }
}
void searchstudent(vector<student>& students) //member function to search details of a student
{
    int searchrollno;
    cout<<"Enter rollno of the student to be searched";
    cin>>searchrollno;
    for(int i=0;i<students.size();i++){
        if(students[i].rollno==searchrollno){
            cout<<"Name: "<<students[i].name<<endl;
            cout<<"Rollno: "<<students[i].rollno<<endl;
            cout<<"Address: "<<students[i].add<<endl;
            cout<<"Zip: "<<students[i].zip<<endl;
        }
    }
}
void displayResult(vector<student>& students) {
         int RollNo;
         char choice;
         cout << "Enter roll number of the student to get the result: ";
         cin >> RollNo;
            for (int i = 0; i < students.size(); i++) {
                if (students[i].rollno == RollNo) {
                    // Calculate the total marks and percentage for the student
                    for (int j = 0; j < sub ; j++) {
                        total_marks = total_marks + obt_mark[j];
                        //overallMarks = overallMarks + max_mark[j];
                    }
					overallMarks = sub*100;
                    percentage = (total_marks / overallMarks) * 100;

                    // Display the result for the student
                    cout << "Name: " << students[i].name << endl;
                    cout << "Roll Number: " << students[i].rollno << endl;
                    cout << "Marks Obtained: " << total_marks << endl;
					cout << "Overall Marks: " << overallMarks << endl;
                    cout << "Percentage: " << percentage << "%" << endl;

                    // Break out of the loop since we've found the student
                    break;
                }
                else
                cout<<"Roll no not found";
            }

        }
};
class Course
{
    private:
     string name1;
     int cid;
     int semester;

     int n;

    public:

    void addcourse(vector<Course>& courses) {     //Member function to insert student details

    cout<<"Enter semester: ";
    cin >> semester;
    cout << "Enter the number of subjects: ";
    cin >> n;
    for (int i = 0; i <n; i++) {
        cout << "Enter name of course ";
        cin>>name1;
        cout<<"Enter course id: ";
        cin>>cid;
        courses.push_back(*this);
    }
}


    void updatecourse(vector<Course>& courses) {    //Member function to Modify student details
    cout << "Enter semester to update the details: ";
    cin >> semester;
    for (int i = 0; i < courses.size(); i++) {           //modifying the details by entering roll number
        if (courses[i].semester == semester) {
            cout << "Enter updated Course name: ";
            cin >> courses[i].name1;
            cout<<"Enter updated course id: ";
            cin>>courses[i].cid;
        }
    }
}


     void displaycourse(vector<Course>& courses)    //Member function to display all student details
        {
            cout << "Course id\t Course Credit\t Course Name\t\n";
            for (int i = 0; i < courses.size(); i++)
            {
            cout <<courses[i].cid<<"\t\t"<< courses[i].name1<<"\t\t"<< endl;
            }
        }
};

int main(){
vector<student> students;
student s;
    vector<Course> courses;   // class student object is created
    Course c;
    int choice;


do{
    cout<<"\n\t            Model institute of Engineering "<<endl;

cout<<"\n___________________________________________________"<<endl;
  cout << "1. Add student" << endl;
        cout << "2. Update student" << endl;
        cout << "3. Delete student" << endl;
        cout << "4. Display all students" << endl;
        cout << "5. Search" << endl;
        cout << "6.Display result "<<endl;
        cout << "7.Add details of course" <<endl;
        cout << "8.To Update Course details:" <<endl;
        cout << "9.To Display Course details:" <<endl;
        cout << "10.Exit"<<endl;
        cout << "\n Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                s.addstudent(students);
                break;
            case 2:
                s.updatestudent(students);
                break;
            case 3:
                s.deletestudent(students);
                break;
            case 4:
                s.displaystudents(students);
                break;
            case 5:
                s.searchstudent(students);
                break;
           case 6:
                s.displayResult(students);   //function to display result by roll no of student
                break;
            case 7:
                c.addcourse(courses);
                break;
            case 8:
                c.updatecourse(courses);
                break;
            case 9:
                c.displaycourse(courses);
                break;
            case 10:
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 10);
    return 0;
}
