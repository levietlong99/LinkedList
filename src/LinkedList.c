#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Tạo struct lưu danh sách sinh viên */
struct student{
    int ID;
    char name[50];
    int mark;
    /* Con trỏ trỏ tới node sau */
    struct student *pNext;
    /* Con trỏ trỏ tới node trước */
    struct student *pPrev;
};

/* Tạo con trỏ trỏ tới struct student */
typedef struct student *pStudent;
pStudent pHead = NULL;
pStudent pTail = NULL;

/* Số lượng sinh viên của danh sách */
int amount = 0;

/* In ra menu */
void outputMenu();

/* Nhập dữ liệu */
void insertInformation(student &pNewStudent);

/* Tạo sinh viên mới of danh sách */
pStudent creatNewStudent();

/* Tạo học sinh đầu danh sách */
void newHead(pStudent &pHead, pStudent &pTail);

/* Tạo học sinh cuối danh sách */
void newTail(pStudent &pHead, pStudent &pTail);

/* Tạo học sinh đầu tại thứ tự bất kì */
void newAny(pStudent &pHead, pStudent &pTail, int  &amount);

/* Xóa học sinh đầu danh sách */
void deleteHead(pStudent &pHead, pStudent &pTail);

/* Xóa sinh viên cuối danh sách */
void deleteTail(pStudent &pHead, pStudent &pTail);

/* Xóa sinh viên ở vị trí bất kì */
void deleteAny(pStudent &pHead, pStudent &pTail, int &amount);

/* Sửa sinh viên đầu danh sách */
void fixHead(pStudent &pHead);

/* Sửa sinh viên cuối danh sách */
void fixTail(pStudent &pTail);

/* Sửa sinh viên tại thứ tự bất kì */
void fixAny(pStudent &pHead);

/* Tìm sinh viên qua thông tin */
void findStudent(pStudent &pHead);

/* Giải phóng và xóa danh sách sinh viên */
void deleteAll(pStudent &pHead);

/* In toàn bộ danh sách sinh viên */
void outputList(pStudent &pHead);

/* Cập nhật Id và số lượng sinh viên trước mỗi lần chạy lại */
void fillID(pStudent &pHead, int &amount);

/* Tạo, truy xuất thông tin sinh viên từ file.txt */
void readFromTxt(pStudent &pHead, pStudent &pTail);

/* Cập nhật lại thông tin sinh viên vào file txt trước khi đóng file */
void writeToTxt(pStudent &pHead, pStudent &pTail);

int main(){

    readFromTxt(pHead, pTail);
    /* In ra menu */
    /* 1. Tạo sinh viên đầu danh sách 
       2. Tạo sinh viên cuối danh sách 
       3. Tạo sinh viên tại vị trí bất kì
       4. Xóa sinh viên đầu danh sách
       5. Xóa sinh viên cuối danh sách 
       6. Xóa sinh viên tại vị trí bất kì
       7. Tìm sinh viên
       8. Thay thế sinh viên ở đầu
       9. Thay thế sinh viên ở cuối
       10. Thay thế sinh viên ở vị trí bất kì
       11. In ra danh sách sinh viên
       12. Thoát chương trình */
    /* Vòng lặp chương trình */
    while(true)
    {

        /* In menu và chọn chế độ trong menu */
        outputMenu();
        int section = 0;
        printf("\nInsert your propose?");
        scanf("%d", &section);

        switch(section){
            case 1:
            {
                printf("\nYou choose to creat first student in list");
                newHead(pHead, pTail);
                break;
            }
            case 2:
            {
                printf("\nYou choose to creat last student in list");
                newTail(pHead, pTail);
                break;
            }
            case 3:
            {
                printf("\nYou choose to creat student in any place");
                newAny(pHead, pTail, amount);
                break;
            }
            case 4:
            {
                printf("\nYou choose to delete first student in list");
                deleteHead(pHead, pTail);
                break;
            }
            case 5:
            {
                printf("\nYou choose to delete last student in list");
                deleteTail(pHead ,pTail);
                break;
            }
            case 6:
            {
                printf("\nYou choose to delete student in any places");
                deleteAny(pHead, pTail, amount);
                break;
            }
            case 7:
            {
                printf("\nYou choose to find student");
                findStudent(pHead);
                break;
            }
            case 8:
            {
                printf("\nYou choose to fix infor of first student ");
                fixHead(pHead);
                break;
            }
            case 9:
            {
                printf("\nYou choose to fix infor of last student");
                fixTail(pTail);
                break;
            }
            case 10:
            {
                printf("\nYou choose to fix infor of student by position");
                fixAny(pHead);
                break;
            }
            case 11:
            {
                outputList(pHead);
                break;
            }
        }

        /* Cập nhật lại Id và số lượng sinh viên */
        /* Xóa màn hình */
        fillID(pHead, amount);

        /* Xác nhận dừng hoặc sử dụng tiếp chương trình */
        /* Nhập Y/y để tiếp tục chương trình */
        char command[5];
        printf("\nDo you want to choose more option?(Y / N)");
        fflush(stdin);
        gets(command);
        system("cls");
        if(strcmp(command, "Y") != 0 && strcmp(command, "y") != 0)
        {
            break;
        }
        /* Khởi động lại chương trình */
    }
    /* Lưu vào file trước khi thoát chương trình */
    writeToTxt(pHead, pTail);
    deleteAll(pHead);
    return 0;
}

void outputMenu(){

    printf("    ___________________________________________________________________________________________\n");
    printf("    |                                                                                          |\n");
    printf("    |                                         MENU                                             |\n");
    printf("    |       1. Creat student of header list                                                    |\n");
    printf("    |       2. Creat student of footer list                                                    |\n");
    printf("    |       3. Creat student of any places in list                                             |\n");
    printf("    |       4. Delete student of header list                                                   |\n");
    printf("    |       5. Delete student of footer list                                                   |\n");
    printf("    |       6. Delete student of any places in list                                            |\n");
    printf("    |       7. Find student                                                                    |\n");
    printf("    |       8. Fix infor about student of header list                                          |\n");
    printf("    |       9. Fix infor about student of footer list                                          |\n");
    printf("    |      10. Fix infor about student of list                                                 |\n");
    printf("    |      11. Print information about student of list                                         |\n");
    printf("    |__________________________________________________________________________________________|\n");

}

void fillID(pStudent &pHead, int &amount){

    /* Khởi tạo pRun từ pHead chạy đến cuối vừa duyệt id và số lượng */
    pStudent pRun = pHead;
    amount = 0;
    while(pRun != NULL)
    {
        amount++;
        pRun -> ID = amount;
        pRun = pRun -> pNext;
    }
}

void insertInformation(pStudent &pNewStudent){

    /* Nhập thông tin cho struct trỏ tới bởi pNewStudent */
    printf("\nInsert name of student: ");
    fflush(stdin);
    gets(pNewStudent -> name);
    printf("\nInsert points of student: ");
    scanf("%d", &(pNewStudent -> mark));
}

pStudent creatNewStudent(){

    /* Cấp phát cho struct student tại địa chỉ mà con trỏ pNewStudent trỏ tới */
    pStudent pNewStudent = (student*)malloc(sizeof(student));
    /* Khởi tạo giá trị */
    pNewStudent -> mark = 0;
    pNewStudent -> pNext = NULL;
    pNewStudent -> pPrev = NULL;
    return pNewStudent;
}

void newHead(pStudent &pHead, pStudent &pTail){

    /* Tạo học sinh và nhập thông tin */
    pStudent pNewStudent = creatNewStudent();
    insertInformation(pNewStudent);

    if(pHead == NULL)
    {
        pHead = pNewStudent;
        pTail = pNewStudent;
    }
    else
    {
        /* Thiết lập con trỏ kết nối giữ đầu mới và đầu cũ */
        pNewStudent -> pNext = pHead;
        pHead -> pPrev = pNewStudent;
        pHead = pNewStudent;
    }
}

void deleteHead(pStudent &pHead, pStudent &pTail){

    if(pHead != NULL)
    {
        /* Kiểm tra trường hợp cả danh sách chỉ có 1 sinh viên */
        if(pHead -> pNext != NULL)
        {
            /* Di chuyển pHead sang sinh viên sau và xóa sinh viên đầu */
            pHead = pHead -> pNext;
            free(pHead -> pPrev);
            pHead -> pPrev = NULL;
        }
        else
        {
            /* Giải phóng cả 2 con trỏ */
            free(pHead);
            pHead = NULL;
            free(pTail);
            pTail = NULL;
        }
    }
    else
    {
        printf("\nYou dont have anything to delete");
    }
}


void newTail(pStudent &pHead ,pStudent &pTail){

    if(pHead != NULL)
    {
        /* Tạo học sinh và nhập thông tin */
        pStudent pNewStudent = creatNewStudent();
        insertInformation(pNewStudent);

        pTail -> pNext = pNewStudent;
        pNewStudent -> pPrev = pTail;
        pTail = pNewStudent;
    }
    /* Danh sách trống */
    else
    {   
        /* Thêm vào đầu */
        newHead(pHead, pTail);
    }
}

void newAny(pStudent &pHead, pStudent &pTail, int &amount){

    /* Khởi tạo vị trí muốn đặt */
    int position = 0;
    printf("\nInsert your position that u want to put student:");
    scanf("%d", &position);

    /* Loại bỏ các trường hợp vô lý */
    if(position < 1 || position > amount + 1)
    {
        /* In thông báo và thoát hàm */
        printf("\nWTF are you doing!");
        return;
    }

    /* Xét các trường hợp thêm vào đầu */
    else if(pHead == NULL || position == 1)
    {
        newHead(pHead, pTail);
    }

    /* Xét các trường hợp thêm vào cuối */
    else if(position == amount + 1)
    {
        newTail(pHead, pTail);
    }
    else
    {
        /* Khởi tạo con trỏ chạy từ pRun đến đuôi đối với các trường hợp còn lại */
        pStudent pRun = pHead;

        while(pRun != NULL)
        {
            position--;
            /* Dừng khi gặp vị trí đặt vào */
            if(position == 0)
            {
                break;
            }
            pRun = pRun -> pNext;
        }
        /* Nhập thông tin node và thiếp lập liên kết */
        pStudent pNewStudent = creatNewStudent();
        insertInformation(pNewStudent);
        /* Cho node trước trỏ đến node đang tạo */
        (*(pRun -> pPrev)).pNext = pNewStudent;
        /* Cho node sau trỏ đến node đang tạo */
        pRun -> pPrev = pNewStudent;
        /* Lần lượt cho node đang tạo trỏ tới node trước và node sau */
        pNewStudent -> pNext = pRun;
        pNewStudent -> pPrev = pRun -> pPrev;
    }
}

void deleteTail(pStudent &pHead, pStudent &pTail){

    /* Xét trường hợp danh sách chỉ có từ 2 sinh viên trở lên */
    if(pHead != NULL && pHead -> pNext != NULL)
    {
        pTail = pTail -> pPrev;
        free(pTail -> pNext);
        pTail -> pNext = NULL;
    }
    /* Quay lại trường hợp đặc biệt đã có ở xóa đầu */
    else
    {
        deleteHead(pHead, pTail);
    }
}

void deleteAny(pStudent &pHead, pStudent &pTail, int &amount){

    /* Khởi tạo vị trí muốn xóa */
    int position = 0;
    printf("\nInsert your position that u want to delete student:");
    scanf("%d", &position);

    /* Loại bỏ các trường hợp vô lý */
    if(position < 1 || position > amount)
    {
        /* In thông báo và thoát hàm */
        printf("\nWTF are you doing!");
        return;
    }

    /* Xét các trường hợp xóa đầu hoặc danh sách trống */
    else if(pHead == NULL || position == 1)
    {
        deleteHead(pHead, pTail);
    }

    /* Xét các trường hợp xóa cuối */
    else if(position == amount)
    {
        deleteTail(pHead, pTail);
    }
    else
    {
        /* Khởi tạo con trỏ chạy từ pRun đến đuôi đối với các trường hợp còn lại */
        pStudent pRun = pHead;

        while(pRun != NULL)
        {
            position--;
            /* Dừng khi gặp vị trí xóa */
            if(position == 0)
            {
                break;
            }
            pRun = pRun -> pNext;
        }
        (pRun -> pPrev) -> pNext = pRun -> pNext;
        (pRun -> pNext) -> pPrev = pRun -> pPrev;
        free(pRun);
        pRun = NULL;
    }
}

void fixHead(pStudent &pHead){

    if(pHead == NULL)
    {
        printf("Nothing to fix");
    }
    else
    {
        insertInformation(pHead);
    }
}

void fixTail(pStudent &pTail){

    if(pTail == NULL)
    {
        printf("Nothing to fix");
    }
    else
    {
        insertInformation(pTail);
    }
}

void fixAny(pStudent &pHead){

    /* Khởi tạo vị trí muốn sửa */
    int position = 0;
    printf("\nInsert your position that u want to fix:");
    scanf("%d", &position);

    /* Loại bỏ các trường hợp vô lý */
    if(position < 1 || position > amount)
    {
        /* In thông báo và thoát hàm */
        printf("\nWTF are you doing!");
        return;
    }
    /* Xét các trường hợp sửa đầu hoặc danh sách trống */
    else if(pHead == NULL || position == 1)
    {
        fixHead(pHead);
    }
    /* xét các trường hợp sửa đuôi */
    else if(position == amount)
    {
        fixTail(pHead);
    }
    /* Xét các trường hợp còn lại */
    else
    {
        /* Khởi tạo biến chạy pRun */
        pStudent pRun = pHead;
        while(pRun != NULL)
        {
            position--;
            /* Thoát vòng lặp khi gặp vị trí cần sửa */
            if(position == 0)
            {
                break;
            }
            pRun = pRun -> pNext;
        }
        insertInformation(pRun);
    }
}

void findStudent(pStudent &pHead){

    printf("\n1. Find by name\n2. Find by ID\n3. Find by mark\nChoose mode: ");
    /* section là lựa chọn, result là số lượng trùng kết quả */
    int section = 0;
    int result = 0;
    scanf("%d", &section);
    switch (section)
    {
        case 1:
        {
            char temp[55];
            printf("\nInsert name that u want to find:");
            /* Xóa kí tự \n để tránh việc mảng kí tự nhận phần tử này */
            fflush(stdin);
            gets(temp);
            /* Tạo con trỏ pRun chạy từ đầu đến cuối duyệt tên */
            pStudent pRun = pHead;
            while(pRun != NULL)
            {
                /* So sánh 2 chuỗi kí tự bằng hàm strcmp */
                if(strcmp(pRun -> name, temp) == 0)
                {
                    result++;
                    printf("\n%d\t%s\t%d", pRun -> ID, pRun -> name, pRun -> mark);
                }
                pRun = pRun -> pNext;
            }
            if(result == 0)
            {
                printf("\nNo information is found!");
            }
            break;

        }
        case 2:
        {
            int value;
            printf("\nInsert ID that u want to find:");
            scanf("%d", &value);
            /* Kiểm tra điều kiện ID */
            if(value > amount || value < 1)
            {
                printf("No information is found");
            }
            /* Tạo con trỏ pRun chạy từ đầu đến cuối duyệt ID */
            pStudent pRun = pHead;
            while(pRun != NULL)
            {
                if(pRun -> ID == value)
                {
                    printf("\n%d\t%s\t%d", pRun -> ID, pRun -> name, pRun -> mark);
                }
                pRun = pRun -> pNext;
            }
            break;
        }
        case 3:
        {
            int value;
            printf("\nInsert mark that u want to find:");
            scanf("%d", &value);
            /* Tạo con trỏ pRun chạy từ đầu đến cuối duyệt ID */
            pStudent pRun = pHead;
            while(pRun != NULL)
            {
                if(pRun -> mark == value)
                {
                    result++;
                    printf("\n%d\t%s\t%d", pRun -> ID, pRun -> name, pRun -> mark);
                }
                pRun = pRun -> pNext;
            }
            if(result == 0)
            {
                printf("No information is found");
            }
            break;
        }
    }
}

void outputList(pStudent &pHead){

    pStudent pRun = pHead;
    if(pHead == NULL)
    {
        printf("\nNothing to show");
    }
    else
    {
        printf("ID\t\tNAME\t\tPOINTS");
        pRun = pHead;
        while(pRun != NULL)
        {
            printf("\n%d\t%s\t\t%d", pRun -> ID, pRun -> name, pRun -> mark);
            pRun = pRun -> pNext;
        }
    }
}

void deleteAll(pStudent &pHead){

    while(pHead != NULL)
    {
        /* Cho pHead chạy sang sinh viên tiếp theo rồi xóa sinh viên phía trước */
        if(pHead -> pNext != NULL)
        {
            pHead = pHead -> pNext;
            free(pHead -> pPrev);
            pHead -> pPrev = NULL;
        }
        /* Khi danh sách chỉ còn 1 sinh viên thì giải phóng chính nó */
        else
        {
            free(pHead);
            pHead = NULL;
        }
    }
}

void readFromTxt(pStudent &pHead, pStudent &pTail){

    /* Tạo con trỏ file */
    FILE *fp;
    fp = fopen("D:\\File.txt", "a+");
    /* xử lý khi mờ thất bại */
    if(feof(fp))
    {
        printf("Failed to open file!");
        exit(1);
    }
    /* Đưa con trỏ file về vị trí đầu file */
    fseek(fp, 0, SEEK_SET);

    /* Khởi tạo số lượng sinh viên từ dữ liệu file */
    fscanf(fp, "%d", &amount);
    fseek(fp, 1, SEEK_CUR);

    int fileMark = 0;
    char fileName[50];
    /* Vòng lặp tạo node liên tục từ file .txt */
    /*  Tạo số node tương ứng số lượng sinh viên*/
    for(int run = amount; run > 0;  run--)
    {
        /* Khởi tạo theo cơ chế tạo đuôi liên tục */
        /* Dùng fseek đẩy con trỏ qua các kí tự ",", "\n" */
        fscanf(fp, "%d", &fileMark);
        fseek(fp, 1, SEEK_CUR);
        fflush(stdin);
        fscanf(fp, "%[^\n,]s", fileName);
        fseek(fp, 1, SEEK_CUR);

        /* Nếu gặp kí tự  kết thúc text thì thoát ra */
        pStudent pNewStudent = creatNewStudent();

        /* Sao chép giá trị vào học sinh mới vừa tạo */
        pNewStudent -> mark = fileMark;
        strcpy(pNewStudent -> name, fileName);

        if(pHead == NULL)
        {
            /* Cho node đó là đầu và đuôi nếu danh sách trống */
            pHead = pNewStudent;
            pTail = pNewStudent;
        }
        else
        {
            /* Khi danh sách đã có node thì thêm vào đuôi */
            pTail -> pNext = pNewStudent;
            pNewStudent -> pPrev = pTail;
            pTail = pNewStudent;
        }
    }
    fclose(fp);
    fillID(pHead, amount);
}

void writeToTxt(pStudent &pHead, pStudent &pTail){

    /* Tạo con trỏ file */
    FILE *fp;
    /* Ghi đè lại từ đầu */
    fp = fopen("D:\\File.txt", "w");
    /* Khởi tạo con trỏ pRun chạy từ đầu tới cuối */
    /* Ghi số lượng sinh viên lên đầu file txt */
    fprintf(fp,  "%d\n", amount);
    pStudent pRun = pHead;
    while(pRun != NULL)
    {
        fprintf(fp, "%d,", pRun -> mark);
        fprintf(fp, "%s\n", pRun -> name);
        pRun = pRun -> pNext;
    }
    fclose(fp);
}