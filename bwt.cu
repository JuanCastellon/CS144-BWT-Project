#include <iostream>
#include <string>
#include<iterator>
#include<algorithm>
#include <vector>

std::vector<std::pair<char, int>> createRankList(std::string inputStr)
{
    
    std::vector<std::pair<char, int>> rank_lst;
    int a = 0;
    int c = 0;
    int g = 0;
    int t = 0;
    int d = 0;

    for (auto& s : inputStr)
    {
        char letter;
        int pos;
        switch (s)
        {
        case '$':
            d += 1;
            letter = s;
            pos = d;
            break;

        case 'A':
            a += 1;
            letter = s;
            pos = a;
            break;

        case 'C':
            c += 1;
            letter = s;
            pos = c;

            break;

        case 'G':
            g += 1;
            letter = s;
            pos = g;

            break;

        case 'T':
            t += 1;
            letter = s;
            pos = t;

            break;
        default:
            std::cout << " no case was chosen\n";
        }
        std::pair <char, int> rankPair = std::make_pair(letter,pos);
        rank_lst.push_back(rankPair);
    }
    return rank_lst;
}


std::vector<std::pair<char, int>> createHelperList(std::string inputStr)
{
    std::vector<std::pair<char, int> > helper_lst;
    std::sort(inputStr.begin(), inputStr.end());
    std::reverse(inputStr.begin(), inputStr.end());
    int a = 0;
    int c = 0;
    int g = 0;
    int t = 0;
    int d = 0;

    for (auto& s : inputStr)
    {
        char letter;
        int pos;
        switch (s)
        {
        case '$':
            d += 1;
            letter = s;
            pos = d;
            break;

        case 'A':
            a += 1;
            letter = s;
            pos = a;
            break;

        case 'C':
            c += 1;
            letter = s;
            pos = c;

            break;

        case 'G':
            g += 1;
            letter = s;
            pos = g;

            break;

        case 'T':
            t += 1;
            letter = s;
            pos = t;

            break;
        default:
            std::cout << " no case was chosen\n";
        }
        std::pair <char, int> rankPair = std::make_pair(letter, pos);
        helper_lst.push_back(rankPair);
      
    }
    return helper_lst;
}

void computeSuffixArray(std::string input_text)
{
    std::vector< std::pair< std::string, int> > suffixArr; // list of tuple < string text_input, index>

    int index = 0;

    for (int i = 0; i < input_text.length(); i++)
    {
        std::cout << input_text << std::endl;
        std::pair <std::string, int> suffPair = std::make_pair(input_text, index);
        suffixArr.push_back(suffPair);
  
        std::rotate(input_text.rbegin(), input_text.rbegin() + 1, input_text.rend());
        index++;

    }

    for (auto& x : suffixArr)
    {
        std::cout << " (" << x.first << "[" << x.first[0] << "]" << "," << x.second << ")";
    }
    std::cout << "we did it bois before sort print " << std::endl;
    sort(suffixArr.begin(), suffixArr.end());
   

    for (auto& x : suffixArr)
    {
        std::cout << " (" << x.first << "[" << x.first[0] << "]" << "," << x.second << ")";
    }
    std::cout << "we did it bois after sort" << std::endl;

}

std::vector<std::string> rotation(std::string input_text) {
    std::vector<std::string> rotations;
    std::string first;

    for (int i = 0; i < input_text.length(); i++) {
        input_text = input_text.substr(1, input_text.length() - 1) + input_text.front();
        rotations.push_back(input_text);
    }
    std::cout << "==========" << std::endl;
    sort(rotations.begin(), rotations.end());
 
    for (auto const& i : rotations) {
        std::cout << i << std::endl;
    }
    return rotations;
}


void bwt(std::string input_text) {


    std::vector<std::string> sortedlist = rotation(input_text);
    std::vector<std::string> finalList;
    std::string first;

    std::vector<std::string>::iterator it;

    std::string finalString;
    for (auto& x : sortedlist)
    {

        finalString.push_back(x.back());

        std::cout << "this is finalString: " << finalString << std::endl;
    }
    std::cout << "==========" << std::endl;
    sort(finalList.begin(), finalList.end());

    for (auto const& i : finalList) {
        std::cout << i << std::endl;
    }

}

int main()
{
    std::string inputStr = "ACTGGCT$TGCGGC";

    std::vector<std::pair<char, int> > rank_lst = createRankList(inputStr);
    std::vector<std::pair<char, int> > helper_lst = createHelperList(inputStr);

    for (auto& x : rank_lst)
    {
        std::cout << " (" << x.first << "," << x.second << ")";
    }
    std::cout << "we did it bois " << std::endl;


    for (auto& x : helper_lst)
    {
        std::cout << " (" << x.first << "," << x.second << ")";
    }
    std::cout << "we did it bois " << std::endl;

    computeSuffixArray("banana$");




    bwt("ACTGGCT$TGCGGC");

    return 0;
}
