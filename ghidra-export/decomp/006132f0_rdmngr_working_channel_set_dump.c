// func rdmngr_working_channel_set_dump @ 006132f0 size=1

void rdmngr_working_channel_set_dump(void)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = 0;
  printf("working channel set:");
  FUN_004082d0(l_working_channel_mutex,0xffffffff);
  do {
    uVar1 = 0;
    do {
      if ((1 << (uVar1 & 0x1f) & *(uint *)(&rdmngr_working_channel_set + iVar2)) != 0) {
        printf("%d ",uVar1 + iVar2 * 8);
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 != 0x20);
    iVar2 = iVar2 + 4;
  } while (iVar2 != 0x18);
  printf("\n working channel set num:");
  piVar3 = (int *)&rdmngr_working_channel_set_count;
  iVar2 = 0;
  do {
    if (*piVar3 != 0) {
      printf("%d:%d  ",iVar2);
    }
    iVar2 = iVar2 + 1;
    piVar3 = piVar3 + 1;
  } while (iVar2 != 0xc0);
  FUN_00407f30(l_working_channel_mutex);
  putchar(10);
  return;
}

