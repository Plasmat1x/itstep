#include <iostream>

int main1(int argc,char* ragv[])
{
    // Task 5
    std::cout << "\n"
    <<"\"Hello, World!\"\n/Bjarne Stroustrup/" << std::endl; // single string comment

    // Task 6
    std::cout << "\n\n"
    << "Hello, World!" << std::endl 
    << "\\Dennis Ritchi\\" << std::endl;
    /*
        multiple string comment
    */

    // Task 7
    /*
    откуда я это взял?
    -----------------------------------------------------------
    std::cout << "To be, or not to be: that is the question:\n
    Whether \'tis nobler in the mind to suffer\n
    The slings and arrows of outrageous fortune,\n
    Or to take arms against a sea of troubles.\n
    And by opposing end them?\n
    William Shakespeare" << std::endl;
    -----------------------------------------------------------
    */

    std::cout   << "\n\n"
                << "To be, or not to be: that is the question:"     << std::endl
                << "Whether \'tis nobler in the mind to suffer"     << std::endl
                << "The slings and arrows of outrageous fortune,"   << std::endl
                << "Or to take arms against a sea of troubles."     << std::endl
                << "And by opposing end them?"                      << std::endl
                << "William Shakespeare"                            << std::endl;

    std::cout << "\n" << std::endl;

    return 0;
}