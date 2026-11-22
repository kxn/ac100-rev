// func udbg_dup_stdout @ 005d5050 size=140

void udbg_dup_stdout(char *param_1)

{
  int __fd;
  
  if ((param_1 != (char *)0x0) && (__fd = open(param_1,1), 0 < __fd)) {
    dup2(__fd,1);
    dup2(__fd,2);
    setvbuf(stdout,(char *)0x0,2,0);
    setvbuf(stderr,(char *)0x0,2,0);
    close(__fd);
    return;
  }
  return;
}

