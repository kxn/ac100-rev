// func wportal_url_get_domain @ 00424f78 size=164

char * wportal_url_get_domain(char *param_1,size_t *param_2)

{
  char *pcVar1;
  size_t sVar2;
  char *__s;
  
  if (param_1 == (char *)0x0) {
    *param_2 = 0;
    __s = (char *)0x0;
  }
  else {
    pcVar1 = strstr(param_1,"https://");
    __s = param_1 + 8;
    if (pcVar1 == (char *)0x0) {
      pcVar1 = strstr(param_1,"http://");
      __s = param_1 + 7;
      if (pcVar1 == (char *)0x0) {
        __s = param_1;
      }
    }
    sVar2 = strcspn(__s,"/");
    if (sVar2 == 0) {
      sVar2 = strlen(__s);
      *param_2 = sVar2;
    }
    else {
      *param_2 = sVar2;
    }
  }
  return __s;
}

