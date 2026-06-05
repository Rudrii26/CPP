//5.1_25CS027
#include<iostream>
using namespace std;

int main(){
    string paragraph;
    string words[100];
    int count[100]={0};
    int wordCount=0;
    string currentWord;

    cout<<"Enter a paragraph: ";
    getline(cin, paragraph);

    string word="";
    for(int i=0; i<paragraph.length(); i++){
        char c = paragraph[i];
        if(isalnum(c)){
            currentWord += c;
        }
        
        else{
            bool found = false;

            for(int i=0; i<wordCount; i++){
                if(words[i] == currentWord){
                    count[i]++;
                    found = true;
                    break;
                }
    
            }
            if(!found && wordCount<100){
                words[wordCount] = currentWord;
                count[wordCount] = 1;
                wordCount++;
            }
            currentWord = "";
        }
    }
    for(int i=0; i<wordCount; i++){
        cout<<words[i]<<" : "<<count[i]<<endl;
    }
    return 0;
}