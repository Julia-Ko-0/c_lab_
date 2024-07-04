// for (auto grade : student.grades) {
//             if(grade==3 || grade==2){
//                 return false;
//             }
//             }
//             regularScholarshipStudents.push_back(student.name);


#include <iostream>
#include <vector>
struct Student {
char name[30];
std::vector<int> grades; //оценка
float averageGrade; //ср балл
};
int main() {
    std::vector<Student> students;
    std::vector<std::string> highScholarshipStudents; //повыш стипендия
    std::vector<std::string> regularScholarshipStudents; //об стипендия
    students.push_back({"Иванов", {5, 5, 5}, 0.0});
    students.push_back({"Петров", {4, 4, 5}, 0.0});
    students.push_back({"Сидоров", {3, 4, 5}, 0.0});
    students.push_back({"Смирнов", {4, 4, 4}, 0.0});
//ср балл каждого студента
    for (auto & student : students) {
    float sum = 0.0;
    for (auto grade : student.grades) {
        sum += grade;
    }
    student.averageGrade = sum / student.grades.size();
    }
//назначение стипендии
    for (auto student : students) {
        int a;
        a=0;
        std::cout << student.name;
        for (auto grade : student.grades) {
            std::cout << " " << grade;
        }
        std::cout << ", средний балл: "<< student.averageGrade << std::endl;
        if (student.averageGrade == 5.0) {
            highScholarshipStudents.push_back(student.name);
        } else if (student.averageGrade >= 4.0) {
            for (auto grade : student.grades) {
            if(grade== 3|| grade==2){
                a=1;
            }
            }
            if(a==0){
                regularScholarshipStudents.push_back(student.name);
            }
            
        }
    }
    std::cout << "Студенты, получающие повышенную стипендию:" << std::endl;
    for (auto student : highScholarshipStudents) {
    std::cout << student << std::endl;
    }
    std::cout << "Студенты, получающие обычную стипендию:" << std::endl;
    for (auto student : regularScholarshipStudents) {
    std::cout << student << std::endl;
    }
}