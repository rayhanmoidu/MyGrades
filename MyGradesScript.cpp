#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct evaluation{

  string name;
  double grade;
  double weight;

};

void longstars() {

  cout<<"\n*******************************************\n"<<endl;

}

void shortstars() {

  cout<<"\n***********************\n"<<endl;

}

void starting_statement() {

  longstars();

  cout<<"MyGrades: Calculate your current mark in multiple classes at once"<<endl;

  longstars();

  cout<<"How to use:\n\nInput 'cc' to create a class, then enter the class name when prompted\n\nFor each evaluation you want to enter, follow this format: \nClass_Name Class_Grade Class_Weight (3 space separated inputs)\nExample: Midterm 90 35\nThis would denote a midterm worth 35% on which a 90% was obtained\nEnter as many evaluations as desired \nInput 'Done' when finished\n\nYou can continue creating classes upon finishing one\nEnter 'Exit' when finished last class to view all final marks"<<endl;

  longstars();

}

int main() {

  starting_statement();

  cout<<"Input 'cc' to create a class: ";

  string input;
  cin>>input;

  vector<string> class_names;
  vector<double> finalgrades;

  while(1) {

    if(input=="cc") {

      shortstars();

      cout<<"Enter the name of the class: ";
      string classname;
      cin>>classname;
      class_names.push_back(classname);
      //cout<<class_names[0]<<endl;

      vector<evaluation> evaluations;
      int i = 0;
      int evalslength = 0;

      while(true) {

        cout<<"\nEnter evaluation #"<<i+1<<" (or 'Done' if you are done with "<<classname<<"): "<<endl;

        evaluations.push_back(evaluation());

        string evaluation_name;
        double egrade;
        double eweight;

        cin>>evaluation_name;
        if(evaluation_name=="Done" || evaluation_name=="done") {evalslength = evaluations.size(); break;}
        cin>>egrade>>eweight;

        evaluations[i].name = evaluation_name;
        evaluations[i].grade = egrade;
        evaluations[i].weight = eweight;

        i++;

      }

      double finalgrade = 0;
      double weightthusfar = 0;

      for(int i = 0; i<evalslength; i++) {

        finalgrade += (evaluations[i].weight/100)*evaluations[i].grade;
        weightthusfar += (evaluations[i].weight)/100;

      }

      finalgrade/=weightthusfar;
      finalgrades.push_back(finalgrade);

    }

    shortstars();
    cout<<"Input 'cc' to create another class, or 'Exit' to view grades: ";
    cin>>input;

    if(input=="Exit" || input=="exit") {break;}

  }

  longstars();
  cout<<"Course Marks Thus Far: \n"<<endl;

  for(int i = 0; i<class_names.size(); i++) {

    cout<<class_names[i]<<": "<<finalgrades[i]<<endl;

  }

  longstars();

  cout<<"Thank you for using MyGrades!"<<endl;



}
