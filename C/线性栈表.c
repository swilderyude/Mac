#include<stdio.h>
#include<stdlib.h>
 
struct LinkStack{
 char c;
 struct LinkStack *next;
};
 
LinkStack *InitLinkStack();
int IsEmptyStack(struct LinkStack *stack);
void Push(struct LinkStack *stack);
void Pop(struct LinkStack *stack);
void DispStackTop(struct LinkStack *stack);
void PrintIsEmptyStack(struct LinkStack *stack);
void PrintStack(struct LinkStack *stack);
 
void menu(){
 printf("\n         链栈的各种操作");
 printf("\n==================================");
 printf("\n|         1--初始化栈            |");
 printf("\n|         2--判断栈空            |");
 printf("\n|         3--入栈                |");
 printf("\n|         4--出栈                |");
 printf("\n|         5--得到栈顶元素         |");
 printf("\n|         6--输出栈              |");
 printf("\n|         0--退出                |");
 printf("\n==================================");
 printf("\n输入选择（0~6）：");
}
 

LinkStack *InitLinkStack(){
 struct LinkStack *stack;      
 stack = (struct LinkStack *)malloc(sizeof(struct LinkStack));
 stack->next = NULL;
 
 printf("初始化栈成功\n");
 return stack;
}
 

int IsEmptyStack(struct LinkStack *stack){
 if(stack->next == NULL)
  return 1;    
 else
  return 0;
}
 

void Push(struct LinkStack *stack){
 char ch;
 struct LinkStack *s;
 
 printf("输入要入栈的字符：");
 ch = getchar();
 getchar();    
 
 s = (struct LinkStack *)malloc(sizeof(struct LinkStack));
 s->c = ch;   
 s->next = stack->next;    
 stack->next = s;   
}
 
void Pop(struct LinkStack *stack){
 struct LinkStack *s;
 char ch;
 
 if(stack->next == NULL){    
  printf("当前栈已空，无法出栈！\n");
  exit(1);
 }
 
 s = stack->next;    
 ch = s->c;         
 stack->next = s->next;  
 free(s);    
 
 printf("出栈成功，出栈元素为%2c\n",ch);
}
 
void DispStackTop(struct LinkStack *stack){
 printf("当前栈顶元素为%2c\n",stack->next->c);
}
 
void PrintIsEmptyStack(struct LinkStack *stack){
 if(IsEmptyStack(stack)) 
   printf("当前栈为空\n"); 
 else
      printf("当前栈不为空\n");
}

void PrintStack(struct LinkStack *stack){
 struct LinkStack *s = stack->next;
 
 printf("当前栈为：\n");
 while(s != NULL){
  printf("%3c",s->c);
  s = s->next;    
 }
 putchar('\n');
}
 int main(){
 struct LinkStack *stack;
 char char1 = 'y',char2;
 
 do{
  menu();
  char2 = getchar();
  getchar();
 
  while(char1 == 'y' || char1 == 'Y'){
    switch(char2){
    case '1': stack = InitLinkStack();break;
    case '2': PrintIsEmptyStack(stack);break;
    case '3': Push(stack);break;
    case '4': Pop(stack);break;
    case '5': DispStackTop(stack);break;
    case '6': PrintStack(stack);break;
    case '0': char1 = 'n';break;
    default:printf("选择有误，范围应为0~6！\n");
   }
   
   char1 = 'n';
   if(char2=='3' || char2=='4'){
    printf("是否继续(y/n)：");
    char1 = getchar();
    getchar();
   }
  }
 
  char1 = 'y';
  if(char2 != '0'){
   printf("按回车键继续，按任意键退出...");
   char2 = getchar();
   if(char2 != '\n'){
    getchar();
    char1 = 'n';
   }
  }else
   char1 = 'n';
 }while(char1 == 'Y' || char1 == 'y');
 
 printf("\n操作结束\n");
 system("pause");  
}