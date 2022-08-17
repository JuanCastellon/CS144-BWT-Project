#include <iostream>
#include <string>
#include<iterator>
#include<algorithm>
#include <vector>
#include <fstream>
#include <chrono>

using namespace std::chrono;
std::vector<std::pair<char, int>> createRankList(std::string inputStr)
{
	std::cout << "\nstart create rank list\n";
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
    std::cout << "\nstart createhelper\n";
    std::vector<std::pair<char, int> > helper_lst;
    std::sort(inputStr.begin(), inputStr.end());
    //std::reverse(inputStr.begin(), inputStr.end());
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
   // helper_lst.push_front(helper_lst.back());
   // helper_lst.pop_back();

    return helper_lst;
}

void computeSuffixArray(std::string input_text)
{
    std::cout << "\nstart computeSuffix\n";
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

std::vector<std::string> rotation(std::string input_text) 
{
    std::cout << "\nstart rotation func\n";
    std::cout << "\n this is the original input text: " << input_text << std::endl;
    std::vector<std::string> rotations;
    std::string first;

    for (int i = 0; i < input_text.length(); i++) {
        input_text = input_text.substr(1, input_text.length() - 1) + input_text.front();
        rotations.push_back(input_text);
    }

     std::cout << "==========this is all of the rotations before sort===============" << std::endl;
 
    for (auto const& i : rotations) {
        std::cout << i << std::endl;
    }



    std::cout << "==========this is all of the rotations===============" << std::endl;
    sort(rotations.begin(), rotations.end());
 
    for (auto const& i : rotations) {
        std::cout << i << std::endl;
    }
    return rotations;
}


std::string bwt(std::string input_text) 
{
    std::cout << "\nStart bwt func\n";

    std::vector<std::string> sortedlist = rotation(input_text);
    std::vector<std::string> finalList;
    std::string first;

    std::vector<std::string>::iterator it;

    std::string finalString;
    for (auto& x : sortedlist)
    {

        finalString.push_back(x.back());

        //std::cout << "this is finalString: " << finalString << std::endl;
    }
    std::cout << "==========" << std::endl;
    sort(finalList.begin(), finalList.end());
    std::cout << "\nthis is all strings in finalList\n";
    for (auto const& i : finalList) {
        std::cout << i << std::endl;
    }
    return finalString;
}

std::string reverseBwt(std::string inputStr)
{
    std::vector<std::pair<char, int> > rank_lst = createRankList(inputStr);
    std::vector<std::pair<char, int> > helper_lst = createHelperList(inputStr);
    
    std::cout << "==========RANK LIST PRINT OUT BEGIN ++++++++==" << std::endl;
    for (auto& x : rank_lst)
    {
        std::cout << " (" << x.first << "," << x.second << ")";
    }

    std::cout << "==========HELPER LIST PRINT OUT BEGIN ++++++++==" << std::endl;
    for (auto& x : helper_lst)
    {
        std::cout << " (" << x.first << "," << x.second << ")";
    }

    std::cout << "=======lists generated. starting loop=========\n"; 

    std::cout << "this is the size of inputStr: " << inputStr.size();
    std::string originalStr;
    int index;
    for(int i = 0; i < inputStr.size(); i++)
    {
        std::pair<char, int> currPair;
        if(i == 0)
	{
            currPair = helper_lst[i];
	}
	else
	{
	    currPair = helper_lst[index];
	}

            std::cout << "this is currPair: <suffix: " << currPair.first << ", index: " << currPair.second << ">\n"; 
	    std::vector<std::pair<char,int>>::iterator it;
            it = std::find(rank_lst.begin(), rank_lst.end(), currPair);
            index = it - rank_lst.begin();
            std::cout << "this is index or the element number of the rank_lst array: " << index << std::endl;

	    originalStr += helper_lst[index].first;
	    std::cout << "this is ogString: " << originalStr << std::endl;
	
    }
    return originalStr;
}
 
int main()
{
    std::vector<std::string> textString;
    std::ifstream input_stream;

    const char* str = "hw3_test3.txt";

    input_stream.open(str, std::ios_base::in);

    if (input_stream.is_open() == true)

    std::cout << "File is opened." << std::endl;

    else

    std::cout << "File could not be open!" << std::endl;
    
    std::string line;
    while(getline(input_stream, line))
    {
	 textString.push_back(line);
    }
    std::cout << "This is the file output: \n";;
    for(int i = 0; i < textString.size(); i++ )
    {
        std::cout  << textString[i] << " ";
    }
    std::cout << "\n======================================";
    /*std::string inputStr = "ACTGGCT$TGCGGC";

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
    */

    auto start = high_resolution_clock::now();
    std::string completeStr;
    completeStr = bwt(textString.front());
    std::cout << "\nThis is the complete bwt return string: " << completeStr << std::endl;
    std::cout << "starting reverseBWT\n";
    reverseBwt(bwt(textString.front()));
	
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    std::cout << duration.count() << std::endl;
	
	
    return 0;
}
