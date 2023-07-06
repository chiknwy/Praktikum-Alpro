#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Structure to store student data
struct Student
{
    char student_id[MAX_LENGTH];
    char name[MAX_LENGTH];
    float grade;
};

void addStudent(struct Student students[], int *count)
{
    struct Student newStudent;

    printf("Enter Student ID: ");
    fgets(newStudent.student_id, sizeof(newStudent.student_id), stdin);
    newStudent.student_id[strcspn(newStudent.student_id, "\n")] = '\0'; // Remove newline character

    printf("Enter Name: ");
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0'; // Remove newline character

    printf("Enter Grade: ");
    scanf("%f", &newStudent.grade);
    getchar(); // Consume the newline character after scanf

    // Add the new student to the array
    students[*count] = newStudent;
    (*count)++;
}

void editStudent(struct Student students[], int count)
{
    char searchID[MAX_LENGTH];
    printf("Enter the Student ID to edit: ");
    fgets(searchID, sizeof(searchID), stdin);
    searchID[strcspn(searchID, "\n")] = '\0'; // Remove newline character

    int foundIndex = -1;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(students[i].student_id, searchID) == 0)
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1)
    {
        printf("Student not found.\n");
    }
    else
    {
        printf("Enter new Student ID: ");
        fgets(students[foundIndex].student_id, sizeof(students[foundIndex].student_id), stdin);
        students[foundIndex].student_id[strcspn(students[foundIndex].student_id, "\n")] = '\0'; // Remove newline character

        printf("Enter new Name: ");
        fgets(students[foundIndex].name, sizeof(students[foundIndex].name), stdin);
        students[foundIndex].name[strcspn(students[foundIndex].name, "\n")] = '\0'; // Remove newline character

        printf("Enter new Grade: ");
        scanf("%f", &students[foundIndex].grade);
        getchar(); // Consume the newline character after scanf

        printf("Student data updated successfully.\n");
    }
}

void deleteStudent(struct Student students[], int *count)
{
    char searchID[MAX_LENGTH];
    printf("Enter the Student ID to delete: ");
    fgets(searchID, sizeof(searchID), stdin);
    searchID[strcspn(searchID, "\n")] = '\0'; // Remove newline character

    int foundIndex = -1;
    for (int i = 0; i < *count; i++)
    {
        if (strcmp(students[i].student_id, searchID) == 0)
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1)
    {
        printf("Student not found.\n");
    }
    else
    {
        // Shift the remaining elements to overwrite the deleted student
        for (int i = foundIndex; i < *count - 1; i++)
        {
            students[i] = students[i + 1];
        }

        (*count)--;
        printf("Student data deleted successfully.\n");
    }
}

void searchStudent(struct Student students[], int count)
{
    char keyword[MAX_LENGTH];
    int found = 0;

    printf("Enter the student name or ID to search: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0'; // Remove newline character

    printf("\nSearch Results:\n");

    for (int i = 0; i < count; i++)
    {
        if (strcmp(students[i].name, keyword) == 0 || strcmp(students[i].student_id, keyword) == 0)
        {
            printf("Student ID: %s, Name: %s, Grade: %.2f\n",
                   students[i].student_id, students[i].name, students[i].grade);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No matching student found.\n");
    }
}

void saveDataToCSV(struct Student students[], int count)
{
    FILE *file = fopen("data.csv", "w");
    if (file == NULL)
    {
        printf("Failed to open file.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%s;%s;%.2f\n", students[i].student_id, students[i].name, students[i].grade);
    }

    fclose(file);

    printf("Data saved to data.csv\n");
}

void printStudents(struct Student students[], int count)
{
    printf("\nStudents Data:\n");
    for (int i = 0; i < count; i++)
    {
        printf("Student ID: %s, Name: %s, Grade: %.2f\n",
               students[i].student_id, students[i].name, students[i].grade);
    }
}

void sortId(struct Student *students[], int count)
{
    for (int step = 0; step < count - 1; ++step)
    {
        for (int i = 0; i < count - step - 1; ++i)
        {
            if (strcmp(students[i]->student_id, students[i + 1]->student_id) > 0)
            {
                struct Student *temp = students[i];
                students[i] = students[i + 1];
                students[i + 1] = temp;
            }
        }
    }
}

void sortGrade(struct Student *students[], int count)
{
    for (int step = 0; step < count - 1; ++step)
    {
        for (int i = 0; i < count - step - 1; ++i)
        {
            if (students[i]->grade < students[i + 1]->grade)
            {
                struct Student *temp = students[i];
                students[i] = students[i + 1];
                students[i + 1] = temp;
            }
        }
    }
}



int main()
{
    FILE *file;
    char line[MAX_LENGTH];
    struct Student students[MAX_LENGTH];
    struct Student *sortedStudentsById[MAX_LENGTH];
    struct Student *sortedStudentsByGrade[MAX_LENGTH];
    int count = 0;
    int option = 0;

    file = fopen("data.csv", "r");
    if (file == NULL)
    {
        printf("Failed to open file.\n");
        return 1;
    }
	
    while (fgets(line, sizeof(line), file))
    {
        char *token = strtok(line, ";");
        int i = 0;
        struct Student student;

        while (token != NULL)
        {
            if (i == 0)
            {
                strcpy(student.student_id, token);
            }
            else if (i == 1)
            {
                strcpy(student.name, token);
            }
            else if (i == 2)
            {
                student.grade = atof(token);
            }

            token = strtok(NULL, ";");
            i++;
        }

        students[count] = student;
        sortedStudentsById[count] = &students[count];
        sortedStudentsByGrade[count] = &students[count];
        count++;
    }

    fclose(file);

    sortId(sortedStudentsById, count);

    printf("\nInitial Students Data (Sorted by student_id):\n");
    for (int i = 0; i < count; i++)
    {
        printf("Student ID: %s, Name: %s, Grade: %.2f\n",
               sortedStudentsById[i]->student_id, sortedStudentsById[i]->name, sortedStudentsById[i]->grade);
    }

    while (option != 7)
    {
        printf("\nOptions:\n");
        printf("1. Add a new student\n");
        printf("2. Edit student data\n");
        printf("3. Delete student data\n");
        printf("4. Search Student\n");
        printf("5. Display Student (Sorted by student_id)\n");
        printf("6. Display Student (Sorted by grade)\n");
        printf("7. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        getchar();

        switch (option)
        {
        case 1:
            addStudent(students, &count);
            sortedStudentsById[count - 1] = &students[count - 1];
            sortedStudentsByGrade[count - 1] = &students[count - 1];
            sortId(sortedStudentsById, count);
            sortGrade(sortedStudentsByGrade, count);
            saveDataToCSV(students, count);
            break;
        case 2:
            editStudent(students, count);
            sortId(sortedStudentsById, count);
            sortGrade(sortedStudentsByGrade, count);
            saveDataToCSV(students, count);
            break;
        case 3:
            deleteStudent(students, &count);
            sortId(sortedStudentsById, count);
            sortGrade(sortedStudentsByGrade, count);
            saveDataToCSV(students, count);
            break;
        case 4:
            searchStudent(students, count);
            break;
        case 5:
            printf("\nStudents Data (Sorted by student_id):\n");
            for (int i = 0; i < count; i++)
            {
                printf("Student ID: %s, Name: %s, Grade: %.2f\n",
                    sortedStudentsById[i]->student_id, sortedStudentsById[i]->name, sortedStudentsById[i]->grade);
            }
            break;
        case 6:
            sortGrade(sortedStudentsByGrade, count);
            printf("\nStudents Data (Sorted by grade):\n");
            for (int i = 0; i < count; i++)
            {
                printf("Student ID: %s, Name: %s, Grade: %.2f\n",
                    sortedStudentsByGrade[i]->student_id, sortedStudentsByGrade[i]->name, sortedStudentsByGrade[i]->grade);
        }
        break;

        case 7:
            saveDataToCSV(students, count);
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid option. Please try again.\n");
            break;
        }
    }

    return 0;
}