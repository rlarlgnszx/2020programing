#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define STRING 256
typedef struct money{
    char value[10];
    char purpose[20];
    char day[11];
    char p_m[2];
}money_m;
/*char timeput2(FILE **p){
    time_t rawTime;
    struct tm* pTimeInfo;
    char s1[4];
    char s2[4];
    char s3[4];
    char new_day[10];
    rawTime = time(NULL);
    pTimeInfo = localtime(&rawTime);
    int year = pTimeInfo -> tm_year +1900;
    int month = pTimeInfo -> tm_mon +1;
    int day = pTimeInfo -> tm_mday;
    sprintf(s1,"%d",year);
    sprintf(s2,"%02d",month);
    sprintf(s3,"%02d",day);
    printf("%d %d %d",year, month,day);
    //fputs(s1,*p);
    //fputs(s2,*p);
    //fputs(s3,*p);
    //fputs("\n",*p);
    strcat(new_day,s1);
    strcat(new_day,s2);
    strcat(new_day,s3);
    return new_day;
}*/
money_m get_record()
{
    money_m data;

    time_t rawTime;
    struct tm* pTimeInfo;
    char s1[4];
    char s2[4];
    char s3[4];
        char new_day[10];
    rawTime = time(NULL);
    pTimeInfo = localtime(&rawTime);
    int year = pTimeInfo -> tm_year +1900;
    int month = pTimeInfo -> tm_mon +1;
    int day = pTimeInfo -> tm_mday;
    sprintf(s1,"%d",year);
    sprintf(s2,"%02d",month);
    sprintf(s3,"%02d",day);
    //fputs(s1,*p);
    //fputs(s2,*p);
    //fputs(s3,*p);
    //fputs("\n",*p);
    strcat(new_day,s1);
    //strcat(new_day,s2);
    strcat(new_day,s3);
    fflush(stdin);
    printf("input/ouput(i,o) money_value purpose ");

    scanf("%c %s %s",data.p_m,data.value,data.purpose);
    strcpy(data.day,new_day);
    printf("%s\n",data.day);
    return data;
}
void print_board(money_m data)
{
    char plus[1];
    char day2[11];
    if(strcmp(data.p_m,"i")==0){
        printf("+");
        printf("%s",data.value);
        printf("%s",data.purpose);

    }else{
        printf("-");
        printf("%s",data.value);
        printf("%s",data.purpose);
    }
}
void input_money(FILE *fp){
        money_m data;
        data = get_record();
        fseek(fp,0,SEEK_END);
        fwrite(&data,sizeof(data),1,fp);
}
void print_day(FILE *fp){
    char day3[11];
    money_m data;
    fseek(fp,0,SEEK_SET);
    fflush(stdin);
    printf("search day ex)19980319 :");
    scanf("%s",day3);
    printf("day = %s\n",day3);
    while(!feof(fp)){
        fread(&data,sizeof(data),1,fp);

        if(strcmp(data.day,day3)==0){
            print_board(data);
            printf("\n");
            continue;
        }
    }
}
void have_money(FILE *fp){
    int sum = 0;
    money_m data;
    fseek(fp,0,SEEK_SET);
    fflush(stdin);
    while(!feof(fp)){
        fread(&data,sizeof(data),1,fp);
        char money_value[10];
        strcpy(money_value,data.value);


        printf("money_value = %ls",(int*)money_value);
        if(data.p_m == "i"){
            sum += *money_value;
        }else{
            sum -= *money_value;
        }

    }
    printf("all money = %d",sum);


}
int main(void){

    FILE *pFile = fopen("hello.txt","a+");
    int key=0;

    while (key!= 5){
        printf("1.input 2.output 3.find_day 4.having_money 5.quit");
        printf("\n");
        scanf("%d",&key);
        switch(key){

            case 1:
            case 2:
                input_money(pFile);
                break;
            case 3:
                print_day(pFile);
                break;
            case 4:
                have_money(pFile);
                break;
            case 5:
            
                return 0;
        }
    }

    printf("111");
    fclose(pFile);






    return 0;
}
