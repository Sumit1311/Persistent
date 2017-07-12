#include <stdio.h>
#include <string.h>

int stack[1000];
int top = 0;

int push(int c)
{
   if(top == 1000)
   {
      return -1;
   }
   stack[top++] = c;
}

int pop()
{
   if(top == 0)
   {
      return;
   }
   return stack[--top];
}

void empty()
{
   top = 0;
   stack[top] = 0;
}

int stack_top()
{
   if(top > 0)
   {
      return stack[top - 1];
   }
   return -1;
}

void print_stack()
{
   int i = 0;
   while(i < top)
   {
      printf("%d,",stack[i]);
      i++;
   }
   printf("\n");
}


int longestWellFormed(char *str)
{
   int i = 0, max_length = 0, count = 0, save_count = 0, temp = 0;
   int len = strlen(str);
   while(i < len)
   {
      char t = str[i];
      //printf("(%d,%d,%d)\n",i,count,max_length);
      //print_stack();
      //printf("*%c*",str[stack_top()]);
      if(t == '{' || t == '[' || t == '(')
      {
         push(i);
      }
      else if((t == ')' && str[stack_top()] == '(') || 
         (t == '}' && str[stack_top()] == '{') || 
         (t == ']' && str[stack_top()] == '[') )
      {
           temp = pop();
           //printf(", %d)",temp);
           count = (i - stack_top());
           max_length = (count > max_length ? count : max_length);
      } 
      else
      {
         empty();
         max_length = (count > max_length ? count : max_length);
         count = 0;
         push(i);
      }
      i++;
      //printf("\n");
   }
   empty();
   //max_length = max_length > count ? max_length : count;
   //max_length = (max_length > (i - stack_top()) ? max_length : (i - stack_top()) );
   //printf("\n");
   return max_length;
}


int main()
{
   int i = 0;
  struct {
      int ExpectedLength;
      char *string;
   }
   TestData[] = 
   {
      {848,"({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[(({[()[][{}()]]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]}))]})"}
     // {10, "(({{}}[]))"},
     // {10, "[][(({{}}[]))["},
     // {0, "["},
     // {0, "]"},
     // {10, "{{{{{{(((())))}]]{{{}{}{}"},
     // {0, ""},
     // {0, "[}"},
     // {10, "(())()(()){{{}}{}"},
     // {18, "]{()}[][()[{}[][[]](()){}]}{}(){"},
     // {8, "{{{}}{}{}{{{{{{{]}}}}}}}()()"} 
   };

   for(;i < sizeof(TestData) / sizeof(*TestData);i++)
   {
      int length = longestWellFormed(TestData[i].string);
      printf("%d,%d\n",length, TestData[i].ExpectedLength);
   }
  return 0;
}
