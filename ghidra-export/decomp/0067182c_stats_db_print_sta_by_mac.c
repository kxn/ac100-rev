// func stats_db_print_sta_by_mac @ 0067182c size=252

void stats_db_print_sta_by_mac(byte *param_1)

{
  size_t sVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  uint uVar5;
  char *pcVar6;
  char local_10 [8];
  
  local_10[0] = '\0';
  local_10[1] = '\0';
  local_10[2] = '\0';
  local_10[3] = '\0';
  local_10[4] = '\0';
  local_10[5] = '\0';
  if (param_1 != (byte *)0x0) {
    sVar1 = strlen((char *)param_1);
    iVar2 = 0;
    if (0x10 < sVar1) {
      do {
        uVar5 = *param_1 - 0x31 & 0xff;
        cVar3 = '\0';
        if (uVar5 < 0x36) {
          cVar3 = (&DAT_00720190)[uVar5];
        }
        uVar5 = param_1[1] - 0x31 & 0xff;
        cVar4 = '\0';
        if (uVar5 < 0x36) {
          cVar4 = (&DAT_00720190)[uVar5];
        }
        pcVar6 = local_10 + iVar2;
        iVar2 = iVar2 + 1;
        param_1 = param_1 + 3;
        *pcVar6 = cVar4 + cVar3 * '\x10';
      } while (iVar2 != 6);
      FUN_004082d0(l_stats_data,0xffffffff);
      iVar2 = FUN_00407fa0(DAT_007cc8e0,local_10);
      if (iVar2 != 0) {
        FUN_0066a080(iVar2);
      }
      FUN_00407f30(l_stats_data);
      return;
    }
  }
  puts("Inputs error\r");
  return;
}

