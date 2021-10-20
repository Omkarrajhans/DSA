#include <bits/stdc++.h>//header

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'hourglassSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

int hourglassSum(vector<vector<int>> arr) {
    int A[4],B[4],C[4],D[4],E[4],F[4],s[16];
    int mx;

    //mx is maximum sum
    
    A[0]=arr[0][0]+arr[0][1]+arr[0][2];
    A[1]=arr[0][3]+arr[0][1]+arr[0][2];
    A[2]=arr[0][3]+arr[0][4]+arr[0][2];
    A[3]=arr[0][3]+arr[0][4]+arr[0][5];
    B[0]=arr[1][0]+arr[1][1]+arr[1][2];
    B[1]=arr[1][3]+arr[1][1]+arr[1][2];
    B[2]=arr[1][3]+arr[1][4]+arr[1][2];
    B[3]=arr[1][3]+arr[1][4]+arr[1][5];
    C[0]=arr[2][0]+arr[2][1]+arr[2][2];
    C[1]=arr[2][3]+arr[2][1]+arr[2][2];
    C[2]=arr[2][3]+arr[2][4]+arr[2][2];
    C[3]=arr[2][3]+arr[2][4]+arr[2][5];
    D[0]=arr[3][0]+arr[3][1]+arr[3][2];
    D[1]=arr[3][3]+arr[3][1]+arr[3][2];
    D[2]=arr[3][3]+arr[3][4]+arr[3][2];
    D[3]=arr[3][3]+arr[3][4]+arr[3][5];
    E[0]=arr[4][0]+arr[4][1]+arr[4][2];
    E[1]=arr[4][3]+arr[4][1]+arr[4][2];
    E[2]=arr[4][3]+arr[4][4]+arr[4][2];
    E[3]=arr[4][3]+arr[4][4]+arr[4][5];
    F[0]=arr[5][0]+arr[5][1]+arr[5][2];
    F[1]=arr[5][3]+arr[5][1]+arr[5][2];
    F[2]=arr[5][3]+arr[5][4]+arr[5][2];
    F[3]=arr[5][3]+arr[5][4]+arr[5][5];
    //finding sum of all elements
    
    
    s[0]=A[0]+C[0]+arr[1][1];
    mx=s[0];//initialising mx;
    s[1]=A[1]+C[1]+arr[1][2];
    s[2]=A[2]+C[2]+arr[1][3];
    s[3]=A[3]+C[3]+arr[1][4];
    s[4]=B[0]+D[0]+arr[2][1];
    s[5]=B[1]+D[1]+arr[2][2];
    s[6]=B[2]+D[2]+arr[2][3];
    s[7]=B[3]+D[3]+arr[2][4];
    s[8]=C[0]+E[0]+arr[3][1];
    s[9]=C[1]+E[1]+arr[3][2];
    s[10]=C[2]+E[2]+arr[3][3];
    s[11]=C[3]+E[3]+arr[3][4];
    s[12]=D[0]+F[0]+arr[4][1];
    s[13]=D[1]+F[1]+arr[4][2];
    s[14]=D[2]+F[2]+arr[4][3];
    s[15]=D[3]+F[3]+arr[4][4];
    for(int i=0;i<16;i++)
    {
        if(mx<s[i])
        {
            mx=s[i];
        }
    }
    return mx;

    
    
    

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);

    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < 6; j++) {
            int arr_row_item = stoi(arr_row_temp[j]);

            arr[i][j] = arr_row_item;
        }
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
 
 
