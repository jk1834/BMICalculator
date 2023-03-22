#include <iostream>
#include <string>
#include <typeinfo>
#include <limits>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::invalid_argument;


float inchToCenti(int num)

{
    if(num < 1 || num > 500)
    {
        throw invalid_argument("inchtoCenti arguments must be in the range of [1,500].\n");
    }
    return (num * 0.025);
}

float lbToKg(int num)
{
    if(num < 5 || num > 1000)
    {
        throw invalid_argument("lbToKg arguments must be in the range of [5,1000].\n");
    }
    return (num * 0.45);
}

float BMICalc(float h, float w)
{
    if((h < 0.025 || h > 12.5) || (w < 2.25 || w > 450.0))
    {
        throw invalid_argument("BMICalc arguments must be in the range of [0.025, 12.5] for h and [2.25, 450.0] for w.\n");
    }
    return (w/(h * h));
}

void introText()
{
    cout << "=======================================" << endl;
    cout << "|   Welcome to the BMI Calculator!    |" << endl;
    cout << "=======================================" << endl << endl;

    cout << "---------------------------------------" << endl;
    cout << "|             Instructions            |" << endl;
    cout << "---------------------------------------" << endl << endl;

    cout << "Enter a weight (lbs) and height (in)\nin whole numbers in the range of [5,1000] and [1,500] respectively." << endl << endl;
    cout << "For example, entering a weight of 125 lbs\nand a height of 63 in yields a BMI of 22.7!" << endl;
    cout << "Alongside the number, you will also be\nshown what category your BMI falls under, ranging\nfrom Underweight, Normal Weight, Overweight, and Obese." << endl << endl;

    cout << "---------------------------------------" << endl;
    cout << "|           What is my BMI?           |" << endl;
    cout << "---------------------------------------" << endl << endl;

}

void BMIResults(float bmi)
{
    if(bmi < 18.5 ) {cout << "You're underweight." << endl;}
    if(bmi >= 18.5 && bmi < 25) {cout << "You have a normal weight." << endl;}
    if(bmi >= 25 && bmi < 30) {cout << "You're overweight." << endl;}
    if(bmi >= 30) {cout << "You're obese." << endl;}   
}

void inputReader()
{
    int val[2] = {0,0};
    float m_height;
    float m_weight;
    float bmi;

    while(1)
    {
        cout << "First enter your weight in pounds (lbs).\nRound to the nearest whole number." << endl;
        cin >> val[0];
        if(cin.fail())
        {
            cout << "Please enter an integer value." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        cout << "Next, enter your height in inches (in).\nRound to the nearest whole number." << endl;
        cin >> val[1];
        if(cin.fail())
        {
            cout << "Please enter an integer value." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        else
        {
            m_height = inchToCenti(val[1]);
            m_weight = lbToKg(val[0]);

            bmi = BMICalc(m_height, m_weight);

            cout << "Your BMI is " << bmi << "!" << endl;
            BMIResults(bmi);
            continue;
        }
    }
    
}

int main(int argc, char* argv[])
{
    introText();
    inputReader();
    while(1) {continue;}
    return 0;
}

