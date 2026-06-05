//8.4_25CS027
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string filename;
    ifstream file;

    while (true) {
        cout << "Enter file path (or type exit): ";
        cin >> filename;

        if (filename == "exit") {
            return 0;
        }

        file.open(filename);

        if (file.is_open()) {
            break;
        } else {
            cout << "Error opening file\n";
        }
    }

    string line;
    int validLines = 0, invalidLines = 0;

    while (getline(file, line)) {
        stringstream ss(line);
        int num;
        int sum = 0, count = 0;
        bool valid = true;

        while (ss >> num) {
            sum += num;
            count++;
        }

        if (!ss.eof()) {
            valid = false;
        }

        if (!valid || count == 0) {
            cout << "Invalid line: " << line << endl;
            invalidLines++;
            continue;
        }

        double avg = (double)sum / count;
        cout << "Sum: " << sum << " Avg: " << avg << endl;
        validLines++;
    }

    cout << "Valid lines: " << validLines << endl;
    cout << "Invalid lines: " << invalidLines << endl;

    file.close();
    return 0;
}