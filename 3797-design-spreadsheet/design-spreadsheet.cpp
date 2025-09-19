class Spreadsheet {
    unordered_map<string, int> spreadsheet;

public:
    Spreadsheet(int rows) {}

    void setCell(string cell, int value) {
        if (spreadsheet.find(cell) != spreadsheet.end()) {
            spreadsheet[cell] = value;
        } else {
            spreadsheet.emplace(cell, value);
        }
    }

    void resetCell(string cell) {
        if (spreadsheet.find(cell) != spreadsheet.end()) {
            spreadsheet[cell] = 0;
        }
    }

    int getValue(string formula) {
        int X = 0;
        int Y = 0;

        char ch = 'a';
        int index = 0;
        while (ch != '+') {
            ch = formula[index++];
        }

        string xString = formula.substr(1, index - 2);
        string yString = formula.substr(index);

        if (xString[0] >= '0' && xString[0] <= '9') {
            X = stoi(xString);
        } else {
            if (spreadsheet.find(xString) != spreadsheet.end()) {
                X = spreadsheet[xString];
            }
        }
        if (yString[0] >= '0' && yString[0] <= '9') {
            Y = stoi(yString);
        } else {
            if (spreadsheet.find(yString) != spreadsheet.end()) {
                Y = spreadsheet[yString];
            }
        }
        return X + Y;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */