// func _pkt_getNumber @ 0043aff8 size=232

undefined4 _pkt_getNumber(char *param_1,int param_2,int *param_3,undefined4 *param_4)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char local_20 [16];
  
  pcVar3 = param_1 + param_2;
  local_20[0] = '\0';
  local_20[1] = '\0';
  local_20[2] = '\0';
  local_20[3] = '\0';
  local_20[4] = '\0';
  local_20[5] = '\0';
  local_20[6] = '\0';
  local_20[7] = '\0';
  local_20[8] = '\0';
  local_20[9] = '\0';
  local_20[10] = 0;
  cVar1 = *param_1;
  while ((9 < (byte)(cVar1 - 0x30U) && (param_1 < pcVar3))) {
    param_1 = param_1 + 1;
    if (pcVar3 <= param_1) {
      return 0xffffffff;
    }
    cVar1 = *param_1;
  }
  iVar2 = 0;
  while( true ) {
    cVar1 = *param_1;
    if (((9 < (byte)(cVar1 - 0x30U)) || (pcVar3 <= param_1)) || (iVar2 == 10)) break;
    param_1 = param_1 + 1;
    pcVar4 = local_20 + iVar2;
    iVar2 = iVar2 + 1;
    *pcVar4 = cVar1;
  }
  local_20[iVar2] = '\0';
  iVar2 = atoi(local_20);
  *param_3 = iVar2;
  *param_4 = param_1;
  return 0;
}

