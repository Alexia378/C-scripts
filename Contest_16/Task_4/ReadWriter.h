#include <iostream>
#include <fstream>
#include <string>

class ReadWriter
{
private:

    std::fstream fin;
    std::fstream fout;

public:

    ~ReadWriter()
    {
        fin.close();
        fout.close();
    }

    ReadWriter()
    {
        fin.open("input.txt", std::ios::in);
        fout.open("output.txt", std::ios::out);
    }

    // read 1 int value and empty line
    int readInt()
    {
        if (!fin.is_open())
            throw std::ios_base::failure("file not open");

        int n;
        fin >> n;
        //empty line read
        std::string s;
        std::getline(fin, s);
        return n;
    }

    //read data in arr, arr should be initialized before this method
    //n rows, m columns
    void readMatrix(char** arr, int n, int m)
    {
        if (!fin.is_open())
            throw std::ios_base::failure("file not open");
        std::string s;
        //read N rows
        //M element in each
        for (int i = 0; i < n; i++)
        {
            fin.read(arr[i], m);
            std::getline(fin, s); //read empty line
        }
    }

    //write result NxM matrix, each array represent 1 row 
    void writeMatrix(char** matrix, int n, int m)
    {
        if (!fout.is_open())
            throw std::ios_base::failure("file not open");

        //by rows
        for (int i = 0; i < n; i++)
        {
            //by elements in row
            for (int j = 0; j < m; j++)
                fout << matrix[i][j];
            //end line
            fout << std::endl;
        }
    }

    //Matrix size
    void writeInt(int a)
    {
        if (!fout.is_open())
            throw std::ios_base::failure("file not open");

        fout << a << std::endl;
    }
};