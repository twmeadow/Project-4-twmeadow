// Created by Tyler Meadows on 9/6/25.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#ifndef PROJECT1_readCSV_H
#define PROJECT1_readCSV_H

using std::cout, std::endl, std::vector, std::string, std::ifstream;

class csvData
{
    //Variable declaration
    private:
        string date, id;
        int steps, minutes, heartBeatRate, calories, dataEntry;

    public:
        //only one constructor with all fields initialized, because this is the only way I am going to call it
        csvData(int dataEntry, string id, string date, int steps, int calories, int minutes, int heartBeatRate)
        {
            // initializing variables
            this->dataEntry = dataEntry;
            this->id = id;
            this->date = date;
            this->steps = steps;
            this->calories = calories;
            this->minutes = minutes;
            this->heartBeatRate = heartBeatRate;
        }

        // default constructor so Queue can return a blank object
        csvData()
        {
            this->dataEntry = 0;
            this->id = "";
            this->date = "";
            this->steps = 0;
            this->calories = 0;
            this->minutes = 0;
            this->heartBeatRate = 0;
        }

        //Getters and setters
        int getDataEntry() const {return dataEntry;}
        string getId() const {return id;}
        string getDate() const { return date; }
        int getSteps() const {return steps;}
        int getMinutes() const {return minutes;}
        int getHeartBeatRate() const {return heartBeatRate;}
        int getCalories() const {return calories;}

        void setDataEntry(int dataEntry) {this->dataEntry = dataEntry;}
        void setId(string id) {this->id = id;}
        void setDate(string date) {this->date = date;}
        void setSteps(int steps) {this->steps = steps;}
        void setCalories(int calories) {this->calories = calories;}
        void setMinutes(int minutes) {this->minutes = minutes;}
        void setHeartBeatRate(int hbr) {heartBeatRate = hbr;}

        // Overloaded << operator for printing
        friend std::ostream& operator<<(std::ostream& os, const csvData& data)
        {
            os << "Data Entry: " << data.dataEntry << ", "
                << "ID:" << data.id << ", "
               << "Date:" << data.date << ", "
               << data.steps << ", "
               << data.calories << ", "
               << data.minutes << ", "
               << data.heartBeatRate;
            return os;
        }


         friend bool operator==(const csvData& data1, const csvData& data2)
        {
            return data1.dataEntry == data2.dataEntry;
        }

        friend bool operator<(const csvData& data1, const csvData& data2)
        {
            return data1.dataEntry < data2.dataEntry;
        }

        friend bool operator>(const csvData& data1, const csvData& data2)
        {
            return data1.dataEntry > data2.dataEntry;
        }

        friend bool operator>=(const csvData& data1, const csvData& data2)
        {
            return data1.dataEntry >= data2.dataEntry;
        }

        friend bool operator<=(const csvData& data1, const csvData& data2)
        {
            return data1.dataEntry <= data2.dataEntry;
        }



};


int getDataFromFile(vector<csvData>& csvDataV, const string &fileName)
{
    //open file
    ifstream fileIn;
    fileIn.open(fileName);

    if (fileIn)
    {
        //define variables for file
        string id, date, header, temp;
        int dataNum, steps, calories, minutes, heartBeatRate;
        char comma;
        int count = 0;

        //read and check header
        getline(fileIn, header);

        //loop until file is empty
        while (fileIn.peek() != EOF)
        {
            fileIn >> dataNum;        // read "Data_Entry"
            fileIn.get(comma);        // eat the comma so id lines up properly

            //read id and date into strings for simplicity
            getline(fileIn, id, ',');
            getline(fileIn, date, ',');

            // steps
            fileIn >> steps;
            if (steps == 0) { steps = -1; }
            fileIn.get(comma);

            // calories
            fileIn >> calories;
            if (calories == 0) { calories = -1; }
            fileIn.get(comma);

            // minutes
            getline(fileIn, temp, ',');
            //NOTE: the suggestion to use the following lines was form chatGPT, because my code was
            //Running exactly how I wanted, but the autograder was giving me STOI errors
            // it implemented the following lines that I will comment but that was it

            while (!temp.empty() && (temp.back() == '\r' || temp.back() == ' ')) //chatGPT
                temp.pop_back();    //chatGPT
            if (temp.empty() || temp == "Not-Given") {
                minutes = -1;
            } else {
                minutes = std::stoi(temp);
            }

            // heart beat rate (last field to end of line)
            getline(fileIn, temp);
            while (!temp.empty() && (temp.back() == '\r' || temp.back() == ' '))//chatGPT
                temp.pop_back();//chatGPT
            if (temp.empty() || temp == "Not-Given") {
                heartBeatRate = -1;
            } else {
                heartBeatRate = std::stoi(temp);
            }

            // push only if all fields are valid
            if (steps > 0 && calories > 0 && minutes > 0 && heartBeatRate > 0)
            {
                csvDataV.push_back(csvData(dataNum, id, date, steps, calories, minutes, heartBeatRate));
                count++;
            }
        }

        return count;
    }
}

double getAverageFromRow(vector<csvData>& csvDataV, string rowName)
{
    if (rowName == "steps" || rowName == "calories" || rowName == "minutes" || rowName == "heartBeatRate")
    {
        int sum = 0;
        int count = 0;
        double avg;
        for (int i = 0; i < csvDataV.size(); i++)
        {
            if (rowName == "steps") { sum += csvDataV[i].getSteps();}
            if (rowName == "calories") { sum += csvDataV[i].getCalories();}
            if (rowName == "minutes") { sum += csvDataV[i].getMinutes();}
            if (rowName == "heartBeatRate") { sum += csvDataV[i].getHeartBeatRate();}
            count++;
        }
        avg = static_cast<double>(sum) / count;
        return avg;
    } else {
        return -1.0;
    }
}

#endif //PROJECT1_readCSV_H
