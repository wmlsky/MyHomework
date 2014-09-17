/******************************************************************************/
/*Copyright (C) Software Engineering Class 2, SSE@USTC, 2014-2015             */
/*                                                                            */
/* FILE NAME             :   wmlMenu.c                                        */
/* PRINCIPAL AUTHOR      :   WangMingliang                                    */
/* SUBSYSTEM NAME        :   wmlMenu                                          */
/* MODULE NAME           :   wmlMenu                                          */
/* LANGUAGE	         :   C                                                */
/* TARGET ENVIRONMENT    :   ANY                                              */
/* DATE OF FIRST RELEASE :   2014/9/13                                        */
/* DESCRIPTION           :   This is my first homework!                       */
/******************************************************************************/


/*
 *Revision log:
 *
 *Created by WangMingliang, 2014/9/13
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10

/* wmlMenu program */

/* data struct and its operations */

typedef struct DataNode
{
    char*   cmd;
    char*   desc;
    int     (*handle)();
    struct  DataNode* next;
} tDataNode;

tDataNode* FindCmd(char*);
int ShowCmd();
int Help();

static tDataNode head[] = 
{
    {"help", "this is help cmd!", Help, &head[1]},
    {"version", "wmlMenu program v1.0", NULL, NULL}
};

/* menu program */

main()
{
    /* cmd line begin */
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a cmd > ");
        scanf("%s", cmd);
        tDataNode* p = FindCmd(cmd);
        if(p != NULL)
        {
            printf("%s - %s\n", p->cmd, p->desc);
            if(p->handle != NULL)
            {
                p->handle();
            }
        }
        else
        {
            printf("This is a wrong cmd!\n");
        } 
    }
}

tDataNode* FindCmd(char* cmd)
{
    tDataNode* p = head;
    while(p != NULL)
    {
        if(!strcmp(p->cmd, cmd))
        {   
            return p;
        }
        p = p->next;
    }
    return NULL;
}

int ShowCmd()
{
    printf("Menu List:\n");
    tDataNode* p = NULL;
    p = head;
    while(p != NULL)
    {
        printf("%s - %s\n", p->cmd,p->desc);
        p = p->next;
    } 
}

int Help()
{
    ShowCmd();
    return 0;
}
