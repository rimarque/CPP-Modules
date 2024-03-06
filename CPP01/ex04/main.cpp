#include <iostream>
#include <fstream>

std::string    replace(std::string buffer, int pos, int len, std::string rpl)
{
    std::string result;

    int i = 0;

    while(i < pos)
    {
        result += buffer[i];
        i++;
    }
    i = 0;
    while(rpl[i])
    {
        result += rpl[i];
        i++;
    }
    i = pos + len;
    while(buffer[i])
    {
        result += buffer[i];
        i++;
    }
    return(result);
}

int main(int argc, char **argv)
{
    if(argc < 4 || argc > 4)
    {
        std::cout << "replace: please insert: <filename> <word to be replaced> <word to replace>\n"; 
        return 1;
    }
    std::string find_str = argv[2];
    if(find_str.empty()){
        std::cout << "replace: please insert <word to be replaced>\n"; 
        return 1;
    }
    std::string replace_str = argv[3];
    std::ifstream myfile;
    myfile.open(argv[1]);
    if(!myfile.is_open())
    {
        std::cout << "replace: file " << argv[1] << " does not exist, try again!\n"; 
        return 1;
    }
    std::string filename = argv[1];
    std::ofstream newfile;
    newfile.open(filename.append(".replace").c_str(), std::ios::trunc);
    std::string buffer;
    while(std::getline(myfile, buffer))
    {
        std::string new_buff;
        int pos = 1;
        bool first = true;
        while(pos != -1){
            if(first){
                pos = buffer.find(find_str);
                if(pos >= 0)
                    new_buff = replace(buffer, pos, find_str.length(), replace_str);
                else
                    new_buff = buffer;
            }
            else{
                pos = new_buff.find(find_str, pos + replace_str.length());
                if(pos >= 0)
                    new_buff = replace(new_buff, pos, find_str.length(), replace_str);
            }
            first = false;
        }
        if(myfile.eof())
            newfile << new_buff;
        else
            newfile << new_buff << std::endl;
    }
}