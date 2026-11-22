// func print_show_mem @ 0051de08 size=140

void print_show_mem(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = &g_lines;
  do {
    if (*piVar2 != 0) {
      printf("print_show_mem==line:%d leak cnt:%d\r\n",iVar1);
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 != 0xffff);
  return;
}

