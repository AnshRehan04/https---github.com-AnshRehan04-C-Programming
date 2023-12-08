#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_MEMBERS 100 // maximum number of members that can be registered


struct Member {
    char name[50];
    int age;
    char gender;
    char membership_type[20];
    float weight;
    float height;
    float bmi;
};

struct Gym {
    int num_members;
    struct Member members[MAX_MEMBERS];
};

void print_member(struct Member member) {
    printf("Name: %s\n", member.name);
    printf("Age: %d\n", member.age);
    printf("Gender: %c\n", member.gender);
    printf("Membership Type: %s\n", member.membership_type);
    printf("Weight: %.2f kg\n", member.weight);
    printf("Height: %.2f cm\n", member.height);
    printf("BMI: %.2f\n", member.bmi);
    printf("\n");
}

void print_all_members(struct Gym gym) {
    printf("Total Members: %d\n", gym.num_members);
    printf("--------------------\n");
    for (int i = 0; i < gym.num_members; i++) {
        printf("Member %d:\n", i+1);
        print_member(gym.members[i]);
    }
}

void add_member(struct Gym *gym) {
    if (gym->num_members >= MAX_MEMBERS) {
        printf("Cannot add more members.\n");
        return;
    }
    struct Member new_member;
    printf("Enter member details:\n");
    printf("Name: ");
    scanf("%s", new_member.name);
    printf("Age: ");
    scanf("%d", &new_member.age);
    printf("Gender (M/F): ");
    scanf(" %c", &new_member.gender);
    printf("Membership Type (Regular/Premium): ");
    scanf("%s", new_member.membership_type);
    printf("Weight (in kg): ");
    scanf("%f", &new_member.weight);
    printf("Height (in cm): ");
    scanf("%f", &new_member.height);
    new_member.bmi = new_member.weight / ((new_member.height/100)*(new_member.height/100));
    gym->members[gym->num_members] = new_member;
    gym->num_members++;
    printf("Member added successfully.\n");
}

void remove_member(struct Gym *gym) {
    char name[50];
    printf("Enter name of member to remove: ");
    scanf("%s", name);
    for (int i = 0; i < gym->num_members; i++) {
        if (strcmp(gym->members[i].name, name) == 0) {
            for (int j = i; j < gym->num_members-1; j++) {
                gym->members[j] = gym->members[j+1];
            }
            gym->num_members--;
            printf("Member removed successfully.\n");
            return;
        }
    }
    printf("Member not found.\n");
}

int main() {
    struct Gym gym = {0};
    int _choice;
    while(1)
    {
        printf("1-->Gym Management \n2-->E-Trainer");
        printf("\nChoose system:");
        scanf("%d", &_choice);

        switch(_choice){
            case 1:{
        
        
            int choice;
            while (1) 
            {
                printf("Gym Management System\n");
                printf("---------------------\n");
                printf("1. Add Member\n");
                printf("2. Remove Member\n");
                printf("3. View All Members\n");
                printf("4. Exit\n");
                printf("Enter choice (1-4): ");
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        add_member(&gym);
                        break;
                    case 2:
                        remove_member(&gym);
                        break;
                    case 3:
                        print_all_members(gym);
                        break;
                    default :
                        exit(0);
                        break;}
            break;
            }
            }
        case 2:{
        
        
            printf("E-Trainer System\n");
            printf("---------------------\n");
            printf("1. Bicep Exercise\n");
            printf("2. Tricep Exercise\n");
            printf("3. Chest Exercise\n");
            printf("4. Shoulder Exercise\n");
            printf("5. Back Exercise\n");
            printf("6. Leg Exercise\n");
            printf("7. Abs Exercise\n");
            printf("Choose Exercise (1-7): ");
            scanf("%d", &_choice);
            switch (_choice) {
                    case 1:
                        printf("1.Barbell Curls\n2.Bar Cable Curls\n3.EZ Bar Preacher Curls\n4.Incline Dumbbell Curls\n5.One arm Dumbbell\n6.Preacher Curls\n7.Reverse barbell curls\n8.Seated Dumbbell Curls\n");
                        break;
                        
                    case 2:
                        
                        break;
                        
                    case 3:
                        break;
                        
                    case 4:
                        break;
                        
                    case 5:
                        break;
                        
                    case 6:
                        break;
                        
                    case 7:
                        break;
                        
                    default :
                        exit(0);
                        break;}
            break;}
        default :
            exit(0);
            break;
    }
}
}

