#include <iostream> //untuk input-output
#include <string.h> //untuk str function
#include <algorithm> //untuk reverse function

using namespace std;

string RandomMatriks(char _input[]);

int main(){
    char input[] = {'s', 'w', 'r', 'e', 't', 'n'};
    
    cout << RandomMatriks(input) << endl;
}

string RandomMatriks(char _input[]){
    int z = 0;
    char *checker;
    char temp[15];
    char randomReverse[15][15];
    char randomMatriks[15][15] = {
        {'t', 'g', 'b', 'w', 'w', 'i', 'n', 't', 'e', 'r', 'w', 's', 'e', 's', 'n'},
        {'a', 'a', 'u', 'n', 't', 't', 'm', 'm', 'h', 'f', 'o', 'o', 'd', 'n', 'b'},
        {'j', 'l', 'w', 'c', 'q', 'l', 'd', 'z', 'm', 'p', 'm', 'v', 'd', 'm', 'r'},
        {'a', 's', 'a', 'g', 'm', 'q', 'u', 'w', 'v', 'v', 'b', 's', 'o', 'h', 'i'},
        {'b', 'w', 'p', 'l', 'o', 't', 'a', 'n', 'a', 'd', 't', 'p', 'g', 'n', 'c'},
        {'r', 'e', 'w', 'n', 'g', 'o', 'd', 'j', 'c', 'p', 'n', 'a', 't', 'n', 'k'},
        {'e', 'e', 'o', 't', 'w', 'o', 's', 'b', 'q', 'h', 'a', 'r', 'r', 's', 'a'},
        {'a', 'z', 'c', 'g', 'e', 's', 'w', 'e', 'w', 'n', 'a', 'k', 'n', 'p', 'b'},
        {'d', 'i', 'n', 'n', 'e', 'r', 'q', 'o', 'd', 'l', 'w', 'd', 'c', 'a', 'r'},
        {'o', 'n', 'o', 'p', 'k', 'w', 'm', 'p', 'a', 'r', 'k', 't', 'z', 'c', 'c'},
        {'q', 'b', 'f', 'r', 'o', 'g', 'm', 'a', 'm', 'w', 'p', 'w', 'e', 'e', 'y'},
        {'l', 'q', 'z', 'q', 'n', 'n', 'm', 'r', 'z', 'j', 'j', 's', 'c', 'l', 'g'},
        {'m', 'o', 's', 'g', 'z', 'c', 'z', 'e', 't', 'd', 'b', 'o', 'o', 't', 'o'},
        {'p', 'd', 'c', 'r', 'z', 'm', 's', 'n', 'g', 'r', 'd', 'n', 'e', 'p', 'z'},
        {'o', 'h', 'n', 'k', 'z', 'w', 'a', 't', 'e', 'r', 'j', 'g', 't', 'r', 'a'},
        };
  
    for (int i = 0; i < 15; i++) // Horizontal
    {
      for (int j = 0; j < 15; j++)
      {
        temp[j] = randomMatriks[i][j];
      }
      checker = strstr(temp, _input);
      if(checker != NULL){
        return "Ada";
      }
    }

    int x = strlen(temp);
    char in[15];
    for (int i = 0; i < 15; i++) // Horizontal Reverse
    {
      for (int j = x-1; j >= 0; j--)
      {
        temp[j] = randomMatriks[i][j];
      }

      checker = strstr(temp, _input);
      if(checker != NULL){
        return "Ada";
      }
    }
  
    for (int i = 0; i < 15; i++) //Reverse Multidimensional matrix
    {
        int l = 14;
        for (int j = 0; j < 15; j++)
        {
            randomReverse[i][j] = randomMatriks[i][l];  
            l--;   
        }        
    }
  
    for (int i = 0; i < 15; i++) //Diagonal sebagian kiri-tengah ke atas-kanan
    {
        for (int j = 0; j < 15 - z; j++)
        {
            temp[j] = randomMatriks[j][j + z];
        }   

        z++;
        checker = strstr(temp, _input);
        if(checker != NULL){
            return "Ada";
        }
    }

    z = 14;

    for (int i = 0; i < 14; i++) //Diagonal sebagian kiri-bawah ke atas-tengah
    {
        for (int j = 14; j >= 0 + z; j--)
        {
            temp[j - z] = randomMatriks[j][j - z];
        }   
        
        z--;
        reverse(temp, &temp[strlen(temp)]);
        checker = strstr(temp, _input);
        if(checker != NULL){
            return "Ada";
        }
    }

    for (int i = 0; i < 15; i++) //Diagonal sebagian kanan-tengah ke atas-kanan
    {
        for (int j = 0; j < 15 - z; j++)
        {
            temp[j] = randomReverse[j][j + z];
        }   

        z++;
        checker = strstr(temp, _input);
        if(checker != NULL){
            return "Ada";
        }
    }

    z = 14;

    for (int i = 0; i < 14; i++) //Diagonal sebagian kanan-bawah ke atas-tengah
    {
        for (int j = 14; j >= 0 + z; j--)
        {
            temp[j - z] = randomReverse[j][j - z];
        }
        
        z--;
        reverse(temp, &temp[strlen(temp)]);
        checker = strstr(temp, _input);
        if(checker != NULL){
            return "Ada";
        }
    }

    return "Tidak Ada";
}
