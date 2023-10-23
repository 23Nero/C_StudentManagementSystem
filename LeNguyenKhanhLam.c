#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct student
{
    char name[50];
    int student_id;
    char date_of_birth[20];
    char gender[10];
    char faculty[50];
    int year;
    float year_temp; // year of subjet
    float gpa;
    struct student *next;
} student_t;

typedef struct subject
{
    char subject_name[50];
    int subject_id;
    int subject_credit;
    int required_level_of_year;
    struct subject *next;
} subject_t;

typedef struct class
{
    int class_id;
    int subject_id;
    int max_students;
    int num_registrations;
    int num_registrations_temp;
    char open_status[2];
    struct class *next;
} class_t;

typedef struct class_and_grade
{
    int student_id;
    int subject_id;
    int class_id;
    float grade;
    struct class_and_grade *next;
} class_and_grade_t;

student_t *student_list = NULL;
subject_t *subject_list = NULL;
class_t *class_list = NULL;
class_and_grade_t *class_and_grade_list = NULL;

float removeNegativeZero(float num)
{
    if (num == 0.0 && signbit(num))
    {
        return abs(num);
    }
    else
    {
        return num;
    }
}

void print_student_list(int student_id)
{

    if (student_list == NULL)
    {
        printf("Error, student is not existed\n");
        return;
    }

    student_t *current_student = student_list;
    while (current_student != NULL)
    {
        if (current_student->student_id == student_id)
        {
            printf("%s,", current_student->name);
            printf("%d,", current_student->student_id);
            printf("%s,", current_student->date_of_birth);
            printf("%s,", current_student->gender);
            printf("%s,", current_student->faculty);
            printf("%d,", current_student->year);
            printf("%.2f\n", current_student->gpa);
            // printf("\n");

            return;
        }
        current_student = current_student->next;
    }
    printf("Error, student is not existed\n");
}

void print_student_list1()
{

    if (student_list == NULL)
    {
        printf("Error, student is not existed\n");
        return;
    }

    student_t *current_student = student_list;
    while (current_student != NULL)
    {

        printf("%s,", current_student->name);
        printf("%d,", current_student->student_id);
        printf("%s,", current_student->date_of_birth);
        printf("%s,", current_student->gender);
        printf("%s,", current_student->faculty);
        printf("%d,", current_student->year);
        printf("%.2f\n", current_student->gpa);
        // printf("\n");

        current_student = current_student->next;
    }
    printf("Error, student is not existed\n");
}

void print_student_list_to_file(const char *st)
{
    FILE *student_file = fopen(st, "w");
    if (student_file == NULL)
    {
        return;
    }

    if (student_list == NULL)
    {
        printf("Error, student is not existed\n");
        return;
    }

    fprintf(student_file, "Name,Student ID,Day of Birth,Gender,Faculty,Year,GPA\n");
    student_t *current_student = student_list;
    while (current_student != NULL)
    {
        fprintf(student_file, "%s,", current_student->name);
        fprintf(student_file, "%d,", current_student->student_id);
        fprintf(student_file, "%s,", current_student->date_of_birth);
        fprintf(student_file, "%s,", current_student->gender);
        fprintf(student_file, "%s,", current_student->faculty);
        fprintf(student_file, "%d,", current_student->year);
        fprintf(student_file, "%.2f\n", current_student->gpa);
        // printf("\n");
        current_student = current_student->next;
    }
    fclose(student_file);
}

void print_subject_list(int subject_id)
{

    if (subject_list == NULL)
    {
        printf("Error, subject is not existed\n");
        return;
    }

    subject_t *current_subject = subject_list;
    while (current_subject != NULL)
    {
        if (current_subject->subject_id == subject_id)
        {
            printf("%s,", current_subject->subject_name);
            printf("%d,", current_subject->subject_id);
            printf("%d,", current_subject->subject_credit);
            printf("%d\n", current_subject->required_level_of_year);

            return;
        }
        current_subject = current_subject->next;
    }
    printf("Error, subject is not existed\n");
}

void print_subject_list_to_file(const char *sb)
{
    FILE *subject_file = fopen(sb, "w");
    if (subject_file == NULL)
    {
        return;
    }

    if (subject_list == NULL)
    {
        printf("Error, subject is not existed\n");
        return;
    }

    fprintf(subject_file, "Name,Subject ID,Credit,Year Of Level\n");
    subject_t *current_subject = subject_list;
    while (current_subject != NULL)
    {
        fprintf(subject_file, "%s,", current_subject->subject_name);
        fprintf(subject_file, "%d,", current_subject->subject_id);
        fprintf(subject_file, "%d,", current_subject->subject_credit);
        fprintf(subject_file, "%d\n", current_subject->required_level_of_year);
        current_subject = current_subject->next;
    }

    fclose(subject_file);
}

void print_class_list(int class_id)
{

    if (class_list == NULL)
    {
        printf("Error, class is not existed\n");
        return;
    }

    class_t *current_class = class_list;
    while (current_class != NULL)
    {
        if (current_class->class_id == class_id)
        {
            printf("%d,", current_class->class_id);
            printf("%d,", current_class->subject_id);
            printf("%d,", current_class->max_students);
            printf("%d,", current_class->num_registrations);
            printf("%s\n", current_class->open_status);
            // printf("\n");
            return;
        }
        current_class = current_class->next;
    }
    printf("Error, class is not existed\n");
}

void print_class_list_to_file(const char *class)
{
    FILE *subject_student_file = fopen(class, "w");
    if (subject_student_file == NULL)
    {
        return;
    }

    if (class_list == NULL)
    {
        printf("Error, class is not existed\n");
        return;
    }

    fprintf(subject_student_file, "Class ID,Subject ID,Max number of student,Number of registration\n");
    class_t *current_class = class_list;
    while (current_class != NULL)
    {
        fprintf(subject_student_file, "%d,", current_class->class_id);
        fprintf(subject_student_file, "%d,", current_class->subject_id);
        fprintf(subject_student_file, "%d,", current_class->max_students);
        fprintf(subject_student_file, "%d,", current_class->num_registrations);
        fprintf(subject_student_file, "%s\n", current_class->open_status);
        // printf("\n");
        current_class = current_class->next;
    }

    fclose(subject_student_file);
}

void print_class_and_grade_to_file(const char *class_garde)
{
    FILE *class_and_grade_file = fopen(class_garde, "w");
    if (class_and_grade_file == NULL)
    {
        return;
    }
    if (class_and_grade_file == NULL)
    {
        return;
    }
    fprintf(class_and_grade_file, "Student_ID,Subject_ID,Class_ID,Graded\n");
    class_and_grade_t *current_class_and_grade = class_and_grade_list;
    while (current_class_and_grade != NULL)
    {
        fprintf(class_and_grade_file, "%d,", current_class_and_grade->student_id);
        fprintf(class_and_grade_file, "%d,", current_class_and_grade->subject_id);
        fprintf(class_and_grade_file, "%d,", current_class_and_grade->class_id);
        fprintf(class_and_grade_file, "%.2f\n", current_class_and_grade->grade);
        current_class_and_grade = current_class_and_grade->next;
    }

    fclose(class_and_grade_file);
}

void add_student(const char *name, int student_id, const char *date_of_birth, const char *gender, const char *faculty, int year, float gpa)
{
    student_t *new_student = (student_t *)malloc(sizeof(student_t));

    if (new_student == NULL)
    {
        printf("Error, add failed\n");
        return;
    }

    strcpy(new_student->name, name);
    new_student->student_id = student_id;
    strcpy(new_student->date_of_birth, date_of_birth);
    strcpy(new_student->gender, gender);
    strcpy(new_student->faculty, faculty);
    new_student->year = year;
    new_student->year_temp = 0.0;
    new_student->gpa = gpa;
    new_student->next = NULL;

    if (student_list == NULL)
    {
        student_list = new_student;
    }
    else
    {
        student_t *current_student = student_list;
        while (current_student->next != NULL)
        {
            current_student = current_student->next;
        }
        current_student->next = new_student;
    }
}

void add_subject(const char *subject_name, int subject_id, int subject_credit, int required_level_of_year)
{
    subject_t *new_subject = (subject_t *)malloc(sizeof(subject_t));

    if (new_subject == NULL)
    {
        printf("Error, add failed\n");
        return;
    }

    strcpy(new_subject->subject_name, subject_name);
    new_subject->subject_id = subject_id;
    new_subject->subject_credit = subject_credit;
    new_subject->required_level_of_year = required_level_of_year;
    new_subject->next = NULL;

    if (subject_list == NULL)
    {
        subject_list = new_subject;
    }
    else
    {
        subject_t *current_subject = subject_list;
        while (current_subject->next != NULL)
        {
            current_subject = current_subject->next;
        }
        current_subject->next = new_subject;
    }
}

void add_class(int class_id, int subject_id, int max_students, int num_registrations, char *open_status) // bug here 18/06
{
    // Kiểm tra class_id và subject_id
    // class_t *current_class = class_list;
    // while (current_class != NULL)
    // {
    //     if (current_class->class_id == class_id)
    //     {
    //         break;
    //     }
    //     current_class = current_class->next;
    // }

    // subject_t *current_subject = subject_list;
    // int subject_exists = 0;
    // while (current_subject != NULL)
    // {
    //     if (current_subject->subject_id == subject_id)
    //     {
    //         subject_exists = 1;
    //         break;
    //     }
    //     current_subject = current_subject->next;
    // }

    // if (!subject_exists)
    // {
    //     return;
    // }

    class_t *new_class = (class_t *)malloc(sizeof(class_t));

    if (new_class == NULL)
    {
        printf("Error, add failed\n");
        return;
    }

    new_class->class_id = class_id;
    new_class->subject_id = subject_id;
    new_class->max_students = max_students;
    new_class->num_registrations = num_registrations;
    strcpy(new_class->open_status, open_status);
    new_class->next = NULL;

    if (class_list == NULL)
    {
        class_list = new_class;
    }
    else
    {
        class_t *current_class = class_list;
        while (current_class->next != NULL)
        {
            current_class = current_class->next;
        }
        current_class->next = new_class;
    }
}

void add_class_and_grade(int student_id, int subject_id, int class_id, float grade)
{
    class_and_grade_t *new_class_and_grade = malloc(sizeof(class_and_grade_t));
    if (new_class_and_grade == NULL)
    {
        return;
    }

    new_class_and_grade->student_id = student_id;
    new_class_and_grade->subject_id = subject_id;
    new_class_and_grade->class_id = class_id;
    new_class_and_grade->grade = grade;
    new_class_and_grade->next = NULL;

    if (class_and_grade_list == NULL)
    {
        class_and_grade_list = new_class_and_grade;
    }
    else
    {
        class_and_grade_t *current_class_and_grade = class_and_grade_list;
        while (current_class_and_grade->next != NULL)
        {
            current_class_and_grade = current_class_and_grade->next;
        }
        current_class_and_grade->next = new_class_and_grade;
    }
}

void remove_student(int student_id)
{
    if (student_list == NULL)
    {
        printf("Error, remove failed\n");
        return;
    }

    student_t *current_student = student_list;
    student_t *prev_student = NULL;

    while (current_student != NULL)
    {
        if (current_student->student_id == student_id)
        {
            if (prev_student == NULL)
            {
                student_list = current_student->next;
            }
            else
            {
                prev_student->next = current_student->next;
            }

            free(current_student);
            return;
        }

        prev_student = current_student;
        current_student = current_student->next;
    }
    printf("Error, remove failed\n");
}

void remove_subject(int subject_id)
{
    if (subject_list == NULL)
    {
        printf("Error, remove failed\n");
        return;
    }

    // Check if the subject_id is being used by any classes
    class_t *current_class = class_list;
    while (current_class != NULL)
    {
        if (current_class->subject_id == subject_id)
        {
            printf("Error, remove failed\n");
            return;
        }
        current_class = current_class->next; // added this line to update current_class
    }

    // Start removing the subject from the subject list
    subject_t *current_subject = subject_list;
    subject_t *prev_subject = NULL;

    while (current_subject != NULL)
    {
        if (current_subject->subject_id == subject_id)
        {
            if (prev_subject == NULL)
            {
                subject_list = current_subject->next;
            }
            else
            {
                prev_subject->next = current_subject->next;
            }

            // Update the subject_id in any classes that are using this subject
            // current_class = class_list;
            // while (current_class != NULL)
            // {
            //     if (current_class->subject_id == subject_id)
            //     {
            //         current_class->subject_id = -1; // or some other value to indicate no subject is assigned
            //     }
            //     current_class = current_class->next;
            // }

            free(current_subject);
            return;
        }

        prev_subject = current_subject;
        current_subject = current_subject->next;
    }

    printf("Error, remove failed\n");
}

void remove_class(int class_id)
{
    if (class_list == NULL)
    {
        printf("Error, remove failed\n");
        return;
    }

    class_and_grade_t *current_class_and_grade = class_and_grade_list;
    while (current_class_and_grade != NULL)
    {
        if (current_class_and_grade->class_id == class_id)
        {
            printf("Error, remove failed\n");
            return;
        }
        current_class_and_grade = current_class_and_grade->next;
    }

    class_t *current_class = class_list;
    class_t *prev_class = NULL;

    while (current_class != NULL)
    {
        if ((current_class->class_id == class_id) && (current_class->num_registrations == 0))
        {
            if (prev_class == NULL)
            {
                class_list = current_class->next;
            }
            else
            {
                prev_class->next = current_class->next;
            }

            free(current_class);
            return;
        }

        prev_class = current_class;
        current_class = current_class->next;
    }
    printf("Error, remove failed\n");
}

void remove_class_and_grade(int student_id, int class_id, int grade)
{
    // Check
    if (class_and_grade_list == NULL)
    {
        return;
    }

    class_and_grade_t *current_class_and_grade = class_and_grade_list;
    class_and_grade_t *prev_class_and_grade = NULL;

    while (current_class_and_grade != NULL)
    {
        if ((current_class_and_grade->class_id == class_id) && (current_class_and_grade->student_id == student_id) && (current_class_and_grade->grade == grade))
        {
            if (prev_class_and_grade == NULL)
            {
                class_and_grade_list = current_class_and_grade->next;
            }
            else
            {
                prev_class_and_grade->next = current_class_and_grade->next;
            }

            free(current_class_and_grade);
            return;
        }

        prev_class_and_grade = current_class_and_grade;
        current_class_and_grade = current_class_and_grade->next;
    }
}

void read_data_from_csv(const char *st, const char *sb, const char *class, const char *class_grade) // char *st, char *sb, char *class, char *class_grade
{
    // Read student data from CSV file

    FILE *student_file = fopen(st, "r");
    if (student_file == NULL)
    {
        return;
    }

    char line[256];
    fgets(line, sizeof(line), student_file);
    while (fgets(line, sizeof(line), student_file))
    {
        char *name = strtok(line, ",");
        int student_id = atoi(strtok(NULL, ","));
        char *date_of_birth = strtok(NULL, ",");
        char *gender = strtok(NULL, ",");
        char *faculty = strtok(NULL, ",");
        int year = atoi(strtok(NULL, ","));
        if (year > 10)
        {
            year = 1;
        }
        float gpa = removeNegativeZero(atof(strtok(NULL, "\n")));
        if (gpa > 10.0)
        {
            gpa = 0.0;
        }

        add_student(name, student_id, date_of_birth, gender, faculty, year, gpa);
    }

    fclose(student_file);

    // Read subject data from CSV file
    FILE *subject_file = fopen(sb, "r");
    if (subject_file == NULL)
    {
        return;
    }

    fgets(line, sizeof(line), subject_file);
    while (fgets(line, sizeof(line), subject_file))
    {
        char *subject_name = strtok(line, ",");
        int subject_id = atoi(strtok(NULL, ","));
        int subject_credit = atoi(strtok(NULL, ","));
        int required_level_of_year = atoi(strtok(NULL, "\n"));

        add_subject(subject_name, subject_id, subject_credit, required_level_of_year);
    }

    fclose(subject_file);

    // Read subject-student data from CSV file
    FILE *subject_student_file = fopen(class, "r");
    if (subject_student_file == NULL)
    {
        return;
    }

    fgets(line, sizeof(line), subject_student_file);
    while (fgets(line, sizeof(line), subject_student_file))
    {
        int classes_id = atoi(strtok(line, ","));
        int subject_id = atoi(strtok(NULL, ","));
        int max_students = atoi(strtok(NULL, ","));
        int num_registrations = atoi(strtok(NULL, ","));
        char *open_status = strtok(NULL, "\n");

        add_class(classes_id, subject_id, max_students, num_registrations, open_status);
    }

    fclose(subject_student_file);

    // Read class and grade from CSV file
    FILE *class_and_grade_file = fopen(class_grade, "r");
    if (class_and_grade_file == NULL)
    {
        return;
    }

    fgets(line, sizeof(line), class_and_grade_file);
    while (fgets(line, sizeof(line), class_and_grade_file))
    {
        int student_id = atoi(strtok(line, ","));
        int subject_id = atoi(strtok(NULL, ","));
        int class_id = atoi(strtok(NULL, ","));
        float grade = atof(strtok(NULL, "\n"));

        add_class_and_grade(student_id, subject_id, class_id, grade);
    }

    fclose(class_and_grade_file);

    class_and_grade_t *current_class_and_grade = class_and_grade_list;
    while (current_class_and_grade != NULL)
    {
        if (current_class_and_grade->grade > 0.0)
        {
            student_t *current_student = student_list;
            while (current_student != NULL)
            {
                if (current_student->student_id == current_class_and_grade->student_id)
                {
                    subject_t *current_subject = subject_list;
                    while (current_subject != NULL)
                    {
                        if (current_subject->subject_id == current_class_and_grade->subject_id)
                        {
                            current_student->year_temp += ((float)(current_subject->subject_credit) / 20.0f);
                            // printf("%f\n",current_student->year_temp);
                        }
                        current_subject = current_subject->next;
                    }
                }
                current_student = current_student->next;
            }
        }
        current_class_and_grade = current_class_and_grade->next;
    }
}

void class_registration(int student_id, int subject_id, int class_id)
{
    if (student_list == NULL || subject_list == NULL || class_list == NULL)
    {
        printf("Error, registration failed\n");
        return;
    }

    student_t *current_student = student_list;
    while (current_student != NULL)
    {
        if (current_student->student_id == student_id)
        {
            subject_t *current_subject = subject_list;
            while (current_subject != NULL)
            {
                if (current_subject->subject_id == subject_id)
                {
                    class_t *current_class = class_list;
                    while (current_class != NULL)
                    {
                        // class_t *temp_class = current_class;
                        // if((current_class->subject_id == subject_id && (current_class->class_id != class_id)))
                        // {
                        //     printf("Error, registration failed\n");
                        //     break;
                        // }

                        if (current_class->class_id == class_id)
                        {
                            if (strcmp(current_class->open_status, "O") == 0)
                            {
                                if (current_class->max_students > current_class->num_registrations)
                                {
                                    if (current_student->year >= current_subject->required_level_of_year)
                                    {
                                        class_and_grade_t *current_class_and_grade = class_and_grade_list;
                                        while (current_class_and_grade != NULL)
                                        {
                                            // class_and_grade_t *temp_class_and_grade = current_class_and_grade;

                                            if ((current_class_and_grade->student_id == student_id) && (current_class_and_grade->subject_id == subject_id) && (current_class_and_grade->class_id == class_id) && (current_class_and_grade->grade <= 0.0))
                                            {
                                                if (current_class->num_registrations_temp != 9999)
                                                {
                                                    current_class->num_registrations_temp = 9999;
                                                    current_class->num_registrations++;
                                                }
                                                else
                                                {
                                                    printf("Error, registration failed\n");
                                                }

                                                return;
                                            }

                                            else if ((current_class_and_grade->student_id == student_id) && (current_class_and_grade->class_id != class_id))
                                            {

                                                float grade = -1.0; // default grade
                                                add_class_and_grade(student_id, subject_id, class_id, grade);
                                                if ((strcmp(current_class->open_status, "O") == 0))
                                                {
                                                    current_class->num_registrations++;
                                                    if (current_class->max_students == current_class->num_registrations)
                                                    {
                                                        strcpy(current_class->open_status, "C");
                                                        return;
                                                    }
                                                    if (current_class->max_students > current_class->num_registrations)
                                                    {
                                                        current_class->num_registrations--;
                                                        return;
                                                    }
                                                }
                                                return;
                                            }
                                            else
                                            {
                                                // float grade = -1.0; // default grade
                                                // add_class_and_grade(student_id, subject_id, class_id, grade);
                                                printf("Error, registration failed\n");
                                                return;
                                            }

                                            current_class_and_grade = current_class_and_grade->next;
                                        }
                                    }
                                    else
                                    {
                                        printf("Error, registration failed\n"); // no matching sunject found
                                        return;
                                    }
                                }
                                else
                                {
                                    printf("Error, registration failed\n"); // no matching sunject found
                                    return;
                                }
                            }
                            else
                            {
                                printf("Error, registration failed\n"); // no matching sunject found
                                return;
                            }
                        }
                        current_class = current_class->next;
                    }
                    printf("Error, registration failed\n"); // no matching sunject found
                    return;
                }

                current_subject = current_subject->next;
            }
            printf("Error, registration failed\n"); // no matching sunject found
            return;
        }
        current_student = current_student->next;
    }
    printf("Error, registration failed\n"); // no matching stuuudent found
}

void student_grading(int student_id, int class_id, float grade)
{

    // Check if class_and_grade_list is not null and return error if it is
    if (class_and_grade_list == NULL)
    {
        printf("Error, grade failed\n");
        return;
    }

    class_and_grade_t *current_class_and_grade = class_and_grade_list;
    while (current_class_and_grade != NULL)
    {
        if ((current_class_and_grade->student_id == student_id) && (current_class_and_grade->class_id == class_id) && (current_class_and_grade->grade == -1))
        {
            current_class_and_grade->grade = grade; // update grade

            student_t *current_student = student_list;
            while (current_student != NULL)
            {
                if (current_student->student_id == student_id)
                {
                    subject_t *current_subject = subject_list;
                    while (current_subject != NULL)
                    {
                        if (current_subject->subject_id == current_class_and_grade->subject_id)
                        {

                            current_student->gpa = grade;

                            class_t *current_class = class_list;
                            while (current_class != NULL)
                            {
                                if (current_class->class_id == current_class_and_grade->class_id)
                                {
                                    strcpy(current_class->open_status, "C");
                                    return;
                                }

                                current_class = current_class->next;
                            }
                            // float gpa = ((current_subject->subject_credit * current_class_and_grade->grade) + (current_student->gpa * (current_student->year * 20))) / (current_subject->subject_credit + (current_student->year * 20));
                            // current_student->gpa = gpa;
                            // current_student->year_temp += ((float)(current_subject->subject_credit) / 20.0f);

                            // if (current_student->year_temp >= 1.0)
                            // {
                            //     current_student->year += 1;
                            //     current_student->year_temp -= 1.0;
                            // }
                        }
                        current_subject = current_subject->next;
                    }
                }

                current_student = current_student->next;
            }

            return;
        }
        current_class_and_grade = current_class_and_grade->next;
    }

    printf("Error, grade failed\n");
    return;
}

void export_student_info(int student_id)
{
    if (student_list == NULL)
    {
        printf("Error, student is not existed\n");
        return;
    }

    student_t *current_student = student_list;
    while (current_student != NULL)
    {
        if (current_student->student_id == student_id)
        {
            printf("%s : %.2f\n", current_student->name, current_student->gpa);

            class_and_grade_t *current_class_and_grade = class_and_grade_list;
            while (current_class_and_grade != NULL)
            {
                if (current_class_and_grade->student_id == student_id)
                {
                    printf("%d : %.2f\n", current_class_and_grade->subject_id, current_class_and_grade->grade);
                    return; // printf all subject_id with student_id
                }
                current_class_and_grade = current_class_and_grade->next;
            }

            return;
        }
        current_student = current_student->next;
    }

    printf("Error, student is not existed\n");
}

int main(int args, char *argv[])
{
    // check if data_base path was passed to the program

    if (args != 2)
    {
        printf("Argument Error! please pass the data_base path to this program\n");
    }
    argv[1] = "data_base";
    // get data folder path len
    short path_len = strlen(argv[1]);
    // printf("%s",argv[2]);
    //  set name for data file, we can use #define for those as well
    const char *student_data_file_name = "/student_data.csv";
    const char *subject_data_file_name = "/subject_data.csv";
    const char *classes_data_file_name = "/classes_data.csv";
    const char *class_and_grade_data_file_name = "/class_and_grade_data.csv";
    // allocate memory for the full path
    char *student_data_path = (char *)calloc(path_len + strlen(student_data_file_name), sizeof(char));
    char *subject_data_path = (char *)calloc(path_len + strlen(subject_data_file_name), sizeof(char));
    char *class_data_path = (char *)calloc(path_len + strlen(classes_data_file_name), sizeof(char));
    char *class_and_grade_data_path = (char *)calloc(path_len + strlen(class_and_grade_data_file_name), sizeof(char));

    // copy data folder path (argv[1]) to student_data_path then concatenate the path and file to construct the full file path
    strcpy(student_data_path, argv[1]);
    strcpy(subject_data_path, argv[1]);
    strcpy(class_data_path, argv[1]);
    strcpy(class_and_grade_data_path, argv[1]);

    strcat(student_data_path, student_data_file_name);
    strcat(subject_data_path, subject_data_file_name);
    strcat(class_data_path, classes_data_file_name);
    strcat(class_and_grade_data_path, class_and_grade_data_file_name);

    int user_input;
    // read_data_from_csv(student_data_path, subject_data_path, class_data_path, class_and_grade_data_path);
    read_data_from_csv(student_data_path, subject_data_path, class_data_path, class_and_grade_data_path);

    while (1)
    {
        // cần nhận vào user input nên hàm printf này cần dấu hiệu '::\n' ở cuối string
        printf("Enter your selection::\n");
        scanf("%d", &user_input);

        switch (user_input)
        {
        case 0:

            print_student_list_to_file(student_data_path);
            print_subject_list_to_file(subject_data_path);
            print_class_list_to_file(class_data_path);
            print_class_and_grade_to_file(class_and_grade_data_path);

            student_t *current_student = student_list;
            while (current_student != NULL)
            {
                student_t *temp = current_student;
                current_student = current_student->next;
                free(temp);
            }

            subject_t *current_subject = subject_list;
            while (current_subject != NULL)
            {
                subject_t *temp = current_subject;
                current_subject = current_subject->next;
                free(temp);
            }

            class_t *current_class = class_list;
            while (current_class != NULL)
            {
                class_t *temp = current_class;
                current_class = current_class->next;
                free(temp);
            }

            class_and_grade_t *current_class_and_grade = class_and_grade_list;
            while (current_class_and_grade != NULL)
            {
                class_and_grade_t *temp = current_class_and_grade;
                current_class_and_grade = current_class_and_grade->next;
                free(temp);
            }
            exit(0);
        case 1:
            int student_id;
            printf("Enter the Student ID::\n");
            scanf("%d", &student_id);
            print_student_list(student_id);
            break;
        case 2:
            int subject_id;
            printf("Enter the Subject ID::\n");
            scanf("%d", &subject_id);
            print_subject_list(subject_id);
            break;
        case 3:
            int class_id;
            printf("Enter the Class ID::\n");
            scanf("%d", &class_id);
            print_class_list(class_id);
            break;
        case 4:
        {
            char name[50];
            int student_id;
            char date_of_birth[20];
            char gender[10];
            char faculty[50];
            int year = 1;
            float gpa = 0.00;

            getchar();
            printf("Enter student name::\n");
            fgets(name, 50, stdin);
            name[strcspn(name, "\n")] = '\0';
            printf("Enter student ID::\n");
            scanf("%d", &student_id);
            printf("Enter date of birth::\n");
            scanf("%s", &date_of_birth);
            printf("Enter gender::\n");
            scanf("%s", &gender);
            printf("Enter faculty::\n");
            scanf("%s", &faculty);

            int valid = 0;
            student_t *current_student = student_list;
            do
            {
                if (current_student->student_id == student_id)
                {
                    valid = 1;
                    if ((strcmp(current_student->name, name) == 0) && (strcmp(current_student->date_of_birth, date_of_birth) == 0) && (strcmp(current_student->gender, gender) == 0) && (strcmp(current_student->faculty, faculty) == 0))
                    {
                        break;
                    }
                    printf("Error, add failed\n");
                    break;
                }

                current_student = current_student->next;

            } while (current_student != NULL);

            if (valid == 0)
            {

                add_student(name, student_id, date_of_birth, gender, faculty, year, gpa);
            }

            break;
        }
        case 6:
        {
            int subject_id;
            char subject_name[50];
            int subject_credit;
            int required_level_of_year;

            printf("Enter subject name::\n");
            scanf("%s", &subject_name);
            printf("Enter subject ID::\n");
            scanf("%d", &subject_id);
            printf("Enter subject credit::\n");
            scanf("%d", &subject_credit);
            printf("Enter required level of year::\n");
            scanf("%d", &required_level_of_year);

            int valid = 0;
            subject_t *current_subject = subject_list;
            do
            {
                if (current_subject->subject_id == subject_id)
                {
                    valid = 1;
                    if ((strcmp(current_subject->subject_name, subject_name) == 0) && (current_subject->subject_id == subject_id) && (current_subject->subject_credit == subject_credit) && (current_subject->required_level_of_year == required_level_of_year))
                    {
                        break;
                    }
                    printf("Error, add failed\n");
                    break;
                }

                current_subject = current_subject->next;

            } while (current_subject != NULL);

            if (valid == 0)
            {

                add_subject(subject_name, subject_id, subject_credit, required_level_of_year);
            }

            break;
        }
        case 8:
        {
            int class_id;
            int subject_id;
            int max_students;
            int num_registrations;
            char *open_status;

            printf("Enter class ID::\n");
            scanf("%d", &class_id);
            printf("Enter subject ID::\n");
            scanf("%d", &subject_id);
            printf("Enter max number of students::\n");
            scanf("%d", &max_students);
            num_registrations = 0;
            open_status = "O";

            int valid = 0;
            class_t *current_class = class_list;
            do
            {
                if (current_class->class_id == class_id)
                {
                    valid = 1;
                    if ((current_class->subject_id == subject_id) && (current_class->max_students == max_students))
                    {
                        printf("Error, add failed\n");
                        break;
                    }
                    printf("Error, add failed\n");
                    break;
                }

                current_class = current_class->next;

            } while (current_class != NULL);

            if (valid == 0)
            {
                add_class(class_id, subject_id, max_students, num_registrations, open_status);
            }

            // // Kiểm tra class_id và subject_id
            // class_t *current_class = class_list;
            // int class_exsits = 0;
            // while (current_class != NULL)
            // {
            //     if (current_class->class_id == class_id)
            //     {
            //         class_exsits = 1;
            //         break;
            //     }
            //     current_class = current_class->next;
            // }
        

            // subject_t *current_subject = subject_list;
            // int subject_exists = 0;
            // while (current_subject != NULL)
            // {
            //     if (current_subject->subject_id == subject_id)
            //     {
            //         subject_exists = 1;
            //         break;
            //     }
            //     current_subject = current_subject->next;
            // }

            // if (!class_exsits || !subject_exists)
            // {
            //     printf("Error, add failed\n");
            //     break;
            // }
            // else
            // {
            // add_class(class_id, subject_id, max_students, num_registrations, open_status);
            // }

            break;
        }
        case 5:
        {
            int student_id;
            printf("Enter student ID to remove::\n");
            scanf("%d", &student_id);
            remove_student(student_id);
            // print_student_list_to_file();
            // read_data_from_csv();

            break;
        }
        case 7:
        {
            int subject_id;
            printf("Enter subject ID to remove::\n");
            scanf("%d", &subject_id);
            remove_subject(subject_id);
            break;
        }
        case 9:
        {
            int class_id;
            printf("Enter class ID to remove::\n");
            scanf("%d", &class_id);
            remove_class(class_id);
            break;
        }
        case 10:
        {
            int student_id;
            int class_id;
            int subject_id;
            printf("Enter student ID::\n");
            scanf("%d", &student_id);
            printf("Enter subject ID::\n");
            scanf("%d", &subject_id);
            printf("Enter class ID::\n");
            scanf("%d", &class_id);
            class_registration(student_id, subject_id, class_id);
            // print_class_and_grade_to_file();
            break;
        }
        case 11:
        {
            int class_id;
            int student_id;
            float grade;
            printf("Enter student ID::\n");
            scanf("%d", &student_id);
            printf("Enter class ID::\n");
            scanf("%d", &class_id);
            printf("Enter grade::\n");
            scanf("%f", &grade);
            student_grading(student_id, class_id, grade);
            break;
        }
        case 12:
            int student_id_12;
            printf("Enter student ID::\n");
            scanf("%d", &student_id_12);
            export_student_info(student_id_12);
            break;

        default:
            break;
        }
    }
    return 0;
}