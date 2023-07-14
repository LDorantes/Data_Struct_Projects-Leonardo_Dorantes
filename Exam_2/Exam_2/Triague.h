#pragma once
#include <queue>
#include "ListE.h"
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
    List<std::string> attendedPatients;
    List<std::string> patientLevels[5];

public:
    void AddPatient(const std::string& patient_name, int urgency)
    {
        std::cout << "Adding patient: " << patient_name << ", Urgency: " << urgency << std::endl;
        patientQueue.push(Patient(patient_name, urgency));
        patientLevels[urgency - 1].PushBack(patient_name); // Agrega el nombre del paciente a la lista correspondiente
        std::cout << "Patient added successfully" << std::endl;
    }




    void PassPatient()
    {
        if (!patientQueue.empty())
        {
            Patient nextPatient = patientQueue.top();
            patientQueue.pop();
            attendedPatients.PushBack(nextPatient.name);
        }
    }

    void Print()
    {
        for (int i = 0; i < 5; i++)
        {
            std::cout << i + 1 << "-> ";

            List<std::string>& levelList = patientLevels[i];
            if (levelList.IsEmpty())
            {
                std::cout << std::endl;
                continue;
            }

            ListNode<std::string>* currentNode = levelList.begin();
            while (currentNode != nullptr)
            {
                std::cout << currentNode->data;
                if (currentNode->next != nullptr)
                {
                    std::cout << ", ";
                }
                currentNode = currentNode->next;
            }

            std::cout << std::endl;
        }
    }





};
