// func cw_ac_thread_dump @ 0058cf18 size=140

void cw_ac_thread_dump(uint param_1)

{
  undefined4 uVar1;
  char *__s;
  
  if (param_1 < *(uint *)(ac + 0x18)) {
    printf("\n----------------thread %d\'s ap information-------------------\n",param_1);
    uVar1 = FUN_00407fe0(*(int *)(ac + 0x1c) + param_1 * 0xa0 + 0x4c);
    printf("total num:%d\n",uVar1);
    __s = "---------------------------end-------------------------------";
  }
  else {
    __s = "ac thread\'s index is wrong";
  }
  puts(__s);
  return;
}

