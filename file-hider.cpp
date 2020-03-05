#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;
bool corect = false;
bool hidden = true;
int trys (10);

void lesupersecretalgorithm(string input){
unsigned int b;
unsigned int hashd(/*this is the hash of your password*/);
for (int i = 0; i < input.length(); i++)
    {
        int a;
        char x = input.at(i);
        a = int(x);
        b += (a*(i*i));
    }
    if(b==hashd){corect=true;}
    /*in order to come up with your passhash, just comment out the above line, and uncomment the line below*/
    /*cout<<"b";*/
}



void unlock(string File){
    streampos size;
    fstream rfile (File, ios::out|ios::in|ios::binary|ios::ate);
    if(rfile.is_open()){
        size = rfile.tellg();
        if((size/1e+9) > 1){cout<<"overflow: file size too large; please keep the filesize under 1 gigabyte\n";}
        else{
        char * data = new char[size];
        rfile.seekg(0);
        rfile.read(data, size);
        //beggining of encoding
        for(int i=0; i<size; i++){
        data[i]-=1204954036940594054;
        }
        //end of encoding
        rfile.seekp(0);
        rfile.write(data, size);
        delete[] data;
        rfile.close();
        cout<<"successful unlock"<<endl;
        }
        }
    else{cout<<"fatal error: try re-typing the file name, and make sure it is in the corect directory.\n";}

}

void add(string File){
    streampos size;
    fstream file (File, ios::out|ios::in|ios::binary|ios::ate);
    if(file.is_open()){
        size = file.tellg();
        if((size/1e+9) > 1){cout<<"overflow: file size too large; please keep the filesize under 1 gigabyte\n";}
        else{
        char * data = new char[size];
        file.seekg(0);
        file.read(data, size);
        //beggining of encoding
        for(int i=0; i<size; i++){
        data[i]+=1204954036940594054;
        }
        //end of encoding

        file.seekp(0);
        file.write(data, size);
        delete[] data;
        file.close();
        cout<<"successful lock"<<endl;
        }
        }
    else{cout<<"fatal error: try re-typing the file name, and make sure it is in the corect directory.\n";}
}
void Acess(){
string operation;
while(true){
cout<<"welcome! what would you like to do?\n read: press a \n write: press b\n press q to exit\n :";
getline(cin, operation);

if(operation == "a"){
    string fileName;
    cout<<"type the filename in.\n";
    getline(cin, fileName);
    unlock(fileName);}


else if(operation == "b"){
    string fileName;
    cout<<"add your file now to the folder, and then type the filename in.\n";
    getline(cin, fileName);
    add(fileName);
}
else{cout<<"locking up and exiting...\n";
cout<<"done!\n";
break;
}


}
}
void password(){
    string password;
    cout<<"welcome to the file vault! \n What is the password?\n";
    getline(cin, password);
    if(password.length() >= 16){cout<<"thats a bit too long! try to keep it under 16 characters :) \n";}
    else{lesupersecretalgorithm(password);}
    if(corect){cout<<"Acces Granted!\n";hidden = false;}
    else{trys -= 1;}
}
int main(){
while(trys >= 0 && hidden){password();}
if(hidden){cout<<"woah there! either you're very bad at typing, or you're trying to bruteforce me! :( \n Thats not very nice, so consider your data deleted!\n";}
if(!(hidden)){Acess();}
return 0;
}
