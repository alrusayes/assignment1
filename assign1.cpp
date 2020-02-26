#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char* argv[])  {
//Declaring all the variables needed
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

  double relativeProbA = 0.00;
  double relativeProbG = 0.00;
  double relativeProbC = 0.00;
  double relativeProbT = 0.00;

  double relativeProbAA = 0.00;
  double relativeProbAT = 0.00;
  double relativeProbAG = 0.00;
  double relativeProbAC = 0.00;

  double relativeProbGA = 0.00;
  double relativeProbGT = 0.00;
  double relativeProbGG = 0.00;
  double relativeProbGC = 0.00;

  double relativeProbCA = 0.00;
  double relativeProbCT = 0.00;
  double relativeProbCG = 0.00;
  double relativeProbCC = 0.00;

  double relativeProbTA = 0.00;
  double relativeProbTT = 0.00;
  double relativeProbTC = 0.00;
  double relativeProbTG = 0.00;

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

    if (file.is_open() && file.good()) { //Checks if the file is open and is good. Else it will state that file is not found

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

      // This for loop takes every letter in each line
      // and count the total number of letters and count
      // the number of different letters (nucleotides) indiviually
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

  mean = sum/count;// This calculates the mean of the DNA strings length where sum
                  // is the total number of nucleotides and count is the number of lines



  ifstream myfile;
  myfile.open("myFile.txt"); // opening the file that has the length of each lines
  if (myfile.is_open() && myfile.good()) { // Checking if the file is open and is good
    int num;// declaring an integer called num

     // this while loop is saying as long as there is a number in the file,
    //  calculate the double r and save the result into another file called
   //   myFile2.txt.
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
  myfile2.open("myFile2.txt"); // Opening the file with the calculated r value
  if (myfile2.is_open() && myfile2.good()) { // Checking if the file is open and is good
    float num2 = 0.00; // declaring an a float called num2, which is the numbers inside myFile2
    float sum2 = 0.00; // declaring an float called sum2, which is the sum of all numbers inside myFile2

    // This while loop is to calculate sum2 or all numbers inside myFile2
   //needed to calculate variance
  while(myfile2 >> num2){
    sum2 = sum2 + num2;
    }

    variance = sum2/count;// calculate variance using the numbers obtained previously
    std = sqrt(variance); // calculate standard deviation using variance

// All calculations of relative probability of bigrams and signle nucleotides
    relativeProbA = numA/sum;
    relativeProbG = numG/sum;
    relativeProbC = numC/sum;
    relativeProbT = numT/sum;

    relativeProbAA = numAA/sum;
    relativeProbAT = numAT/sum;
    relativeProbAG = numAG/sum;
    relativeProbAC = numAC/sum;

    relativeProbGA = numGA/sum;
    relativeProbGT = numGT/sum;
    relativeProbGG = numGG/sum;
    relativeProbGC = numGC/sum;

    relativeProbCA = numCA/sum;
    relativeProbCT = numCT/sum;
    relativeProbCG = numCG/sum;
    relativeProbCC = numCC/sum;

    relativeProbTA = numTA/sum;
    relativeProbTT = numTT/sum;
    relativeProbTC = numTC/sum;
    relativeProbTG = numTG/sum;



  }

//Opening and appending all data to a file called "alrusayes".out
  ofstream output;

  output.open("alrusayes.out", ios::out | ios::app);

  output<<"Ahmad Alrusayes\n"<<"ID: 2313076\n"<<"\nRelative probability of A: "
  <<relativeProbA<<"\n"<<"Relative probability of C: "<<relativeProbC<<"\n"
  <<"Relative probability of G: "<<relativeProbG<<"\n"
  <<"Relative probability of T: "<<relativeProbT<<"\n"<<"-----"<<"\n"<<"Total number of nucleotides: "<<sum<<'\n'
  <<"Mean of the length of DNA strings: "<<mean<<'\n'<<'\n'<<"The variance is: "<<variance<<'\n'
  <<"The standard deviation is: "<<std<<'\n'<<'\n'<<"-----"<<"\nRelative probability of AA: "<<relativeProbAA<<"\nRelative probability of AT: "
  <<relativeProbAT<<"\nRelative probability of AG: "<<relativeProbAG<<"\nRelative probability of AC: "<<relativeProbAC<<"\nRelative probability of CA: "
  <<relativeProbCA<<"\nRelative probability of CT: "<<relativeProbCT<<"\nRelative probability of CG: "<<relativeProbCG<<"\nRelative probability of CC: "
  <<relativeProbCC<<"\nRelative probability of TA: "<<relativeProbTA<<"\nRelative probability of TT: "<<relativeProbTT<<"\nRelative probability of TG: "
  <<relativeProbTG<<"\nRelative probability of TC: "<<relativeProbTC<<'\n'<<'\n';

// This for loop will generate 1000 DNA strings whose lengths follow a
// Gaussian distribution with the same mean, variance, and relative
// probability as calculated above.
  for(int i=0; i<=1000; ++i) {

		    a = rand() / (RAND_MAX + 1.0); // produce a random number from 0 to 1 and assign it to the double a
			  b = rand() / (RAND_MAX + 1.0); // produce a random number from 0 to 1 and assign it to the double b
			  c = (sqrt(-2*log(a)))*(cos(2*M_PI*b)); // calculation of c, which is a standard Gaussian with mean 0 and variance 1.
                                               // Because a and b will be randomized, this will generate differnt c's as long
                                               // as i in the for loop is less than or equal to 1000.

			  double d = (std*c) + mean;// Calculate d, which is the random standard Gaussian with mean 0 and variance 1 produced above times
                                  // our standard deviation and mean. This will give us a DNA strings lengths that followe
                                  // Guassian distribution with the same mean and variance as calculated above.

			string newSeq = ""; // Setting a new string to produce a new string in it.
			int seqLength = 0; // Setting the length of the new sequence.
			double randRelativeProb;

// the d  is negative, then times it by -1 to get rid of the negative sign. Otherwise, d will equal to The length of the new sequence.
			if (d < 0) {
				seqLength = d * -1;
			}

			else {
				seqLength = d;
			}

      // This while loop will produce a new string as long as the new string produced is less than d or the length of the sequence we want.
			while(seqLength > newSeq.length()) {

				randRelativeProb = rand() / (RAND_MAX + 1.0); // Produces a random relative probability

        // if the random probability is bigger than zero and less than the relative probability of A, then add A to the sequence.
        // This is to make sure that the relative probability calculated previously and from the DNA strings produced are the same

				if(randRelativeProb > 0 && randRelativeProb < relativeProbA) {
					newSeq += 'A';
				}

        // The same logic is followed to account for all possible nucleatides and relative probability

				else if(randRelativeProb > relativeProbA && randRelativeProb < (relativeProbA + relativeProbT)) {
					newSeq += 'T';
				}

				else if(randRelativeProb > (relativeProbA + relativeProbT) && randRelativeProb < (relativeProbA + relativeProbT + relativeProbC)) {
					newSeq += 'C';
				}

				else if(randRelativeProb > (relativeProbA + relativeProbT + relativeProbC) && randRelativeProb < (relativeProbA + relativeProbT + relativeProbC + relativeProbG)) {
					newSeq += 'G';
				}

			}
// appending all data to a file called "alrusayes".out
			output << newSeq << endl;
		}
// closing the file
		output.close();

}
// This is incase if the file inputed from the comand line is not found
 else {
        cout << "No file is found...\n";
        return 0;
    }
// Asks if the user want to process another file
  cout << "Would you like to process another file? ";

  string u;

	getline(cin, u);

//lower case all the letter in the answer inputed to eliminate possible variations
  for (char& l : u){
    l = tolower(l);
  }

// if the iput is not yes or no, the program will specifically ask the user to type yes or no

  if(!(u == "yes" || u == "no")) {
		cout << "\nPlease type yes or no." << endl;
		getline(cin, u);
    for (char& l : u){
      l = tolower(l);
    }
	}

// if the answer is yes, then it will ask what is the file name and re run the program.
  if(u == "yes") {
		cout <<"\nWhat is the file name? " <<endl;
    cin>>argv[1];
    cout <<"\nYour file name is " <<argv[1] <<"\n"<<endl;
    continue;
  }
// if the answer is no then it will exit.
    else if(u == "no") {

		    cout << "\nThank you.\n" << endl;
		      exit(0);
	       }
// if the user did not type yes or no even after propmting them at the first time,
// then the program will exits.
    else{
      cout << "Program will exit. Please run again if you want to process another file.\n";
      return 0;
    }
  }

}
