// func _autorrm_tmo_caculate @ 004a8b5c size=296

int _autorrm_tmo_caculate(int param_1,int param_2,int *param_3)

{
  tm *ptVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  time_t local_18 [2];
  
  local_18[0] = time((time_t *)0x0);
  ptVar1 = localtime(local_18);
  if (param_2 == 7) {
    iVar4 = 0x15180;
    iVar5 = *param_3 * 0xe10 + param_3[1] * 0x3c + param_3[2];
    iVar3 = ptVar1->tm_hour * 0xe10 + ptVar1->tm_min * 0x3c + ptVar1->tm_sec;
  }
  else {
    iVar5 = *param_3 * 0xe10 + param_3[1] * 0x3c + param_3[2] + param_2 * 0x15180;
    iVar3 = ptVar1->tm_wday * 0x15180 + ptVar1->tm_hour * 0xe10 + ptVar1->tm_min * 0x3c +
            ptVar1->tm_sec;
    iVar4 = 0x93a80;
  }
  if (((param_1 != 1) || (iVar2 = iVar4, iVar5 != iVar3)) && (iVar2 = iVar5 - iVar3, iVar5 < iVar3))
  {
    iVar2 = (iVar5 + iVar4) - iVar3;
  }
  return iVar2;
}

