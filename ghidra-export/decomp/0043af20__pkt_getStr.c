// func _pkt_getStr @ 0043af20 size=216

undefined4 _pkt_getStr(char *param_1,int param_2,void *param_3,int param_4,int *param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int local_18 [2];
  
  iVar3 = 0;
  local_18[0] = 0;
  local_18[1] = 0;
  iVar4 = 0;
  while (((iVar1 = local_18[1], iVar3 < param_2 && (iVar4 < 2)) && (*param_1 != '\0'))) {
    iVar3 = iVar3 + 1;
    if (*param_1 == '\"') {
      local_18[iVar4] = (int)param_1;
      param_1 = param_1 + 1;
      iVar4 = iVar4 + 1;
    }
    else {
      param_1 = param_1 + 1;
    }
  }
  uVar2 = 0xffffffff;
  if (((local_18[0] != 0) && (iVar4 = local_18[1] - local_18[0], local_18[1] != 0)) &&
     (iVar4 <= param_4)) {
    memcpy(param_3,(void *)(local_18[0] + 1),iVar4 - 1);
    *(undefined1 *)((int)param_3 + iVar4 + -1) = 0;
    *param_5 = iVar1 + 1;
    uVar2 = 0;
  }
  return uVar2;
}

