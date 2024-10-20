#include <iostream>
#include <string>

//var0 is the number of arguments, and var1 is a list of the commnad line arguments 
//i like arg since argument count
// and argument varible argv var1 = argv

int sum(std::string& str) {
    int sum = 0;
    for (char ch :str) {
        sum += static_cast<int>(ch);
    }
    return sum;   
}
bool checkCondition(int course_name_length, char letter1, std::size_t program_size, int numbers) { // should have 4 agruments 
    return ((course_name_length ^ letter1 * 3) << (program_size & 0x1f) == numbers);
}

int main(int argc, char *argv[]) {
 
  if (argc == 3) { // checks if so that the number of command-line arguments are 3  
    std::string program{argv[0]};  //var2 is the program name now called main 
    auto letter1{*(argv[1])}; //first  character in MNB11
    auto program_size{program.size()}; //size of the program name main
    
    auto numbers{std::atoi(argv[2])};//converts the numbers to integers var5=numbers
    auto course_name_length{0};
    //auto var7{0};
    std::string course_name{argv[1]}; // stores MNXB11 as a string 

    course_name_length = sum(course_name);
    
   

    if (checkCondition(course_name_length, letter1, program_size, numbers)){
        std::cout <<"Correct!" << std::endl;
    } else {
        std::cout << "Wrong!" << std::endl;
    }
    
  }
  return 0;
}





