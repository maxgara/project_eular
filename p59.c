#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include "test_p59.c"
#define KEYLENGTH 3

int strsplit(char *str, char delim, char ***strs_out);
int readfile(char *fname, char *arr, int max);
int count_matches(char *pattern, char * str);
int decode(int *encoded_text, char key[3], char *clrtext, int n);
int get_cxints(int *cxints);
int get_words(char ***words);


int main(){
  //parse ciphertext into integer array
  int cxints[10000];
  int strcount = get_cxints(cxints);
  test_strsplit();
//
//   //parse common words file into str array
//   char **words;
//   int wordcount = get_words(&words);
//
//   char key[4];
//   strcpy(key,"aaa");
//   char clrtext[10000];
//   int best_match_count = 0;
//   char best_key[4];
//   char best_clrtext[10000];
//   while(strcmp(key,"zzz") <= 0){
//     printf("key:%s\n",key);
//     int match_count = 0;
//     decode(cxints, key, clrtext, strcount);
//     for(int i=0;i<wordcount;i++){
//       //printf("finding matches for str=%s key=%s:",words[i],key);
//       match_count += count_matches(clrtext,words[i]);
//       //printf(" %d found (total)\n",match_count);
//     }
//     if(match_count>best_match_count){
//       best_match_count=match_count;
//       strcpy(best_key, key);
//       strcpy(best_clrtext, clrtext);
//     }
//     printf("incrementing key %s\n",key);
//     //increment key
//     //printf("key[0]:%c\n",key[0]);
//     key[0]++;
//     //printf("change1: %s\n",key);
//     for(int i=0;i<2;i++){
//       if(key[i]>'z'){
//         key[i+1]++;
//         key[i]='a';
//       }
//     }
//   }
// count_matches("max","thismaxstringmaxhasnoneinit");
}

int get_words(char ***words){
  char words_str[10000];
  readfile("common_words.txt",words_str,10000);
  int wordcount = strsplit(words_str,'\n',words);
  printf("words[2]:%s\n",(*words)[2]);
  return wordcount;
}

int get_cxints(int *cxints){
  char cxtext[10000];
  readfile("p059_cipher.txt",cxtext,10000);
  char **cxstrs;
  int strcount = strsplit(cxtext,',',&cxstrs);
  for(int i=0;i<strcount;i++) {
    cxints[i]=atoi(cxstrs[i]);
  }
  return strcount;
}

int count_matches(char *pattern, char * str){
  int count=0;
  regex_t rex;
  int compstatus;
  compstatus = regcomp(&rex, pattern, 0);
  regmatch_t matchresult[1];
  while(regexec(&rex, str, 1, matchresult, 0)==0){
    count++;
    printf("matched in indices [%d-%d]\n",matchresult->rm_so,matchresult->rm_eo);
    str+=matchresult->rm_eo;
  }
  //printf("No match\n");
  return count;
}

int readfile(char *fname, char *arr, int max){
  FILE *fp;
  fp = fopen(fname,"r+");
  char newchar;
  int i=0;
  while((newchar=fgetc(fp)) != EOF && i<(max-1)){
    arr[i] = newchar;
    i++;
  }
  arr[i]='\0';
  fclose(fp);
}

int decode(int *encoded_text, char key[3], char *clrtext, int n){
  for(int i=0;i<n;i++){
   int keybyte = (int) key[i%3];
   clrtext[i] = (char) (encoded_text[i] ^ keybyte);
 }
}

int strsplit(char *str, char delim, char ***strs_out){
  //dry run through str to figure out how much space to malloc
  int arr_len=0;
  int str_len_max = 0;
  int str_len=0;
  int i=0;
  int hit_null_char = 0;
  while(!hit_null_char) {
    if(str[i]==delim){
      arr_len++;
      str_len_max = (str_len>str_len_max ? str_len : str_len_max);
      str_len = 0;
    }
    else if(str[i]=='\0'){
      arr_len++;
      str_len_max = (str_len>str_len_max ? str_len : str_len_max);
      hit_null_char=1;

    }
    else{
      str_len++;
    }
    i++;
  }
  int str_total_len = i; //include null terminating char
  printf("arr_len:%d\n",arr_len);
  printf("str_total_len:%d\n",str_total_len);
  printf("str_len_max:%d\n",str_len_max);
  char **strs = malloc(sizeof(char*) * arr_len);
  char *chars = malloc(sizeof(char) * str_total_len);
  //run through str again

  int idx_to_str = 0;
  int j=0;
  hit_null_char=0;
  int hit_new_str = 1;
  while(!hit_null_char){
    if(hit_new_str){
      strs[idx_to_str] = &chars[j];
      idx_to_str++;
      hit_new_str = 0;
    }
    if(str[j]==delim){
      chars[j] = '\0';
      hit_new_str = 1;
    }
    else if(str[j]=='\0'){
      chars[j] = '\0';
      hit_null_char=1;
    }
    else{
      chars[j] = str[j];
    }
    j++;
  }

  *strs_out=strs;
  return arr_len;
}
