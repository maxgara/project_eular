#include <stdio.h>
#include <stdlib.h>

int strsplit(char *str, char delim, char ***strs_out);

int test_strsplit(){
  char *dstr = "this-is-a-dash-separated-string";
  char *cstr = "this,is,a,comma,separated,string";
  char *repeated_sepstr = "this,,string,has,repeated,separators";
  char **dstr_list = malloc(100);
  char **cstr_list = malloc(100);

  printf("test with commas:\n");
  int cstr_list_len = strsplit(cstr, ',', &cstr_list);
  for(int i=0;i<cstr_list_len;i++){
    printf("[%s]\n",cstr_list[i]);
  }

  printf("test with dashes\n");
  int dstr_list_len = strsplit(dstr, '-', &dstr_list);
  for(int i=0;i<dstr_list_len;i++){
    printf("[%s]\n",dstr_list[i]);
  }

  printf("test repeated separators:\n");
  int repeated_sepstr_list_len = strsplit(repeated_sepstr, ',', &cstr_list);
  for(int i=0;i<cstr_list_len;i++){
    printf("[%s]\n",cstr_list[i]);
  }
  

}
