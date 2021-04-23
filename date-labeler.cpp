#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main () {
  string line;
  string UTC_time;

  // Current date/time based on current system 
  time_t now = time(0);

  // Convert now to tm struct for local timezone
  tm* localtm = localtime(&now);
  
  // Convert now to tm struct for UTC
  // Then create vector named label and append the UTC value
  // Same method to create vector for datas in txt file
  tm* gmtm = gmtime(&now); 
  UTC_time = asctime(localtm);
  std::vector<std::string> label = {};
  std::vector<std::string> x = {};
  label.push_back(UTC_time);

  // Isn't that obvious
  cout<<"Enter file path ";
  int status;
  char file[40];//
  cin>>file;

  // Append lines to array
  ifstream myfile (file);
  
  if (myfile.is_open())
  {
    while(getline(myfile, line)) 
    {
      x.push_back(line);
    }
    myfile.close();
  }
  else cout << "No such file or directory"; 
  
  // Remove existing file content
  remove(file);
  
  // Open fresh file and append the strings
  std::ofstream outfile (file);
  for (int a=0;a<label.size();a++) 
  {
	  outfile<<label[a]<<std::endl;
  }
  for (int b=0;b<x.size();b++) 
  {
	  outfile<<x[b]<<std::endl;
  }

  outfile.close();

  cout<<"Done "<<endl;
 
  return 0;
}

