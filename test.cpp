/* 
* @Author: anchen
* @Date:   2016-11-22 14:54:20
* @Last Modified by:   anchen
* @Last Modified time: 2016-11-28 18:11:43
*/

#include <iostream>  
#include <fstream>  
#include <stdlib.h>  
using namespace std;

void save_text_to_file(string text)
{
    ofstream file("example.txt");
    if (file.is_open())
    {
        file << text;
        file.close();
    }
}

int main()
{
    string kk = "hi i am xxx";
    save_text_to_file(kk);
    return 0;
}