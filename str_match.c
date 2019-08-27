                // string matching and replacing a new string by that pattern using brute-force approach
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int check_str(char *,char *,int);       // checking the pattern found or not
void replace(char *,char *,char *,int );   // if pattern found in main string replace the pattern with a replacing string
void main()
{
        char ms[50],ss[50],rep_str[20],res_str[100];
       // scanf("%s%s%s",ms,ss,rep_str);
       gets(ms);
       gets(ss);
       gets(rep_str);
        int i,check,pos_search=0,pos_copy=0,len_ms=strlen(ms),len_ss=strlen(ss),len_rep_str=strlen(rep_str);
       //  printf("%s%s%s",ms,ss,rep_str);
        for(i=0;i<len_ms;)
        {
            check = check_str(ms,ss,pos_search);
            if (check == -1)                        // when pattern not found
            {
                res_str[pos_copy] = ms[pos_search];
                i++;
                pos_copy++;
                pos_search++;
            }

            else                                // when pattern found in main string
            {
                replace(ms,rep_str,res_str,pos_copy);
                i = i + len_ss;
                pos_search = i;
                pos_copy = pos_copy + len_rep_str;
            }
        }
        res_str[pos_copy] = '\0';
        printf("%s",res_str);
}
int check_str(char *ms,char *ss,int pos_search)
{
    int i,len_ss = strlen(ss);

    for(i=0;i<len_ss;i++,pos_search++)
    {
        if (ms[pos_search]!=ss[i])
        {
            return -1;                                     // when pattern not found
        }
    }
    return 1;
}

void replace(char *ms,char *rep_str,char *res_str,int pos_copy)
{
    int i,len_rep_str = strlen(rep_str);
    for(i=0;i<len_rep_str;i++)
    {
        res_str[pos_copy] =  rep_str[i];
        pos_copy++;
    }
}
