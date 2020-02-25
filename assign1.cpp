#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char* argv[])  {
//Defining all the variables needed
  ofstream file_;
  double sum = 0.00;
  double numA = 0.00;
  double numC = 0.00;
  double numG = 0.00;
  double numT = 0.00;

  double numAA = 0.00;
  double numAT = 0.00;
  double numAG = 0.00;
  double numAC = 0.00;

  double numCA = 0.00;
  double numCT = 0.00;
  double numCC = 0.00;
  double numCG = 0.00;

  double numTA = 0.00;
  double numTC = 0.00;
  double numTT = 0.00;
  double numTG = 0.00;

  double numGA = 0.00;
  double numGG = 0.00;
  double numGC = 0.00;
  double numGT = 0.00;

  double relativePropA = 0.00;
  double relativePropG = 0.00;
  double relativePropC = 0.00;
  double relativePropT = 0.00;

  double relativePropAA = 0.00;
  double relativePropAT = 0.00;
  double relativePropAG = 0.00;
  double relativePropAC = 0.00;

  double relativePropGA = 0.00;
  double relativePropGT = 0.00;
  double relativePropGG = 0.00;
  double relativePropGC = 0.00;

  double relativePropCA = 0.00;
  double relativePropCT = 0.00;
  double relativePropCG = 0.00;
  double relativePropCC = 0.00;

  double relativePropTA = 0.00;
  double relativePropTT = 0.00;
  double relativePropTC = 0.00;
  double relativePropTG = 0.00;

  double count = 0.00;
  string line = "";
  string lines = "";
  double variance;
  double std;
  double mean;
  double a;
  double b;
  double c;



//This if statement will take the name of the file as a command line argument.
  if (argc > 1){
    cout <<"\nYour file name is " <<argv[1] <<"\n"<<endl;
  }
  else{
    cout <<"No file name entered. ";
    return -1;
  }
   //Clear all files needed (if the files have previous data)
  std::ofstream ofs;
  ofs.open("myFile.txt", std::ofstream::out | std::ofstream::trunc);
  ofs.close();
  ofs.open("myFile2.txt", std::ofstream::out | std::ofstream::trunc);
  ofs.close();
  ofs.open("alrusayes.out", std::ofstream::out | std::ofstream::trunc);
  ofs.close();
  string u = "yes";


// This while loop will run as long as the string u is equal to yes. At the end of the program, the user
// will be asked if they want to process another file. If the answer is yes, then the while loop will run again.
// If the answer is no, then the u will equal to no and the while loop will not run.

while(u == "yes"){

    ifstream file(argv[1]);// opens the file that was passed through the command line

    if (file.is_open() && file.good()) { //Checks if the file is open and is good.

        char letter; //define letter
          while(getline(file, line)){ // gets every line in the file
            ++count; //counts the number of lines
            int c = line.length(); //c equals to the length of the line (how many letters in it)

            file_.open("myFile.txt", iostream::app); //opens a file called myFile
            file_<< c <<'\n'; // appends into it a length of each lines
            file_.close(); // closes the file
            c = 0; //resets integer c to zero so the length of the lines do not keep adding up

            for (char& letter : line){ //for every letter in line.
              letter = tolower(letter);//lower case them all.
            }


// This for loop will check for bigrams in the file.
// It sets i to 0 and it says as long as i is less than the length of the line, keep adding one to i.
          for(int i=0; i<line.length(); ++i) {
				          if (line[i]== 'a') { // if the letter assigned to the number i in line is "a",
				                if (line[i+1] == 'a') { // and the letter right next to it is also "a"
						            ++numAA; // add one to number of AA (numAA)
                        ++i; // Then add one to i. This is to make sur that the program does not Check more than one frame in the sequence.

// The same logic is followed to account for all possible bigrams
					}
					else if (line[i+1] == 't') {
						      ++numAT;
                  ++i;

					}
          else if (line[i+1] == 'c') {
						      ++numAC;
                  ++i;

					}
          else if (line[i+1] == 'g') {
						      ++numAG;
                  ++i;

					}
				}


				else if (line[i] == 't') {
					     if (line[i+1] == 'a') {
						           ++numTA;
                       ++i;

					}
          else if (line[i+1] == 't') {
                  ++numTT;
                  ++i;

          }
          else if (line[i+1] == 'c') {
                  ++numTC;
                  ++i;

          }
          else if (line[i+1] == 'g') {
                  ++numTG;
                  ++i;

          }
				}


        else if (line[i] == 'c') {
					     if (line[i+1] == 'a') {
						           ++numCA;
                       ++i;

					}
          else if (line[i+1] == 't') {
                  ++numCT;
                  ++i;

          }
          else if (line[i+1] == 'c') {
                  ++numCC;
                  ++i;

          }
          else if (line[i+1] == 'g') {
                  ++numCG;
                  ++i;

          }
				}


        else if (line[i] == 'g') {
               if (line[i+1] == 'a') {
                 ++numGA;
                 ++i;

          }
          else if (line[i+1] == 't') {
                  ++numGT;
                  ++i;

          }
          else if (line[i+1] == 'c') {
                  ++numGC;
                  ++i;

          }
          else if (line[i+1] == 'g') {
                  ++numGG;
                  ++i;

          }
        }
			}

      // This for loop
      for (char& letter : line){
        if (letter != '\n'){

        sum = sum + 1;

        if (letter =='a'){
          numA = numA + 1;
        }
        else if (letter == 'c'){
          numC = numC +1;
        }
        else if (letter == 'g'){
          numG = numG +1;
        }
        else if (letter == 't'){
          numT = numT +1;
        }
      }
    }
  }

  mean = sum/count;


  char num;
  ifstream myfile;
  myfile.open("myFile.txt");
  if (myfile.is_open() && myfile.good()) {
    int num;
  while(myfile >> num){

    if (num != '\n'){
        double r = pow(num - mean,2);
        file_.open("myFile2.txt", iostream::app);
        file_<< r <<'\n';
        file_.close();
        r = 0;
      }
    }
  }


  ifstream myfile2;
  myfile2.open("myFile2.txt");
  if (myfile2.is_open() && myfile2.good()) {
    float num2 = 0.00;
    float sum2 = 0.00;
  while(myfile2 >> num2){
    sum2 = sum2 + num2;
    }
    variance = sum2/count;
    std = sqrt(variance);

    relativePropA = numA/sum;
    relativePropG = numG/sum;
    relativePropC = numC/sum;
    relativePropT = numT/sum;

    relativePropAA = numAA/sum;
    relativePropAT = numAT/sum;
    relativePropAG = numAG/sum;
    relativePropAC = numAC/sum;

    relativePropGA = numGA/sum;
    relativePropGT = numGT/sum;
    relativePropGG = numGG/sum;
    relativePropGC = numGC/sum;

    relativePropCA = numCA/sum;
    relativePropCT = numCT/sum;
    relativePropCG = numCG/sum;
    relativePropCC = numCC/sum;

    relativePropTA = numTA/sum;
    relativePropTT = numTT/sum;
    relativePropTC = numTC/sum;
    relativePropTG = numTG/sum;



  }


  ofstream output;

  output.open("alrusayes.out", ios::out | ios::app);

  output<<"Ahmad Alrusayes\n"<<"2313076\n"<<"\nRelative probability of A: "
  <<relativePropA<<"\n"<<"Relative probability of C: "<<relativePropC<<"\n"
  <<"Relative probability of G: "<<relativePropG<<"\n"
  <<"Relative probability of T: "<<relativePropT<<"\n"<<"-----"<<"\n"<<"Total number of nucleotides: "<<sum<<'\n'
  <<"Mean of the length of DNA strings: "<<mean<<'\n'<<'\n'<<"The variance is: "<<variance<<'\n'
  <<"The standard deviation is: "<<std<<'\n'<<'\n'<<"-----"<<"\nRelative probability of AA: "<<relativePropAA<<"\nRelative probability of AT: "
  <<relativePropAT<<"\nRelative probability of AG: "<<relativePropAG<<"\nRelative probability of AC: "<<relativePropAC<<"\nRelative probability of CA: "
  <<relativePropCA<<"\nRelative probability of CT: "<<relativePropCT<<"\nRelative probability of CG: "<<relativePropCG<<"\nRelative probability of CC: "
  <<relativePropCC<<"\nRelative probability of TA: "<<relativePropTA<<"\nRelative probability of TT: "<<relativePropTT<<"\nRelative probability of TG: "
  <<relativePropTG<<"\nRelative probability of TC: "<<relativePropTC<<'\n'<<'\n';


  for(int i=0; i<=1000; ++i) {

		    a = rand() / (RAND_MAX + 1.0);
			  b = rand() / (RAND_MAX + 1.0);
			  c = (sqrt(-2*log(a)))*(cos(2*M_PI*b));

			  double d = (std*c) + mean;

			string newSeq = "";
			int seqLength = 0;
			double randRelativeProp;

			if (d < 0) {
				seqLength = d * -1;
			}

			else {
				seqLength = d;
			}

			while(seqLength > newSeq.length()) {

				randRelativeProp = rand() / (RAND_MAX + 1.0);

				if(randRelativeProp > 0 && randRelativeProp < relativePropA) {
					newSeq += 'A';
				}

				else if(randRelativeProp > relativePropA && randRelativeProp < (relativePropA + relativePropT)) {
					newSeq += 'T';
				}

				else if(randRelativeProp > (relativePropA + relativePropT) && randRelativeProp < (relativePropA + relativePropT + relativePropC)) {
					newSeq += 'C';
				}

				else if(randRelativeProp > (relativePropA + relativePropT + relativePropC) && randRelativeProp < (relativePropA + relativePropT + relativePropC + relativePropG)) {
					newSeq += 'G';
				}

			}

			output << newSeq << endl;
		}

		output.close();

}
 else {
        cout << "No file is found...\n";
        return 0;
    }

  cout << "Would you like to process another file? ";

  string u;

	getline(cin, u);

  for (char& l : u){
    l = tolower(l);
  }

  if(!(u == "yes" || u == "no")) {
		cout << "\nPlease type yes or no." << endl;
		getline(cin, u);
    for (char& l : u){
      l = tolower(l);
    }
	}

  if(u == "yes") {
		cout <<"\nWhat is the file name? " <<endl;
    cin>>argv[1];
    cout <<"\nYour file name is " <<argv[1] <<"\n"<<endl;
    continue;
  }

    else if(u == "no") {

		    cout << "\nThank you.\n" << endl;
		      exit(0);
	       }

    else{
      cout << "Program will exit. Please run again if you want to process another file.\n";
      return 0;
    }
  }

}
