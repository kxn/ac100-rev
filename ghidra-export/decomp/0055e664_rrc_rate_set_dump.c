// func rrc_rate_set_dump @ 0055e664 size=112

void rrc_rate_set_dump(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = param_1;
  do {
    iVar2 = iVar2 + 4;
    if (*piVar1 == 0) break;
    printf("%u ");
    piVar1 = (int *)((int)param_1 + iVar2);
  } while (iVar2 != 0x40);
  puts("\r");
  return;
}

