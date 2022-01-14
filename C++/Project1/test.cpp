    #include <iostream>
    #include <vector>
    #include <exception>
    #include <stdexcept>

    using namespace std;

    int main()
    {
        string testNum = "12345678";
        int shrtNum;
        int i =0;
        while(i<4)
        {
            shrtNum = shrtNum + testNum[i];
            cout << shrtNum << endl;
            i +=1; 
        }
        cout << shrtNum;
        return 0;
    }

