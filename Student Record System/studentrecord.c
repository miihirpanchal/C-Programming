#include <stdio.h>
struct studentrecord
{
    char name[30];
    int Id;
    int Age;
    char Branch[15];
    int Semester;
    float Performance;
};
struct studentrecord student[100];
int i = 0;

int main()
{
    while (1)
    {

        printf("\n**********  STUDENT RECORD SYSTEM   **********\n");
        printf("\n----------         Options          ----------\n");
        printf("\n                1.Add A Student               \n");
        printf("\n                2. View All Students.         \n");
        printf("\n                3. Search Student.            \n");
        printf("\n                4. Update Student.            \n");
        printf("\n                5. Delete A Student.          \n");
        printf("\n                6. Exit                       \n");

        int num;

        printf("\nEnter A Corresponding Number To Make The Appropriate Changes.\n");
        scanf("%d", &num);

        switch (num)
        {
        case 1:
        {
            int duplicateId = 0;

            if (i >= 100)
            {
                printf("\nStudent Record Is Full\n");
                break;
            }
            printf("Enter The Student ID\n");
            scanf("%d", &student[i].Id);
            if (student[i].Id <= 0 || student[i].Id > 100)
            {
                printf("\nInvalid Student ID\n");
                break;
            }
            for (int j = 0; j < i; j++)
            {
                if (student[j].Id == student[i].Id)
                {
                    duplicateId = 1;
                    break;
                }
            }
            if (duplicateId == 1)
            {
                printf("\nStudent ID Already Exists\n");
                break;
            }

            printf("Enter The Student Name\n");
            scanf("%s", student[i].name);

            printf("Enter The Student Age\n");
            scanf("%d", &student[i].Age);

            printf("Enter The Student Branch\n");
            scanf("%s", student[i].Branch);

            printf("Enter The Student Semester\n");
            scanf("%d", &student[i].Semester);

            printf("Enter The Student Performance\n");
            scanf("%f", &student[i].Performance);

            printf("\nStudent Record Added Successfully\n");
            i++;

            break;
        }

        case 6:
        {
            printf("\nExiting The Program\n");
            return 0;
        }

        case 2:
        {
            if (i == 0)
            {
                printf("\nNo Student Records Found\n");
                break;
            }

            printf("\n----------         Student Records          ----------\n");
            for (int j = 0; j < i; j++)
            {
                printf("\nStudent Name: %s\n", student[j].name);
                printf("Student ID: %d\n", student[j].Id);
                printf("Student Age: %d\n", student[j].Age);
                printf("Student Branch: %s\n", student[j].Branch);
                printf("Student Semester: %d\n", student[j].Semester);
                printf("Student Performance: %.2f\n", student[j].Performance);
            }
            break;
        }

        case 3:
        {
            if (i == 0)
            {
                printf("\nNo Student Records Found\n");
                break;
            }

            int searchId;
            printf("\nEnter The Student ID Here To Search For The Student Record: ");
            scanf("%d", &searchId);

            if (searchId < 0)
            {
                printf("\nInvalid Student ID\n");
                break;
            }
            else if (searchId == 0)
            {
                printf("\nInvalid Student ID\n");
                break;
            }
            else if (searchId > 100)
            {
                printf("\nInvalid Student ID\n");
                break;
            }
            else if (searchId > 0 && searchId <= 100)
            {
                printf("\nSearching For Student Record With ID: %d\n", searchId);
            }
            else
            {
                printf("\nInvalid Student ID\n");
                break;
            }

            int found = 0;
            for (int j = 0; j < i; j++)
            {
                if (student[j].Id == searchId)
                {
                    printf("\nStudent Name: %s\n", student[j].name);
                    printf("Student ID: %d\n", student[j].Id);
                    printf("Student Age: %d\n", student[j].Age);
                    printf("Student Branch: %s\n", student[j].Branch);
                    printf("Student Semester: %d\n", student[j].Semester);
                    printf("Student Performance: %.2f\n", student[j].Performance);
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                printf("\nStudent Record Not Found\n");
                break;
            }
            break;
        }

        case 4:
        {
            if (i == 0)
            {
                printf("\nNo Student Records Found\n");
                break;
            }

            int updateId;
            printf("\nEnter The Student ID Here To Update The Student Record: ");
            scanf("%d", &updateId);

            if (updateId < 0)
            {
                printf("\nInvalid Student ID\n");
                break;
            }
            else if (updateId == 0)
            {
                printf("\nInvalid Student ID\n");
                break;
            }
            else if (updateId > 100)
            {
                printf("\nInvalid Student ID\n");
                break;
            }
            else if (updateId > 0 && updateId <= 100)
            {
                printf("\nUpdating Student Record With ID: %d\n", updateId);
            }
            else
            {
                printf("\nInvalid Student ID\n");
                break;
            }

            int updated = 0;
            int found = 0;
            int index = -1;
            for (int j = 0; j < i; j++)
            {
                if (student[j].Id == updateId)
                {
                    printf("\nStudent Name: %s\n", student[j].name);
                    printf("Student ID: %d\n", student[j].Id);
                    printf("Student Age: %d\n", student[j].Age);
                    printf("Student Branch: %s\n", student[j].Branch);
                    printf("Student Semester: %d\n", student[j].Semester);
                    printf("Student Performance: %.2f\n", student[j].Performance);
                    found = 1;
                    index = j;
                    break;
                }
            }
            if (!found)
            {
                printf("\nStudent Record Not Found\n");
                break;
            }

            printf("\nWhat Do You Want To Update?\n");
            printf("\n1. Student Name\n");
            printf("\n2. Student Age\n");
            printf("\n3. Student Branch\n");
            printf("\n4. Student Semester\n");
            printf("\n5. Student Performance\n");

            int updateOption;
            printf("\nEnter A Corresponding Number To Make The Appropriate Changes.\n");
            scanf("%d", &updateOption);
            switch (updateOption)
            {
            case 1:
                printf("\nEnter The New Student Name: ");
                scanf("%s", student[index].name);
                printf("\nStudent Name Updated Successfully\n");
                updated = 1;
                break;
            case 2:
                printf("\nEnter The New Student Age: ");
                scanf("%d", &student[index].Age);
                printf("\nStudent Age Updated Successfully\n");
                updated = 1;
                break;
            case 3:
                printf("\nEnter The New Student Branch: ");
                scanf("%s", student[index].Branch);
                printf("\nStudent Branch Updated Successfully\n");
                updated = 1;
                break;
            case 4:
                printf("\nEnter The New Student Semester: ");
                scanf("%d", &student[index].Semester);
                printf("\nStudent Semester Updated Successfully\n");
                updated = 1;
                break;
            case 5:
                printf("\nEnter The New Student Performance: ");
                scanf("%f", &student[index].Performance);
                printf("\nStudent Performance Updated Successfully\n");
                updated = 1;
                break;
            default:
                printf("\nInvalid Option\n");
                break;
            }
            break;
        }

        case 5:

            if (i == 0)
            {
                printf("\nNo Student Records Found\n");
                break;
            }

            int deleteId;
            int index = -1;
            printf("\nEnter The Student ID Here To Delete The Student Record: ");
            scanf("%d", &deleteId);

            if (deleteId < 0)
            {
                printf("\nInvalid Student ID\n");
                break;
            }
            else if (deleteId == 0)
            {
                printf("\nInvalid Student ID\n");
                break;
            }
            else if (deleteId > 100)
            {
                printf("\nInvalid Student ID\n");
                break;
            }
            else if (deleteId > 0 && deleteId <= 100)
            {
                printf("\nDeleting Student Record With ID: %d\n", deleteId);
            }
            else
            {
                printf("\nInvalid Student ID\n");
                break;
            }

            int found = 0;
            for (int j = 0; j < i; j++)
            {
                if (student[j].Id == deleteId)
                {
                    printf("\nStudent Name: %s\n", student[j].name);
                    printf("Student ID: %d\n", student[j].Id);
                    printf("Student Age: %d\n", student[j].Age);
                    printf("Student Branch: %s\n", student[j].Branch);
                    printf("Student Semester: %d\n", student[j].Semester);
                    printf("Student Performance: %.2f\n", student[j].Performance);
                    index = j;
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                printf("\nStudent Record Not Found\n");
                break;
            }

            for (int j = 0; j < i; j++)
            {
                if (student[j].Id == deleteId)
                {
                    for (int k = j; k < i - 1; k++)
                    {
                        student[k] = student[k + 1];
                    }
                    i--;
                    printf("\nStudent Record Deleted Successfully\n");
                    break;
                }
            }

            break;

        default:
        {
            printf("\nInvalid Option\n");
            break;
        }
        }
    }
    return 0;
}
