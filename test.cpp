/* 
* @Author: anchen
* @Date:   2016-11-22 14:54:20
* @Last Modified by:   anchen
* @Last Modified time: 2016-11-22 14:56:49
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str_v[20] = {"jsjjs","jsdjsdj"};
    int size = sizeof(str_v)/sizeof(string);
    cout<< size<<endl;
    return 0;
}