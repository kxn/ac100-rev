// func cw_priv_sta_ip_list_length @ 005c6010 size=112

short cw_priv_sta_ip_list_length(int *param_1)

{
  char cVar1;
  short sVar2;
  int iVar3;
  
  sVar2 = 0;
  if (param_1 != (int *)0x0) {
    sVar2 = 4;
    if (*param_1 != 0) {
      iVar3 = 0;
      do {
        cVar1 = *(char *)(param_1[1] + iVar3 * 0x1c + 8);
        if (cVar1 == '\x01') {
          sVar2 = sVar2 + 0xb;
        }
        else if (cVar1 == '\x02') {
          sVar2 = sVar2 + 0x17;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 != *param_1);
    }
  }
  return sVar2;
}

