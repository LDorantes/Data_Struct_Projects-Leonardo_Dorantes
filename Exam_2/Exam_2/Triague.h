#pragma once
#include <queue>
#include "LQueue.h"
#include <string>

class Triage
{
private:
    struct Patient
    {
        std::string name;
        int urgencyLevel;

        // Constructor para facilitar la creación de pacientes
        Patient(const std::string& in_name, int in_urgencyLevel)
            : name(in_name), urgencyLevel(in_urgencyLevel)
        {
        }
    };

    struct CompareUrgency
    {
        bool operator()(const Patient& p1, const Patient& p2)
        {
            return p1.urgencyLevel > p2.urgencyLevel;
        }
    };

    std::priority_queue<Patient, std::vector<Patient>, CompareUrgency> patientQueue;
    LQueue<std::string> attendedPatients;
    LQueue<std::string> patientLevels[5];

public:
    void AddPatient(const std::string& patient_name, int urgency)
    {
        patientQueue.push(Patient(patient_name, urgency));
        patientLevels[urgency - 1].Enqueue(patient_name);
    }

    void PassPatient()
    {
        for (int i = 0; i < 5; i++)
        {
            LQueue<std::string>& levelQueue = patientLevels[i];
            if (!levelQueue.IsEmpty())
            {
                levelQueue.Dequeue();
                break;
            }
        }
    }

    void Print()
    {
        for (int i = 0; i < 5; i++)
        {
            std::cout << i + 1 << "-> ";

            LQueue<std::string>& levelQueue = patientLevels[i];
            if (levelQueue.IsEmpty())
            {
                std::cout << std::endl;
                continue;
            }

            LQueue<std::string> tempQueue = levelQueue;
            while (!tempQueue.IsEmpty())
            {
                std::cout << tempQueue.front();
                tempQueue.Dequeue();
                if (!tempQueue.IsEmpty())
                {
                    std::cout << ", ";
                }
            }

            std::cout << std::endl;
        }
    }
};
